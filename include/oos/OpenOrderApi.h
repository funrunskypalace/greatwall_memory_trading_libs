#pragma once

#ifdef USE_OPENORDERAPI

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ORDataStruct.h"
#include "ORDataType.h"

using namespace cycnoches::ort;

const int LIBOR_API_VER = 18;

namespace cycnoches
{
namespace ort
{
/****************************************************************
 * OpenOrderApi global functions
 ****************************************************************/

/****************************************************************
 * Libor API & SPI
 ****************************************************************/
class OpenOrderSpi;
class ORAPI OpenOrderApi
{
public:
    ///构造函数，创建UserApi类对象
    static OpenOrderApi* createTradeApi(const char* pszFlowPath);

    //********************************************
    //****************************************/
    // API基本接口
    //************************************************************************************/

    ///删除接口对象本身
    ///@remark 不再使用本接口对象时,调用该函数删除接口对象
    virtual void release() = 0;

    ///初始化函数
    // ret -1: 初始化失败
    // ret -2: 配置文件解析失败
    // ret -3: 内部数据初始化异常
    /**
     * \brief
     * \param rawFlowFilePathName
     * \param outFlowFilePathName
     * \param memPersistFilePathName 异常恢复时存储流位置、last ORRequestID。
     * \ return
     */
    virtual int init(const OR_RESUME_TYPE resumeType = OR_TERT_RESUME) = 0;

    virtual int stop() = 0;

    ///等待线程结束
    virtual int join() = 0;

    ///注册SPI对象，映射资金帐号
    virtual void registerSpi(OpenOrderSpi* pSpi) = 0;

    //设置Api必须的Config，在Init前调用
    virtual void subscribePrivateTopic(OR_RESUME_TYPE nResumeType) = 0;

    ///注册前置机网络地址
    virtual void registerFront(const char* pszFrontAddress) = 0;

    virtual int login(OROperatorAccountField* pOperatorAccount) = 0;

    //************************************************************************************/
    // 交易接口
    //************************************************************************************/

    ///报单录入请求
    ///[in, out]
    ///若pOrder->OrderLocalID输入为空，则OR会将ORRequestID填入作为输出。
    ///必须填入：InvestorID、ExID、InsID、LimitPrice、VolumeTotalOriginal、ProductClass、Direction字段。
    virtual int sendOrder(OROrderReqField* pOrder) = 0;

    ///报单操作请求
    /// [in]
    /// 必须填入：InvestorID、RefORRequestID、ORRequestID字段。InsID、ExID、ProductClass会自动填入。
    /// 其余字段OR不会修改，原样保留。
    virtual int cancelOrder(OROrderCancelReqField* pOrderCancel) = 0;

    //************************************************************************************/
    // 查询接口
    //************************************************************************************/

    ///查询交易日
    virtual int queryTradeDate(ORQryTradeDateField* pQuery) = 0;

    //获取所有合约的证券代码信息
    virtual void queryStockCode(ORQryStockCodeField* pQuery) = 0;

    /**
     * \brief 查询股东代码信息
     * \param pQuery 查询基础信息。
     * 对于UFT柜台，无需输入交易市场编码。
     * 对于O32柜台，需要输入交易市场编码。
     * \ return 发送到OR，返回0，否则返回错误值。
     */
    virtual int queryTradeCode(ORQryTradeCodeField* pQuery) = 0;

    /**
     * \brief 查询账户交易编码类型（投机、套利、套保等）
     * \param pQuery 查询基础信息。
     * 对于UFT柜台，无需输入交易市场编码。
     * 对于O32柜台，需要输入交易市场编码。
     * \ return 发送到OR，返回0，否则返回错误值。
     */
    virtual int queryTradingCodeType(ORQryTradingCodeTypeField* pQuery) = 0;

    ///投资者信息查询
    virtual int queryInvestor(ORQryInvestorField* pQuery) = 0;

    ///资金查询
    virtual int queryAccountAsset(ORQryAccountAssetField* pQuery) = 0;

    ///
    virtual int
    queryFuturesAccountMargin(ORQryFuturesAccountMarginField* pQuery) = 0;

    ///持仓查询
    virtual int queryPosition(ORQryPositionField* pQuery) = 0;

    /**
     * \brief 持仓明细查询。
     * 对于UFT和O32股票，不需要该功能。
     * 对于O32期货，可以使用该功能。
     * \param pQuery
     * \ return
     */
    virtual int queryPositionDtl(ORQryPositionDtlField* pQuery) = 0;

    ///保证金率查询
    virtual int queryMarginRate(ORQryMarginRateField* pQuery) = 0;

    /////证券委托查询
    // virtual int queryOrder (ORQryOrderField *pQuery) = 0;
    /////成交查询
    // virtual int queryTrade (ORQryTradeField *pQuery) = 0;

    ///查询新股申购额度
    virtual int queryStockPurQuotation(ORQryStockPurQuotationField* pQuery) = 0;
    ///查询新股申购信息
    virtual int queryStockPurInfo(ORQryStockPurInfoField* pQuery) = 0;
    ///查询新股申购汇总信息
    // virtual int queryStockPurStatistics (ORQryStockPurStatisticsField*
    // pQuery) = 0;

    //********************************************************************/
    // 其他接口
    //********************************************************************/
    virtual int
    subscribeMarket(const ORReqSubscribeMarketDataField* marketData) = 0;

    virtual ~OpenOrderApi() {}
};

class OpenOrderSpi
{
public:
    virtual ~OpenOrderSpi() = default;
    ///当API与OpenOrder连接时调用
    virtual void onConnected(){};

    ///当API与OpenOrder连接断开时调用
    virtual void onDisconnected(int nReason){};

    ///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
    virtual void onCounterConnected(ORCounterConfigField* counterConfig){};

    ///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
    virtual void onCounterDisconnected(ORCounterConfigField* counterConfig,
                                       int nReason){};

    virtual void onHeartBeatMessage(){};

    virtual void onLogin(or_channelid_i channelId, ORRspLoginField* pAccount,
                         ORRspInfoField* rspInfo){};

    virtual void onRuntimeStatus(or_channelid_i channelId,
                                 ORRuntimeStatusField* pStatus,
                                 ORRspInfoField* rspInfo){};

    virtual void onCheckAccount(or_channelid_i channelId,
                                ORCheckAccountField* pInvestor,
                                ORRspInfoField* rspInfo){};

    virtual void onAssetTransfer(or_channelid_i channelId,
                                 ORAssetTransferField* pTransfer,
                                 ORRspInfoField* rspInfo)
    {
    }

    ///错误应答
    virtual void onError(or_channelid_i channelId, ORRspInfoField* rspInfo){};

    ///报单通知
    virtual void onRtnOrder(or_channelid_i channelId, OROrderField* pOrder){};

    ///成交通知
    virtual void onRtnTrade(or_channelid_i channelId, ORTradeField* pTrade){};

    ///报单录入错误回报
    virtual void onErrRtnOrderSend(or_channelid_i channelId,
                                   OROrderReqField* pInputOrder,
                                   ORRspInfoField* rspInfo){};

    ///报单操作错误回报
    virtual void onErrRtnOrderCancel(or_channelid_i channelId,
                                     OROrderCancelReqField* pOrderAction,
                                     ORRspInfoField* rspInfo){};

    virtual void onRspQryInstrument(or_channelid_i channelId,
                                    ORInstrumentField* pInstrument,
                                    ORRspInfoField* rspInfo){};

    virtual void onRspTradeDate(or_channelid_i channelId,
                                ORRspTradeDateField* pRspTradeDate,
                                ORRspInfoField* rspInfo){};

    virtual void onRspStockCode(or_channelid_i channelId,
                                ORRspStockCodeField* pRspStockCode,
                                ORRspInfoField* rspInfo){};

    virtual void onRspMarginRate(or_channelid_i channelId,
                                 ORMarginRateField* pRspStockCode,
                                 ORRspInfoField* rspInfo){};

    virtual void onRspQryTradeCode(or_channelid_i channelId,
                                   ORTradingCodeField* pRspTradingCode,
                                   ORRspInfoField* rspInfo){};

    virtual void onRspQryTradingCodeType(or_channelid_i channelId,
                                         ORTradingCodeField* pRspTradingCode,
                                         ORRspInfoField* rspInfo){};

    virtual void onRspQryAccountAsset(or_channelid_i channelId,
                                      ORAccountAssetField* pRspAccountAsset,
                                      ORRspInfoField* rspInfo){};

    virtual void
    onRspQryFuturesAccountMargin(or_channelid_i channelId,
                                 ORAccountAssetField* pRspFuturesAccountMargin,
                                 ORRspInfoField* rspInfo){};

    virtual void onRspQryStockPurQuotation(or_channelid_i channelId,
                                           ORStockPurQuotationField* field,
                                           ORRspInfoField* rspInfo){};

    virtual void onRspQryStockPurInfo(or_channelid_i channelId,
                                      ORStockPurInfoField* field,
                                      ORRspInfoField* rspInfo){};

    virtual void onRspQryStockPurStatistics(or_channelid_i channelId,
                                            ORStockPurStatisticsField* field,
                                            ORRspInfoField* rspInfo){};

    virtual void onRspQryInvestor(or_channelid_i channelId,
                                  ORInvestorField* field,
                                  ORRspInfoField* rspInfo){};

    virtual void onRspQryPosition(or_channelid_i channelId,
                                  ORAccountPositionField* pRspPosition,
                                  ORRspInfoField* rspInfo){};

    virtual void onRspQryPositionDtl(or_channelid_i channelId,
                                     ORAccountPositionDtlField* pRspPositionDtl,
                                     ORRspInfoField* rspInfo){};

    virtual void onRspQryMarginRate(or_channelid_i channelId,
                                    ORMarginRateField* pRspMarginRate,
                                    ORRspInfoField* rspInfo){};

    virtual void onDepthMarketData(or_channelid_i channelId,
                                   ORDepthMarketDataField* pDepthMarketData){};

    virtual void onTransactionData(or_channelid_i channelId,
                                   ORTransactionDataField* pTransactionData){};
};

#ifdef __cplusplus
extern "C"
{
#endif
    /// 是否处于完结状态（成交、部成部撤、已撤单、废单）
    ORAPI bool is_ost_finished(or_orderstatus_e status);
    /// 是否撤单或部成部撤。
    ORAPI bool is_ost_canceled(or_orderstatus_e status);
#ifdef __cplusplus
}
#endif

} // namespace ort
} // namespace cycnoches

#else

#include "ort/libor.h"

#endif