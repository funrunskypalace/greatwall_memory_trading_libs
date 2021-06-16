#pragma once

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ort/ORDataStruct.h"
#include "ort/ORDataType.h"
#include "ort/OrderCache.h"

const int LIBOR_API_VER = 18;

namespace cycnoches {
namespace ort {
class AdapterBase;
/****************************************************************
 * OrderRouterApi global functions
 ****************************************************************/
#ifdef __cplusplus
extern "C" { // only need to export C interface if used by C++ source code
#endif
/**
 * @param consoleLevel: enable console log info if consoleLevel >= debug,
 * then use g_setConsoleLevel () to change console log level.
 * @ return:
 * 0: success.
 * -1: init failed. see log erorr.
 */
ORAPI int g_initLibOrderRouter(const char* logPathName, int level, int consoleLevel,
                                   const std::string& logFormatter = "[%Y-%m-%d %T.%e][%t][%l][%n] %v");
ORAPI void g_uninitLibOrderRouter();
ORAPI void g_setConsoleLevel(int level);

#ifdef __cplusplus
}
#endif

/****************************************************************
 * Libor API & SPI
 ****************************************************************/
class OrderRouterSpi;
/**
 *   `Counter` is interchangeable with `Channel`. Investor A1 / ...... Counter
 * C1 (channelid=1) ~1---1~ Adapter A1 - Investor An / ....
 *    OrderRouterApi-Instance01  - ....  (all counters with same channel type
 * shares one instance) \ .... Counter CN (channelid=2) ~1---1~ Adapater AN -
 * Investor N1 \ ...... Investor Nn
 */
class ORAPI OrderRouterApi {
public:
    ///构造函数，创建UserApi类对象
    static OrderRouterApi* createTradeApi(or_channeltype_e channelType, const char* authCode,
                                          const char* licenseFilePath);

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
    virtual int init(bool flatInflow, const char* userCode, const char* rawFlowFilePathName,
                     const char* outFlowFilePathName, const char* memPersistFilePathName,
                     const OR_RESUME_TYPE resumeType = OR_TERT_RESUME) = 0;

    virtual int stop() = 0;

    ///等待线程结束
    virtual int join() = 0;

    /**
     * \brief 连接柜台，映射资金帐号
     * \param counterConfig
     * \param investors
     * 对于飞马、CTP，仅使用第一个Investor。对于UFT，可以传入多个资金帐号。
     * \param numInvestor 传入的资金帐号数量。
     * \param tradingCodes 交易编码对应表 下一版本支持。
     * \param numTradingCode 交易编码表行数。
     * \ return
     */
    virtual int connect(ORCounterConfigField* counterConfig, const std::list<ORInvestorFieldPtr>& investors,
                        const std::list<ORTradingCodeFieldPtr>& tradingCodes) = 0;

    ///注册SPI对象，映射资金帐号
    virtual void registerSpi(OrderRouterSpi* pSpi) = 0;

    virtual void login(ORReqLoginField* pLogin) = 0;

    virtual ORCounterConfigFieldPtr getCounterConfigByChannelID(or_channelid_i channelId) = 0;

    virtual int checkAccount(ORCheckAccountField* pInvestor) = 0;

    virtual int assetTransfer(ORAssetTransferField* pTransfer) = 0;

    /////更新柜台配置信息
    /////盘中更改配置需要调用该函数。
    // virtual void insertCounterConfig (ORCounterConfigField *counterConfig) =
    // 0;

    //************************************************************************************/
    // 交易接口
    //************************************************************************************/

    /// JSON 格式请求录入
    virtual int reqJsonTrading(ORJsonTradingReqField* reqJson) = 0;

    ///报单录入请求
    ///[in, out]
    ///若pOrder->OrderLocalID输入为空，则OR会将ORRequestID填入作为输出。 [in]
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
    virtual int queryFuturesAccountMargin(ORQryFuturesAccountMarginField* pQuery) = 0;

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

    //************************************************************************************/
    // 其他接口
    //************************************************************************************/

    /**
     * 通过marketData.SubscribeSwitch进行订阅/取消订阅。
     */
    virtual int subscribeMarket(const ORReqSubscribeMarketDataField* marketData) = 0;

    /// 使用API的应用程序可以注册委托缓存，OR在内部维护该缓存。
    virtual void registerOrderCache(OrderCachePtr& orderCache) = 0;

    virtual ~OrderRouterApi() {}
};
using OrderRouterPtr = std::shared_ptr<OrderRouterApi>;

class OrderRouterSpi {
public:
    virtual ~OrderRouterSpi() = default;
    ///当API与OrderRouter连接时调用
    virtual void onConnected(){};

    ///当API与OrderRouter连接断开时调用
    virtual void onDisconnected(int nReason){};

    ///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
    virtual void onCounterConnected(ORCounterConfigField* counterConfig){};

    ///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
    virtual void onCounterDisconnected(ORCounterConfigField* counterConfig, int nReason){};

    ///登录
    virtual void onLogin(ORRspLoginField* pAccount, ORRspInfoField* rspInfo){};

    ///登录
    virtual void onRuntimeStatus(ORRuntimeStatusField* pStatus, ORRspInfoField* rspInfo){};

    ///校验资金帐户（密码）
    virtual void onCheckAccount(ORCheckAccountField* pInvestor, ORRspInfoField* rspInfo){};

    ///资金划拨
    virtual void onAssetTransfer(ORAssetTransferField* pTransfer, ORRspInfoField* rspInfo){};

    ///错误应答
    virtual void onError(ORRspInfoField* rspInfo){};

    ///JSON请求通知
    virtual void onJsonTrading(ORJsonTradingRspField* rspJsonTrading){};

    ///报单通知
    virtual void onRtnOrder(OROrderField* pOrder) {};

    ///成交通知
    virtual void onRtnTrade(ORTradeField* pTrade){};

    ///报单录入错误回报
    virtual void onErrRtnOrderSend(OROrderReqField* pInputOrder, ORRspInfoField* rspInfo){};

    ///报单操作错误回报
    virtual void onErrRtnOrderCancel(OROrderCancelReqField* pOrderAction, ORRspInfoField* rspInfo){};

    /// 查询回复
    virtual void onRspQryInstrument(ORInstrumentField* pInstrument, ORRspInfoField* rspInfo){};
    virtual void onRspTradeDate(ORRspTradeDateField* pRspTradeDate, ORRspInfoField* rspInfo){};
    virtual void onRspStockCode(ORRspStockCodeField* pRspStockCode, ORRspInfoField* rspInfo){};
    virtual void onRspMarginRate(ORMarginRateField* pRspStockCode, ORRspInfoField* rspInfo){};
    virtual void onRspQryTradeCode(ORTradingCodeField* pRspTradingCode, ORRspInfoField* rspInfo){};
    virtual void onRspQryTradingCodeType(ORTradingCodeField* pRspTradingCode, ORRspInfoField* rspInfo){};
    virtual void onRspQryAccountAsset(ORAccountAssetField* pRspAccountAsset, ORRspInfoField* rspInfo){};
    virtual void onRspQryFuturesAccountMargin(ORAccountAssetField* pRspFuturesAccountMargin, ORRspInfoField* rspInfo){};
    virtual void onRspQryStockPurQuotation(ORStockPurQuotationField* field, ORRspInfoField* rspInfo){};
    virtual void onRspQryStockPurInfo(ORStockPurInfoField* field, ORRspInfoField* rspInfo){};
    virtual void onRspQryStockPurStatistics(ORStockPurStatisticsField* field, ORRspInfoField* rspInfo){};
    virtual void onRspQryInvestor(ORInvestorField* field, ORRspInfoField* rspInfo){};
    virtual void onRspSubscribeMarketData(ORReqSubscribeMarketDataField* field, ORRspInfoField* rspInfo){};

    /**
     * \brief 查询持仓回复。
     * 对于UFT，TradingCodeType值始终='\0'；TradeCode为股东代码。
     * 对于O32股票，TradingCodetype值='\0'。
     * 对于O32期货，TradingCodeType为投机、套利、套保等值其中之一。
     * YdPosition/YdEnableVolume这两个字段对于非SHFE和INE的其他交易所都是0，TotalPosition和EnableVolume包含全部持仓。
     * \param pRspPosition
     * \param rspInfo
     */
    virtual void onRspQryPosition(ORAccountPositionField* pRspPosition, ORRspInfoField* rspInfo){};
    /**
     * \brief
     * 查询持仓详细信息，包括占用保证金、成交编号、开仓数量、平仓数量、前结算价、开仓价等。
     * 对于UFT和O32股票，不需要该功能。
     * 对于O32期货，可以使用该功能。
     * \param pRspPositionDtl
     * \param rspInfo
     */
    virtual void onRspQryPositionDtl(ORAccountPositionDtlField* pRspPositionDtl, ORRspInfoField* rspInfo){};
    virtual void onRspQryMarginRate(ORMarginRateField* pRspMarginRate, ORRspInfoField* rspInfo){};
    virtual void onRspQryOptionsCombine(const OROptionsCombineField* pOptionsCombine, ORRspInfoField* rspInfo){};

    virtual void onDepthMarketData(or_channelid_i channelId, ORDepthMarketDataField* pDepthMarketData){};
    virtual void onTransactionData(or_channelid_i channelId, ORTransactionDataField* pTransactionData){};
};

#ifdef __cplusplus
extern "C" { // only need to export C interface if used by C++ source code
#endif
/// 是否处于完结状态（成交、部成部撤、已撤单、废单）
    ORAPI bool is_ost_finished(or_orderstatus_e status);
    /// 是否撤单或部成部撤。
    ORAPI bool is_ost_canceled(or_orderstatus_e status);
    ORAPI bool is_buy_direction(or_direction_e direction);
    ORAPI bool is_sell_direction(or_direction_e direction);
    ORAPI int product_class_to_market_data_type(or_productclass_e product_class);
    ORAPI or_productclass_e market_data_type_to_product_class(int market_data_type);
    ORAPI int parse_json_trading_req(const std::string& json_obj, ORJsonTradingReqField& field);
#ifdef __cplusplus
}
#endif

} // namespace ort
} // namespace cycnoches
