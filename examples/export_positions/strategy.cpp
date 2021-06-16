#include "pch/compat.h"
#include "pch/compat_time.h"

#include "strategy.h"
#include <fstream>
#include <sstream>
#include <string>

ExportPositionsStrategy::ExportPositionsStrategy(strat::ContextPtr& context) : strat::Instance(context) {}

int ExportPositionsStrategy::load(const std::string& jsonContent)
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
        my_transaction_props.RiskControl = std::make_shared<ExportPositionsRiskControl>(context_, my_transaction_props);

        /// parse strategy parameters first

        if (cfg["strategy"].contains("output_path")) {
            cfg["strategy"]["output_path"].get_to(output_path_);
        }
        else {
            output_path_ = "./";
        }
        fix_path(output_path_);
        make_directory_tree(output_path_.c_str());
        if (cfg["strategy"].contains("first_line")) {
            cfg["strategy"]["first_line"].get_to(first_line_);
        }
        else {
            first_line_ = "Ticker, open, target, forecast, yst, current,";
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

    auto poslist = context()->getAllPositions();
    auto fn = fmt::format("{}{}.csv", output_path_, pch::get_current_date(false));
    std::ofstream out(fn);
    // out << "Ticker, open, target, forecast, yst, current,";
    out << first_line_ << std::endl;
    for (auto pos : *poslist) {
        log(info, "pos: {}.{}, total {}, enable {}, today {}, todayenable {}", pos->ExchangeID, pos->InstrumentID,
            pos->TotalPosition, pos->EnableVolume, pos->TodayPosition, pos->TodayEnableVolume);
        out << fmt::format("{}{}, {}, {}, {}, {}, {}, ", pos->ExchangeID, pos->InstrumentID, pos->TotalPosition,
                           pos->TotalPosition, 0, pos->TotalPosition, pos->EnableVolume)
            << std::endl;
    }
    out.close();
    return 0;
}

int ExportPositionsStrategy::reload(const std::string& jsonContent)
{
    // kill timers
    for (auto tid : timer_ids_) {
        context()->killTimer(tid);
    }
    timer_ids_.clear();

    load(jsonContent);
    return 0;
}

bool ExportPositionsStrategy::onTimer(int32_t timerId)
{
    // get local time
    uint64_t msnow = pch::get_nano(false) / 1000000;
    // uint64_t msstart = parse_milliseconds(trading_day_, on_start_time_, false) / 1000000;
    // uint64_t msstop = parse_milliseconds(trading_day_, on_stop_time_, false) / 1000000;
    // bool cantrade = (msnow >= msstart) && (msnow <= msstop);
    // if (!cantrade) {
    //    // keep timer
    //    return true;
    //}

    for (auto tid : timer_ids_) {
        if (tid == timerId) {
        }
        else {
            log(framework::info, "Unknown timerid {} triggered.", timerId);
            return true;
        }
    }

    return true;
}

void ExportPositionsStrategy::onData(int32_t dataType, const char* data, size_t datasiz) {}

void ExportPositionsStrategy::onExecStarted(const trade::TransactionPtr& transaction)
{
    log(framework::debug, "Transaction Start> UUID={}", transaction->uuid());
}

void ExportPositionsStrategy::onExecSnapshot(const trade::TransactionPtr& transaction, OROrderFieldPtr order)
{
    log(framework::debug, "ExecSnapshot> UUID={} Contract={}", transaction->uuid(), order->InstrumentID);
    log(framework::debug, "ExecSnapshot> {}", order->OrderStatus);
}

void ExportPositionsStrategy::onExecSnapshot(const trade::TransactionPtr& transaction, ORTradeFieldPtr trade)
{
    log(framework::info, "Trade, price={:.6f}, filled_vol={}, amount={:.6f}, transaction={}", trade->Price, trade->Volume,
        trade->TradeAmount, transaction->uuid());
}

void ExportPositionsStrategy::onExecFinished(const trade::TransactionPtr& transaction)
{
    log(framework::info, "Transaction onExecFinished, uuid={}, filled={}, terminated={}", transaction->uuid(),
        transaction->filled(), transaction->terminated());
    transaction->iterate([&](trade::OrderPackInfoPtr& pack) -> bool {
        auto req = pack->getOrderReq(false);
        log(framework::info, "{}.{} traded at price {}, inserted {}, filled {}", req.ExchangeID, req.InstrumentID, req.LimitPrice,
            req.VolumeTotalOriginal, pack->volumeTradedSum());
        return true;
    });
}
