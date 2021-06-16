#pragma once

#include "ort/libor.h"
#include "ort_ext/message/OrtPackage.h"

namespace cycnoches { namespace ort {

/**
 * API for extending OrderRouter (OrderRouter Extension API)
 */
class ORAPI OrderRouterExtApi : public OrderRouterApi {
public:
    virtual void onCounterConnected(ORCounterConfigField* counterConfig) = 0;

    virtual void onCounterDisconnected(ORCounterConfigField* counterConfig, int nReason) = 0;

    virtual or_orrequestid_i getNextRequestID() = 0;

    virtual void postTradePackage(const OrtPackagePtr& package) const = 0;

    virtual void postQueryPackage(const OrtPackagePtr& package, int delayMs = 0) const = 0;

    /**
     * \brief 暂不开放给API，所以内部实现为补全查询。
     * \param pQuery
     * \return
     */
    virtual int queryOrderInternal(ORQryOrderField* pQuery) = 0;
    /**
     * \brief 暂不开放给API，所以内部实现为补全查询。
     * \param pQuery
     * \return
     */
    virtual int queryTradeInternal(ORQryTradeField* pQuery) = 0;
};

}} // namespace cycnoches::ort