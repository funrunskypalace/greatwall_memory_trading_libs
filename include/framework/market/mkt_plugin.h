// @author Jiang Sanyi 2019-12-03
#pragma once

#include "framework/common/common.h"
#include "framework/market/filter_context.h"
#include "framework/market/market.h"
#include "framework/common/logger.h"

#include "framework/market/mkt_plugin-inl.h"

namespace framework { namespace market {

/**
 * 用户扩展行情处理，由用户自行对接外部行情，执行行情扩展计算后
 * 将计算结果反馈到框架。
 *
 * 行情接收器不需要由MarketPlugin启动，由框架启动。
 */
class MarketPlugin {
public:
    MarketPlugin(FilterContextPtr context) : context_(context){};

    virtual ~MarketPlugin(){};

    virtual MarketPluginId globalUniqueName() PURE;

    virtual int load(const std::string& jsonContent = "") PURE;

    virtual MarketPluginInstId instanceId() const { return context_ == nullptr ? "" : context_->uuid(); };

    FilterContextPtr context() const { return context_; }

    template <typename... Args> void log(int level, const char* fmt, const Args&... args)
    {
        if (1 != is_running_) return;
        if (nullptr == context_) {
            return;
        }
        context_->logger()->log(level, fmt, args...);
    }

    virtual void subscribe(int dataType, const std::string& exId, const std::string& insId) PURE;

    virtual void unsubscribe(int dataType, const std::string& exId, const std::string& insId) PURE;

    virtual void onData(int32_t dataType, const char* data, size_t datasiz) PURE;

    int unload(std::string& reason)
    {
        is_running_ = 0;
        onUnload(reason);
        log(info, "market plugin {} unloaded", instanceId());
        if (nullptr != context_) {
            context_->stop();
            context_ = nullptr;
        }
        return F_NOERR;
    }

    virtual void onLoaded(){ is_running_ = 1; };

    /// 默认不执行任何操作，以支持已有策略。
    virtual void onUnload(std::string& reason){};

protected:
    /// 统一用于访问Context对象。
    FilterContextPtr context_;
    /// 通过is_running_控制，避免某些情况（例如使用了implugin加载hdf5文件时，框架快速推出但插件尚未完成初始化，导致插件log()调用失败的问题。
    volatile std::atomic<int> is_running_ = { 1 };
};
using MarketPluginPtr = std::shared_ptr<MarketPlugin>;
}} // namespace framework::market
