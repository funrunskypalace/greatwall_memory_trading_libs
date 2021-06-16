#pragma once

#include "framework/common/common.h"
#include "framework/strategy/instance.h"

namespace framework { namespace strat {

class StrategyEngine {
public:
    virtual ~StrategyEngine() = default;

    /// synchronous stop and return, no need to join.
    virtual int stop() PURE;

    /// dynamic create strategy
    /// @param strategyId strategy-id
    /// @param strategyInstId newly created strategy's instance id.
    virtual int load(const StrategyId& strategyId, const StrategyInstId& strategyInstId, const std::string& jsonContent,
                     const GreatWallAppPtr& service) PURE;

    virtual int unload(const StrategyId& strategyId, const StrategyInstId& strategyInstId, std::string& reason) PURE;

    virtual int reload(const StrategyId& strategyId, const StrategyInstId& strategyInstId,
                       const std::string& jsonContent, const GreatWallAppPtr& service, std::string& reason)
    {
        return F_FAIL;
    };

    virtual InstancePtr getInstance(const StrategyInstId& strategyInstId) PURE;

    virtual std::list<strat::InstancePtr> getInstances(const StrategyId& strategyId) PURE;
};

}} // namespace framework::strat