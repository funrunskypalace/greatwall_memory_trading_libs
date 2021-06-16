#pragma once
#include "pch/compat.h"

#include "framework/common/common.h"
#include "oos/OpenOrderApi.h"

#include <memory>
#include <mutex>

using namespace cycnoches::ort;

namespace framework { namespace trade {

typedef int32_t or_execstatus_i;
///未知
const int OR_EST_Unkfalsewn = 0x01;
///已提交
const int OR_EST_PendingNew = 0x04;
///已接收
const int OR_EST_New = 0x08;
///部分成交
const int OR_EST_PartilyFilled = 0x10;
///全部成交
const int OR_EST_Filled = 0x20;
///部分成交部分撤单
const int OR_EST_PartilyCanceled = 0x40;
///已撤单
const int OR_EST_Canceled = 0x80;
///已拒绝
const int OR_EST_Rejected = 0x100;
///已发送撤单
const int OR_EST_Cancelling = 0x200;
///已发送委托
const int OR_EST_Sending = 0x400;
const int OR_EST_ALL = 0xFFFFFFFF;

struct OrderPackInfoField;
using OrderPackInfoFieldPtr = std::shared_ptr<OrderPackInfoField>;

class OrderPackInfo {
public:
    OrderPackInfo(or_channelid_i channelId, OROrderReqField& orderReq, or_execstatus_i targetExecStatus,
                  bool suppressing);

    OrderPackInfo();

    /// @param TargetExecStatus：期望的最终执行状态。
    /// - 注意：交易事务必须最终达到完结状态，整个事务才会结束处理。
    ///   TargetExecStatus仅仅用于判断是否Terminated。
    void initialize(or_channelid_i channelId, or_investorid_i invesotrId, or_productclass_e pc, const std::string& exId,
                    const std::string& insId, or_direction_e dir, or_offsetflag_e offset, or_hedgeflag_e hedge,
                    or_volume_i volume, or_price_f price, or_orderpricetype_e pt, or_timecondition_e tc,
                    or_contingentcondition_e cc, or_volumecondition_e vc, or_execstatus_i targetExecStatus,
                    bool suppressing, const std::string& orderRef = "");
    void protect(or_price_f lower, or_price_f upper, or_price_f bidask_spread, or_volume_i bidask_volume);
    void moreDirection(or_direction_e open, or_direction_e close);
    void moreOffsetFlag(or_offsetflag_e open, or_offsetflag_e close);

    void setRequestID(or_orrequestid_i requestId);
    std::string getOrderRef() const;
    void setOrderRef(const std::string& orderRef);
    std::string getInternalOrderRef() const;
    void setInternalOrderRef(const std::string& orderLocalId);
    or_channelid_i getChannelID() const;
    or_investorid_i getInvestorID() const;
    or_orrequestid_i getRequestID();
    OROrderReqField getOrderReq(bool getOriginal) const;
    bool isSuppressing() const;
    or_execstatus_i targetExecStatus() const;
    void setReSend(bool needReSend /*, int MaxSendTimes*/);
    bool needReSend() const;
    std::string description() const;
    or_volume_i originalVolume() const;
    or_price_f originalPrice() const;
    or_volume_i volumeTradedSum() const;
    or_money_f amountTradedSum() const;
    void addVolumeTraded(or_volume_i volume, or_money_f amount);
    or_price_f limitPrice() const;
    or_price_f lowerPrice() const;
    or_price_f upperPrice() const;
    or_volume_i volume() const;
    bool meetTargetExecStatus(or_execstatus_i execStatus) const;
    or_price_f getPriceShift() const;
    void setPriceShift(or_price_f shift) const;
    or_price_f getBidAskSpread() const;
    or_volume_i getBidAskVolume() const;
    void setBidAskSpread(or_price_f spread);
    void setBidAskVolume(or_volume_i volume);
    void updateDirection(or_direction_e dir);
    void updateOffsetFlag(or_offsetflag_e offset);
    void updateVolume(or_volume_i volume);
    void updatePrice(or_price_f limitPrice);
    or_direction_e directionOpen() const;
    or_direction_e directionClose() const;
    or_offsetflag_e offsetFlagOpen() const;
    or_offsetflag_e offsetFlagClose() const;

private:
    OrderPackInfoFieldPtr field_;
};
using OrderPackInfoPtr = std::shared_ptr<OrderPackInfo>;
using OrderPackList = std::list<OrderPackInfoPtr>;

class OrderExecInfo {
public:
    virtual or_orrequestid_i getORRequestID() const PURE;
    virtual bool isJson() const PURE;
    virtual std::string getOrderRef() const PURE;
    virtual or_execstatus_i orderExecStatus() const PURE;
    virtual void setOrderExecStatus(or_execstatus_i execStatus) PURE;
    virtual std::string description() const PURE;
    virtual bool isSuppressing() const PURE;
    virtual bool needReSend() const PURE;
    virtual bool execFilled() const PURE;
    virtual bool execFinished(bool includeFilled) const PURE;
    virtual bool meetTargetExecStatus() const PURE;
    virtual bool execPending() const PURE;
    virtual bool execCanceled() const PURE;
    virtual bool execRejected() const PURE;
    virtual bool expired(int durationMicro) const PURE;
    virtual void setSendingTime() PURE;
};
using OrderExecInfoPtr = std::shared_ptr<OrderExecInfo>;
using OrderExecInfoList = std::list<OrderExecInfoPtr>;

bool or_execstatus_finished(or_execstatus_i execStatus, bool includeFilled);
bool or_execstatus_pending(or_execstatus_i execStatus);
bool or_execstatus_filled(or_execstatus_i execStatus);
bool or_execstatus_canceled(or_execstatus_i execStatus);
bool or_execstatus_rejected(or_execstatus_i execStatus);
or_execstatus_i or_ost2execstatus(or_orderstatus_e ost);

}} // namespace framework::trade