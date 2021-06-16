#pragma once
#include <mutex>
#include <unordered_map>

#include "ort/pre.h"
#include "ort/ORDataStruct.h"
#include "ort_ext/core/AdapterBase.h"

namespace cycnoches
{

namespace ort
{

class AdapterCache
{
public:
    AdapterCache() = default;
    virtual ~AdapterCache() = default;

    virtual void addORRequestID(or_orrequestid_i orRequestId, const std::string& adapterKeyData) = 0;
    virtual or_orrequestid_i getOrRequestId(const std::string& adapterKeyData) = 0;
    virtual void setAccountCode(or_orrequestid_i orRequestId, const char* accountCode) = 0;
    virtual std::string getAccountCode(or_orrequestid_i orRequestId) = 0;
    virtual void cacheOrderLocalID(or_orrequestid_i orRequestId, const or_orderlocalid_s orderLocalId,
                                   or_frontid_i frontId, or_sessionid_i sessionId) = 0;
    virtual void mapQmtTaskId(const int64_t taskId, const int64_t groupId, or_orrequestid_i request_id) = 0;
    virtual or_orrequestid_i getByQmtTaskId(int64_t taskId) const = 0;
    virtual bool checkAndDoneQmtRspOrderInsert(int64_t taskId, int64_t& groupId) = 0;
    virtual void mapCounterOrderId(const or_counterorderid_s counterOrderId, or_orrequestid_i orRequestId) = 0;
    virtual void mapCounterOrderId(const std::string& counterOrderId, or_orrequestid_i orRequestId) = 0;
    virtual or_orrequestid_i findRequestID(const or_counterorderid_s counterOrderId) const = 0;
    virtual or_orrequestid_i findRequestID(const std::string& counterOrderId) const = 0;
    virtual void removeRequestID(const or_counterorderid_s counterOrderId) = 0;
    virtual void removeRequestID(const std::string& counterOrderId) = 0;
    virtual std::string findCounterOrderId(or_orrequestid_i orRequestId) const = 0;

    /// 添加通道。每个通道都有一个柜台配置信息。
    virtual void insertCounter(or_channelid_i channelId, const ORCounterConfigFieldPtr& counterConfig) = 0;
    virtual ORCounterConfigFieldPtr getCounterConfigByInvestorID(or_investorid_i investorId) = 0;
    virtual ORCounterConfigFieldPtr getCounterConfigByChannelID(or_channelid_i channelId) = 0;
    virtual void updateInsertAdapter(const ORCounterConfigFieldPtr& counterConfig, const AdapterBasePtr& adapter) = 0;
    virtual AdapterBasePtr getAdapter(or_channelid_i channelId) = 0;
    virtual void clearAdapters() = 0;

    virtual void addInvestor(const ORCounterConfigFieldPtr& counterConfig, const ORInvestorFieldPtr& investor,
                             const InvestorTradingCodesPtr& tradingCodes) = 0;
    virtual ORInvestorFieldPtr getInvestorByCode(or_channelid_i channelId, const char* accountCode) = 0;
    virtual ORInvestorFieldPtr getInvestor(int investorId) = 0;
    virtual void updateInvestorPassword(const ORInvestorFieldPtr& old, or_password_s newPassword) = 0;
    virtual or_channelid_i getChannelID(or_investorid_i investorId) const = 0;
    virtual void updateInvestorWithConfig(const ORInvestorFieldPtr& investor,
                                          const ORCounterConfigFieldPtr& counterConfig,
                                          const std::list<ORTradingCodeFieldPtr>& tradingCodes) = 0;

    virtual void cacheReqPackage(const OrtPackagePtr& package) = 0;
    virtual void makeUpInvestorID(or_orrequestid_i orRequestId, or_investorid_i& investorId) = 0;
    virtual void makeUpAccountID(or_orrequestid_i orRequestId, or_accountid_i& accountId, char* accountCode,
                                 bool erase) = 0;

    virtual void cacheUniqueString(const std::string& strval) = 0;
    virtual bool findUniqueString(const std::string& strval) = 0;

    virtual void cacheUniqueInt64(int64_t int64val) = 0;
    virtual bool findUniqueInt64(int64_t int64val) = 0;

    virtual OrtPackagePtr acquirePooledPackage() = 0;
    virtual OROrderFieldPtr acquirePooledOrder() = 0;
    virtual ORTradeFieldPtr acquirePooledTrade() = 0;
};
} // namespace ort

} // namespace cycnoches