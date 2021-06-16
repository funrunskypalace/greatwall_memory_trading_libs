#pragma once
#include "orchid/common/logger.h"
#include "ort/logger.h"
#include "ort/pre.h"
#include "ort_ext/core/AdapterCache.h"
#include "ort_ext/message/ORTypeDefs.h"
#include "ort_ext/message/OrtPackage.h"

using namespace orchid::net;

namespace cycnoches {
namespace ort {
/**
 * \brief
 * 抽象基础类，封装了一个CFlow，一个线程。线程在flow中读取Package，然后通过Dispatcher
 * 处理报文。
 * \remarks 创建这个类的目的是希望能将O32Adapter和UftAdapter公用的代码
 * \tparam HandlerT
 * 将从FlowT中读取出来的报文转换为发送到ChannelT的报文（具备Forward函数）。
 * 抽象出来。
 */
template <class FlowT, class FlowReaderT, class HandlerT, class PackageT> class FlowWorker {
public:
    typedef FlowT flow_t;
    typedef FlowReaderT flow_reader_t;
    typedef HandlerT handler_t;
    typedef PackageT package_t;

    FlowWorker(AdapterCache& adapter_cache, std::shared_ptr<flow_t>& flow, handler_t* handler,
               const std::string& name)
        : adapter_cache_(adapter_cache), flow_name_(name)
    {
        flow_ = flow;
        handler_ = handler;
    }

    ~FlowWorker() { StopThread(); }

    void StartThread(int initFlowId)
    {
        if (!flow_) {
            OR_LOG(err, "no flow registered to flow handler! wont start thread!");
            return;
        }
        keep_run_ = true;
        worker_ = std::make_shared<std::thread>(&FlowWorker::ReadFlow, this, initFlowId);
        // OR_LOG(debug, "Flow {} handler thread started.",  flow_name_);
    }

    void StopThread()
    {
        if (worker_.get() && worker_->joinable()) {
            auto package = adapter_cache_.acquirePooledPackage();
            package->preparePackage(TID_Finished, 0x01, ORT_TOPIC_REQRESP, -1, -1);
            package->makePackage();
            flow_->append(package);
            worker_->join();
            worker_.reset();
        }
    }

    AdapterCache& adapterCache() const { return adapter_cache_; }

private:
    void HandleMessage(OrtPackagePtr& packageIn, int flowId) { handler_->forward(packageIn, flowId); }

    void ReadFlow(int initFlowId)
    {
        flow_reader_t reader;
        reader.attachFlow(flow_.get(), initFlowId);
        int curid = initFlowId;
        while (keep_run_) {
            if (flow_->getFlowType() == FLAT) {
                curid = reader.getId();
            }

            auto cpkg = reader.getNext(2, true);
            if (nullptr == cpkg) {
                yield_thread();
                continue;
            }

            auto package = std::dynamic_pointer_cast<package_t>(cpkg);
            if (nullptr == package || package->getTID() == TID_Finished) {
                keep_run_ = false;
                continue;
            }
            else {
                HandleMessage(package, curid);
            }
        }
        OR_LOG(info, "Flow handler thread stopped.");
    }

private:
    AdapterCache& adapter_cache_;
    std::shared_ptr<flow_t> flow_;
    std::shared_ptr<std::thread> worker_;
    handler_t* handler_;
    // synchronization
    std::atomic_bool keep_run_;
    // todo: test mutex&cv cost versus getNext blocking
    std::condition_variable cv_;
    std::mutex cv_m_; // used with cv_
    std::string flow_name_;
};
} // namespace ort

} // namespace cycnoches
