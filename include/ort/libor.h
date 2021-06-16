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
    ///���캯��������UserApi�����
    static OrderRouterApi* createTradeApi(or_channeltype_e channelType, const char* authCode,
                                          const char* licenseFilePath);

    //********************************************
    //****************************************/
    // API�����ӿ�
    //************************************************************************************/

    ///ɾ���ӿڶ�����
    ///@remark ����ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
    virtual void release() = 0;

    ///��ʼ������
    // ret -1: ��ʼ��ʧ��
    // ret -2: �����ļ�����ʧ��
    // ret -3: �ڲ����ݳ�ʼ���쳣
    /**
     * \brief
     * \param rawFlowFilePathName
     * \param outFlowFilePathName
     * \param memPersistFilePathName �쳣�ָ�ʱ�洢��λ�á�last ORRequestID��
     * \ return
     */
    virtual int init(bool flatInflow, const char* userCode, const char* rawFlowFilePathName,
                     const char* outFlowFilePathName, const char* memPersistFilePathName,
                     const OR_RESUME_TYPE resumeType = OR_TERT_RESUME) = 0;

    virtual int stop() = 0;

    ///�ȴ��߳̽���
    virtual int join() = 0;

    /**
     * \brief ���ӹ�̨��ӳ���ʽ��ʺ�
     * \param counterConfig
     * \param investors
     * ���ڷ���CTP����ʹ�õ�һ��Investor������UFT�����Դ������ʽ��ʺš�
     * \param numInvestor ������ʽ��ʺ�������
     * \param tradingCodes ���ױ����Ӧ�� ��һ�汾֧�֡�
     * \param numTradingCode ���ױ����������
     * \ return
     */
    virtual int connect(ORCounterConfigField* counterConfig, const std::list<ORInvestorFieldPtr>& investors,
                        const std::list<ORTradingCodeFieldPtr>& tradingCodes) = 0;

    ///ע��SPI����ӳ���ʽ��ʺ�
    virtual void registerSpi(OrderRouterSpi* pSpi) = 0;

    virtual void login(ORReqLoginField* pLogin) = 0;

    virtual ORCounterConfigFieldPtr getCounterConfigByChannelID(or_channelid_i channelId) = 0;

    virtual int checkAccount(ORCheckAccountField* pInvestor) = 0;

    virtual int assetTransfer(ORAssetTransferField* pTransfer) = 0;

    /////���¹�̨������Ϣ
    /////���и���������Ҫ���øú�����
    // virtual void insertCounterConfig (ORCounterConfigField *counterConfig) =
    // 0;

    //************************************************************************************/
    // ���׽ӿ�
    //************************************************************************************/

    /// JSON ��ʽ����¼��
    virtual int reqJsonTrading(ORJsonTradingReqField* reqJson) = 0;

    ///����¼������
    ///[in, out]
    ///��pOrder->OrderLocalID����Ϊ�գ���OR�ὫORRequestID������Ϊ����� [in]
    ///�������룺InvestorID��ExID��InsID��LimitPrice��VolumeTotalOriginal��ProductClass��Direction�ֶΡ�
    virtual int sendOrder(OROrderReqField* pOrder) = 0;

    ///������������
    /// [in]
    /// �������룺InvestorID��RefORRequestID��ORRequestID�ֶΡ�InsID��ExID��ProductClass���Զ����롣
    /// �����ֶ�OR�����޸ģ�ԭ��������
    virtual int cancelOrder(OROrderCancelReqField* pOrderCancel) = 0;

    //************************************************************************************/
    // ��ѯ�ӿ�
    //************************************************************************************/

    ///��ѯ������
    virtual int queryTradeDate(ORQryTradeDateField* pQuery) = 0;

    //��ȡ���к�Լ��֤ȯ������Ϣ
    virtual void queryStockCode(ORQryStockCodeField* pQuery) = 0;

    /**
     * \brief ��ѯ�ɶ�������Ϣ
     * \param pQuery ��ѯ������Ϣ��
     * ����UFT��̨���������뽻���г����롣
     * ����O32��̨����Ҫ���뽻���г����롣
     * \ return ���͵�OR������0�����򷵻ش���ֵ��
     */
    virtual int queryTradeCode(ORQryTradeCodeField* pQuery) = 0;

    /**
     * \brief ��ѯ�˻����ױ������ͣ�Ͷ�����������ױ��ȣ�
     * \param pQuery ��ѯ������Ϣ��
     * ����UFT��̨���������뽻���г����롣
     * ����O32��̨����Ҫ���뽻���г����롣
     * \ return ���͵�OR������0�����򷵻ش���ֵ��
     */
    virtual int queryTradingCodeType(ORQryTradingCodeTypeField* pQuery) = 0;

    ///Ͷ������Ϣ��ѯ
    virtual int queryInvestor(ORQryInvestorField* pQuery) = 0;

    ///�ʽ��ѯ
    virtual int queryAccountAsset(ORQryAccountAssetField* pQuery) = 0;

    ///
    virtual int queryFuturesAccountMargin(ORQryFuturesAccountMarginField* pQuery) = 0;

    ///�ֲֲ�ѯ
    virtual int queryPosition(ORQryPositionField* pQuery) = 0;

    /**
     * \brief �ֲ���ϸ��ѯ��
     * ����UFT��O32��Ʊ������Ҫ�ù��ܡ�
     * ����O32�ڻ�������ʹ�øù��ܡ�
     * \param pQuery
     * \ return
     */
    virtual int queryPositionDtl(ORQryPositionDtlField* pQuery) = 0;

    ///��֤���ʲ�ѯ
    virtual int queryMarginRate(ORQryMarginRateField* pQuery) = 0;

    /////֤ȯί�в�ѯ
    // virtual int queryOrder (ORQryOrderField *pQuery) = 0;
    /////�ɽ���ѯ
    // virtual int queryTrade (ORQryTradeField *pQuery) = 0;

    ///��ѯ�¹��깺���
    virtual int queryStockPurQuotation(ORQryStockPurQuotationField* pQuery) = 0;
    ///��ѯ�¹��깺��Ϣ
    virtual int queryStockPurInfo(ORQryStockPurInfoField* pQuery) = 0;
    ///��ѯ�¹��깺������Ϣ
    // virtual int queryStockPurStatistics (ORQryStockPurStatisticsField*
    // pQuery) = 0;

    //************************************************************************************/
    // �����ӿ�
    //************************************************************************************/

    /**
     * ͨ��marketData.SubscribeSwitch���ж���/ȡ�����ġ�
     */
    virtual int subscribeMarket(const ORReqSubscribeMarketDataField* marketData) = 0;

    /// ʹ��API��Ӧ�ó������ע��ί�л��棬OR���ڲ�ά���û��档
    virtual void registerOrderCache(OrderCachePtr& orderCache) = 0;

    virtual ~OrderRouterApi() {}
};
using OrderRouterPtr = std::shared_ptr<OrderRouterApi>;

class OrderRouterSpi {
public:
    virtual ~OrderRouterSpi() = default;
    ///��API��OrderRouter����ʱ����
    virtual void onConnected(){};

    ///��API��OrderRouter���ӶϿ�ʱ����
    virtual void onDisconnected(int nReason){};

    ///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
    virtual void onCounterConnected(ORCounterConfigField* counterConfig){};

    ///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
    virtual void onCounterDisconnected(ORCounterConfigField* counterConfig, int nReason){};

    ///��¼
    virtual void onLogin(ORRspLoginField* pAccount, ORRspInfoField* rspInfo){};

    ///��¼
    virtual void onRuntimeStatus(ORRuntimeStatusField* pStatus, ORRspInfoField* rspInfo){};

    ///У���ʽ��ʻ������룩
    virtual void onCheckAccount(ORCheckAccountField* pInvestor, ORRspInfoField* rspInfo){};

    ///�ʽ𻮲�
    virtual void onAssetTransfer(ORAssetTransferField* pTransfer, ORRspInfoField* rspInfo){};

    ///����Ӧ��
    virtual void onError(ORRspInfoField* rspInfo){};

    ///JSON����֪ͨ
    virtual void onJsonTrading(ORJsonTradingRspField* rspJsonTrading){};

    ///����֪ͨ
    virtual void onRtnOrder(OROrderField* pOrder) {};

    ///�ɽ�֪ͨ
    virtual void onRtnTrade(ORTradeField* pTrade){};

    ///����¼�����ر�
    virtual void onErrRtnOrderSend(OROrderReqField* pInputOrder, ORRspInfoField* rspInfo){};

    ///������������ر�
    virtual void onErrRtnOrderCancel(OROrderCancelReqField* pOrderAction, ORRspInfoField* rspInfo){};

    /// ��ѯ�ظ�
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
     * \brief ��ѯ�ֲֻظ���
     * ����UFT��TradingCodeTypeֵʼ��='\0'��TradeCodeΪ�ɶ����롣
     * ����O32��Ʊ��TradingCodetypeֵ='\0'��
     * ����O32�ڻ���TradingCodeTypeΪͶ�����������ױ���ֵ����֮һ��
     * YdPosition/YdEnableVolume�������ֶζ��ڷ�SHFE��INE����������������0��TotalPosition��EnableVolume����ȫ���ֲ֡�
     * \param pRspPosition
     * \param rspInfo
     */
    virtual void onRspQryPosition(ORAccountPositionField* pRspPosition, ORRspInfoField* rspInfo){};
    /**
     * \brief
     * ��ѯ�ֲ���ϸ��Ϣ������ռ�ñ�֤�𡢳ɽ���š�����������ƽ��������ǰ����ۡ����ּ۵ȡ�
     * ����UFT��O32��Ʊ������Ҫ�ù��ܡ�
     * ����O32�ڻ�������ʹ�øù��ܡ�
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
/// �Ƿ������״̬���ɽ������ɲ������ѳ������ϵ���
    ORAPI bool is_ost_finished(or_orderstatus_e status);
    /// �Ƿ񳷵��򲿳ɲ�����
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
