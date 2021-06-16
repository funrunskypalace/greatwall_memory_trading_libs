
#ifndef OR_DATA_STRUCT_H
#define OR_DATA_STRUCT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ORDataType.h"
#ifdef __linux__
#include "string.h"
#endif

namespace cycnoches
{
namespace ort
{

/// ϵͳ����״̬
#pragma pack(push, 1)
struct ORRuntimeStatusField
{
    /// ����ͨ�����
    or_channelid_i ChannelID;
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ϵͳģ������
    or_modulename_s ModuleName;
    /// ״̬����
    or_statuscode_s StatusCode;
    void clear() { memset(this, 0, sizeof(ORRuntimeStatusField)); }
    /// initialized to zero
    ORRuntimeStatusField() { clear(); }
};
#pragma pack(pop)
using ORRuntimeStatusFieldPtr = std::shared_ptr<ORRuntimeStatusField>;
ORAPI std::string or_runtimestatus_field_csv_header(const char* delim);
ORAPI std::string or_runtimestatus_field_csv(const char* delim, const ORRuntimeStatusField* pRuntimeStatus);
ORAPI std::string or_runtimestatus_field_desc(const char* delim, const ORRuntimeStatusField* pRuntimeStatus);
ORAPI std::string or_runtimestatus_field_json(const ORRuntimeStatusField* pRuntimeStatus);

/// ��̨���ò���
#pragma pack(push, 1)
struct ORCounterConfigField
{
    /// ����ͨ�����
    or_channelid_i ChannelID;
    /// ͨ������
    or_channeltype_e ChannelType;
    /// IPv4��ַ
    or_ipv4address_s IPv4Address;
    /// IPv4�˿ں�
    or_ipv4port_i IPv4Port;
    /// ͨ����������
    or_channelloadtype_e ChannelLoadType;
    /// ����ͨ��Ψһ��ʶ
    or_channelloadid_s ChannelLoadID;
    /// ͨ�������Զ������
    or_channelcustomconfig_s ChannelCustomConfig;
    /// ��չ��Ϣ
    or_extendfield_s ExtendField;
    void clear() { memset(this, 0, sizeof(ORCounterConfigField)); }
    /// initialized to zero
    ORCounterConfigField() { clear(); }
};
#pragma pack(pop)
using ORCounterConfigFieldPtr = std::shared_ptr<ORCounterConfigField>;
ORAPI std::string or_counterconfig_field_csv_header(const char* delim);
ORAPI std::string or_counterconfig_field_csv(const char* delim, const ORCounterConfigField* pCounterConfig);
ORAPI std::string or_counterconfig_field_desc(const char* delim, const ORCounterConfigField* pCounterConfig);
ORAPI std::string or_counterconfig_field_json(const ORCounterConfigField* pCounterConfig);

/// ����Ա�˺�
#pragma pack(push, 1)
struct OROperatorAccountField
{
    /// ����Ա�˺ű��
    or_operatorid_i OperatorID;
    /// ����
    or_password_s Password;
    /// ���ĵ�TID�����б�
    or_subscribetids_s SubscribeTIDs;
    void clear() { memset(this, 0, sizeof(OROperatorAccountField)); }
    /// initialized to zero
    OROperatorAccountField() { clear(); }
};
#pragma pack(pop)
using OROperatorAccountFieldPtr = std::shared_ptr<OROperatorAccountField>;
ORAPI std::string or_operatoraccount_field_csv_header(const char* delim);
ORAPI std::string or_operatoraccount_field_csv(const char* delim, const OROperatorAccountField* pOperatorAccount);
ORAPI std::string or_operatoraccount_field_desc(const char* delim, const OROperatorAccountField* pOperatorAccount);
ORAPI std::string or_operatoraccount_field_json(const OROperatorAccountField* pOperatorAccount);

/// Ͷ������Ϣ
#pragma pack(push, 1)
struct ORInvestorField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// �˻����
    or_accountid_i AccountID;
    /// �˻�����
    or_accounttype_e AccountType;
    /// ������
    or_date_i TradingDay;
    /// ���͹�˾����
    or_brokerid_s BrokerID;
    /// ĸ�˻�����
    or_brokerinvestorid_s BrokerInvestorID;
    /// �û�����
    or_userid_s UserID;
    /// �ͻ���
    or_clientid_s ClientID;
    /// �ʽ��˻�����
    or_accountcode_s AccountCode;
    /// ����
    or_password_s Password;
    /// Ͷ��������
    or_investorname_s InvestorName;
    /// Ͷ��������
    or_investortype_e InvestorType;
    /// ֤������
    or_idcardtype_e IDCardType;
    /// ֤����
    or_idcardno_s IDCardNo;
    /// �Ƿ��Ծ
    or_isactive_b IsActive;
    /// ������
    or_groupid_s GroupID;
    /// O32����Ա����
    or_o32operatorno_s O32OperatorNo;
    /// O32�������
    or_o32accountcode_s O32AccountCode;
    /// O32��ϱ��
    or_o32combino_s O32CombiNo;
    /// O32�ʲ���Ԫ���
    or_o32assetno_s O32AssetNo;
    void clear() { memset(this, 0, sizeof(ORInvestorField)); }
    /// initialized to zero
    ORInvestorField() { clear(); }
};
#pragma pack(pop)
using ORInvestorFieldPtr = std::shared_ptr<ORInvestorField>;
ORAPI std::string or_investor_field_csv_header(const char* delim);
ORAPI std::string or_investor_field_csv(const char* delim, const ORInvestorField* pInvestor);
ORAPI std::string or_investor_field_desc(const char* delim, const ORInvestorField* pInvestor);
ORAPI std::string or_investor_field_json(const ORInvestorField* pInvestor);

/// Ͷ�����ʽ��˻�
#pragma pack(push, 1)
struct ORAccountAssetField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// �ʽ��˻�����
    or_accountcode_s AccountCode;
    /// ������
    or_date_i TradingDay;
    /// �˻����
    or_accountid_i AccountID;
    /// ���ִ���
    or_currencyid_s CurrencyID;
    /// �ʽ��˻�����
    or_accountname_s AccountName;
    /// �ϴδ���
    or_money_f PreDeposit;
    /// �ϴ�ռ�õı�֤��
    or_money_f PreMargin;
    /// �ϴν���׼����
    or_money_f PreBalance;
    /// ����׼����
    or_money_f Balance;
    /// �����
    or_money_f Deposit;
    /// ����ı�֤��
    or_money_f FrozenMargin;
    /// �����������
    or_money_f FrozenCommission;
    /// ������ʽ�
    or_money_f FrozenCash;
    /// �ֹ�������ʽ�
    or_money_f ManualFrozenCash;
    /// ��λռ�ñ�֤��
    or_money_f UseMargin;
    /// ������
    or_money_f Commission;
    /// ��ȡ�ʽ�
    or_money_f WithdrawQuota;
    /// ��֤��������
    or_money_f Credit;
    /// �����ʽ�
    or_money_f Available;
    /// ƽ��ӯ��
    or_money_f CloseProfit;
    /// �ֲ�ӯ��
    or_money_f PositionProfit;
    /// �ʽ���
    or_money_f CashIn;
    /// ������
    or_money_f CashOut;
    /// ȱʡ״̬
    or_isdefault_b IsDefault;
    /// ��ѯ������
    or_qtprequestid_i QTPRequestID;
    /// ��ѯ�Ự���
    or_qtpsessionid_i QTPSessionID;
    /// ��ѯǰ�ñ��
    or_qtpfrontid_i QTPFrontID;
    void clear() { memset(this, 0, sizeof(ORAccountAssetField)); }
    /// initialized to zero
    ORAccountAssetField() { clear(); }
};
#pragma pack(pop)
using ORAccountAssetFieldPtr = std::shared_ptr<ORAccountAssetField>;
ORAPI std::string or_accountasset_field_csv_header(const char* delim);
ORAPI std::string or_accountasset_field_csv(const char* delim, const ORAccountAssetField* pAccountAsset);
ORAPI std::string or_accountasset_field_desc(const char* delim, const ORAccountAssetField* pAccountAsset);
ORAPI std::string or_accountasset_field_json(const ORAccountAssetField* pAccountAsset);

/// Ͷ���߽��ױ���
#pragma pack(push, 1)
struct ORTradingCodeField
{
    /// ������
    or_date_i TradingDay;
    /// �˻����
    or_accountid_i AccountID;
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ����������
    or_exchangeid_s ExchangeID;
    /// ���ױ�������
    or_tradingcodetype_e TradingCodeType;
    /// �ɶ�����
    or_tradecode_s TradeCode;
    /// Ӫҵ������
    or_branchid_s BranchID;
    /// ϯλ��
    or_seatid_s SeatID;
    /// Ͷ�����˻��ӱ���
    or_optclientid_s OptClientID;
    /// �Ƿ��Ծ
    or_isactive_b IsActive;
    void clear() { memset(this, 0, sizeof(ORTradingCodeField)); }
    /// initialized to zero
    ORTradingCodeField() { clear(); }
};
#pragma pack(pop)
using ORTradingCodeFieldPtr = std::shared_ptr<ORTradingCodeField>;
ORAPI std::string or_tradingcode_field_csv_header(const char* delim);
ORAPI std::string or_tradingcode_field_csv(const char* delim, const ORTradingCodeField* pTradingCode);
ORAPI std::string or_tradingcode_field_desc(const char* delim, const ORTradingCodeField* pTradingCode);
ORAPI std::string or_tradingcode_field_json(const ORTradingCodeField* pTradingCode);

/// ������Ϣ
#pragma pack(push, 1)
struct ORRspInfoField
{
    /// �������
    or_errorid_ei ErrorID;
    /// ������־
    or_islast_b IsLast;
    /// ������Ϣ
    or_errormsg_s ErrorMsg;
    void clear() { memset(this, 0, sizeof(ORRspInfoField)); }
    /// initialized to zero
    ORRspInfoField() { clear(); }
};
#pragma pack(pop)
using ORRspInfoFieldPtr = std::shared_ptr<ORRspInfoField>;
ORAPI std::string or_rspinfo_field_csv_header(const char* delim);
ORAPI std::string or_rspinfo_field_csv(const char* delim, const ORRspInfoField* pRspInfo);
ORAPI std::string or_rspinfo_field_desc(const char* delim, const ORRspInfoField* pRspInfo);
ORAPI std::string or_rspinfo_field_json(const ORRspInfoField* pRspInfo);

/// ����¼������
#pragma pack(push, 1)
struct OROrderReqField
{
    /// ���ر������
    or_orderlocalid_s OrderLocalID;
    /// ��������
    or_orderref_s OrderRef;
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ��Լ����
    or_instrumentid_s InstrumentID;
    /// ����������
    or_exchangeid_s ExchangeID;
    /// �����۸�����
    or_orderpricetype_e OrderPriceType;
    /// ��������
    or_direction_e Direction;
    /// ���Ͷ���ױ���־
    or_combhedgeflag_s CombHedgeFlag;
    /// ���ұ�־
    or_coveredflag_e CoveredFlag;
    /// �۸�
    or_price_f LimitPrice;
    /// ԭʼ����
    or_volume_i VolumeTotalOriginal;
    /// ��Ч������
    or_timecondition_e TimeCondition;
    /// �ɽ�������
    or_volumecondition_e VolumeCondition;
    /// ��С�ɽ���
    or_volume_i MinVolume;
    /// ��������
    or_contingentcondition_e ContingentCondition;
    /// ֹ���
    or_price_f StopPrice;
    /// Ԥ���ֶ�1
    or_thirdreff1_s ThirdReff1;
    /// Ԥ���ֶ�2
    or_thirdreff2_s ThirdReff2;
    /// ��ע
    or_remark_s Remark;
    /// ������־
    or_cancelflag_e CancelFlag;
    /// ����IP
    or_orderip_s OrderIP;
    /// ����MAC
    or_ordermac_s OrderMAC;
    /// ����Ӳ�����к�
    or_orderhdnum_s OrderHDNum;
    /// ����������
    or_ordermaccode_s OrderMacCode;
    /// ��������ϵͳ
    or_orderos_s OrderOS;
    /// ��Ͽ�ƽ��ʶ
    or_comboffsetflag_s CombOffsetFlag;
    /// ��Ʒ����
    or_productclass_e ProductClass;
    /// ��С�ɽ���
    or_volume_i LimitDealAmount;
    /// ֤ȯ�������
    or_subproductclass_e SubProductClass;
    /// ��ծ��Լ���
    or_compactid_s CompactID;
    /// ǰ�ñ��
    or_frontid_i FrontID;
    /// �Ự���
    or_sessionid_i SessionID;
    void clear() { memset(this, 0, sizeof(OROrderReqField)); }
    /// initialized to zero
    OROrderReqField() { clear(); }
};
#pragma pack(pop)
using OROrderReqFieldPtr = std::shared_ptr<OROrderReqField>;
ORAPI std::string or_orderreq_field_csv_header(const char* delim);
ORAPI std::string or_orderreq_field_csv(const char* delim, const OROrderReqField* pOrderReq);
ORAPI std::string or_orderreq_field_desc(const char* delim, const OROrderReqField* pOrderReq);
ORAPI std::string or_orderreq_field_json(const OROrderReqField* pOrderReq);

/// ������������
#pragma pack(push, 1)
struct OROrderCancelReqField
{
    /// ���ر������
    or_orderlocalid_s OrderLocalID;
    /// ��������
    or_orderref_s OrderRef;
    /// �Զ������ñ��
    or_orderactionref_s OrderActionRef;
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ����OrderRouterί�б��
    or_reforrequestid_i RefORRequestID;
    /// �������
    or_ordersysid_s OrderSysID;
    /// ��Լ����
    or_instrumentid_s InstrumentID;
    /// ����������
    or_exchangeid_s ExchangeID;
    /// ���ñ������
    or_orderlocalid_s RefOrderLocalID;
    /// ��̨�������
    or_counterorderid_s CounterOrderID;
    /// ��Ʒ����
    or_productclass_e ProductClass;
    /// ǰ�ñ��
    or_frontid_i FrontID;
    /// �Ự���
    or_sessionid_i SessionID;
    /// ��ע
    or_remark_s Remark;
    void clear() { memset(this, 0, sizeof(OROrderCancelReqField)); }
    /// initialized to zero
    OROrderCancelReqField() { clear(); }
};
#pragma pack(pop)
using OROrderCancelReqFieldPtr = std::shared_ptr<OROrderCancelReqField>;
ORAPI std::string or_ordercancelreq_field_csv_header(const char* delim);
ORAPI std::string or_ordercancelreq_field_csv(const char* delim, const OROrderCancelReqField* pOrderCancelReq);
ORAPI std::string or_ordercancelreq_field_desc(const char* delim, const OROrderCancelReqField* pOrderCancelReq);
ORAPI std::string or_ordercancelreq_field_json(const OROrderCancelReqField* pOrderCancelReq);

/// ����
#pragma pack(push, 1)
struct OROrderField
{
    /// ����״̬
    or_orderstatus_e OrderStatus;
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// OrderRouterί�б��
    or_orrequestid_i ORRequestID;
    /// ���ر������
    or_orderlocalid_s OrderLocalID;
    /// ��������
    or_orderref_s OrderRef;
    /// ��̨�������
    or_counterorderid_s CounterOrderID;
    /// �������
    or_ordersysid_s OrderSysID;
    /// ״̬��Ϣ
    or_statusmsg_s StatusMsg;
    /// ������
    or_date_i TradingDay;
    /// ��Ʒ����
    or_productclass_e ProductClass;
    /// ֤ȯ�������
    or_subproductclass_e SubProductClass;
    /// ����������
    or_exchangeid_s ExchangeID;
    /// ��Լ����
    or_instrumentid_s InstrumentID;
    /// ��������
    or_direction_e Direction;
    /// ԭʼ����
    or_volume_i VolumeTotalOriginal;
    /// �۸�
    or_price_f LimitPrice;
    /// ֹ���
    or_price_f StopPrice;
    /// ��Ч������
    or_timecondition_e TimeCondition;
    /// �ɽ�������
    or_volumecondition_e VolumeCondition;
    /// ��������
    or_contingentcondition_e ContingentCondition;
    /// �����۸�����
    or_orderpricetype_e OrderPriceType;
    /// ��Ͽ�ƽ��ʶ
    or_comboffsetflag_s CombOffsetFlag;
    /// ���Ͷ���ױ���־
    or_combhedgeflag_s CombHedgeFlag;
    /// ϯλ��
    or_seatid_s SeatID;
    /// �ɶ�����
    or_tradecode_s TradeCode;
    /// Ӫҵ������
    or_branchid_s BranchID;
    /// ���ұ�־
    or_coveredflag_e CoveredFlag;
    /// ��������
    or_ordertype_e OrderType;
    /// ��С�ɽ���
    or_volume_i MinVolume;
    /// ��ɽ�����
    or_volume_i VolumeTraded;
    /// ��ɽ����
    or_money_f AmountTraded;
    /// ʣ������
    or_volume_i VolumeRemain;
    /// ����\�ϵ�����
    or_volume_i VolumeCanceled;
    /// ��������
    or_date_i InsertDate;
    /// ί��ʱ��
    or_time_i InsertTime;
    /// ����޸�ʱ��
    or_time_i UpdateTime;
    /// ����ʱ��
    or_time_i CancelTime;
    /// �����־
    or_ownertype_e OwnerType;
    /// Ԥ���ֶ�1
    or_thirdreff1_s ThirdReff1;
    /// Ԥ���ֶ�2
    or_thirdreff2_s ThirdReff2;
    /// ��ע
    or_remark_s Remark;
    /// ������־
    or_cancelflag_e CancelFlag;
    /// ����IP
    or_orderip_s OrderIP;
    /// ����MAC
    or_ordermac_s OrderMAC;
    /// ����Ӳ�����к�
    or_orderhdnum_s OrderHDNum;
    /// ����������
    or_ordermaccode_s OrderMacCode;
    /// ��������ϵͳ
    or_orderos_s OrderOS;
    /// ��С�ɽ���
    or_volume_i LimitDealAmount;
    /// ǰ�ñ��
    or_frontid_i FrontID;
    /// �Ự���
    or_sessionid_i SessionID;
    void clear() { memset(this, 0, sizeof(OROrderField)); }
    /// initialized to zero
    OROrderField() { clear(); }
};
#pragma pack(pop)
using OROrderFieldPtr = std::shared_ptr<OROrderField>;
ORAPI std::string or_order_field_csv_header(const char* delim);
ORAPI std::string or_order_field_csv(const char* delim, const OROrderField* pOrder);
ORAPI std::string or_order_field_desc(const char* delim, const OROrderField* pOrder);
ORAPI std::string or_order_field_json(const OROrderField* pOrder);

/// �ɽ�
#pragma pack(push, 1)
struct ORTradeField
{
    /// OrderRouterί�б��
    or_orrequestid_i ORRequestID;
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ���ر������
    or_orderlocalid_s OrderLocalID;
    /// ��������
    or_orderref_s OrderRef;
    /// ��̨�������
    or_counterorderid_s CounterOrderID;
    /// �������
    or_ordersysid_s OrderSysID;
    /// �ɽ����
    or_tradeid_s TradeID;
    /// �ɽ��ر�����
    or_tradetype_e TradeType;
    /// ������
    or_date_i TradingDay;
    /// ��Ʒ����
    or_productclass_e ProductClass;
    /// ֤ȯ�������
    or_subproductclass_e SubProductClass;
    /// ����������
    or_exchangeid_s ExchangeID;
    /// ��Լ����
    or_instrumentid_s InstrumentID;
    /// �۸�
    or_price_f Price;
    /// �ɽ���
    or_volume_i Volume;
    /// �ɽ����
    or_money_f TradeAmount;
    /// ��������
    or_direction_e Direction;
    /// ��ƽ��־
    or_offsetflag_e OffsetFlag;
    /// Ͷ���ױ���־
    or_hedgeflag_e HedgeFlag;
    /// �ɶ�����
    or_tradecode_s TradeCode;
    /// ϯλ��
    or_seatid_s SeatID;
    /// Ӫҵ������
    or_branchid_s BranchID;
    /// ��Լ���״���
    or_instrumentcode_s InstrumentCode;
    /// �û�����
    or_userid_s UserID;
    /// ���ұ�־
    or_coveredflag_e CoveredFlag;
    /// �ɽ�ʱ��
    or_date_i TradeDate;
    /// �ɽ�ʱ��
    or_time_i TradeTime;
    /// ������
    or_money_f Commission;
    /// �����־
    or_ownertype_e OwnerType;
    /// �ɽ�����
    or_tradetypefutures_e TradeTypeFutures;
    /// Ԥ���ֶ�1
    or_thirdreff1_s ThirdReff1;
    /// Ԥ���ֶ�2
    or_thirdreff2_s ThirdReff2;
    /// Ͷ�ʵ�Ԫ����
    or_investunitid_s InvestUnitID;
    /// ������
    or_settlementid_i SettlementID;
    void clear() { memset(this, 0, sizeof(ORTradeField)); }
    /// initialized to zero
    ORTradeField() { clear(); }
};
#pragma pack(pop)
using ORTradeFieldPtr = std::shared_ptr<ORTradeField>;
ORAPI std::string or_trade_field_csv_header(const char* delim);
ORAPI std::string or_trade_field_csv(const char* delim, const ORTradeField* pTrade);
ORAPI std::string or_trade_field_desc(const char* delim, const ORTradeField* pTrade);
ORAPI std::string or_trade_field_json(const ORTradeField* pTrade);

/// ͨ��JSON¼������
#pragma pack(push, 1)
struct ORJsonTradingReqField
{
    /// ����ͨ�����
    or_channelid_i ChannelID;
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// OrderRouterί�б��
    or_orrequestid_i ORRequestID;
    /// ���ر������
    or_orderlocalid_s OrderLocalID;
    /// ��������
    or_orderref_s OrderRef;
    /// ��Ʒ����
    or_productclass_e ProductClass;
    /// ֤ȯ�������
    or_subproductclass_e SubProductClass;
    /// ��������
    or_direction_e Direction;
    /// ��Ϲ���/��ֱ�־
    or_offsetflag_e OffsetFlag;
    /// Ԥ���ֶ�1
    or_thirdreff1_s ThirdReff1;
    /// Ԥ���ֶ�2
    or_thirdreff2_s ThirdReff2;
    /// ��ע
    or_remark_s Remark;
    /// JSON������Զ�������
    or_jsontypeid_i JsonTypeID;
    /// JSON��������
    or_jsoncontent_s JsonContent;
    /// ǰ�ñ��
    or_frontid_i FrontID;
    /// �Ự���
    or_sessionid_i SessionID;
    void clear() { memset(this, 0, sizeof(ORJsonTradingReqField)); }
    /// initialized to zero
    ORJsonTradingReqField() { clear(); }
};
#pragma pack(pop)
using ORJsonTradingReqFieldPtr = std::shared_ptr<ORJsonTradingReqField>;
ORAPI std::string or_jsontradingreq_field_csv_header(const char* delim);
ORAPI std::string or_jsontradingreq_field_csv(const char* delim, const ORJsonTradingReqField* pJsonTradingReq);
ORAPI std::string or_jsontradingreq_field_desc(const char* delim, const ORJsonTradingReqField* pJsonTradingReq);
ORAPI std::string or_jsontradingreq_field_json(const ORJsonTradingReqField* pJsonTradingReq);

/// JSON����Ļظ�
#pragma pack(push, 1)
struct ORJsonTradingRspField
{
    /// ����ͨ�����
    or_channelid_i ChannelID;
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// OrderRouterί�б��
    or_orrequestid_i ORRequestID;
    /// ���ر������
    or_orderlocalid_s OrderLocalID;
    /// ��������
    or_orderref_s OrderRef;
    /// ��Ʒ����
    or_productclass_e ProductClass;
    /// ֤ȯ�������
    or_subproductclass_e SubProductClass;
    /// Ԥ���ֶ�1
    or_thirdreff1_s ThirdReff1;
    /// Ԥ���ֶ�2
    or_thirdreff2_s ThirdReff2;
    /// ��ע
    or_remark_s Remark;
    /// ������
    or_date_i TradingDay;
    /// ����ʱ��
    or_time_i TradeTime;
    /// ������־
    or_islast_b IsLast;
    /// �������
    or_errorid_ei ErrorID;
    /// ������Ϣ
    or_errormsg_s ErrorMsg;
    /// JSON������Զ�������
    or_jsontypeid_i JsonTypeID;
    /// JSON��������
    or_jsoncontent_s JsonContent;
    /// ǰ�ñ��
    or_frontid_i FrontID;
    /// �Ự���
    or_sessionid_i SessionID;
    void clear() { memset(this, 0, sizeof(ORJsonTradingRspField)); }
    /// initialized to zero
    ORJsonTradingRspField() { clear(); }
};
#pragma pack(pop)
using ORJsonTradingRspFieldPtr = std::shared_ptr<ORJsonTradingRspField>;
ORAPI std::string or_jsontradingrsp_field_csv_header(const char* delim);
ORAPI std::string or_jsontradingrsp_field_csv(const char* delim, const ORJsonTradingRspField* pJsonTradingRsp);
ORAPI std::string or_jsontradingrsp_field_desc(const char* delim, const ORJsonTradingRspField* pJsonTradingRsp);
ORAPI std::string or_jsontradingrsp_field_json(const ORJsonTradingRspField* pJsonTradingRsp);

/// ��Ȩ��ϱ���¼������
#pragma pack(push, 1)
struct OROptionsCombineOrderField
{
    /// ���ر������
    or_orderlocalid_s OrderLocalID;
    /// ��������
    or_orderref_s OrderRef;
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ��Ȩ��ϲ��Դ��루���������'PNSJC�Ϲ�ţ�м۲����'�ȡ�
    or_optionscombstrategyid_s StrategyId;
    /// ��Ȩ��ϲ�����ϱ��룬OffsetFlag��ƽ����Ϊ���ʱ��Ҫ����ʱ����Ҫ��
    or_optionscombsecondaryorderid_s SecondaryOrderId;
    /// ��Ʒ����
    or_productclass_e ProductClass;
    /// ֤ȯ�������
    or_subproductclass_e SubProductClass;
    /// ��������
    or_direction_e Direction;
    /// ��Ϲ���/��ֱ�־
    or_offsetflag_e OffsetFlag;
    /// Ԥ���ֶ�1
    or_thirdreff1_s ThirdReff1;
    /// Ԥ���ֶ�2
    or_thirdreff2_s ThirdReff2;
    /// ��ע
    or_remark_s Remark;
    /// ��ǰ��Ȩ��Ϻ�Լ����
    or_optionscomblegnum_i OptionsCombLegNum;
    /// �Ƚ���������
    or_exchangeid_s ExchangeIDLeg1;
    /// �Ⱥ�Լ����
    or_instrumentid_s InstrumentIDLeg1;
    /// ����Ȩ����
    or_optionstype_e OptionsTypeLeg1;
    /// �ȳֲ�Ȩ��������
    or_posidirection_e PosiDirectionLeg1;
    /// �ȱ��ұ�־
    or_coveredflag_e CoveredFlagLeg1;
    /// �Ⱥ�Լ�������ţ����ֶ���Ӧʱ���أ�ί�в���Ҫ��
    or_volume_i VolumeLeg1;
    /// �Ⱥ�Լ����
    or_instrumentid_s InstrumentIDLeg2;
    /// �Ƚ���������
    or_exchangeid_s ExchangeIDLeg2;
    /// ����Ȩ����
    or_optionstype_e OptionsTypeLeg2;
    /// �ȳֲ�Ȩ��������
    or_posidirection_e PosiDirectionLeg2;
    /// �ȱ��ұ�־
    or_coveredflag_e CoveredFlagLeg2;
    /// �Ⱥ�Լ�������ţ����ֶ���Ӧʱ���أ�ί�в���Ҫ��
    or_volume_i VolumeLeg2;
    /// �Ⱥ�Լ����
    or_instrumentid_s InstrumentIDLeg3;
    /// �Ƚ���������
    or_exchangeid_s ExchangeIDLeg3;
    /// ����Ȩ����
    or_optionstype_e OptionsTypeLeg3;
    /// �ȳֲ�Ȩ��������
    or_posidirection_e PosiDirectionLeg3;
    /// �ȱ��ұ�־
    or_coveredflag_e CoveredFlagLeg3;
    /// �Ⱥ�Լ�������ţ����ֶ���Ӧʱ���أ�ί�в���Ҫ��
    or_volume_i VolumeLeg3;
    /// �Ⱥ�Լ����
    or_instrumentid_s InstrumentIDLeg4;
    /// �Ƚ���������
    or_exchangeid_s ExchangeIDLeg4;
    /// ����Ȩ����
    or_optionstype_e OptionsTypeLeg4;
    /// �ȳֲ�Ȩ��������
    or_posidirection_e PosiDirectionLeg4;
    /// �ȱ��ұ�־
    or_coveredflag_e CoveredFlagLeg4;
    /// �Ⱥ�Լ�������ţ����ֶ���Ӧʱ���أ�ί�в���Ҫ��
    or_volume_i VolumeLeg4;
    /// ǰ�ñ��
    or_frontid_i FrontID;
    /// �Ự���
    or_sessionid_i SessionID;
    void clear() { memset(this, 0, sizeof(OROptionsCombineOrderField)); }
    /// initialized to zero
    OROptionsCombineOrderField() { clear(); }
};
#pragma pack(pop)
using OROptionsCombineOrderFieldPtr = std::shared_ptr<OROptionsCombineOrderField>;
ORAPI std::string or_optionscombineorder_field_csv_header(const char* delim);
ORAPI std::string or_optionscombineorder_field_csv(const char* delim, const OROptionsCombineOrderField* pOptionsCombineOrder);
ORAPI std::string or_optionscombineorder_field_desc(const char* delim, const OROptionsCombineOrderField* pOptionsCombineOrder);
ORAPI std::string or_optionscombineorder_field_json(const OROptionsCombineOrderField* pOptionsCombineOrder);

/// ��Ȩ��ϱ�����ѯ����
#pragma pack(push, 1)
struct OROptionsCombineQryField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ��Ȩ��ϲ�����ϱ��룬OffsetFlag��ƽ����Ϊ���ʱ��Ҫ����ʱ����Ҫ��
    or_optionscombsecondaryorderid_s SecondaryOrderId;
    /// �Ƚ���������
    or_exchangeid_s ExchangeIDLeg3;
    void clear() { memset(this, 0, sizeof(OROptionsCombineQryField)); }
    /// initialized to zero
    OROptionsCombineQryField() { clear(); }
};
#pragma pack(pop)
using OROptionsCombineQryFieldPtr = std::shared_ptr<OROptionsCombineQryField>;
ORAPI std::string or_optionscombineqry_field_csv_header(const char* delim);
ORAPI std::string or_optionscombineqry_field_csv(const char* delim, const OROptionsCombineQryField* pOptionsCombineQry);
ORAPI std::string or_optionscombineqry_field_desc(const char* delim, const OROptionsCombineQryField* pOptionsCombineQry);
ORAPI std::string or_optionscombineqry_field_json(const OROptionsCombineQryField* pOptionsCombineQry);

/// ��Ȩ�����Ϣ
#pragma pack(push, 1)
struct OROptionsCombineField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ����������
    or_exchangeid_s ExchangeID;
    /// ��Լ����
    or_instrumentid_s InstrumentID;
    /// ��Ȩ��ϲ��Դ��루���������'PNSJC�Ϲ�ţ�м۲����'�ȡ�
    or_optionscombstrategyid_s StrategyId;
    /// ��Ȩ��ϲ�����ϱ��룬OffsetFlag��ƽ����Ϊ���ʱ��Ҫ����ʱ����Ҫ��
    or_optionscombsecondaryorderid_s SecondaryOrderId;
    /// ��ǰ��Ȩ��Ϻ�Լ����
    or_optionscomblegnum_i OptionsCombLegNum;
    /// �Ⱥ�Լ����
    or_instrumentid_s InstrumentIDLeg1;
    /// �Ƚ���������
    or_exchangeid_s ExchangeIDLeg1;
    /// ����Ȩ����
    or_optionstype_e OptionsTypeLeg1;
    /// �ȳֲ�Ȩ��������
    or_posidirection_e PosiDirectionLeg1;
    /// �ȱ��ұ�־
    or_coveredflag_e CoveredFlagLeg1;
    /// �Ⱥ�Լ�������ţ����ֶ���Ӧʱ���أ�ί�в���Ҫ��
    or_volume_i VolumeLeg1;
    /// �Ƚ���������
    or_exchangeid_s ExchangeIDLeg2;
    /// �Ⱥ�Լ����
    or_instrumentid_s InstrumentIDLeg2;
    /// ����Ȩ����
    or_optionstype_e OptionsTypeLeg2;
    /// �ȳֲ�Ȩ��������
    or_posidirection_e PosiDirectionLeg2;
    /// �ȱ��ұ�־
    or_coveredflag_e CoveredFlagLeg2;
    /// �Ⱥ�Լ�������ţ����ֶ���Ӧʱ���أ�ί�в���Ҫ��
    or_volume_i VolumeLeg2;
    /// �Ƚ���������
    or_exchangeid_s ExchangeIDLeg3;
    /// �Ⱥ�Լ����
    or_instrumentid_s InstrumentIDLeg3;
    /// ����Ȩ����
    or_optionstype_e OptionsTypeLeg3;
    /// �ȳֲ�Ȩ��������
    or_posidirection_e PosiDirectionLeg3;
    /// �ȱ��ұ�־
    or_coveredflag_e CoveredFlagLeg3;
    /// �Ⱥ�Լ�������ţ����ֶ���Ӧʱ���أ�ί�в���Ҫ��
    or_volume_i VolumeLeg3;
    /// �Ƚ���������
    or_exchangeid_s ExchangeIDLeg4;
    /// �Ⱥ�Լ����
    or_instrumentid_s InstrumentIDLeg4;
    /// ����Ȩ����
    or_optionstype_e OptionsTypeLeg4;
    /// �ȳֲ�Ȩ��������
    or_posidirection_e PosiDirectionLeg4;
    /// �ȱ��ұ�־
    or_coveredflag_e CoveredFlagLeg4;
    /// �Ⱥ�Լ�������ţ����ֶ���Ӧʱ���أ�ί�в���Ҫ��
    or_volume_i VolumeLeg4;
    void clear() { memset(this, 0, sizeof(OROptionsCombineField)); }
    /// initialized to zero
    OROptionsCombineField() { clear(); }
};
#pragma pack(pop)
using OROptionsCombineFieldPtr = std::shared_ptr<OROptionsCombineField>;
ORAPI std::string or_optionscombine_field_csv_header(const char* delim);
ORAPI std::string or_optionscombine_field_csv(const char* delim, const OROptionsCombineField* pOptionsCombine);
ORAPI std::string or_optionscombine_field_desc(const char* delim, const OROptionsCombineField* pOptionsCombine);
ORAPI std::string or_optionscombine_field_json(const OROptionsCombineField* pOptionsCombine);

/// ĸ�˻��ֲ�
#pragma pack(push, 1)
struct ORAccountPositionField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ����������
    or_exchangeid_s ExchangeID;
    /// ��Լ����
    or_instrumentid_s InstrumentID;
    /// �ֲֶ�շ���
    or_posidirection_e PosiDirection;
    /// �ֲ����ڱ�־
    or_positiondate_e PositionDate;
    /// �ֲܳ�
    or_volume_i TotalPosition;
    /// ��������
    or_volume_i EnableVolume;
    /// ���ճֲ�
    or_volume_i YdPosition;
    /// ��ֿ�������
    or_volume_i YdEnableVolume;
    /// ��ֲ�
    or_volume_i TodayPosition;
    /// ��ֿ�������
    or_volume_i TodayEnableVolume;
    /// ��ͷ����
    or_volume_i LongFrozen;
    /// ���ֶ�����
    or_money_f LongFrozenAmount;
    /// ��ͷ����
    or_money_f ShortFrozen;
    /// ���ֶ�����
    or_money_f ShortFrozenAmount;
    /// �ֹ���������
    or_money_f ManualFrozenAmount;
    /// �ɶ�����
    or_tradecode_s TradeCode;
    /// ���ױ�������
    or_tradingcodetype_e TradingCodeType;
    /// ������
    or_date_i TradingDay;
    /// Ͷ���ױ���־
    or_hedgeflag_e HedgeFlag;
    /// ���ұ�־
    or_coveredflag_e CoveredFlag;
    /// �ϴ�ռ�õı�֤��
    or_money_f PreMargin;
    /// ��λռ�ñ�֤��
    or_money_f UseMargin;
    /// ������
    or_volume_i OpenVolume;
    /// ƽ����
    or_volume_i CloseVolume;
    /// ƽ�����
    or_volume_i CloseYdVolume;
    /// ���ν����
    or_price_f SettlementPrice;
    /// �ϴν����
    or_price_f PreSettlementPrice;
    /// ������
    or_money_f Commission;
    /// �����������
    or_money_f FrozenCommission;
    /// ����ı�֤��
    or_money_f FrozenMargin;
    /// ���ֳɱ�
    or_money_f OpenCost;
    /// �ֲֳɱ�
    or_money_f PositionCost;
    /// ƽ��ӯ��
    or_money_f CloseProfit;
    /// �ֲ�ӯ��
    or_money_f PositionProfit;
    /// ���ֽ��
    or_money_f OpenAmount;
    /// ƽ�ֽ��
    or_money_f CloseAmount;
    /// ƽ��ֽ��
    or_money_f CloseYdAmount;
    /// �ʽ���
    or_money_f CashIn;
    /// ������ʽ�
    or_money_f FrozenCash;
    /// ������
    or_settlementid_i SettlementID;
    /// ��������֤��
    or_money_f ExchangeMargin;
    /// ��Լ����
    or_volumemultiple_i VolumeMultiple;
    /// ִ�ж�������
    or_volume_i YdStrikeFrozen;
    /// �������ֲֳɱ���ֵ��ֻ�д�����ʹ��
    or_money_f PositionCostOffset;
    void clear() { memset(this, 0, sizeof(ORAccountPositionField)); }
    /// initialized to zero
    ORAccountPositionField() { clear(); }
};
#pragma pack(pop)
using ORAccountPositionFieldPtr = std::shared_ptr<ORAccountPositionField>;
ORAPI std::string or_accountposition_field_csv_header(const char* delim);
ORAPI std::string or_accountposition_field_csv(const char* delim, const ORAccountPositionField* pAccountPosition);
ORAPI std::string or_accountposition_field_desc(const char* delim, const ORAccountPositionField* pAccountPosition);
ORAPI std::string or_accountposition_field_json(const ORAccountPositionField* pAccountPosition);

/// �˻��ֲ���ϸ
#pragma pack(push, 1)
struct ORAccountPositionDtlField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ����������
    or_exchangeid_s ExchangeID;
    /// ��Լ����
    or_instrumentid_s InstrumentID;
    /// ���ұ�־
    or_coveredflag_e CoveredFlag;
    /// �ֲֶ�շ���
    or_posidirection_e PosiDirection;
    /// ������
    or_date_i OpenDate;
    /// �ɽ����
    or_tradeid_s TradeID;
    /// �ɽ�����
    or_tradetypefutures_e TradeTypeFutures;
    /// �ɶ�����
    or_tradecode_s TradeCode;
    /// ���ױ�������
    or_tradingcodetype_e TradingCodeType;
    /// �ɽ���
    or_volume_i Volume;
    /// �ϴν����
    or_price_f PreSettlementPrice;
    /// ����
    or_price_f OpenPrice;
    /// Ͷ���߱�֤��
    or_money_f Margin;
    /// ƽ����
    or_volume_i CloseVolume;
    /// ƽ�ֽ��
    or_money_f CloseAmount;
    /// ������
    or_settlementid_i SettlementID;
    /// Ͷ���ױ���־
    or_hedgeflag_e HedgeFlag;
    /// ��������
    or_direction_e Direction;
    /// ������
    or_date_i TradingDay;
    /// ��֤����
    or_ratio_f MarginRateByMoney;
    /// ��֤����(������)
    or_ratio_f MarginRateByVolume;
    /// ������
    or_price_f LastSettlementPrice;
    /// ���ν����
    or_price_f SettlementPrice;
    /// ����ʱ��˳��ƽ�ֵı���,������ר��
    or_volume_i TimeFirstVolume;
    /// Ͷ�ʵ�Ԫ����
    or_investunitid_s InvestUnitID;
    void clear() { memset(this, 0, sizeof(ORAccountPositionDtlField)); }
    /// initialized to zero
    ORAccountPositionDtlField() { clear(); }
};
#pragma pack(pop)
using ORAccountPositionDtlFieldPtr = std::shared_ptr<ORAccountPositionDtlField>;
ORAPI std::string or_accountpositiondtl_field_csv_header(const char* delim);
ORAPI std::string or_accountpositiondtl_field_csv(const char* delim, const ORAccountPositionDtlField* pAccountPositionDtl);
ORAPI std::string or_accountpositiondtl_field_desc(const char* delim, const ORAccountPositionDtlField* pAccountPositionDtl);
ORAPI std::string or_accountpositiondtl_field_json(const ORAccountPositionDtlField* pAccountPositionDtl);

/// ��֤����
#pragma pack(push, 1)
struct ORMarginRateField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ����������
    or_exchangeid_s ExchangeID;
    /// ��Լ����
    or_instrumentid_s InstrumentID;
    /// ��ͷ��֤����
    or_ratio_f LongMarginRatioByMoney;
    /// ��ͷ��֤����
    or_ratio_f ShortMarginRatioByMoney;
    void clear() { memset(this, 0, sizeof(ORMarginRateField)); }
    /// initialized to zero
    ORMarginRateField() { clear(); }
};
#pragma pack(pop)
using ORMarginRateFieldPtr = std::shared_ptr<ORMarginRateField>;
ORAPI std::string or_marginrate_field_csv_header(const char* delim);
ORAPI std::string or_marginrate_field_csv(const char* delim, const ORMarginRateField* pMarginRate);
ORAPI std::string or_marginrate_field_desc(const char* delim, const ORMarginRateField* pMarginRate);
ORAPI std::string or_marginrate_field_json(const ORMarginRateField* pMarginRate);

/// ��ѯ��Ʒ��������Ϣ
#pragma pack(push, 1)
struct ORQryCommissionRateField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ����������
    or_exchangeid_s ExchangeID;
    /// ��Լ����
    or_instrumentid_s InstrumentID;
    /// ��������
    or_direction_e Direction;
    /// ��ƽ��־
    or_offsetflag_e OffsetFlag;
    /// ���ұ�־
    or_coveredflag_e CoveredFlag;
    /// Ͷ���ױ���־
    or_hedgeflag_e HedgeFlag;
    void clear() { memset(this, 0, sizeof(ORQryCommissionRateField)); }
    /// initialized to zero
    ORQryCommissionRateField() { clear(); }
};
#pragma pack(pop)
using ORQryCommissionRateFieldPtr = std::shared_ptr<ORQryCommissionRateField>;
ORAPI std::string or_qrycommissionrate_field_csv_header(const char* delim);
ORAPI std::string or_qrycommissionrate_field_csv(const char* delim, const ORQryCommissionRateField* pQryCommissionRate);
ORAPI std::string or_qrycommissionrate_field_desc(const char* delim, const ORQryCommissionRateField* pQryCommissionRate);
ORAPI std::string or_qrycommissionrate_field_json(const ORQryCommissionRateField* pQryCommissionRate);

/// ��ѯ��Ʒ��֤������Ϣ
#pragma pack(push, 1)
struct ORQryMarginRateField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ����������
    or_exchangeid_s ExchangeID;
    /// ��Լ����
    or_instrumentid_s InstrumentID;
    void clear() { memset(this, 0, sizeof(ORQryMarginRateField)); }
    /// initialized to zero
    ORQryMarginRateField() { clear(); }
};
#pragma pack(pop)
using ORQryMarginRateFieldPtr = std::shared_ptr<ORQryMarginRateField>;
ORAPI std::string or_qrymarginrate_field_csv_header(const char* delim);
ORAPI std::string or_qrymarginrate_field_csv(const char* delim, const ORQryMarginRateField* pQryMarginRate);
ORAPI std::string or_qrymarginrate_field_desc(const char* delim, const ORQryMarginRateField* pQryMarginRate);
ORAPI std::string or_qrymarginrate_field_json(const ORQryMarginRateField* pQryMarginRate);

/// ��ѯ����
#pragma pack(push, 1)
struct ORQryOrderField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ����������
    or_exchangeid_s ExchangeID;
    /// ��Լ����
    or_instrumentid_s InstrumentID;
    /// �������
    or_ordersysid_s OrderSysID;
    /// ��λ��
    or_positionstr_s PositionStr;
    void clear() { memset(this, 0, sizeof(ORQryOrderField)); }
    /// initialized to zero
    ORQryOrderField() { clear(); }
};
#pragma pack(pop)
using ORQryOrderFieldPtr = std::shared_ptr<ORQryOrderField>;
ORAPI std::string or_qryorder_field_csv_header(const char* delim);
ORAPI std::string or_qryorder_field_csv(const char* delim, const ORQryOrderField* pQryOrder);
ORAPI std::string or_qryorder_field_desc(const char* delim, const ORQryOrderField* pQryOrder);
ORAPI std::string or_qryorder_field_json(const ORQryOrderField* pQryOrder);

/// ��ѯ�ɽ�
#pragma pack(push, 1)
struct ORQryTradeField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ����������
    or_exchangeid_s ExchangeID;
    /// ��Լ����
    or_instrumentid_s InstrumentID;
    /// �ɽ����
    or_tradeid_s TradeID;
    /// ��λ��
    or_positionstr_s PositionStr;
    void clear() { memset(this, 0, sizeof(ORQryTradeField)); }
    /// initialized to zero
    ORQryTradeField() { clear(); }
};
#pragma pack(pop)
using ORQryTradeFieldPtr = std::shared_ptr<ORQryTradeField>;
ORAPI std::string or_qrytrade_field_csv_header(const char* delim);
ORAPI std::string or_qrytrade_field_csv(const char* delim, const ORQryTradeField* pQryTrade);
ORAPI std::string or_qrytrade_field_desc(const char* delim, const ORQryTradeField* pQryTrade);
ORAPI std::string or_qrytrade_field_json(const ORQryTradeField* pQryTrade);

/// ��ѯͶ���ֲ߳�
#pragma pack(push, 1)
struct ORQryPositionField
{
    /// ����������
    or_exchangeid_s ExchangeID;
    /// ��Լ����
    or_instrumentid_s InstrumentID;
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ��Ʒ����
    or_productclass_e ProductClass;
    void clear() { memset(this, 0, sizeof(ORQryPositionField)); }
    /// initialized to zero
    ORQryPositionField() { clear(); }
};
#pragma pack(pop)
using ORQryPositionFieldPtr = std::shared_ptr<ORQryPositionField>;
ORAPI std::string or_qryposition_field_csv_header(const char* delim);
ORAPI std::string or_qryposition_field_csv(const char* delim, const ORQryPositionField* pQryPosition);
ORAPI std::string or_qryposition_field_desc(const char* delim, const ORQryPositionField* pQryPosition);
ORAPI std::string or_qryposition_field_json(const ORQryPositionField* pQryPosition);

/// ��ѯͶ���ֲ߳���ϸ
#pragma pack(push, 1)
struct ORQryPositionDtlField
{
    /// ����������
    or_exchangeid_s ExchangeID;
    /// ��Լ����
    or_instrumentid_s InstrumentID;
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    void clear() { memset(this, 0, sizeof(ORQryPositionDtlField)); }
    /// initialized to zero
    ORQryPositionDtlField() { clear(); }
};
#pragma pack(pop)
using ORQryPositionDtlFieldPtr = std::shared_ptr<ORQryPositionDtlField>;
ORAPI std::string or_qrypositiondtl_field_csv_header(const char* delim);
ORAPI std::string or_qrypositiondtl_field_csv(const char* delim, const ORQryPositionDtlField* pQryPositionDtl);
ORAPI std::string or_qrypositiondtl_field_desc(const char* delim, const ORQryPositionDtlField* pQryPositionDtl);
ORAPI std::string or_qrypositiondtl_field_json(const ORQryPositionDtlField* pQryPositionDtl);

/// ��ѯ��һ������
#pragma pack(push, 1)
struct ORQryTradeDateField
{
    /// ������
    or_date_i TradingDay;
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    void clear() { memset(this, 0, sizeof(ORQryTradeDateField)); }
    /// initialized to zero
    ORQryTradeDateField() { clear(); }
};
#pragma pack(pop)
using ORQryTradeDateFieldPtr = std::shared_ptr<ORQryTradeDateField>;
ORAPI std::string or_qrytradedate_field_csv_header(const char* delim);
ORAPI std::string or_qrytradedate_field_csv(const char* delim, const ORQryTradeDateField* pQryTradeDate);
ORAPI std::string or_qrytradedate_field_desc(const char* delim, const ORQryTradeDateField* pQryTradeDate);
ORAPI std::string or_qrytradedate_field_json(const ORQryTradeDateField* pQryTradeDate);

/// ��ѯ��һ�������ڵĻظ�
#pragma pack(push, 1)
struct ORRspTradeDateField
{
    /// ������
    or_date_i TradingDay;
    /// ��һ������
    or_date_i NextTradingDay;
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    void clear() { memset(this, 0, sizeof(ORRspTradeDateField)); }
    /// initialized to zero
    ORRspTradeDateField() { clear(); }
};
#pragma pack(pop)
using ORRspTradeDateFieldPtr = std::shared_ptr<ORRspTradeDateField>;
ORAPI std::string or_rsptradedate_field_csv_header(const char* delim);
ORAPI std::string or_rsptradedate_field_csv(const char* delim, const ORRspTradeDateField* pRspTradeDate);
ORAPI std::string or_rsptradedate_field_desc(const char* delim, const ORRspTradeDateField* pRspTradeDate);
ORAPI std::string or_rsptradedate_field_json(const ORRspTradeDateField* pRspTradeDate);

/// ��ѯͶ������Ϣ��Ϣ
#pragma pack(push, 1)
struct ORQryInvestorField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    void clear() { memset(this, 0, sizeof(ORQryInvestorField)); }
    /// initialized to zero
    ORQryInvestorField() { clear(); }
};
#pragma pack(pop)
using ORQryInvestorFieldPtr = std::shared_ptr<ORQryInvestorField>;
ORAPI std::string or_qryinvestor_field_csv_header(const char* delim);
ORAPI std::string or_qryinvestor_field_csv(const char* delim, const ORQryInvestorField* pQryInvestor);
ORAPI std::string or_qryinvestor_field_desc(const char* delim, const ORQryInvestorField* pQryInvestor);
ORAPI std::string or_qryinvestor_field_json(const ORQryInvestorField* pQryInvestor);

/// ��ѯ�ʲ��˻��ʽ���Ϣ
#pragma pack(push, 1)
struct ORQryAccountAssetField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ��ѯ������
    or_qtprequestid_i QTPRequestID;
    /// ��ѯ�Ự���
    or_qtpsessionid_i QTPSessionID;
    /// ��ѯǰ�ñ��
    or_qtpfrontid_i QTPFrontID;
    void clear() { memset(this, 0, sizeof(ORQryAccountAssetField)); }
    /// initialized to zero
    ORQryAccountAssetField() { clear(); }
};
#pragma pack(pop)
using ORQryAccountAssetFieldPtr = std::shared_ptr<ORQryAccountAssetField>;
ORAPI std::string or_qryaccountasset_field_csv_header(const char* delim);
ORAPI std::string or_qryaccountasset_field_csv(const char* delim, const ORQryAccountAssetField* pQryAccountAsset);
ORAPI std::string or_qryaccountasset_field_desc(const char* delim, const ORQryAccountAssetField* pQryAccountAsset);
ORAPI std::string or_qryaccountasset_field_json(const ORQryAccountAssetField* pQryAccountAsset);

/// ��ѯ�ڻ���֤��
#pragma pack(push, 1)
struct ORQryFuturesAccountMarginField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    void clear() { memset(this, 0, sizeof(ORQryFuturesAccountMarginField)); }
    /// initialized to zero
    ORQryFuturesAccountMarginField() { clear(); }
};
#pragma pack(pop)
using ORQryFuturesAccountMarginFieldPtr = std::shared_ptr<ORQryFuturesAccountMarginField>;
ORAPI std::string or_qryfuturesaccountmargin_field_csv_header(const char* delim);
ORAPI std::string or_qryfuturesaccountmargin_field_csv(const char* delim, const ORQryFuturesAccountMarginField* pQryFuturesAccountMargin);
ORAPI std::string or_qryfuturesaccountmargin_field_desc(const char* delim, const ORQryFuturesAccountMarginField* pQryFuturesAccountMargin);
ORAPI std::string or_qryfuturesaccountmargin_field_json(const ORQryFuturesAccountMarginField* pQryFuturesAccountMargin);

/// ��ѯͶ���߹ɶ�����
#pragma pack(push, 1)
struct ORQryTradeCodeField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ����������
    or_exchangeid_s ExchangeID;
    void clear() { memset(this, 0, sizeof(ORQryTradeCodeField)); }
    /// initialized to zero
    ORQryTradeCodeField() { clear(); }
};
#pragma pack(pop)
using ORQryTradeCodeFieldPtr = std::shared_ptr<ORQryTradeCodeField>;
ORAPI std::string or_qrytradecode_field_csv_header(const char* delim);
ORAPI std::string or_qrytradecode_field_csv(const char* delim, const ORQryTradeCodeField* pQryTradeCode);
ORAPI std::string or_qrytradecode_field_desc(const char* delim, const ORQryTradeCodeField* pQryTradeCode);
ORAPI std::string or_qrytradecode_field_json(const ORQryTradeCodeField* pQryTradeCode);

/// ��ѯͶ���߽��ױ��롣UFT��ѯʱ��ExchangeID���Բ����룬O32��������
#pragma pack(push, 1)
struct ORQryTradingCodeTypeField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ����������
    or_exchangeid_s ExchangeID;
    void clear() { memset(this, 0, sizeof(ORQryTradingCodeTypeField)); }
    /// initialized to zero
    ORQryTradingCodeTypeField() { clear(); }
};
#pragma pack(pop)
using ORQryTradingCodeTypeFieldPtr = std::shared_ptr<ORQryTradingCodeTypeField>;
ORAPI std::string or_qrytradingcodetype_field_csv_header(const char* delim);
ORAPI std::string or_qrytradingcodetype_field_csv(const char* delim, const ORQryTradingCodeTypeField* pQryTradingCodeType);
ORAPI std::string or_qrytradingcodetype_field_desc(const char* delim, const ORQryTradingCodeTypeField* pQryTradingCodeType);
ORAPI std::string or_qrytradingcodetype_field_json(const ORQryTradingCodeTypeField* pQryTradingCodeType);

/// ��ѯ��ծ��Լ��Ϣ
#pragma pack(push, 1)
struct ORQryCrdtCompactField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ����������
    or_exchangeid_s ExchangeID;
    /// ֤ȯ����
    or_instrumentid_s InstrumentID;
    /// ��ѯ������
    or_qtprequestid_i QTPRequestID;
    /// ��ѯ�Ự���
    or_qtpsessionid_i QTPSessionID;
    /// ��ѯǰ�ñ��
    or_qtpfrontid_i QTPFrontID;
    void clear() { memset(this, 0, sizeof(ORQryCrdtCompactField)); }
    /// initialized to zero
    ORQryCrdtCompactField() { clear(); }
};
#pragma pack(pop)
using ORQryCrdtCompactFieldPtr = std::shared_ptr<ORQryCrdtCompactField>;
ORAPI std::string or_qrycrdtcompact_field_csv_header(const char* delim);
ORAPI std::string or_qrycrdtcompact_field_csv(const char* delim, const ORQryCrdtCompactField* pQryCrdtCompact);
ORAPI std::string or_qrycrdtcompact_field_desc(const char* delim, const ORQryCrdtCompactField* pQryCrdtCompact);
ORAPI std::string or_qrycrdtcompact_field_json(const ORQryCrdtCompactField* pQryCrdtCompact);

/// ��ѯ��ծ��Լ��Ϣ�ظ�
#pragma pack(push, 1)
struct ORCrdtCompactField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ����������
    or_exchangeid_s ExchangeID;
    /// ֤ȯ����
    or_instrumentid_s InstrumentID;
    /// ������
    or_date_i TradingDay;
    /// ��ծ��Լ���
    or_compactid_s CompactID;
    /// ��֤�����
    or_ratio_f CreditRatio;
    /// ���ر������
    or_orderlocalid_s OrderLocalID;
    /// �۸�
    or_price_f LimitPrice;
    /// ԭʼ����
    or_volume_i VolumeTotalOriginal;
    /// ��ɽ�����
    or_volume_i VolumeTraded;
    /// ��ɽ����
    or_money_f AmountTraded;
    /// ������
    or_money_f Commission;
    /// ��Լ���
    or_compacttype_e CompactType;
    /// ��Լ״̬
    or_compactstatus_e CompactStatus;
    /// ʵʱ��Լ���
    or_money_f RealCompactbalance;
    /// ʵʱ��Լ����
    or_volume_i RealCompactVolume;
    /// ʵʱ��Լ������
    or_money_f RealCompactFee;
    /// ʵʱ��Լ��Ϣ
    or_money_f RealCompactInterest;
    /// �ѻ���Ϣ
    or_money_f RepaidInterest;
    /// �ѻ�����
    or_volume_i RepaidVolume;
    /// �ѻ����
    or_money_f RepaidBalance;
    /// ��Լ��Ϣ
    or_money_f CompactInterest;
    /// ������
    or_rate_f YearRate;
    /// �黹��ֹ����
    or_date_i ReturnEndDate;
    /// ͷ����
    or_cashgroupid_i CashGroupID;
    /// ͷ������
    or_compactsource_e CompactSource;
    /// ��ǩ������
    or_date_i PostPoneEndDate;
    /// ��ծ�ܶ�
    or_money_f TotalDebit;
    /// ��ԼԤ����Ϣ
    or_money_f CompactPreInterest;
    /// ��ѯ������
    or_qtprequestid_i QTPRequestID;
    /// ��ѯ�Ự���
    or_qtpsessionid_i QTPSessionID;
    /// ��ѯǰ�ñ��
    or_qtpfrontid_i QTPFrontID;
    void clear() { memset(this, 0, sizeof(ORCrdtCompactField)); }
    /// initialized to zero
    ORCrdtCompactField() { clear(); }
};
#pragma pack(pop)
using ORCrdtCompactFieldPtr = std::shared_ptr<ORCrdtCompactField>;
ORAPI std::string or_crdtcompact_field_csv_header(const char* delim);
ORAPI std::string or_crdtcompact_field_csv(const char* delim, const ORCrdtCompactField* pCrdtCompact);
ORAPI std::string or_crdtcompact_field_desc(const char* delim, const ORCrdtCompactField* pCrdtCompact);
ORAPI std::string or_crdtcompact_field_json(const ORCrdtCompactField* pCrdtCompact);

/// ��ѯͶ��������ͷ��
#pragma pack(push, 1)
struct ORQryCrdtEnFinFundField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ͷ������
    or_cashgroup_e CashGroup;
    /// ��ѯ������
    or_qtprequestid_i QTPRequestID;
    /// ��ѯ�Ự���
    or_qtpsessionid_i QTPSessionID;
    /// ��ѯǰ�ñ��
    or_qtpfrontid_i QTPFrontID;
    void clear() { memset(this, 0, sizeof(ORQryCrdtEnFinFundField)); }
    /// initialized to zero
    ORQryCrdtEnFinFundField() { clear(); }
};
#pragma pack(pop)
using ORQryCrdtEnFinFundFieldPtr = std::shared_ptr<ORQryCrdtEnFinFundField>;
ORAPI std::string or_qrycrdtenfinfund_field_csv_header(const char* delim);
ORAPI std::string or_qrycrdtenfinfund_field_csv(const char* delim, const ORQryCrdtEnFinFundField* pQryCrdtEnFinFund);
ORAPI std::string or_qrycrdtenfinfund_field_desc(const char* delim, const ORQryCrdtEnFinFundField* pQryCrdtEnFinFund);
ORAPI std::string or_qrycrdtenfinfund_field_json(const ORQryCrdtEnFinFundField* pQryCrdtEnFinFund);

/// ��ѯͶ��������ͷ��ظ�
#pragma pack(push, 1)
struct ORCrdtEnFinFundField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ͷ������
    or_cashgroup_e CashGroup;
    /// �����ʽ�
    or_money_f EnableBalance;
    /// ������
    or_date_i TradingDay;
    /// ��ѯ������
    or_qtprequestid_i QTPRequestID;
    /// ��ѯ�Ự���
    or_qtpsessionid_i QTPSessionID;
    /// ��ѯǰ�ñ��
    or_qtpfrontid_i QTPFrontID;
    void clear() { memset(this, 0, sizeof(ORCrdtEnFinFundField)); }
    /// initialized to zero
    ORCrdtEnFinFundField() { clear(); }
};
#pragma pack(pop)
using ORCrdtEnFinFundFieldPtr = std::shared_ptr<ORCrdtEnFinFundField>;
ORAPI std::string or_crdtenfinfund_field_csv_header(const char* delim);
ORAPI std::string or_crdtenfinfund_field_csv(const char* delim, const ORCrdtEnFinFundField* pCrdtEnFinFund);
ORAPI std::string or_crdtenfinfund_field_desc(const char* delim, const ORCrdtEnFinFundField* pCrdtEnFinFund);
ORAPI std::string or_crdtenfinfund_field_json(const ORCrdtEnFinFundField* pCrdtEnFinFund);

/// ��ѯͶ������ȯͷ��
#pragma pack(push, 1)
struct ORQryCrdtEnSloInstrumentField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ����������
    or_exchangeid_s ExchangeID;
    /// ֤ȯ����
    or_instrumentid_s InstrumentID;
    /// ͷ������
    or_cashgroup_e CashGroup;
    /// ��ѯ������
    or_qtprequestid_i QTPRequestID;
    /// ��ѯ�Ự���
    or_qtpsessionid_i QTPSessionID;
    /// ��ѯǰ�ñ��
    or_qtpfrontid_i QTPFrontID;
    void clear() { memset(this, 0, sizeof(ORQryCrdtEnSloInstrumentField)); }
    /// initialized to zero
    ORQryCrdtEnSloInstrumentField() { clear(); }
};
#pragma pack(pop)
using ORQryCrdtEnSloInstrumentFieldPtr = std::shared_ptr<ORQryCrdtEnSloInstrumentField>;
ORAPI std::string or_qrycrdtensloinstrument_field_csv_header(const char* delim);
ORAPI std::string or_qrycrdtensloinstrument_field_csv(const char* delim, const ORQryCrdtEnSloInstrumentField* pQryCrdtEnSloInstrument);
ORAPI std::string or_qrycrdtensloinstrument_field_desc(const char* delim, const ORQryCrdtEnSloInstrumentField* pQryCrdtEnSloInstrument);
ORAPI std::string or_qrycrdtensloinstrument_field_json(const ORQryCrdtEnSloInstrumentField* pQryCrdtEnSloInstrument);

/// ��ѯͶ������ȯͷ��ظ�
#pragma pack(push, 1)
struct ORCrdtEnSloInstrumentField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ����������
    or_exchangeid_s ExchangeID;
    /// ֤ȯ����
    or_instrumentid_s InstrumentID;
    /// ͷ������
    or_cashgroup_e CashGroup;
    /// ��������
    or_money_f EnableAmount;
    /// ������
    or_date_i TradingDay;
    /// ��ѯ������
    or_qtprequestid_i QTPRequestID;
    /// ��ѯ�Ự���
    or_qtpsessionid_i QTPSessionID;
    /// ��ѯǰ�ñ��
    or_qtpfrontid_i QTPFrontID;
    void clear() { memset(this, 0, sizeof(ORCrdtEnSloInstrumentField)); }
    /// initialized to zero
    ORCrdtEnSloInstrumentField() { clear(); }
};
#pragma pack(pop)
using ORCrdtEnSloInstrumentFieldPtr = std::shared_ptr<ORCrdtEnSloInstrumentField>;
ORAPI std::string or_crdtensloinstrument_field_csv_header(const char* delim);
ORAPI std::string or_crdtensloinstrument_field_csv(const char* delim, const ORCrdtEnSloInstrumentField* pCrdtEnSloInstrument);
ORAPI std::string or_crdtensloinstrument_field_desc(const char* delim, const ORCrdtEnSloInstrumentField* pCrdtEnSloInstrument);
ORAPI std::string or_crdtensloinstrument_field_json(const ORCrdtEnSloInstrumentField* pCrdtEnSloInstrument);

/// ��ѯͶ���������ʲ�
#pragma pack(push, 1)
struct ORQryCrdtClientInfoField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ��ѯ������
    or_qtprequestid_i QTPRequestID;
    /// ��ѯ�Ự���
    or_qtpsessionid_i QTPSessionID;
    /// ��ѯǰ�ñ��
    or_qtpfrontid_i QTPFrontID;
    void clear() { memset(this, 0, sizeof(ORQryCrdtClientInfoField)); }
    /// initialized to zero
    ORQryCrdtClientInfoField() { clear(); }
};
#pragma pack(pop)
using ORQryCrdtClientInfoFieldPtr = std::shared_ptr<ORQryCrdtClientInfoField>;
ORAPI std::string or_qrycrdtclientinfo_field_csv_header(const char* delim);
ORAPI std::string or_qrycrdtclientinfo_field_csv(const char* delim, const ORQryCrdtClientInfoField* pQryCrdtClientInfo);
ORAPI std::string or_qrycrdtclientinfo_field_desc(const char* delim, const ORQryCrdtClientInfoField* pQryCrdtClientInfo);
ORAPI std::string or_qrycrdtclientinfo_field_json(const ORQryCrdtClientInfoField* pQryCrdtClientInfo);

/// ��ѯͶ���������ʲ��ظ�
#pragma pack(push, 1)
struct ORCrdtClientInfoField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ����ά�ֵ�������
    or_ratio_f AssureScale;
    /// ��ȯ����ʹ�ý��
    or_money_f SloUsedBalance;
    /// ��ȯ�������
    or_money_f SloSellBalance;
    /// ��֤��������
    or_money_f Credit;
    /// �򵣱�Ʒ�����ʽ�
    or_money_f AssureEnbuyBalance;
    /// ��ȯ��ȯ�����ʽ�
    or_money_f SloEnrepaidBalance;
    /// �ֽ𻹿�����ʽ�
    or_money_f FinEnrepaidBalance;
    /// ��ѯ������
    or_qtprequestid_i QTPRequestID;
    /// ��ѯ�Ự���
    or_qtpsessionid_i QTPSessionID;
    /// ��ѯǰ�ñ��
    or_qtpfrontid_i QTPFrontID;
    void clear() { memset(this, 0, sizeof(ORCrdtClientInfoField)); }
    /// initialized to zero
    ORCrdtClientInfoField() { clear(); }
};
#pragma pack(pop)
using ORCrdtClientInfoFieldPtr = std::shared_ptr<ORCrdtClientInfoField>;
ORAPI std::string or_crdtclientinfo_field_csv_header(const char* delim);
ORAPI std::string or_crdtclientinfo_field_csv(const char* delim, const ORCrdtClientInfoField* pCrdtClientInfo);
ORAPI std::string or_crdtclientinfo_field_desc(const char* delim, const ORCrdtClientInfoField* pCrdtClientInfo);
ORAPI std::string or_crdtclientinfo_field_json(const ORCrdtClientInfoField* pCrdtClientInfo);

/// ��ѯͶ���߱��֤ȯ��Ϣ
#pragma pack(push, 1)
struct ORQryCrdtTargetStockInfoField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ����������
    or_exchangeid_s ExchangeID;
    /// ֤ȯ����
    or_instrumentid_s InstrumentID;
    void clear() { memset(this, 0, sizeof(ORQryCrdtTargetStockInfoField)); }
    /// initialized to zero
    ORQryCrdtTargetStockInfoField() { clear(); }
};
#pragma pack(pop)
using ORQryCrdtTargetStockInfoFieldPtr = std::shared_ptr<ORQryCrdtTargetStockInfoField>;
ORAPI std::string or_qrycrdttargetstockinfo_field_csv_header(const char* delim);
ORAPI std::string or_qrycrdttargetstockinfo_field_csv(const char* delim, const ORQryCrdtTargetStockInfoField* pQryCrdtTargetStockInfo);
ORAPI std::string or_qrycrdttargetstockinfo_field_desc(const char* delim, const ORQryCrdtTargetStockInfoField* pQryCrdtTargetStockInfo);
ORAPI std::string or_qrycrdttargetstockinfo_field_json(const ORQryCrdtTargetStockInfoField* pQryCrdtTargetStockInfo);

/// ��ѯͶ���߱��֤ȯ��Ϣ�ظ�
#pragma pack(push, 1)
struct ORCrdtTargetStockInfoField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ����������
    or_exchangeid_s ExchangeID;
    /// ֤ȯ����
    or_instrumentid_s InstrumentID;
    /// ���ʱ�֤�����
    or_ratio_f FinRatio;
    /// ���ʸ�������
    or_ratio_f FinFloatRatio;
    /// ����״̬
    or_finstatus_e FinStatus;
    /// ��ȯ��֤�����
    or_ratio_f SloRatio;
    /// ��ȯ��������
    or_ratio_f SloFloatRatio;
    /// ��ȯ״̬
    or_slostatus_e SloStatus;
    void clear() { memset(this, 0, sizeof(ORCrdtTargetStockInfoField)); }
    /// initialized to zero
    ORCrdtTargetStockInfoField() { clear(); }
};
#pragma pack(pop)
using ORCrdtTargetStockInfoFieldPtr = std::shared_ptr<ORCrdtTargetStockInfoField>;
ORAPI std::string or_crdttargetstockinfo_field_csv_header(const char* delim);
ORAPI std::string or_crdttargetstockinfo_field_csv(const char* delim, const ORCrdtTargetStockInfoField* pCrdtTargetStockInfo);
ORAPI std::string or_crdttargetstockinfo_field_desc(const char* delim, const ORCrdtTargetStockInfoField* pCrdtTargetStockInfo);
ORAPI std::string or_crdttargetstockinfo_field_json(const ORCrdtTargetStockInfoField* pCrdtTargetStockInfo);

/// ��ѯͶ���ߵ���֤ȯ��Ϣ
#pragma pack(push, 1)
struct ORQryCrdtStockInfoField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ����������
    or_exchangeid_s ExchangeID;
    /// ֤ȯ����
    or_instrumentid_s InstrumentID;
    void clear() { memset(this, 0, sizeof(ORQryCrdtStockInfoField)); }
    /// initialized to zero
    ORQryCrdtStockInfoField() { clear(); }
};
#pragma pack(pop)
using ORQryCrdtStockInfoFieldPtr = std::shared_ptr<ORQryCrdtStockInfoField>;
ORAPI std::string or_qrycrdtstockinfo_field_csv_header(const char* delim);
ORAPI std::string or_qrycrdtstockinfo_field_csv(const char* delim, const ORQryCrdtStockInfoField* pQryCrdtStockInfo);
ORAPI std::string or_qrycrdtstockinfo_field_desc(const char* delim, const ORQryCrdtStockInfoField* pQryCrdtStockInfo);
ORAPI std::string or_qrycrdtstockinfo_field_json(const ORQryCrdtStockInfoField* pQryCrdtStockInfo);

/// ��ѯͶ���ߵ���֤ȯ��Ϣ�ظ�
#pragma pack(push, 1)
struct ORCrdtStockInfoField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ����������
    or_exchangeid_s ExchangeID;
    /// ֤ȯ����
    or_instrumentid_s InstrumentID;
    /// ����������
    or_ratio_f AssureRatio;
    /// ��������
    or_ratio_f FloatRatio;
    /// ����Ʒ״̬
    or_assurestatus_e AssureStatus;
    void clear() { memset(this, 0, sizeof(ORCrdtStockInfoField)); }
    /// initialized to zero
    ORCrdtStockInfoField() { clear(); }
};
#pragma pack(pop)
using ORCrdtStockInfoFieldPtr = std::shared_ptr<ORCrdtStockInfoField>;
ORAPI std::string or_crdtstockinfo_field_csv_header(const char* delim);
ORAPI std::string or_crdtstockinfo_field_csv(const char* delim, const ORCrdtStockInfoField* pCrdtStockInfo);
ORAPI std::string or_crdtstockinfo_field_desc(const char* delim, const ORCrdtStockInfoField* pCrdtStockInfo);
ORAPI std::string or_crdtstockinfo_field_json(const ORCrdtStockInfoField* pCrdtStockInfo);

/// ��Լ
#pragma pack(push, 1)
struct ORInstrumentField
{
    /// ����������
    or_exchangeid_s ExchangeID;
    /// ��Ʒ����
    or_productid_s ProductID;
    /// ֤ȯ����
    or_instrumentid_s InstrumentID;
    /// ֤ȯ���״���
    or_instrumentcode_s InstrumentCode;
    /// ��Լ����
    or_instrumentname_s InstrumentName;
    /// ֤ȯ���
    or_productclass_e ProductClass;
    /// ��Լ��������
    or_volumemultiple_i VolumeMultiple;
    /// ��С�䶯��λ
    or_price_f PriceTick;
    /// ������
    or_date_i OpenDate;
    /// ������
    or_date_i ExpireDate;
    /// ��ǰ�Ƿ���
    or_istrading_b IsTrading;
    /// ��Ȩִ�м۸�
    or_price_f ExecPrice;
    /// ��Ȩ���ֱ�֤��
    or_money_f UnitMargin;
    /// ������
    or_date_i TradingDay;
    /// ��Ȩ��
    or_date_i ExerciseDay;
    /// ��ʼ������
    or_date_i StartDeliveryDay;
    /// ����������
    or_date_i EndDeliveryDay;
    /// �м�����µ���
    or_volume_i MaxMarketOrderVolume;
    /// �м���С�µ���
    or_volume_i MinMarketOrderVolume;
    /// �޼�����µ���
    or_volume_i MaxLimitOrderVolume;
    /// �޼���С�µ���
    or_volume_i MinLimitOrderVolume;
    /// ��ͣ���
    or_price_f UpperLimitPrice;
    /// ��ͣ���
    or_price_f LowerLimitPrice;
    /// ��Ȩ����
    or_optionstype_e OptionsType;
    /// ��С����䶯����
    or_volume_i BuyVolumeTick;
    /// ��С�����䶯����
    or_volume_i SellVolumeTick;
    /// ������Ʒ����
    or_instrumentid_s UnderlyingInstrumentID;
    /// �ر�֤ȯ��־
    or_stockrealback_e StockRealBack;
    /// �ر��ʽ��־
    or_fundrealback_e FundRealBack;
    /// ������Ʒ����
    or_underlyingmultiple_i UnderlyingMultiple;
    /// �����̼�
    or_price_f PreClosePrice;
    /// �ϴν����
    or_price_f PreSettlementPrice;
    /// �ٽ����ڱ�֤���ϸ�����
    or_ratio_f MarginRatioExpiring;
    void clear() { memset(this, 0, sizeof(ORInstrumentField)); }
    /// initialized to zero
    ORInstrumentField() { clear(); }
};
#pragma pack(pop)
using ORInstrumentFieldPtr = std::shared_ptr<ORInstrumentField>;
ORAPI std::string or_instrument_field_csv_header(const char* delim);
ORAPI std::string or_instrument_field_csv(const char* delim, const ORInstrumentField* pInstrument);
ORAPI std::string or_instrument_field_desc(const char* delim, const ORInstrumentField* pInstrument);
ORAPI std::string or_instrument_field_json(const ORInstrumentField* pInstrument);

/// ��ѯ��Ʒ��֤ȯ����ͺ�Լ��Ϣ
#pragma pack(push, 1)
struct ORQryInstrumentField
{
    /// ��Լ����
    or_instrumentid_s InstrumentID;
    /// ����������
    or_exchangeid_s ExchangeID;
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    void clear() { memset(this, 0, sizeof(ORQryInstrumentField)); }
    /// initialized to zero
    ORQryInstrumentField() { clear(); }
};
#pragma pack(pop)
using ORQryInstrumentFieldPtr = std::shared_ptr<ORQryInstrumentField>;
ORAPI std::string or_qryinstrument_field_csv_header(const char* delim);
ORAPI std::string or_qryinstrument_field_csv(const char* delim, const ORQryInstrumentField* pQryInstrument);
ORAPI std::string or_qryinstrument_field_desc(const char* delim, const ORQryInstrumentField* pQryInstrument);
ORAPI std::string or_qryinstrument_field_json(const ORQryInstrumentField* pQryInstrument);

/// ��ѯ֤ȯ����
#pragma pack(push, 1)
struct ORQryStockCodeField
{
    /// ��Լ����
    or_instrumentid_s InstrumentID;
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ����������
    or_exchangeid_s ExchangeID;
    void clear() { memset(this, 0, sizeof(ORQryStockCodeField)); }
    /// initialized to zero
    ORQryStockCodeField() { clear(); }
};
#pragma pack(pop)
using ORQryStockCodeFieldPtr = std::shared_ptr<ORQryStockCodeField>;
ORAPI std::string or_qrystockcode_field_csv_header(const char* delim);
ORAPI std::string or_qrystockcode_field_csv(const char* delim, const ORQryStockCodeField* pQryStockCode);
ORAPI std::string or_qrystockcode_field_desc(const char* delim, const ORQryStockCodeField* pQryStockCode);
ORAPI std::string or_qrystockcode_field_json(const ORQryStockCodeField* pQryStockCode);

/// ��ѯ֤ȯ�����ظ�
#pragma pack(push, 1)
struct ORRspStockCodeField
{
    /// ��Լ����
    or_instrumentid_s InstrumentID;
    /// �ر�֤ȯ��־
    or_stockrealback_e StockRealBack;
    /// �ر��ʽ��־
    or_fundrealback_e FundRealBack;
    /// ����������
    or_exchangeid_s ExchangeID;
    /// ��Ʒ����
    or_productid_s ProductID;
    /// ֤ȯ���״���
    or_instrumentcode_s InstrumentCode;
    /// ��Լ����
    or_instrumentname_s InstrumentName;
    /// ��Լ�ڽ������Ĵ���
    or_exchangeinstid_s ExchangeInstID;
    /// ֤ȯ���
    or_productclass_e ProductClass;
    /// ��Լ��������
    or_volumemultiple_i VolumeMultiple;
    /// ��С�䶯��λ
    or_price_f PriceTick;
    /// ������
    or_date_i OpenDate;
    /// ������
    or_date_i ExpireDate;
    /// ��ǰ�Ƿ���
    or_istrading_b IsTrading;
    /// ��Ȩִ�м۸�
    or_price_f ExecPrice;
    /// ��Ȩ���ֱ�֤��
    or_money_f UnitMargin;
    /// ������
    or_date_i TradingDay;
    /// ��Ȩ��
    or_date_i ExerciseDay;
    /// ��ʼ������
    or_date_i StartDeliveryDay;
    /// ����������
    or_date_i EndDeliveryDay;
    /// �м�����µ���
    or_volume_i MaxMarketOrderVolume;
    /// �м���С�µ���
    or_volume_i MinMarketOrderVolume;
    /// �޼�����µ���
    or_volume_i MaxLimitOrderVolume;
    /// �޼���С�µ���
    or_volume_i MinLimitOrderVolume;
    /// ��Ȩ����
    or_optionstype_e OptionsType;
    /// ��С����䶯����
    or_volume_i BuyVolumeTick;
    /// ��С�����䶯����
    or_volume_i SellVolumeTick;
    /// ������Ʒ����
    or_underlyingmultiple_i UnderlyingMultiple;
    /// �����̼�
    or_price_f PreClosePrice;
    /// �ϴν����
    or_price_f PreSettlementPrice;
    /// �ٽ����ڱ�֤���ϸ�����
    or_ratio_f MarginRatioExpiring;
    /// �������
    or_year_i DeliveryYear;
    /// ������
    or_month_i DeliveryMonth;
    /// ��Լ��������״̬
    or_instlifephase_e InstLifePhase;
    /// �ֲ�����
    or_positiontype_e PositionType;
    /// �Ƿ�ʹ����ʷ�ֲ�
    or_positionhistorytype_e PositionHistoryType;
    /// ��ͷ��֤����
    or_ratio_f LongMarginRatioByMoney;
    /// ��ͷ��֤���
    or_ratio_f LongMarginRatioByVolume;
    /// ��ͷ��֤����
    or_ratio_f ShortMarginRatioByMoney;
    /// ��ͷ��֤���
    or_ratio_f ShortMarginRatioByVolume;
    /// �Ƿ�ʹ�ô��߱�֤���㷨
    or_maxmarginsidealgorithm_e MaxMarginSideAlgorithm;
    /// ������Ʒ����
    or_instrumentid_s UnderlyingInstrumentID;
    /// ִ�м�
    or_price_f StrikePrice;
    /// �������
    or_combinationtype_e CombinationType;
    void clear() { memset(this, 0, sizeof(ORRspStockCodeField)); }
    /// initialized to zero
    ORRspStockCodeField() { clear(); }
};
#pragma pack(pop)
using ORRspStockCodeFieldPtr = std::shared_ptr<ORRspStockCodeField>;
ORAPI std::string or_rspstockcode_field_csv_header(const char* delim);
ORAPI std::string or_rspstockcode_field_csv(const char* delim, const ORRspStockCodeField* pRspStockCode);
ORAPI std::string or_rspstockcode_field_desc(const char* delim, const ORRspStockCodeField* pRspStockCode);
ORAPI std::string or_rspstockcode_field_json(const ORRspStockCodeField* pRspStockCode);

/// ��ѯ�¹��깺���
#pragma pack(push, 1)
struct ORQryStockPurQuotationField
{
    /// ����������
    or_exchangeid_s ExchangeID;
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// �˻���Ϣ
    or_accountinfo_s AccountInfo;
    void clear() { memset(this, 0, sizeof(ORQryStockPurQuotationField)); }
    /// initialized to zero
    ORQryStockPurQuotationField() { clear(); }
};
#pragma pack(pop)
using ORQryStockPurQuotationFieldPtr = std::shared_ptr<ORQryStockPurQuotationField>;
ORAPI std::string or_qrystockpurquotation_field_csv_header(const char* delim);
ORAPI std::string or_qrystockpurquotation_field_csv(const char* delim, const ORQryStockPurQuotationField* pQryStockPurQuotation);
ORAPI std::string or_qrystockpurquotation_field_desc(const char* delim, const ORQryStockPurQuotationField* pQryStockPurQuotation);
ORAPI std::string or_qrystockpurquotation_field_json(const ORQryStockPurQuotationField* pQryStockPurQuotation);

/// ��ѯ�¹��깺���
#pragma pack(push, 1)
struct ORStockPurQuotationField
{
    /// ����������
    or_exchangeid_s ExchangeID;
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ������깺���
    or_money_f EnableAmount;
    /// �ƴ�����깺���
    or_money_f StibEnableAmount;
    void clear() { memset(this, 0, sizeof(ORStockPurQuotationField)); }
    /// initialized to zero
    ORStockPurQuotationField() { clear(); }
};
#pragma pack(pop)
using ORStockPurQuotationFieldPtr = std::shared_ptr<ORStockPurQuotationField>;
ORAPI std::string or_stockpurquotation_field_csv_header(const char* delim);
ORAPI std::string or_stockpurquotation_field_csv(const char* delim, const ORStockPurQuotationField* pStockPurQuotation);
ORAPI std::string or_stockpurquotation_field_desc(const char* delim, const ORStockPurQuotationField* pStockPurQuotation);
ORAPI std::string or_stockpurquotation_field_json(const ORStockPurQuotationField* pStockPurQuotation);

/// ��ѯ�¹��깺������Ϣ
#pragma pack(push, 1)
struct ORQryStockPurInfoField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    void clear() { memset(this, 0, sizeof(ORQryStockPurInfoField)); }
    /// initialized to zero
    ORQryStockPurInfoField() { clear(); }
};
#pragma pack(pop)
using ORQryStockPurInfoFieldPtr = std::shared_ptr<ORQryStockPurInfoField>;
ORAPI std::string or_qrystockpurinfo_field_csv_header(const char* delim);
ORAPI std::string or_qrystockpurinfo_field_csv(const char* delim, const ORQryStockPurInfoField* pQryStockPurInfo);
ORAPI std::string or_qrystockpurinfo_field_desc(const char* delim, const ORQryStockPurInfoField* pQryStockPurInfo);
ORAPI std::string or_qrystockpurinfo_field_json(const ORQryStockPurInfoField* pQryStockPurInfo);

/// ��ѯ�¹��깺������Ϣ
#pragma pack(push, 1)
struct ORStockPurInfoField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ����������
    or_exchangeid_s ExchangeID;
    /// ��Լ����
    or_instrumentid_s InstrumentID;
    /// ����깺����
    or_volume_i HighQuantity;
    /// ����깺����
    or_volume_i LowQuantity;
    void clear() { memset(this, 0, sizeof(ORStockPurInfoField)); }
    /// initialized to zero
    ORStockPurInfoField() { clear(); }
};
#pragma pack(pop)
using ORStockPurInfoFieldPtr = std::shared_ptr<ORStockPurInfoField>;
ORAPI std::string or_stockpurinfo_field_csv_header(const char* delim);
ORAPI std::string or_stockpurinfo_field_csv(const char* delim, const ORStockPurInfoField* pStockPurInfo);
ORAPI std::string or_stockpurinfo_field_desc(const char* delim, const ORStockPurInfoField* pStockPurInfo);
ORAPI std::string or_stockpurinfo_field_json(const ORStockPurInfoField* pStockPurInfo);

/// ��ѯ�¹��깺������Ϣ
#pragma pack(push, 1)
struct ORQryStockPurStatisticsField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ����������
    or_exchangeid_s ExchangeID;
    void clear() { memset(this, 0, sizeof(ORQryStockPurStatisticsField)); }
    /// initialized to zero
    ORQryStockPurStatisticsField() { clear(); }
};
#pragma pack(pop)
using ORQryStockPurStatisticsFieldPtr = std::shared_ptr<ORQryStockPurStatisticsField>;
ORAPI std::string or_qrystockpurstatistics_field_csv_header(const char* delim);
ORAPI std::string or_qrystockpurstatistics_field_csv(const char* delim, const ORQryStockPurStatisticsField* pQryStockPurStatistics);
ORAPI std::string or_qrystockpurstatistics_field_desc(const char* delim, const ORQryStockPurStatisticsField* pQryStockPurStatistics);
ORAPI std::string or_qrystockpurstatistics_field_json(const ORQryStockPurStatisticsField* pQryStockPurStatistics);

/// ��ѯ�¹��깺������Ϣ
#pragma pack(push, 1)
struct ORStockPurStatisticsField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ����������
    or_exchangeid_s ExchangeID;
    /// ��Լ����
    or_instrumentid_s InstrumentID;
    /// �깺����
    or_collectcode_s CollectCode;
    /// �깺����
    or_volume_i AppAmount;
    /// ��ǩ״̬
    or_luckystatus_e LuckyStatus;
    /// ��ǩ����
    or_volume_i LuckyVolume;
    /// ��ǩ���
    or_money_f LuckyAmount;
    void clear() { memset(this, 0, sizeof(ORStockPurStatisticsField)); }
    /// initialized to zero
    ORStockPurStatisticsField() { clear(); }
};
#pragma pack(pop)
using ORStockPurStatisticsFieldPtr = std::shared_ptr<ORStockPurStatisticsField>;
ORAPI std::string or_stockpurstatistics_field_csv_header(const char* delim);
ORAPI std::string or_stockpurstatistics_field_csv(const char* delim, const ORStockPurStatisticsField* pStockPurStatistics);
ORAPI std::string or_stockpurstatistics_field_desc(const char* delim, const ORStockPurStatisticsField* pStockPurStatistics);
ORAPI std::string or_stockpurstatistics_field_json(const ORStockPurStatisticsField* pStockPurStatistics);

/// ����ͨ����¼�ɹ�
#pragma pack(push, 1)
struct ORRspLoginField
{
    /// ����ͨ�����
    or_channelid_i ChannelID;
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// �ͻ���
    or_clientid_s ClientID;
    /// ������
    or_date_i TradingDay;
    /// Ӫҵ������
    or_branchid_s BranchID;
    /// O32��¼����
    or_o32usertoken_s O32UserToken;
    /// O32-UFX�汾
    or_o32versionno_s O32VersionNo;
    /// �ʽ��˻�����
    or_accountcode_s AccountCode;
    void clear() { memset(this, 0, sizeof(ORRspLoginField)); }
    /// initialized to zero
    ORRspLoginField() { clear(); }
};
#pragma pack(pop)
using ORRspLoginFieldPtr = std::shared_ptr<ORRspLoginField>;
ORAPI std::string or_rsplogin_field_csv_header(const char* delim);
ORAPI std::string or_rsplogin_field_csv(const char* delim, const ORRspLoginField* pRspLogin);
ORAPI std::string or_rsplogin_field_desc(const char* delim, const ORRspLoginField* pRspLogin);
ORAPI std::string or_rsplogin_field_json(const ORRspLoginField* pRspLogin);

/// ��¼��̨�ʽ��ʺ�����
#pragma pack(push, 1)
struct ORReqLoginField
{
    /// ����ͨ�����
    or_channelid_i ChannelID;
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ��¼����MAC��ַ
    or_loginmac_s LoginMAC;
    /// ��¼����IP��ַ
    or_loginip_s LoginIp;
    /// ��¼����Ӳ�����к�
    or_orderhdvolserial_s OrderHdVolSerial;
    /// ����
    or_password_s Password;
    /// �ʽ��˻�����
    or_accountcode_s AccountCode;
    /// ҵ����
    or_enbflag_e EnbFlag;
    void clear() { memset(this, 0, sizeof(ORReqLoginField)); }
    /// initialized to zero
    ORReqLoginField() { clear(); }
};
#pragma pack(pop)
using ORReqLoginFieldPtr = std::shared_ptr<ORReqLoginField>;
ORAPI std::string or_reqlogin_field_csv_header(const char* delim);
ORAPI std::string or_reqlogin_field_csv(const char* delim, const ORReqLoginField* pReqLogin);
ORAPI std::string or_reqlogin_field_desc(const char* delim, const ORReqLoginField* pReqLogin);
ORAPI std::string or_reqlogin_field_json(const ORReqLoginField* pReqLogin);

/// �ʽ𻮲�
#pragma pack(push, 1)
struct ORAssetTransferField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ����׼����
    or_money_f Balance;
    /// �ʽ𻮲���Ϣ
    or_transferinfo_s TransferInfo;
    /// �ʽ𻮲�����
    or_transferdirection_e TransferDirection;
    /// ���
    or_sequenceno_i SequenceNo;
    void clear() { memset(this, 0, sizeof(ORAssetTransferField)); }
    /// initialized to zero
    ORAssetTransferField() { clear(); }
};
#pragma pack(pop)
using ORAssetTransferFieldPtr = std::shared_ptr<ORAssetTransferField>;
ORAPI std::string or_assettransfer_field_csv_header(const char* delim);
ORAPI std::string or_assettransfer_field_csv(const char* delim, const ORAssetTransferField* pAssetTransfer);
ORAPI std::string or_assettransfer_field_desc(const char* delim, const ORAssetTransferField* pAssetTransfer);
ORAPI std::string or_assettransfer_field_json(const ORAssetTransferField* pAssetTransfer);

/// ����ȷ��
#pragma pack(push, 1)
struct ORRspOrderCancelField
{
    /// OrderRouterί�б��
    or_orrequestid_i ORRequestID;
    /// ��̨�������
    or_counterorderid_s CounterOrderID;
    /// ���ù�̨�������
    or_refcounterorderid_s RefCounterOrderID;
    /// ���ý������������
    or_ordersysid_s RefOrderSysID;
    /// ϯλ��
    or_seatid_s SeatID;
    void clear() { memset(this, 0, sizeof(ORRspOrderCancelField)); }
    /// initialized to zero
    ORRspOrderCancelField() { clear(); }
};
#pragma pack(pop)
using ORRspOrderCancelFieldPtr = std::shared_ptr<ORRspOrderCancelField>;
ORAPI std::string or_rspordercancel_field_csv_header(const char* delim);
ORAPI std::string or_rspordercancel_field_csv(const char* delim, const ORRspOrderCancelField* pRspOrderCancel);
ORAPI std::string or_rspordercancel_field_desc(const char* delim, const ORRspOrderCancelField* pRspOrderCancel);
ORAPI std::string or_rspordercancel_field_json(const ORRspOrderCancelField* pRspOrderCancel);

/// ��̨ί��ȷ��
#pragma pack(push, 1)
struct ORRspOrderInsertField
{
    /// OrderRouterί�б��
    or_orrequestid_i ORRequestID;
    /// ��̨�������
    or_counterorderid_s CounterOrderID;
    /// �������
    or_ordersysid_s OrderSysID;
    /// ϯλ��
    or_seatid_s SeatID;
    void clear() { memset(this, 0, sizeof(ORRspOrderInsertField)); }
    /// initialized to zero
    ORRspOrderInsertField() { clear(); }
};
#pragma pack(pop)
using ORRspOrderInsertFieldPtr = std::shared_ptr<ORRspOrderInsertField>;
ORAPI std::string or_rsporderinsert_field_csv_header(const char* delim);
ORAPI std::string or_rsporderinsert_field_csv(const char* delim, const ORRspOrderInsertField* pRspOrderInsert);
ORAPI std::string or_rsporderinsert_field_desc(const char* delim, const ORRspOrderInsertField* pRspOrderInsert);
ORAPI std::string or_rsporderinsert_field_json(const ORRspOrderInsertField* pRspOrderInsert);

/// �ʽ�ת�ظ�
#pragma pack(push, 1)
struct ORRspAssetTransferField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// �������
    or_errorid_ei ErrorID;
    /// ������Ϣ
    or_errormsg_s ErrorMsg;
    /// ���
    or_sequenceno_i SequenceNo;
    void clear() { memset(this, 0, sizeof(ORRspAssetTransferField)); }
    /// initialized to zero
    ORRspAssetTransferField() { clear(); }
};
#pragma pack(pop)
using ORRspAssetTransferFieldPtr = std::shared_ptr<ORRspAssetTransferField>;
ORAPI std::string or_rspassettransfer_field_csv_header(const char* delim);
ORAPI std::string or_rspassettransfer_field_csv(const char* delim, const ORRspAssetTransferField* pRspAssetTransfer);
ORAPI std::string or_rspassettransfer_field_desc(const char* delim, const ORRspAssetTransferField* pRspAssetTransfer);
ORAPI std::string or_rspassettransfer_field_json(const ORRspAssetTransferField* pRspAssetTransfer);

/// У���˺ſ���
#pragma pack(push, 1)
struct ORCheckAccountField
{
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ���
    or_sequenceno_i SequenceNo;
    /// �ʽ��˻�����
    or_accountcode_s AccountCode;
    /// ����
    or_password_s Password;
    /// ����ͨ�����
    or_channelid_i ChannelID;
    /// ҵ����
    or_enbflag_e EnbFlag;
    void clear() { memset(this, 0, sizeof(ORCheckAccountField)); }
    /// initialized to zero
    ORCheckAccountField() { clear(); }
};
#pragma pack(pop)
using ORCheckAccountFieldPtr = std::shared_ptr<ORCheckAccountField>;
ORAPI std::string or_checkaccount_field_csv_header(const char* delim);
ORAPI std::string or_checkaccount_field_csv(const char* delim, const ORCheckAccountField* pCheckAccount);
ORAPI std::string or_checkaccount_field_desc(const char* delim, const ORCheckAccountField* pCheckAccount);
ORAPI std::string or_checkaccount_field_json(const ORCheckAccountField* pCheckAccount);

/// UFT20��ص�����
#pragma pack(push, 1)
struct ORUft20ConfigField
{
    /// �����̨��IP�Ͷ˿ں��б�
    or_ufxt2sdkservers_s UfxT2sdkServers;
    /// ���֤�ļ�����
    or_ufxt2sdklicensefilename_s UfxT2sdkLicenseFileName;
    /// ���֤����
    or_ufxt2sdklicensepwd_s UfxT2sdkLicensePwd;
    /// �Զ�����
    or_ufxt2sdkautoconnect_b UfxT2sdkAutoConnect;
    /// ί�з�ʽ
    or_ufxt2sdkentrustway_e UfxT2sdkEntrustWay;
    /// UFT20��̨BatchNoƫ����
    or_ufxbatchnooffset_i UfxBatchNoOffset;
    /// ʹ��UF20��̨�Ĺ��ܺ�
    or_uft20uf20functions_s Uft20UF20Functions;
    /// UF20ϵͳ��
    or_uft20uf20systemno_i Uft20UF20SystemNo;
    /// UFT2ϵͳ��
    or_uft20uft2systemno_i Uft20UFT2SystemNo;
    /// �Զ���ѯ���׺�ί�е�ʱ����
    or_uft20syncinterval_i Uft20SyncInterval;
    /// T2SDK�շ���־����
    or_ufxt2sdksendrecvlog_b UfxT2sdkSendRecvLog;
    void clear() { memset(this, 0, sizeof(ORUft20ConfigField)); }
    /// initialized to zero
    ORUft20ConfigField() { clear(); }
};
#pragma pack(pop)
using ORUft20ConfigFieldPtr = std::shared_ptr<ORUft20ConfigField>;
ORAPI std::string or_uft20config_field_csv_header(const char* delim);
ORAPI std::string or_uft20config_field_csv(const char* delim, const ORUft20ConfigField* pUft20Config);
ORAPI std::string or_uft20config_field_desc(const char* delim, const ORUft20ConfigField* pUft20Config);
ORAPI std::string or_uft20config_field_json(const ORUft20ConfigField* pUft20Config);

/// O32��ص�����
#pragma pack(push, 1)
struct ORO32ConfigField
{
    /// ���֤�ļ�����
    or_ufxt2sdklicensefilename_s UfxT2sdkLicenseFileName;
    /// ���֤����
    or_ufxt2sdklicensepwd_s UfxT2sdkLicensePwd;
    /// �Զ�����
    or_ufxt2sdkautoconnect_b UfxT2sdkAutoConnect;
    /// ί�з�ʽ
    or_ufxt2sdkentrustway_e UfxT2sdkEntrustWay;
    /// UFT20��̨BatchNoƫ����
    or_ufxbatchnooffset_i UfxBatchNoOffset;
    /// �����̨��IP�Ͷ˿ں��б�
    or_ufxt2sdkservers_s UfxT2sdkServers;
    /// O32���ķ�����
    or_o32subscribeservers_s O32SubscribeServers;
    /// ��������
    or_o32topicname_s O32TopicName;
    /// ҵ������
    or_o32bizname_s O32BizName;
    /// O32��������Ȩ���
    or_o32authorizationid_s O32AuthorizationId;
    /// T2SDK�շ���־����
    or_ufxt2sdksendrecvlog_b UfxT2sdkSendRecvLog;
    /// �ͻ���ID
    or_o32appid_s O32AppID;
    /// �ն���Ȩ��
    or_o32authorizecode_s O32AuthorizeCode;
    /// ����˿�
    or_o32portid_i O32PortID;
    void clear() { memset(this, 0, sizeof(ORO32ConfigField)); }
    /// initialized to zero
    ORO32ConfigField() { clear(); }
};
#pragma pack(pop)
using ORO32ConfigFieldPtr = std::shared_ptr<ORO32ConfigField>;
ORAPI std::string or_o32config_field_csv_header(const char* delim);
ORAPI std::string or_o32config_field_csv(const char* delim, const ORO32ConfigField* pO32Config);
ORAPI std::string or_o32config_field_desc(const char* delim, const ORO32ConfigField* pO32Config);
ORAPI std::string or_o32config_field_json(const ORO32ConfigField* pO32Config);

/// ģ�⽻������������
#pragma pack(push, 1)
struct ORMockMarketConfigField
{
    /// ģ�⽻����������IP��ַ
    or_ipv4address_s MockMarketServerAddress;
    /// ģ�⽻����������IP�˿�
    or_ipv4port_i MockMarketServerPort;
    void clear() { memset(this, 0, sizeof(ORMockMarketConfigField)); }
    /// initialized to zero
    ORMockMarketConfigField() { clear(); }
};
#pragma pack(pop)
using ORMockMarketConfigFieldPtr = std::shared_ptr<ORMockMarketConfigField>;
ORAPI std::string or_mockmarketconfig_field_csv_header(const char* delim);
ORAPI std::string or_mockmarketconfig_field_csv(const char* delim, const ORMockMarketConfigField* pMockMarketConfig);
ORAPI std::string or_mockmarketconfig_field_desc(const char* delim, const ORMockMarketConfigField* pMockMarketConfig);
ORAPI std::string or_mockmarketconfig_field_json(const ORMockMarketConfigField* pMockMarketConfig);

/// ģ���̨��������
#pragma pack(push, 1)
struct ORMockCounterConfigField
{
    /// ģ���̨������IP��ַ
    or_ipv4address_s MockCounterServerAddress;
    /// ģ���̨������IP�˿�
    or_ipv4port_i MockCounterServerPort;
    void clear() { memset(this, 0, sizeof(ORMockCounterConfigField)); }
    /// initialized to zero
    ORMockCounterConfigField() { clear(); }
};
#pragma pack(pop)
using ORMockCounterConfigFieldPtr = std::shared_ptr<ORMockCounterConfigField>;
ORAPI std::string or_mockcounterconfig_field_csv_header(const char* delim);
ORAPI std::string or_mockcounterconfig_field_csv(const char* delim, const ORMockCounterConfigField* pMockCounterConfig);
ORAPI std::string or_mockcounterconfig_field_desc(const char* delim, const ORMockCounterConfigField* pMockCounterConfig);
ORAPI std::string or_mockcounterconfig_field_json(const ORMockCounterConfigField* pMockCounterConfig);

/// STP��Ȩ��̨����������
#pragma pack(push, 1)
struct ORStpOptionServerConfigField
{
    /// STP��Ȩ��̨��������ַ
    or_ipv4address_s StpOptionServerAddress;
    /// STP��Ȩ��̨�������˿�
    or_ipv4port_i StpOptionServerPort;
    void clear() { memset(this, 0, sizeof(ORStpOptionServerConfigField)); }
    /// initialized to zero
    ORStpOptionServerConfigField() { clear(); }
};
#pragma pack(pop)
using ORStpOptionServerConfigFieldPtr = std::shared_ptr<ORStpOptionServerConfigField>;
ORAPI std::string or_stpoptionserverconfig_field_csv_header(const char* delim);
ORAPI std::string or_stpoptionserverconfig_field_csv(const char* delim, const ORStpOptionServerConfigField* pStpOptionServerConfig);
ORAPI std::string or_stpoptionserverconfig_field_desc(const char* delim, const ORStpOptionServerConfigField* pStpOptionServerConfig);
ORAPI std::string or_stpoptionserverconfig_field_json(const ORStpOptionServerConfigField* pStpOptionServerConfig);

/// QMT��ǿ��������
#pragma pack(push, 1)
struct ORQmtEnhanceConfigField
{
    /// QMT��ǿģ���ʶ
    or_qmtenhancemoduletag_s QmtEnhanceModuleTag;
    void clear() { memset(this, 0, sizeof(ORQmtEnhanceConfigField)); }
    /// initialized to zero
    ORQmtEnhanceConfigField() { clear(); }
};
#pragma pack(pop)
using ORQmtEnhanceConfigFieldPtr = std::shared_ptr<ORQmtEnhanceConfigField>;
ORAPI std::string or_qmtenhanceconfig_field_csv_header(const char* delim);
ORAPI std::string or_qmtenhanceconfig_field_csv(const char* delim, const ORQmtEnhanceConfigField* pQmtEnhanceConfig);
ORAPI std::string or_qmtenhanceconfig_field_desc(const char* delim, const ORQmtEnhanceConfigField* pQmtEnhanceConfig);
ORAPI std::string or_qmtenhanceconfig_field_json(const ORQmtEnhanceConfigField* pQmtEnhanceConfig);

/// TradeX��������
#pragma pack(push, 1)
struct ORTradeXConfigField
{
    /// ֤ȯ��˾TDX���
    or_tdxcompanyid_i TdxCompanyID;
    /// ͨ���ſͻ��˵İ汾��
    or_tdxclientversion_s TdxClientVersion;
    /// ͨ���Ų�ѯ˯��ʱ��
    or_tdxsleepmsqry_i TdxSleepMsQry;
    /// ͨ���Ž���˯��ʱ��
    or_tdxsleepmstrd_i TdxSleepMsTrd;
    /// ʹ�õ���Ʒ����
    or_buysellcollateral_i BuySellCollateral;
    /// ʹ�÷�ҳ��ѯ
    or_tdxpagedquery_i TdxPagedQuery;
    /// Broker IND
    or_tdxbrokerind_s TdxBrokerIND;
    /// ��̨������֤���ѯ�ֲ�ί�гɽ�
    or_startupqryposordertrade_b StartupQryPosOrderTrade;
    void clear() { memset(this, 0, sizeof(ORTradeXConfigField)); }
    /// initialized to zero
    ORTradeXConfigField() { clear(); }
};
#pragma pack(pop)
using ORTradeXConfigFieldPtr = std::shared_ptr<ORTradeXConfigField>;
ORAPI std::string or_tradexconfig_field_csv_header(const char* delim);
ORAPI std::string or_tradexconfig_field_csv(const char* delim, const ORTradeXConfigField* pTradeXConfig);
ORAPI std::string or_tradexconfig_field_desc(const char* delim, const ORTradeXConfigField* pTradeXConfig);
ORAPI std::string or_tradexconfig_field_json(const ORTradeXConfigField* pTradeXConfig);

/// CTP��������
#pragma pack(push, 1)
struct ORCtpConfigField
{
    /// CTP������������
    or_ctprunningmode_s CtpRunningMode;
    /// ���׽����ַ
    or_ctptradeaddr_s CtpTradeAddr;
    /// ��������ַ
    or_ctpmdaddr_s CtpMdAddr;
    /// �����̱��
    or_brokerid_s BrokerID;
    /// �û���֤��
    or_ctpauthcode_s CtpAuthCode;
    /// Ӧ�ñ��
    or_ctpappid_s CtpAppId;
    /// ��Ʒ��Ϣ
    or_ctpproductinfo_s CtpProductInfo;
    /// ��̨������֤���ѯ�ֲ�ί�гɽ�
    or_startupqryposordertrade_b StartupQryPosOrderTrade;
    /// ƽ��ʱ�Զ�����ƽ��ƽ��
    or_closehistorytype_e CloseHistoryType;
    /// ���յ��ѳ�ί��ʱ���в���
    or_faketradeonrtnorder_b FakeTradeOnRtnOrder;
    void clear() { memset(this, 0, sizeof(ORCtpConfigField)); }
    /// initialized to zero
    ORCtpConfigField() { clear(); }
};
#pragma pack(pop)
using ORCtpConfigFieldPtr = std::shared_ptr<ORCtpConfigField>;
ORAPI std::string or_ctpconfig_field_csv_header(const char* delim);
ORAPI std::string or_ctpconfig_field_csv(const char* delim, const ORCtpConfigField* pCtpConfig);
ORAPI std::string or_ctpconfig_field_desc(const char* delim, const ORCtpConfigField* pCtpConfig);
ORAPI std::string or_ctpconfig_field_json(const ORCtpConfigField* pCtpConfig);

/// LTS��������
#pragma pack(push, 1)
struct ORLtsConfigField
{
    /// LTS���������ļ�·��
    or_ltsconfigpath_s LtsConfigPath;
    /// ���͹�˾����
    or_brokerid_s BrokerID;
    void clear() { memset(this, 0, sizeof(ORLtsConfigField)); }
    /// initialized to zero
    ORLtsConfigField() { clear(); }
};
#pragma pack(pop)
using ORLtsConfigFieldPtr = std::shared_ptr<ORLtsConfigField>;
ORAPI std::string or_ltsconfig_field_csv_header(const char* delim);
ORAPI std::string or_ltsconfig_field_csv(const char* delim, const ORLtsConfigField* pLtsConfig);
ORAPI std::string or_ltsconfig_field_desc(const char* delim, const ORLtsConfigField* pLtsConfig);
ORAPI std::string or_ltsconfig_field_json(const ORLtsConfigField* pLtsConfig);

/// TFTrade��������
#pragma pack(push, 1)
struct ORTFTradeConfigField
{
    /// ����ͨ�����
    or_channelid_i ChannelID;
    /// ����Ա���
    or_tfoperatorid_i OperatorID;
    /// ����Ա�˺ű��
    or_tfaccountid_i AccountID;
    /// ����Ա�˺ű��
    or_tfcomboid_i ComboID;
    /// ����Ա�˺�����
    or_password_s Password;
    /// ���׽����ַ
    or_filepath_s TFTradeAddr;
    /// ��ѯ�����ַ
    or_filepath_s TFQueryAddr;
    /// �������ļ���ַ
    or_filepath_s TradeFlowPath;
    /// ��̨������֤���ѯ�ֲ�ί�гɽ�
    or_startupqryposordertrade_b StartupQryPosOrderTrade;
    void clear() { memset(this, 0, sizeof(ORTFTradeConfigField)); }
    /// initialized to zero
    ORTFTradeConfigField() { clear(); }
};
#pragma pack(pop)
using ORTFTradeConfigFieldPtr = std::shared_ptr<ORTFTradeConfigField>;
ORAPI std::string or_tftradeconfig_field_csv_header(const char* delim);
ORAPI std::string or_tftradeconfig_field_csv(const char* delim, const ORTFTradeConfigField* pTFTradeConfig);
ORAPI std::string or_tftradeconfig_field_desc(const char* delim, const ORTFTradeConfigField* pTFTradeConfig);
ORAPI std::string or_tftradeconfig_field_json(const ORTFTradeConfigField* pTFTradeConfig);

/// TF������������
#pragma pack(push, 1)
struct ORTFMarketConfigField
{
    /// ��������
    or_tfmdptype_e MdpType;
    /// ����Ա���
    or_userid_s MarketUser;
    /// ����Ա�˺�����
    or_password_s MarketPassword;
    void clear() { memset(this, 0, sizeof(ORTFMarketConfigField)); }
    /// initialized to zero
    ORTFMarketConfigField() { clear(); }
};
#pragma pack(pop)
using ORTFMarketConfigFieldPtr = std::shared_ptr<ORTFMarketConfigField>;
ORAPI std::string or_tfmarketconfig_field_csv_header(const char* delim);
ORAPI std::string or_tfmarketconfig_field_csv(const char* delim, const ORTFMarketConfigField* pTFMarketConfig);
ORAPI std::string or_tfmarketconfig_field_desc(const char* delim, const ORTFMarketConfigField* pTFMarketConfig);
ORAPI std::string or_tfmarketconfig_field_json(const ORTFMarketConfigField* pTFMarketConfig);

/// Qmt�ļ�����������
#pragma pack(push, 1)
struct ORQmtFileConfigField
{
    /// �µ��ļ�����·�����ļ���
    or_filepath_s QmtInsertFilePath;
    /// AccountInfo��ѯ����ļ�����·�����ļ���
    or_filepath_s QmtResultAccountInfoFilePath;
    /// Position��ѯ����ļ�����·�����ļ���
    or_filepath_s QmtResultPositionFilePath;
    /// Order��ѯ����ļ�����·�����ļ���
    or_filepath_s QmtResultOrderFilePath;
    /// Trade��ѯ����ļ�����·�����ļ���
    or_filepath_s QmtResultTradeFilePath;
    /// QMTͨ����
    or_qmtchannelid_i QmtChannelID;
    /// QMT��������
    or_qmtstrategyname_s QmtStrategyName;
    /// QMT��������
    or_qmttradingtype_i QmtTradingType;
    /// QMT�˺���
    or_qmtaccountgroup_s QmtAccountGroup;
    /// QMT�ֵ�����
    or_qmtslicetype_i QmtSliceType;
    /// QMT�ļ�����ѯ�ظ�����(����)
    or_qmtfetchresultintervalms_i QmtFetchResultIntervalMs;
    void clear() { memset(this, 0, sizeof(ORQmtFileConfigField)); }
    /// initialized to zero
    ORQmtFileConfigField() { clear(); }
};
#pragma pack(pop)
using ORQmtFileConfigFieldPtr = std::shared_ptr<ORQmtFileConfigField>;
ORAPI std::string or_qmtfileconfig_field_csv_header(const char* delim);
ORAPI std::string or_qmtfileconfig_field_csv(const char* delim, const ORQmtFileConfigField* pQmtFileConfig);
ORAPI std::string or_qmtfileconfig_field_desc(const char* delim, const ORQmtFileConfigField* pQmtFileConfig);
ORAPI std::string or_qmtfileconfig_field_json(const ORQmtFileConfigField* pQmtFileConfig);

/// IBTwsͨ������
#pragma pack(push, 1)
struct ORIBTwsConfigField
{
    /// IBTWSͨ�����
    or_ibtwschannelid_s IBTwsChannelID;
    /// �ͻ���ID
    or_ibtwsclientid_i ClientID;
    /// ���ִ���
    or_currencyid_s CurrencyID;
    /// TWS������������
    or_ibtwsmarketdatatype_i MarketDataType;
    /// ��ȡʵʱ����
    or_ibtwssnapshot_b Snapshot;
    /// �洢Tick
    or_ibtwssavetick_i SaveTick;
    /// Tick�ļ�·��
    or_ibtwstickfile_s TickFile;
    /// �洢Snapshot
    or_ibtwssavesnapshot_i SaveSnapshot;
    /// Snapshot�ļ�·��
    or_ibtwssnapshotfile_s SnapshotFile;
    /// �Զ����ĺ�Լ
    or_ibtwsinstruments_s Instruments;
    void clear() { memset(this, 0, sizeof(ORIBTwsConfigField)); }
    /// initialized to zero
    ORIBTwsConfigField() { clear(); }
};
#pragma pack(pop)
using ORIBTwsConfigFieldPtr = std::shared_ptr<ORIBTwsConfigField>;
ORAPI std::string or_ibtwsconfig_field_csv_header(const char* delim);
ORAPI std::string or_ibtwsconfig_field_csv(const char* delim, const ORIBTwsConfigField* pIBTwsConfig);
ORAPI std::string or_ibtwsconfig_field_desc(const char* delim, const ORIBTwsConfigField* pIBTwsConfig);
ORAPI std::string or_ibtwsconfig_field_json(const ORIBTwsConfigField* pIBTwsConfig);

/// JinZ��ǿ��������
#pragma pack(push, 1)
struct ORJinZEnhanceConfigField
{
    /// JinZ��ǿģ���ʶ
    or_jinzserveraddress_s jinzserverAddress;
    /// JinZ��ǿģ���ʶ
    or_jinzserverport_i jinzserverPort;
    /// JinZ��ǿģ���ʶ
    or_jinzchannel_e jinzchannel;
    /// JinZ��ǿģ���ʶ
    or_jinzstropsite_s jinzstrOpSite;
    /// JinZ��ǿģ���ʶ
    or_jinzusercode_s jinzuserCode;
    /// JinZ��ǿģ���ʶ
    or_jinzauthdata_s jinzauthData;
    /// JinZ��ǿģ���ʶ
    or_jinzencryptkey_s jinzencryptKey;
    /// JinZ��ǿģ���ʶ
    or_jinzthirdparty_s jinzthirdParty;
    void clear() { memset(this, 0, sizeof(ORJinZEnhanceConfigField)); }
    /// initialized to zero
    ORJinZEnhanceConfigField() { clear(); }
};
#pragma pack(pop)
using ORJinZEnhanceConfigFieldPtr = std::shared_ptr<ORJinZEnhanceConfigField>;
ORAPI std::string or_jinzenhanceconfig_field_csv_header(const char* delim);
ORAPI std::string or_jinzenhanceconfig_field_csv(const char* delim, const ORJinZEnhanceConfigField* pJinZEnhanceConfig);
ORAPI std::string or_jinzenhanceconfig_field_desc(const char* delim, const ORJinZEnhanceConfigField* pJinZEnhanceConfig);
ORAPI std::string or_jinzenhanceconfig_field_json(const ORJinZEnhanceConfigField* pJinZEnhanceConfig);

/// ATP��������
#pragma pack(push, 1)
struct ORAtpConfigField
{
    /// ATP������������IP��ַ
    or_ipv4address_s AtpServerAddress;
    /// IPv4�˿ں�
    or_ipv4port_i AtpServerPort;
    void clear() { memset(this, 0, sizeof(ORAtpConfigField)); }
    /// initialized to zero
    ORAtpConfigField() { clear(); }
};
#pragma pack(pop)
using ORAtpConfigFieldPtr = std::shared_ptr<ORAtpConfigField>;
ORAPI std::string or_atpconfig_field_csv_header(const char* delim);
ORAPI std::string or_atpconfig_field_csv(const char* delim, const ORAtpConfigField* pAtpConfig);
ORAPI std::string or_atpconfig_field_desc(const char* delim, const ORAtpConfigField* pAtpConfig);
ORAPI std::string or_atpconfig_field_json(const ORAtpConfigField* pAtpConfig);

/// ����������
#pragma pack(push, 1)
struct ORReqSubscribeMarketDataField
{
    /// ����ͨ�����
    or_channelid_i ChannelID;
    /// Ͷ���ߴ���
    or_investorid_i InvestorID;
    /// ��Լ����
    or_instrumentid_s InstrumentID;
    /// ����������
    or_exchangeid_s ExchangeID;
    /// ���ִ���
    or_currencyid_s CurrencyID;
    /// ��Ʒ����
    or_productclass_e ProductClass;
    /// ������������
    or_marketdatatype_i MarketDataType;
    /// ���󿪹�
    or_reqswitch_e SubscribeSwitch;
    void clear() { memset(this, 0, sizeof(ORReqSubscribeMarketDataField)); }
    /// initialized to zero
    ORReqSubscribeMarketDataField() { clear(); }
};
#pragma pack(pop)
using ORReqSubscribeMarketDataFieldPtr = std::shared_ptr<ORReqSubscribeMarketDataField>;
ORAPI std::string or_reqsubscribemarketdata_field_csv_header(const char* delim);
ORAPI std::string or_reqsubscribemarketdata_field_csv(const char* delim, const ORReqSubscribeMarketDataField* pReqSubscribeMarketData);
ORAPI std::string or_reqsubscribemarketdata_field_desc(const char* delim, const ORReqSubscribeMarketDataField* pReqSubscribeMarketData);
ORAPI std::string or_reqsubscribemarketdata_field_json(const ORReqSubscribeMarketDataField* pReqSubscribeMarketData);

/// �������
#pragma pack(push, 1)
struct ORDepthMarketDataField
{
    /// ������
    or_date_i TradingDay;
    /// ��Ʒ����
    or_productclass_e ProductClass;
    /// ������������
    or_marketdatatype_i MarketDataType;
    /// ��Լ����
    or_instrumentid_s InstrumentID;
    /// ����������
    or_exchangeid_s ExchangeID;
    /// ��Լ�ڽ������Ĵ���
    or_exchangeinstid_s ExchangeInstID;
    /// ���¼�
    or_price_f LastPrice;
    /// �ϴν����
    or_price_f PreSettlementPrice;
    /// ������
    or_price_f PreClosePrice;
    /// ��ֲ���
    or_volume_i PreOpenInterest;
    /// ����
    or_price_f OpenPrice;
    /// ��߼�
    or_price_f HighestPrice;
    /// ��ͼ�
    or_price_f LowestPrice;
    /// ����
    or_volume_i Volume;
    /// �ɽ����
    or_money_f Turnover;
    /// �ֲ���
    or_volume_i OpenInterest;
    /// ������
    or_price_f ClosePrice;
    /// ���ν����
    or_price_f SettlementPrice;
    /// ��ͣ���
    or_price_f UpperLimitPrice;
    /// ��ͣ���
    or_price_f LowerLimitPrice;
    /// ����ʵ��
    or_ratio_f PreDelta;
    /// ����ʵ��
    or_ratio_f CurrDelta;
    /// ����޸�ʱ��
    or_time_i UpdateTime;
    /// ����޸ĺ���
    or_millisec_i UpdateMillisec;
    /// �����һ
    or_price_f BidPrice1;
    /// ������һ
    or_volume_i BidVolume1;
    /// ������һ
    or_price_f AskPrice1;
    /// ������һ
    or_volume_i AskVolume1;
    /// ����۶�
    or_price_f BidPrice2;
    /// ��������
    or_volume_i BidVolume2;
    /// �����۶�
    or_price_f AskPrice2;
    /// ��������
    or_volume_i AskVolume2;
    /// �������
    or_price_f BidPrice3;
    /// ��������
    or_volume_i BidVolume3;
    /// ��������
    or_price_f AskPrice3;
    /// ��������
    or_volume_i AskVolume3;
    /// �������
    or_price_f BidPrice4;
    /// ��������
    or_volume_i BidVolume4;
    /// ��������
    or_price_f AskPrice4;
    /// ��������
    or_volume_i AskVolume4;
    /// �������
    or_price_f BidPrice5;
    /// ��������
    or_volume_i BidVolume5;
    /// ��������
    or_price_f AskPrice5;
    /// ��������
    or_volume_i AskVolume5;
    /// �������
    or_price_f BidPrice6;
    /// ��������
    or_volume_i BidVolume6;
    /// ��������
    or_price_f AskPrice6;
    /// ��������
    or_volume_i AskVolume6;
    /// �������
    or_price_f BidPrice7;
    /// ��������
    or_volume_i BidVolume7;
    /// ��������
    or_price_f AskPrice7;
    /// ��������
    or_volume_i AskVolume7;
    /// ����۰�
    or_price_f BidPrice8;
    /// ��������
    or_volume_i BidVolume8;
    /// �����۰�
    or_price_f AskPrice8;
    /// ��������
    or_volume_i AskVolume8;
    /// ����۾�
    or_price_f BidPrice9;
    /// ��������
    or_volume_i BidVolume9;
    /// �����۾�
    or_price_f AskPrice9;
    /// ��������
    or_volume_i AskVolume9;
    /// �����ʮ
    or_price_f BidPrice10;
    /// ������ʮ
    or_volume_i BidVolume10;
    /// ������ʮ
    or_price_f AskPrice10;
    /// ������ʮ
    or_volume_i AskVolume10;
    /// ���վ���
    or_price_f AveragePrice;
    /// ҵ������
    or_date_i ActionDay;
    void clear() { memset(this, 0, sizeof(ORDepthMarketDataField)); }
    /// initialized to zero
    ORDepthMarketDataField() { clear(); }
};
#pragma pack(pop)
using ORDepthMarketDataFieldPtr = std::shared_ptr<ORDepthMarketDataField>;
ORAPI std::string or_depthmarketdata_field_csv_header(const char* delim);
ORAPI std::string or_depthmarketdata_field_csv(const char* delim, const ORDepthMarketDataField* pDepthMarketData);
ORAPI std::string or_depthmarketdata_field_desc(const char* delim, const ORDepthMarketDataField* pDepthMarketData);
ORAPI std::string or_depthmarketdata_field_json(const ORDepthMarketDataField* pDepthMarketData);

/// ��ʳɽ�
#pragma pack(push, 1)
struct ORTransactionDataField
{
    /// ��������
    or_marketdatatype_i Type;
    /// ������
    or_date_i TradingDay;
    /// ��Լ����
    or_instrumentid_s InstrumentID;
    /// ����������
    or_exchangeid_s ExchangeID;
    /// �ɽ��۸�
    or_price_f Price;
    /// ����
    or_volume_i Volume;
    /// ����ʱ��
    or_timestampnano_i Time;
    /// ��ʳɽ�ִ�б�־
    or_tradeflag_e TradeFlag;
    void clear() { memset(this, 0, sizeof(ORTransactionDataField)); }
    /// initialized to zero
    ORTransactionDataField() { clear(); }
};
#pragma pack(pop)
using ORTransactionDataFieldPtr = std::shared_ptr<ORTransactionDataField>;
ORAPI std::string or_transactiondata_field_csv_header(const char* delim);
ORAPI std::string or_transactiondata_field_csv(const char* delim, const ORTransactionDataField* pTransactionData);
ORAPI std::string or_transactiondata_field_desc(const char* delim, const ORTransactionDataField* pTransactionData);
ORAPI std::string or_transactiondata_field_json(const ORTransactionDataField* pTransactionData);

/// OpenOrderService������Ϣ
#pragma pack(push, 1)
struct OROpenOrderServiceConfigField
{
    /// �����ļ�·��
    or_filepath_s ConfigFilePath;
    /// ���ļ�Ŀ¼
    or_filepath_s FlowDataDir;
    /// OR��־·��
    or_filepath_s OrderRouterLogFile;
    /// ͨ�������Զ������
    or_channelcustomconfig_s ChannelCustomConfig;
    /// �������������
    or_intervalmilliseconds_i HeartBeatIntervalMs;
    void clear() { memset(this, 0, sizeof(OROpenOrderServiceConfigField)); }
    /// initialized to zero
    OROpenOrderServiceConfigField() { clear(); }
};
#pragma pack(pop)
using OROpenOrderServiceConfigFieldPtr = std::shared_ptr<OROpenOrderServiceConfigField>;
ORAPI std::string or_openorderserviceconfig_field_csv_header(const char* delim);
ORAPI std::string or_openorderserviceconfig_field_csv(const char* delim, const OROpenOrderServiceConfigField* pOpenOrderServiceConfig);
ORAPI std::string or_openorderserviceconfig_field_desc(const char* delim, const OROpenOrderServiceConfigField* pOpenOrderServiceConfig);
ORAPI std::string or_openorderserviceconfig_field_json(const OROpenOrderServiceConfigField* pOpenOrderServiceConfig);

/// Job send to adapter
#pragma pack(push, 1)
struct ORAdapterJobField
{
    void clear() { memset(this, 0, sizeof(ORAdapterJobField)); }
    /// initialized to zero
    ORAdapterJobField() { clear(); }
};
#pragma pack(pop)
using ORAdapterJobFieldPtr = std::shared_ptr<ORAdapterJobField>;
ORAPI std::string or_adapterjob_field_csv_header(const char* delim);
ORAPI std::string or_adapterjob_field_csv(const char* delim, const ORAdapterJobField* pAdapterJob);
ORAPI std::string or_adapterjob_field_desc(const char* delim, const ORAdapterJobField* pAdapterJob);
ORAPI std::string or_adapterjob_field_json(const ORAdapterJobField* pAdapterJob);

} // namespace ort
} // namespace cycnoches
#endif
