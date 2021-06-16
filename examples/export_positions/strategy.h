#pragma once

#include "framework/strategy/context.h"
#include "framework/strategy/instance.h"
#include "framework/strategy/rc_base.h"
#include "framework/trade/transaction_prop.h"
#include "framework/strategy/context.h"
#include "framework/science/mathexpr.h"
#include "framework/trade/executor.h"

using namespace framework;

class ExportPositionsRiskControl : public strat::RcBase {
public:
    ExportPositionsRiskControl(const strat::ContextPtr& context, const trade::TransactionProp& prop)
        : context_(context), trans_prop_(prop){};
    virtual bool canTerminate(int orderIndex) const { return true; };
    virtual bool riskCheck(const trade::Transaction& transaction)
    {
        context_->log(framework::info, "Risk check skipped in ExportPositions strategy now!");
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

class ExportPositionsStrategy : public strat::Instance {
public:
    ExportPositionsStrategy(strat::ContextPtr& context);

    virtual int load(const std::string& jsonContent = "") override;
    virtual int reload(const std::string& jsonContent = "") override;
    virtual StrategyId globalUniqueName() override { return "export_positions"; }
    virtual bool onTimer(int32_t timerId) override;
    virtual void onData(int32_t dataType, const char* data, size_t datasiz) override;
    virtual void onExecStarted(const trade::TransactionPtr& transaction) override;
    virtual void onExecSnapshot(const trade::TransactionPtr& transaction, OROrderFieldPtr order) override;
    virtual void onExecSnapshot(const trade::TransactionPtr& transaction, ORTradeFieldPtr trade) override;
    virtual void onExecFinished(const trade::TransactionPtr& transaction) override;

protected:
private:
    trade::TransactionProp my_transaction_props;
    std::list<int32_t> timer_ids_;
    std::string output_path_;
    std::string first_line_;
};