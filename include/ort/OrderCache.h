#pragma once

#include "ort/ORDataStruct.h"

namespace cycnoches {
namespace ort {
class OrderCache;
using OrderCachePtr = std::shared_ptr<OrderCache>;

class ORAPI OrderCache {
public:
    static OrderCachePtr createInstance();
    virtual OROrderFieldPtr getOrder(or_orrequestid_i orRequestId) const = 0;
    virtual std::shared_ptr<std::list<OROrderFieldPtr>>
    getAllOrders(const std::string& exId = "", const std::string& insId = "",
                 or_investorid_i investorId = INVALID_INVESTORID) const = 0;
    virtual void updateOrder(or_orrequestid_i orRequestId, OROrderField* order) = 0;
    virtual void updateTrade(ORTradeField* trade) = 0;
};

} // namespace ort
} // namespace cycnoches