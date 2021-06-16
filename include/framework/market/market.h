// @author Jiang Sanyi 2019-12-03
#pragma once

#include "framework/common/common.h"
#include "ort/ORDataStruct.h"
#include <regex>

using namespace cycnoches::ort;

namespace framework { namespace market {

/// 要避免在代码中 使用回调对象的引用进行对象内存储。
using MarketPostCb = std::function<void(int32_t dataType, const char* data, size_t datasiz)>;

/// 要避免在代码中 使用回调对象的引用进行对象内存储。
using MarketPluginBackCb = std::function<void(int32_t dataType, const char* data, size_t datasiz)>;

class PredicatorObject {
public:
    PredicatorObject(bool enableRegex, const std::string& exId, const std::string& insId, int tradeDate = 0)
        : exid_(exId), insid_(insId), reginsid_(insid_), enable_regex_(enableRegex), trade_date_(tradeDate)
    {
    }

    // @todo: 这里有了唯一的GreatWall对于Ort的显式依赖。
    inline bool accepted(int32_t dataType, const char* data, size_t datasiz) const
    {
        if (datasiz != sizeof(ORDepthMarketDataField)) return false;
        auto depth = (ORDepthMarketDataField*)data;
        if (0 != trade_date_) {
            if (trade_date_ != depth->TradingDay) {
                return false;
            }
        }
        if (!enable_regex_) return 0 == strcicmp(depth->InstrumentID, insid_.c_str());
        std::string curinsid(depth->InstrumentID);
        auto usefulit = useful_inslist_.find(curinsid);
        if (useful_inslist_.cend() != usefulit) {
            return true;
        }
        auto uselessit = useless_inslist_.find(curinsid);
        if (useless_inslist_.cend() != uselessit) return false;
        // use regex_search instead of regex_match,
        // see https://en.cppreference.com/w/cpp/regex/regex_match
        // also ref:
        // https://stackoverflow.com/questions/14205096/c11-regex-slower-than-python
        if (std::regex_match(curinsid, reginsid_)) {
            // cache for speed up!
            useful_inslist_.insert(curinsid);
            return true;
        }
        useless_inslist_.insert(curinsid);
        return false;
    }

private:
    mutable std::unordered_set<std::string> useless_inslist_;
    mutable std::unordered_set<std::string> useful_inslist_;
    std::string insid_;
    std::string exid_;
    std::regex reginsid_;
    bool enable_regex_;
    int trade_date_;
};
using PredicatorObjectPtr = std::shared_ptr<PredicatorObject>;

}} // namespace framework::market
