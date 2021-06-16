#include "pch/compat.h"

#include "strategy.h"
#include <fstream>
#include <sstream>
#include <string>


OnTimeTradingStrategy::OnTimeTradingStrategy(strat::ContextPtr& context) : strat::Instance(context) {}

int OnTimeTradingStrategy::load(const std::string& jsonContent)
{
    log(framework::info, "load strategy {} - {}...", globalUniqueName(), instanceId());
    // Load configuration
    try {
        nlohmann::json cfg = nlohmann::json::parse(jsonContent);

        // Init Transaction Props
        int32_t tempint, tempbool;
        cfg["transaction"]["TimeoutMicroseconds"].get_to(tempint);
        my_transaction_props.TimeoutMicroseconds = tempint;
        cfg["transaction"]["CancelOnTimeout"].get_to(tempbool);
        my_transaction_props.CancelOnTimeout = tempbool;
        cfg["transaction"]["CloseOnTimeout"].get_to(tempbool);
        my_transaction_props.CloseOnTimeout = tempbool;
        cfg["transaction"]["ExposureDeadlineMicroseconds"].get_to(tempint);
        my_transaction_props.ExposureDeadlineMicroseconds = tempint;
        cfg["transaction"]["MaxCancelTimes"].get_to(tempint);
        my_transaction_props.MaxCancelTimes = tempint;
        cfg["transaction"]["CancelIntervalMicro"].get_to(tempint);
        my_transaction_props.CancelIntervalMicro = tempint;
        cfg["transaction"]["MaxSendTimes"].get_to(tempint);
        my_transaction_props.MaxSendTimes = tempint;
        my_transaction_props.RiskControl = std::make_shared<OnTimeTradingRiskControl>(context_, my_transaction_props);

        /// parse strategy parameters first

        if (cfg["strategy"].contains("is_executing")) {
            cfg["strategy"]["is_executing"].get_to(is_executing_);
        }
        cfg["strategy"]["on_start_time"].get_to(on_start_time_);
        if (0 == on_start_time_) {
            auto str = fmt::format("Failed to parse on_start_time: {}!", on_start_time_);
            throw new std::exception(str.c_str());
        }
        cfg["strategy"]["on_stop_time"].get_to(on_stop_time_);
        if (0 == on_stop_time_) {
            auto str = fmt::format("Failed to parse on_stop_time: {}!", on_stop_time_);
            throw new std::exception(str.c_str());
        }
        if (on_start_time_ >= on_stop_time_) {
            auto str =
                fmt::format("Failed to set on_start_time and on_stop_time: {} <= {}!", on_start_time_, on_stop_time_);
            throw new std::exception(str.c_str());
        }
        cfg["strategy"]["trading_day"].get_to(trading_day_);
        auto curday = pch::get_current_date(false);
        if (trading_day_ != curday) {
            auto str = fmt::format("Trading day set wrong!!! current:{}, config set:{}", curday, trading_day_);
            throw new std::exception(str.c_str());
        }
        cfg["strategy"]["max_rejection_times"].get_to(max_rejection_times_);
        cfg["strategy"]["max_cancel_times"].get_to(max_cancel_times_);
        cfg["strategy"]["execution_mode"].get_to(exec_mode_);
        if (exec_mode_ != 1 && exec_mode_ != 2) {
            auto str = fmt::format("execution_mode set wrong!!! current:{} (1: open, 2: close)", exec_mode_);
            throw new std::exception(str.c_str());
        }
        int64_t tempstart, tempend;
        int64_t tday = trading_day_;
        for (auto periodcfg : cfg["strategy"]["trading_period_protection"]) {
            TradeTimePeriod period;
            periodcfg["start"].get_to(tempstart);
            period.start = pch::parse_milliseconds(tday, tempstart, false);
            periodcfg["end"].get_to(tempend);
            period.end = pch::parse_milliseconds(tday, tempend, false);
            log(framework::info, "add trading period: {}({})-{}({})", tempstart, period.start / 1000000, tempend,
                period.end / 1000000);
            trading_periods_.emplace_back(period);
        }
        log(framework::info, "trading on time: {} - {}", on_start_time_, on_stop_time_);

        /// parse instruments
        if (cfg.contains("instruments")) {
            auto instrumentscfg = cfg["instruments"];
            for (int64_t i = 0; i < instrumentscfg.size(); ++i) {
                auto pk = std::make_shared<trade::OrderPackInfo>();
                auto key = fmt::format("leg{}", i + 1);
                if (!instrumentscfg[i].contains(key)) {
                    log(framework::info, "Doesn't contain instrument with key {}", key);
                    continue;
                }
                auto legcfg = instrumentscfg[i][key];
                std::string exid, insid, tempstr;
                or_direction_e diropen, dirclose;
                or_offsetflag_e offsetflagopen, offsetflagclose;
                or_hedgeflag_e hedgeflag;
                or_volume_i vol;
                or_price_f price_lower, price_upper, bidask_spread = 1, bidask_volume = 2;
                or_price_f price_open, price_close;
                or_channelid_i channelid;
                or_investorid_i investorid;
                or_productclass_e pc;
                bool resend, suppressing;
                double abs_price_shift = 0;

                legcfg["channel_id"].get_to(channelid);
                legcfg["investor_id"].get_to(investorid);
                legcfg["product_class"].get_to(tempstr);
                pc = tempstr[0];
                legcfg["exchange_id"].get_to(exid);
                legcfg["instrument_id"].get_to(insid);
                legcfg["volume"].get_to(vol);
                legcfg["price_open"].get_to(price_open);
                legcfg["price_close"].get_to(price_close);
                legcfg["direction_open"].get_to(tempstr);
                diropen = tempstr[0];
                legcfg["direction_close"].get_to(tempstr);
                dirclose = tempstr[0];
                legcfg["offset_flag_open"].get_to(tempstr);
                if (tempstr.length() > 0)
                    offsetflagopen = tempstr[0];
                else
                    offsetflagopen = 0;
                legcfg["offset_flag_close"].get_to(tempstr);
                if (tempstr.length() > 0)
                    offsetflagclose = tempstr[0];
                else
                    offsetflagclose = 0;
                legcfg["hedge_flag"].get_to(tempstr);
                if (tempstr.length() > 0)
                    hedgeflag = tempstr[0];
                else
                    hedgeflag = 0;
                legcfg["resend"].get_to(resend);
                legcfg["suppressing"].get_to(suppressing);
                legcfg["protection_price_lower"].get_to(price_lower);
                legcfg["protection_price_upper"].get_to(price_upper);
                legcfg["protection_bidask_spread"].get_to(bidask_spread);
                if (legcfg.contains("protection_bidask_volume")) {
                    legcfg["protection_bidask_volume"].get_to(bidask_volume);
                }
                legcfg["price_shift"].get_to(abs_price_shift);
                try {
                    pk->initialize(channelid, investorid, pc, exid, insid, (exec_mode_ == 1 ? diropen : dirclose),
                                   (exec_mode_ == 1 ? offsetflagopen : offsetflagclose), hedgeflag, vol,
                                   (exec_mode_ == 1 ? price_open : price_close), OR_OPT_LimitPrice, OR_TC_GFD,
                                   OR_CC_Immediately, OR_VC_AV, trade::OR_EST_Filled, true);
                    pk->protect(price_lower, price_upper, bidask_spread, bidask_volume);
                    pk->moreDirection(diropen, dirclose);
                    pk->moreOffsetFlag(offsetflagopen, offsetflagclose);
                }
                catch (const std::exception& e) {
                    std::cout << "Failed to parse fields, " << e.what() << std::endl;
                }
                pk->setReSend(resend);
                pk->setPriceShift(abs_price_shift);
                order_packs_.push_back(pk);
            }
        }

        /// timers
        if (cfg.contains("timers")) {
            SleepMs(100);
            auto timerscfg = cfg["timers"];
            for (int64_t i = 0; i < timerscfg.size(); ++i) {
                auto key = fmt::format("timer{}", i + 1);
                if (!timerscfg[i].contains(key)) {
                    log(framework::info, "Doesn't contain timer with key {}", key);
                    continue;
                }
                auto timercfg = timerscfg[i][key];
                int64_t intervalms;
                timercfg["interval_ms"].get_to(intervalms);
                intervalms = std::max(1LL, intervalms);
                int64_t timerid = context()->setTimer(intervalms);
                timer_ids_.push_back(timerid);
            }
        }
    }
    catch (std::exception* e) {
        log(framework::err, "JSON Parse error: {}", e->what());
        return -1;
    }

    initialized_successfully_ = true;
    return 0;
}

int OnTimeTradingStrategy::reload(const std::string& jsonContent)
{
    if (is_executing_) return framework::F_FAIL;
    if (is_reloading_) return framework::F_FAIL;
    is_reloading_ = true;

    // kill timers
    for (auto tid : timer_ids_) {
        context()->killTimer(tid);
    }
    timer_ids_.clear();
    order_packs_.clear();
    is_executed_ = false;

    load(jsonContent);

    is_reloading_ = false;
    return 0;
}

bool OnTimeTradingStrategy::onTimer(int32_t timerId)
{
    if (is_reloading_) {
        return true;
    }

    if (is_executed_) {
        log(framework::info, "is_executed={}, stop timerId: {}", is_executed_, timerId);
        return false;
    }

    if (is_executing_) {
        // keep timer
        return true;
    }
    // get local time
    uint64_t msnow = pch::get_nano(false) / 1000000;
    uint64_t msstart = pch::parse_milliseconds(trading_day_, on_start_time_, false) / 1000000;
    uint64_t msstop = pch::parse_milliseconds(trading_day_, on_stop_time_, false) / 1000000;
    bool cantrade = (msnow >= msstart) && (msnow <= msstop);
    if (!cantrade) {
        // keep timer
        return true;
    }

    for (auto tid : timer_ids_) {
        if (tid == timerId) {
            is_executing_ = true;
            log(framework::info, "execute trading at time={}", msnow);
            // do open
            auto trans = context()->createTransaction(my_transaction_props);
            {
                auto iteret = iterate([&](trade::OrderPackInfoPtr& pack) -> bool {
                    trans->placeOrder(pack);
                    return true;
                });
                if (!iteret) {
                    log(framework::warn, "Failed to place order into transaction!");
                    // don't insert order and return true to keep timer
                    // alive.
                    return true;
                }
            }
            context()->orderInsert(trans);
        }
        else {
            log(framework::info, "Unknown timerid {} triggered.", timerId);
            return true;
        }
    }

    return true;
}

trade::OrderPackInfoPtr OnTimeTradingStrategy::getOrderPack(int64_t index)
{
    if (index >= order_packs_.size()) {
        return nullptr;
    }

    return order_packs_[index];
}

bool OnTimeTradingStrategy::iterate(SaveArbitrageItemCb callback)
{
    for (int64_t i = 0; i < order_packs_.size(); ++i) {
        if (!callback(order_packs_[i])) {
            return false;
        }
    }
    return true;
}

void OnTimeTradingStrategy::onData(int32_t dataType, const char* data, size_t datasiz) {}

void OnTimeTradingStrategy::onExecStarted(const trade::TransactionPtr& transaction)
{
    log(framework::debug, "Transaction Start> UUID={}", transaction->uuid());
}

void OnTimeTradingStrategy::onExecSnapshot(const trade::TransactionPtr& transaction, OROrderFieldPtr order)
{
    log(framework::debug, "ExecSnapshot> UUID={} Contract={}", transaction->uuid(), order->InstrumentID);
    if (order->OrderStatus == OR_OST_New)
        log(framework::debug, "ExecSnapshot> OR_OST_New");
    else if (order->OrderStatus == OR_OST_Filled)
        log(framework::debug, "ExecSnapshot> OR_OST_Filled");
    else if (order->OrderStatus == OR_OST_Rejected) {
        rejection_counter_ += 1;
        log(framework::debug, "ExecSnapshot> OR_OST_Rejected");
    }
    else if (order->OrderStatus == OR_OST_Canceled) {
        cancel_counter_ += 1;
        log(framework::debug, "ExecSnapshot> OR_OST_Canceled");
    }
    else
        log(framework::debug, "ExecSnapshot> {}", order->OrderStatus);
}

void OnTimeTradingStrategy::onExecSnapshot(const trade::TransactionPtr& transaction, ORTradeFieldPtr trade)
{
    log(framework::info, "Trade, price={:.6f}, filled_vol={}, amount={:.6f}, transaction={}", trade->Price,
        trade->Volume, trade->TradeAmount, transaction->uuid());
}

void OnTimeTradingStrategy::onExecFinished(const trade::TransactionPtr& transaction)
{
    log(framework::info, "Transaction onExecFinished, uuid={}, filled={}, terminated={}", transaction->uuid(),
        transaction->filled(), transaction->terminated());
    transaction->iterate([&](trade::OrderPackInfoPtr& pack) -> bool {
        auto req = pack->getOrderReq(false);
        log(framework::info, "{}.{} traded at price {}, inserted {}, filled {}", req.ExchangeID, req.InstrumentID,
            req.LimitPrice, req.VolumeTotalOriginal, pack->volumeTradedSum());
        return true;
    });
    is_executing_ = false;
    is_executed_ = true;
}
