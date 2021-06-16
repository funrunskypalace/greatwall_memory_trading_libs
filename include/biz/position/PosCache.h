#pragma once

#include "ort/ORDataStruct.h"

using namespace cycnoches::ort;

namespace cycnoches { namespace biz {
class PositionCache;
using PositionCachePtr = std::shared_ptr<PositionCache>;

class ORAPI PositionCache {
public:
    static PositionCachePtr createInstance();
    virtual void initialize(or_volume_i minimalPosRemain, or_volume_i maximumPosRemain) = 0;
    virtual ORAccountAssetFieldPtr getAccountAsset(or_investorid_i investorId) const = 0;
    virtual void mergeAccountAsset(const ORAccountAssetFieldPtr& asset) = 0;
    virtual void mergeAccountAsset(const ORAccountAssetField* asset) = 0;
    virtual or_offsetflag_e getAutoOffsetFlag(const OROrderReqFieldPtr& order) = 0;
    virtual or_offsetflag_e getAutoOffsetFlag(const OROrderReqField* order) = 0;
    /// <summary>
    /// merge today and yd positions into single position.
    /// </summary>
    /// <param name="position"></param>
    virtual void mergePosition(const ORAccountPositionFieldPtr& position) = 0;
    virtual void mergePosition(const ORAccountPositionField* position) = 0;
    virtual void preHandleRtnOrder(const OROrderField* order) = 0;
    virtual void updatePosition(const ORTradeField* trade) = 0;
    virtual void preHandleRtnOrder(const OROrderFieldPtr& order) = 0;
    virtual void updatePosition(const ORTradeFieldPtr& trade) = 0;
    virtual void getPosition(const OROrderReqFieldPtr& order, or_volume_i& today_bull_position, or_volume_i& yd_bull_position,
                             or_volume_i& bull_frozen_position, or_volume_i& today_bear_position, or_volume_i& yd_bear_position,
                             or_volume_i& bear_frozen_position) const = 0;
    virtual ORAccountPositionFieldPtr getPosition(or_investorid_i investorId, const std::string& exId, const std::string& insId,
                                                  or_positiondate_e posDate) const = 0;
    virtual std::shared_ptr<std::list<ORAccountPositionFieldPtr>> getAllPositions() const = 0;
};

}} // namespace cycnoches::biz