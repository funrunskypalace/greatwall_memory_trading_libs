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
    ///���캯��������UserApi�����
    static OpenOrderApi* createTradeApi(const char* pszFlowPath);

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
    virtual int init(const OR_RESUME_TYPE resumeType = OR_TERT_RESUME) = 0;

    virtual int stop() = 0;

    ///�ȴ��߳̽���
    virtual int join() = 0;

    ///ע��SPI����ӳ���ʽ��ʺ�
    virtual void registerSpi(OpenOrderSpi* pSpi) = 0;

    //����Api�����Config����Initǰ����
    virtual void subscribePrivateTopic(OR_RESUME_TYPE nResumeType) = 0;

    ///ע��ǰ�û������ַ
    virtual void registerFront(const char* pszFrontAddress) = 0;

    virtual int login(OROperatorAccountField* pOperatorAccount) = 0;

    //************************************************************************************/
    // ���׽ӿ�
    //************************************************************************************/

    ///����¼������
    ///[in, out]
    ///��pOrder->OrderLocalID����Ϊ�գ���OR�ὫORRequestID������Ϊ�����
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
    virtual int
    queryFuturesAccountMargin(ORQryFuturesAccountMarginField* pQuery) = 0;

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

    //********************************************************************/
    // �����ӿ�
    //********************************************************************/
    virtual int
    subscribeMarket(const ORReqSubscribeMarketDataField* marketData) = 0;

    virtual ~OpenOrderApi() {}
};

class OpenOrderSpi
{
public:
    virtual ~OpenOrderSpi() = default;
    ///��API��OpenOrder����ʱ����
    virtual void onConnected(){};

    ///��API��OpenOrder���ӶϿ�ʱ����
    virtual void onDisconnected(int nReason){};

    ///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
    virtual void onCounterConnected(ORCounterConfigField* counterConfig){};

    ///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
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

    ///����Ӧ��
    virtual void onError(or_channelid_i channelId, ORRspInfoField* rspInfo){};

    ///����֪ͨ
    virtual void onRtnOrder(or_channelid_i channelId, OROrderField* pOrder){};

    ///�ɽ�֪ͨ
    virtual void onRtnTrade(or_channelid_i channelId, ORTradeField* pTrade){};

    ///����¼�����ر�
    virtual void onErrRtnOrderSend(or_channelid_i channelId,
                                   OROrderReqField* pInputOrder,
                                   ORRspInfoField* rspInfo){};

    ///������������ر�
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
    /// �Ƿ������״̬���ɽ������ɲ������ѳ������ϵ���
    ORAPI bool is_ost_finished(or_orderstatus_e status);
    /// �Ƿ񳷵��򲿳ɲ�����
    ORAPI bool is_ost_canceled(or_orderstatus_e status);
#ifdef __cplusplus
}
#endif

} // namespace ort
} // namespace cycnoches

#else

#include "ort/libor.h"

#endif