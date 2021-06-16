#pragma once

#include "framework/strategy/context.h"
#include "framework/strategy/instance.h"
#include "framework/strategy/rc_base.h"
#include "framework/trade/transaction_prop.h"
#include "framework/strategy/context.h"
#include "framework/science/mathexpr.h"
#include "framework/trade/executor.h"

using namespace framework;

class OnTimeTradingRiskControl : public strat::RcBase {
public:
    OnTimeTradingRiskControl(const strat::ContextPtr& context, const trade::TransactionProp& prop)
        : context_(context), trans_prop_(prop){};
    virtual bool canTerminate(int orderIndex) const { return true; };
    virtual bool riskCheck(const trade::Transaction& transaction)
    {
        context_->log(framework::info, "Risk check skipped in OnTimeTrading strategy now!");
        return true;
    };

private:
    const trade::TransactionProp& trans_prop_;
    const strat::ContextPtr& context_;
};

using SaveArbitrageItemCb = std::function<bool(trade::OrderPackInfoPtr&)>;

struct TradeTimePeriod {
    uint64_t start;
    uint64_t end;
};

class OnTimeTradingStrategy : public strat::Instance {
public:
    OnTimeTradingStrategy(strat::ContextPtr& context);

    virtual int load(const std::string& jsonContent = "") override;
    virtual int reload(const std::string& jsonContent = "") override;
    virtual StrategyId globalUniqueName() override { return "on_time_trading"; }
    virtual bool onTimer(int32_t timerId) override;
    virtual void onData(int32_t dataType, const char* data, size_t datasiz) override;
    virtual void onExecStarted(const trade::TransactionPtr& transaction) override;
    virtual void onExecSnapshot(const trade::TransactionPtr& transaction, OROrderFieldPtr order) override;
    virtual void onExecSnapshot(const trade::TransactionPtr& transaction, ORTradeFieldPtr trade) override;
    virtual void onExecFinished(const trade::TransactionPtr& transaction) override;

protected:
    trade::OrderPackInfoPtr getOrderPack(int64_t index);
    bool iterate(SaveArbitrageItemCb callback);

private:
    trade::TransactionProp my_transaction_props;
    std::list<int32_t> timer_ids_;
    std::vector<trade::OrderPackInfoPtr> order_packs_;
    std::list<TradeTimePeriod> trading_periods_;
    int64_t trading_day_ = {0};
    int64_t exec_mode_ = {0};
    int64_t max_rejection_times_ = {500};
    std::atomic<int64_t> rejection_counter_ = {0};
    int64_t max_cancel_times_ = {2000};
    int64_t on_start_time_ = {0};
    int64_t on_stop_time_ = {0};
    bool is_executing_ = {false};
    bool is_executed_ = {false};
    std::atomic<int64_t> cancel_counter_ = {0};
    bool initialized_successfully_ = {false};
    std::atomic<bool> is_reloading_ = {false};
};