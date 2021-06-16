#pragma once

#include <atomic>
#include <functional>
#include <mutex>
#include <unordered_map>

#include "orchid/common/common.h"
#include "orchid/common/logger.h"

namespace orchid
{
namespace container
{

/// ͬһ���͵ı��ģ��ڹ涨���ʱ����ֻ�ܲ���һ�Σ�����ѡ�������»�����Ϊ׼��
template <class T> class DelayQueue
{
public:
    using data_type = std::shared_ptr<T>;
    using DelayCallBack = std::function<void(const data_type&)>;
    DelayQueue(bool useLatest, bool globalType, DelayCallBack callback)
    {
        callback_ = callback;
        global_type_ = globalType;
        global_nano_ = 0;
        is_running_ = true;
        use_latest_ = useLatest;
        worker_ = std::make_shared<std::thread>([&]() -> void {
            std::list<int> types;
            while (is_running_)
            {
                types.clear();
                // do locked
                {
                    std::unique_lock<std::mutex> lock(mux_packages_);
                    for (auto it = packages_.cbegin(); it != packages_.cend();
                         ++it)
                    {
                        types.push_back(it->first);
                    }
                }
                for (auto ty : types)
                {
                    push(ty, nullptr, 0);
                }
                SleepMs(200);
            }
        });
    }
    ~DelayQueue()
    {
        is_running_ = false;
        worker_->join();
    }

    void push(int type, const data_type& package, int64_t delayNano)
    {
        std::unique_lock<std::mutex> lock(mux_packages_);
        auto nanonow = get_nano(false);

        auto it = nano_.find(type);
        if (nano_.cend() == it)
        {
            if (nullptr != package)
            {
                auto nanonext = nanonow + delayNano;
                // �������type��Ҫ˳�򷢰���������±��ĵ�ʱ�����ȫ�ּ�ʱ��Ϊ�ο���
                if (global_type_)
                {
                    nanonext = std::max(nanonow, global_nano_) + delayNano;
                }
                nano_.emplace(std::make_pair(type, nanonext));
                packages_.emplace(std::make_pair(type, package));
                global_nano_ = nanonext;
            }
        }
        else if (
            it->second <
            nanonow) // �Ѿ�������ʱ���ڣ�Ҫ��������ķ��ͳ�ȥ�����Ҵӻ��������
        {
            auto kkt = packages_.find(type);
            if (packages_.cend() != kkt)
            {
                if (nullptr != callback_)
                {
                    callback_(kkt->second);
                    ORCHID_LOG(info, "Send delay package: {}", type);
                }
                packages_.erase(kkt);
            }
            nano_.erase(it);
        }
        else // it->second >= nanonow, Ҳ����˵֮ǰ�ļ�ʱ���ڻ�û�н���
        {
            if (use_latest_ && nullptr != package)
            {
                // replace
                packages_[type] = package;
            }
        }
    }

private:
    std::atomic_bool is_running_;
    std::shared_ptr<std::thread> worker_;
    mutable std::mutex mux_packages_;
    uint64_t global_nano_;
    std::unordered_map<int /*type*/, data_type> packages_;
    std::unordered_map<int /*type*/, uint64_t /*last pop nano*/> nano_;
    std::atomic_bool use_latest_;
    std::atomic_bool global_type_;
    DelayCallBack callback_;
};

} // namespace container
} // namespace orchid