
#pragma once

#include "ort/pre.h"
#include "ort/ORDataType.h"
#include "ort_ext/core/AdapterCache.h"
#include "ort_ext/message/OrtPackage.h"

namespace cycnoches { namespace ort {
ORAPI ORMockMarketConfigField g_makeMockConfig(ORCounterConfigField* counterConfig);

ORAPI OrtPackagePtr g_makeInitializedPackage(AdapterCache& adapterCache, or_orrequestid_i orRequestId, or_channelid_i channelId,
                                             or_investorid_i investorId, const char* accountCode, const char* moduleName,
                                             const char* statusCode, or_errorid_ei errNo, const char* errMsg, bool isLast);
ORAPI OrtPackagePtr g_makeLoginReqPackage(AdapterCache& adapterCache, const ORCounterConfigField* counterConfig,
                                          const char* accountCode, const char* password, or_investorid_i investorId,
                                          or_orrequestid_i orRequestId, or_enbflag_e enbFlag);
ORAPI OrtPackagePtr g_makeAssetTransferPackage(AdapterCache& adapterCache, or_channelid_i channelId, or_accountcode_s accountCode,
                                               or_password_s password, ORAssetTransferField* pTransfer,
                                               or_orrequestid_i orRequestId);
ORAPI OrtPackagePtr g_makeOrderReqPackage(AdapterCache& adapterCache, const ORCounterConfigField* counterConfig,
                                          or_investorid_i investorId, const or_accountcode_s accountCode,
                                          const or_password_s password, OROrderReqField* pOrder, or_orrequestid_i orRequestId);
ORAPI OrtPackagePtr g_makeCancelOrderReqPackage(AdapterCache& adapterCache, const ORCounterConfigField* counterConfig,
                                                OROrderCancelReqField* cancelReq, const char* accountCode, const char* password,
                                                or_orrequestid_i orRequestId);
ORAPI OrtPackagePtr g_makeUf20SubPackage(AdapterCache& adapterCache, const ORCounterConfigField* counterConfig,
                                         or_investorid_i investorId, int issueType, const char* accountCode,
                                         const char* password);
ORAPI OrtPackagePtr g_makeUftSubPackage(AdapterCache& adapterCache, const ORCounterConfigField* counterConfig,
                                        or_investorid_i investorId, int issueType, const char* accountCode, const char* password);
// OrtPackagePtr g_makeSubOrderPackage(const ORCounterConfigField*
// counterConfig, int orRequestId);
ORAPI OrtPackagePtr g_makeQryOrderReqPackage(AdapterCache& adapterCache, const ORCounterConfigField* counterConfig,
                                             or_investorid_i investorId, or_orrequestid_i requestId, const char* accountCode,
                                             const char* password, const char* exchangeId, const char* insId,
                                             const char* orderSysId, const char* positionStr, int packageType);
ORAPI OrtPackagePtr g_makeQryTradeReqPackage(AdapterCache& adapterCache, const ORCounterConfigField* counterConfig,
                                             or_investorid_i investorId, or_orrequestid_i requestId, const char* accountCode,
                                             const char* password, const char* exchangeId, const char* insId, const char* tradeId,
                                             const char* positionStr, int packageType);
ORAPI OrtPackagePtr g_makeQryAccountPackage(AdapterCache& adapterCache, const ORCounterConfigField* counterConfig,
                                            or_investorid_i investorId, const char* accountCode, const char* password);
ORAPI OrtPackagePtr g_makeQryFuturesAccountMarginPackage(AdapterCache& adapterCache, const ORCounterConfigField* counterConfig,
                                                         or_investorid_i investorId, const char* accountCode,
                                                         const char* password);
ORAPI OrtPackagePtr g_makeRspLoginPackage(AdapterCache& adapterCache, or_channelid_i channelId, or_date_i tradingDay,
                                          or_investorid_i investorId, or_orrequestid_i requestId, or_errorid_ei errorId,
                                          const char* errorMsg, or_branchid_s branchId = nullptr);
/**
 * 每一笔委托只能伪造一次、一笔成交回报，所以成交回报编号使用ORRequestID加特殊信息。
 */
ORAPI OrtPackagePtr g_fakeRtnTradePackage(AdapterCache& adapterCache, const or_channelid_i channelId,
                                          const or_accountcode_s accountCode, const or_investorid_i investorId,
                                          const or_orrequestid_i requestId, const or_thirdreff1_s thirdReff1,
                                          const or_thirdreff2_s thirdReff2, const or_counterorderid_s counterOrderId,
                                          const or_ordersysid_s orderSysId, const or_date_i tradingDay,
                                          const or_exchangeid_s exId, const or_instrumentid_s insId, const or_volume_i volume,
                                          const or_price_f price, const or_money_f amount);

/***********************************************************************************************/
ORAPI OROrderField g_createOrder(AdapterCache& adapterCache, OROrderReqField* orderReq, or_orrequestid_i orRequestId,
                                 or_orderstatus_e orderStatus);
ORAPI std::string g_packageToStr(OrtPackage* package, const char* delim =
#ifdef DEBUG
                                                          " | "
#else
                                                          " | "
#endif
);
ORAPI std::string g_packageBodyToStr(OrtPackage* package, const char* delim);
}} // namespace cycnoches::ort