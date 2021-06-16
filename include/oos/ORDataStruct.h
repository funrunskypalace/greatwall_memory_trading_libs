
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

/// 系统运行状态
#pragma pack(push, 1)
struct ORRuntimeStatusField
{
    /// 交易通道编号
    or_channelid_i ChannelID;
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 系统模块名称
    or_modulename_s ModuleName;
    /// 状态名称
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

/// 柜台配置参数
#pragma pack(push, 1)
struct ORCounterConfigField
{
    /// 交易通道编号
    or_channelid_i ChannelID;
    /// 通道类型
    or_channeltype_e ChannelType;
    /// IPv4地址
    or_ipv4address_s IPv4Address;
    /// IPv4端口号
    or_ipv4port_i IPv4Port;
    /// 通道创建类型
    or_channelloadtype_e ChannelLoadType;
    /// 交易通道唯一标识
    or_channelloadid_s ChannelLoadID;
    /// 通道连接自定义参数
    or_channelcustomconfig_s ChannelCustomConfig;
    /// 扩展信息
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

/// 操作员账号
#pragma pack(push, 1)
struct OROperatorAccountField
{
    /// 操作员账号编号
    or_operatorid_i OperatorID;
    /// 密码
    or_password_s Password;
    /// 订阅的TID类型列表
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

/// 投资者信息
#pragma pack(push, 1)
struct ORInvestorField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 账户编号
    or_accountid_i AccountID;
    /// 账户类型
    or_accounttype_e AccountType;
    /// 交易日
    or_date_i TradingDay;
    /// 经纪公司代码
    or_brokerid_s BrokerID;
    /// 母账户代码
    or_brokerinvestorid_s BrokerInvestorID;
    /// 用户代码
    or_userid_s UserID;
    /// 客户号
    or_clientid_s ClientID;
    /// 资金账户代码
    or_accountcode_s AccountCode;
    /// 密码
    or_password_s Password;
    /// 投资者名称
    or_investorname_s InvestorName;
    /// 投资者类型
    or_investortype_e InvestorType;
    /// 证件类型
    or_idcardtype_e IDCardType;
    /// 证件号
    or_idcardno_s IDCardNo;
    /// 是否活跃
    or_isactive_b IsActive;
    /// 分组编号
    or_groupid_s GroupID;
    /// O32操作员代码
    or_o32operatorno_s O32OperatorNo;
    /// O32基金代码
    or_o32accountcode_s O32AccountCode;
    /// O32组合编号
    or_o32combino_s O32CombiNo;
    /// O32资产单元编号
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

/// 投资者资金账户
#pragma pack(push, 1)
struct ORAccountAssetField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 资金账户代码
    or_accountcode_s AccountCode;
    /// 交易日
    or_date_i TradingDay;
    /// 账户编号
    or_accountid_i AccountID;
    /// 币种代码
    or_currencyid_s CurrencyID;
    /// 资金账户名称
    or_accountname_s AccountName;
    /// 上次存款额
    or_money_f PreDeposit;
    /// 上次占用的保证金
    or_money_f PreMargin;
    /// 上次结算准备金
    or_money_f PreBalance;
    /// 结算准备金
    or_money_f Balance;
    /// 入金金额
    or_money_f Deposit;
    /// 冻结的保证金
    or_money_f FrozenMargin;
    /// 冻结的手续费
    or_money_f FrozenCommission;
    /// 冻结的资金
    or_money_f FrozenCash;
    /// 手工冻结的资金
    or_money_f ManualFrozenCash;
    /// 仓位占用保证金
    or_money_f UseMargin;
    /// 手续费
    or_money_f Commission;
    /// 可取资金
    or_money_f WithdrawQuota;
    /// 保证金可用余额
    or_money_f Credit;
    /// 可用资金
    or_money_f Available;
    /// 平仓盈亏
    or_money_f CloseProfit;
    /// 持仓盈亏
    or_money_f PositionProfit;
    /// 资金差额
    or_money_f CashIn;
    /// 出金金额
    or_money_f CashOut;
    /// 缺省状态
    or_isdefault_b IsDefault;
    /// 查询请求编号
    or_qtprequestid_i QTPRequestID;
    /// 查询会话编号
    or_qtpsessionid_i QTPSessionID;
    /// 查询前置编号
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

/// 投资者交易编码
#pragma pack(push, 1)
struct ORTradingCodeField
{
    /// 交易日
    or_date_i TradingDay;
    /// 账户编号
    or_accountid_i AccountID;
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 交易编码类型
    or_tradingcodetype_e TradingCodeType;
    /// 股东代码
    or_tradecode_s TradeCode;
    /// 营业部代码
    or_branchid_s BranchID;
    /// 席位号
    or_seatid_s SeatID;
    /// 投资者账户子编码
    or_optclientid_s OptClientID;
    /// 是否活跃
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

/// 返回信息
#pragma pack(push, 1)
struct ORRspInfoField
{
    /// 错误代码
    or_errorid_ei ErrorID;
    /// 结束标志
    or_islast_b IsLast;
    /// 错误信息
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

/// 报单录入请求
#pragma pack(push, 1)
struct OROrderReqField
{
    /// 本地报单编号
    or_orderlocalid_s OrderLocalID;
    /// 报单引用
    or_orderref_s OrderRef;
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 合约代码
    or_instrumentid_s InstrumentID;
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 报单价格条件
    or_orderpricetype_e OrderPriceType;
    /// 买卖方向
    or_direction_e Direction;
    /// 组合投机套保标志
    or_combhedgeflag_s CombHedgeFlag;
    /// 备兑标志
    or_coveredflag_e CoveredFlag;
    /// 价格
    or_price_f LimitPrice;
    /// 原始数量
    or_volume_i VolumeTotalOriginal;
    /// 有效期类型
    or_timecondition_e TimeCondition;
    /// 成交量类型
    or_volumecondition_e VolumeCondition;
    /// 最小成交量
    or_volume_i MinVolume;
    /// 触发条件
    or_contingentcondition_e ContingentCondition;
    /// 止损价
    or_price_f StopPrice;
    /// 预留字段1
    or_thirdreff1_s ThirdReff1;
    /// 预留字段2
    or_thirdreff2_s ThirdReff2;
    /// 备注
    or_remark_s Remark;
    /// 撤单标志
    or_cancelflag_e CancelFlag;
    /// 订单IP
    or_orderip_s OrderIP;
    /// 订单MAC
    or_ordermac_s OrderMAC;
    /// 订单硬盘序列号
    or_orderhdnum_s OrderHDNum;
    /// 订单机器码
    or_ordermaccode_s OrderMacCode;
    /// 订单操作系统
    or_orderos_s OrderOS;
    /// 组合开平标识
    or_comboffsetflag_s CombOffsetFlag;
    /// 产品类型
    or_productclass_e ProductClass;
    /// 最小成交量
    or_volume_i LimitDealAmount;
    /// 证券二级类别
    or_subproductclass_e SubProductClass;
    /// 负债合约编号
    or_compactid_s CompactID;
    /// 前置编号
    or_frontid_i FrontID;
    /// 会话编号
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

/// 撤销报单请求
#pragma pack(push, 1)
struct OROrderCancelReqField
{
    /// 本地报单编号
    or_orderlocalid_s OrderLocalID;
    /// 报单引用
    or_orderref_s OrderRef;
    /// 自定义引用编号
    or_orderactionref_s OrderActionRef;
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 引用OrderRouter委托编号
    or_reforrequestid_i RefORRequestID;
    /// 报单编号
    or_ordersysid_s OrderSysID;
    /// 合约代码
    or_instrumentid_s InstrumentID;
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 引用报单编号
    or_orderlocalid_s RefOrderLocalID;
    /// 柜台报单编号
    or_counterorderid_s CounterOrderID;
    /// 产品类型
    or_productclass_e ProductClass;
    /// 前置编号
    or_frontid_i FrontID;
    /// 会话编号
    or_sessionid_i SessionID;
    /// 备注
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

/// 报单
#pragma pack(push, 1)
struct OROrderField
{
    /// 报单状态
    or_orderstatus_e OrderStatus;
    /// 投资者代码
    or_investorid_i InvestorID;
    /// OrderRouter委托编号
    or_orrequestid_i ORRequestID;
    /// 本地报单编号
    or_orderlocalid_s OrderLocalID;
    /// 报单引用
    or_orderref_s OrderRef;
    /// 柜台报单编号
    or_counterorderid_s CounterOrderID;
    /// 报单编号
    or_ordersysid_s OrderSysID;
    /// 状态信息
    or_statusmsg_s StatusMsg;
    /// 交易日
    or_date_i TradingDay;
    /// 产品类型
    or_productclass_e ProductClass;
    /// 证券二级类别
    or_subproductclass_e SubProductClass;
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 合约代码
    or_instrumentid_s InstrumentID;
    /// 买卖方向
    or_direction_e Direction;
    /// 原始数量
    or_volume_i VolumeTotalOriginal;
    /// 价格
    or_price_f LimitPrice;
    /// 止损价
    or_price_f StopPrice;
    /// 有效期类型
    or_timecondition_e TimeCondition;
    /// 成交量类型
    or_volumecondition_e VolumeCondition;
    /// 触发条件
    or_contingentcondition_e ContingentCondition;
    /// 报单价格条件
    or_orderpricetype_e OrderPriceType;
    /// 组合开平标识
    or_comboffsetflag_s CombOffsetFlag;
    /// 组合投机套保标志
    or_combhedgeflag_s CombHedgeFlag;
    /// 席位号
    or_seatid_s SeatID;
    /// 股东代码
    or_tradecode_s TradeCode;
    /// 营业部代码
    or_branchid_s BranchID;
    /// 备兑标志
    or_coveredflag_e CoveredFlag;
    /// 报单类型
    or_ordertype_e OrderType;
    /// 最小成交量
    or_volume_i MinVolume;
    /// 今成交数量
    or_volume_i VolumeTraded;
    /// 今成交金额
    or_money_f AmountTraded;
    /// 剩余数量
    or_volume_i VolumeRemain;
    /// 撤成\废单数量
    or_volume_i VolumeCanceled;
    /// 报单日期
    or_date_i InsertDate;
    /// 委托时间
    or_time_i InsertTime;
    /// 最后修改时间
    or_time_i UpdateTime;
    /// 撤销时间
    or_time_i CancelTime;
    /// 发起标志
    or_ownertype_e OwnerType;
    /// 预留字段1
    or_thirdreff1_s ThirdReff1;
    /// 预留字段2
    or_thirdreff2_s ThirdReff2;
    /// 备注
    or_remark_s Remark;
    /// 撤单标志
    or_cancelflag_e CancelFlag;
    /// 订单IP
    or_orderip_s OrderIP;
    /// 订单MAC
    or_ordermac_s OrderMAC;
    /// 订单硬盘序列号
    or_orderhdnum_s OrderHDNum;
    /// 订单机器码
    or_ordermaccode_s OrderMacCode;
    /// 订单操作系统
    or_orderos_s OrderOS;
    /// 最小成交量
    or_volume_i LimitDealAmount;
    /// 前置编号
    or_frontid_i FrontID;
    /// 会话编号
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

/// 成交
#pragma pack(push, 1)
struct ORTradeField
{
    /// OrderRouter委托编号
    or_orrequestid_i ORRequestID;
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 本地报单编号
    or_orderlocalid_s OrderLocalID;
    /// 报单引用
    or_orderref_s OrderRef;
    /// 柜台报单编号
    or_counterorderid_s CounterOrderID;
    /// 报单编号
    or_ordersysid_s OrderSysID;
    /// 成交编号
    or_tradeid_s TradeID;
    /// 成交回报类型
    or_tradetype_e TradeType;
    /// 交易日
    or_date_i TradingDay;
    /// 产品类型
    or_productclass_e ProductClass;
    /// 证券二级类别
    or_subproductclass_e SubProductClass;
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 合约代码
    or_instrumentid_s InstrumentID;
    /// 价格
    or_price_f Price;
    /// 成交量
    or_volume_i Volume;
    /// 成交金额
    or_money_f TradeAmount;
    /// 买卖方向
    or_direction_e Direction;
    /// 开平标志
    or_offsetflag_e OffsetFlag;
    /// 投机套保标志
    or_hedgeflag_e HedgeFlag;
    /// 股东代码
    or_tradecode_s TradeCode;
    /// 席位号
    or_seatid_s SeatID;
    /// 营业部代码
    or_branchid_s BranchID;
    /// 合约交易代码
    or_instrumentcode_s InstrumentCode;
    /// 用户代码
    or_userid_s UserID;
    /// 备兑标志
    or_coveredflag_e CoveredFlag;
    /// 成交时期
    or_date_i TradeDate;
    /// 成交时间
    or_time_i TradeTime;
    /// 手续费
    or_money_f Commission;
    /// 发起标志
    or_ownertype_e OwnerType;
    /// 成交类型
    or_tradetypefutures_e TradeTypeFutures;
    /// 预留字段1
    or_thirdreff1_s ThirdReff1;
    /// 预留字段2
    or_thirdreff2_s ThirdReff2;
    /// 投资单元代码
    or_investunitid_s InvestUnitID;
    /// 结算编号
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

/// 通过JSON录入请求
#pragma pack(push, 1)
struct ORJsonTradingReqField
{
    /// 交易通道编号
    or_channelid_i ChannelID;
    /// 投资者代码
    or_investorid_i InvestorID;
    /// OrderRouter委托编号
    or_orrequestid_i ORRequestID;
    /// 本地报单编号
    or_orderlocalid_s OrderLocalID;
    /// 报单引用
    or_orderref_s OrderRef;
    /// 产品类型
    or_productclass_e ProductClass;
    /// 证券二级类别
    or_subproductclass_e SubProductClass;
    /// 买卖方向
    or_direction_e Direction;
    /// 组合构建/拆分标志
    or_offsetflag_e OffsetFlag;
    /// 预留字段1
    or_thirdreff1_s ThirdReff1;
    /// 预留字段2
    or_thirdreff2_s ThirdReff2;
    /// 备注
    or_remark_s Remark;
    /// JSON请求的自定义类型
    or_jsontypeid_i JsonTypeID;
    /// JSON请求内容
    or_jsoncontent_s JsonContent;
    /// 前置编号
    or_frontid_i FrontID;
    /// 会话编号
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

/// JSON请求的回复
#pragma pack(push, 1)
struct ORJsonTradingRspField
{
    /// 交易通道编号
    or_channelid_i ChannelID;
    /// 投资者代码
    or_investorid_i InvestorID;
    /// OrderRouter委托编号
    or_orrequestid_i ORRequestID;
    /// 本地报单编号
    or_orderlocalid_s OrderLocalID;
    /// 报单引用
    or_orderref_s OrderRef;
    /// 产品类型
    or_productclass_e ProductClass;
    /// 证券二级类别
    or_subproductclass_e SubProductClass;
    /// 预留字段1
    or_thirdreff1_s ThirdReff1;
    /// 预留字段2
    or_thirdreff2_s ThirdReff2;
    /// 备注
    or_remark_s Remark;
    /// 交易日
    or_date_i TradingDay;
    /// 交易时间
    or_time_i TradeTime;
    /// 结束标志
    or_islast_b IsLast;
    /// 错误代码
    or_errorid_ei ErrorID;
    /// 错误信息
    or_errormsg_s ErrorMsg;
    /// JSON请求的自定义类型
    or_jsontypeid_i JsonTypeID;
    /// JSON请求内容
    or_jsoncontent_s JsonContent;
    /// 前置编号
    or_frontid_i FrontID;
    /// 会话编号
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

/// 期权组合报单录入请求
#pragma pack(push, 1)
struct OROptionsCombineOrderField
{
    /// 本地报单编号
    or_orderlocalid_s OrderLocalID;
    /// 报单引用
    or_orderref_s OrderRef;
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 期权组合策略代码（必填），比如'PNSJC认沽牛市价差策略'等。
    or_optionscombstrategyid_s StrategyId;
    /// 期权组合策略组合编码，OffsetFlag开平方向为解除时需要填，组合时不需要填
    or_optionscombsecondaryorderid_s SecondaryOrderId;
    /// 产品类型
    or_productclass_e ProductClass;
    /// 证券二级类别
    or_subproductclass_e SubProductClass;
    /// 买卖方向
    or_direction_e Direction;
    /// 组合构建/拆分标志
    or_offsetflag_e OffsetFlag;
    /// 预留字段1
    or_thirdreff1_s ThirdReff1;
    /// 预留字段2
    or_thirdreff2_s ThirdReff2;
    /// 备注
    or_remark_s Remark;
    /// 当前期权组合合约腿数
    or_optionscomblegnum_i OptionsCombLegNum;
    /// 腿交易所代码
    or_exchangeid_s ExchangeIDLeg1;
    /// 腿合约代码
    or_instrumentid_s InstrumentIDLeg1;
    /// 腿期权类型
    or_optionstype_e OptionsTypeLeg1;
    /// 腿持仓权利义务方向
    or_posidirection_e PosiDirectionLeg1;
    /// 腿备兑标志
    or_coveredflag_e CoveredFlagLeg1;
    /// 腿合约数量（张）此字段响应时返回；委托不需要填
    or_volume_i VolumeLeg1;
    /// 腿合约代码
    or_instrumentid_s InstrumentIDLeg2;
    /// 腿交易所代码
    or_exchangeid_s ExchangeIDLeg2;
    /// 腿期权类型
    or_optionstype_e OptionsTypeLeg2;
    /// 腿持仓权利义务方向
    or_posidirection_e PosiDirectionLeg2;
    /// 腿备兑标志
    or_coveredflag_e CoveredFlagLeg2;
    /// 腿合约数量（张）此字段响应时返回；委托不需要填
    or_volume_i VolumeLeg2;
    /// 腿合约代码
    or_instrumentid_s InstrumentIDLeg3;
    /// 腿交易所代码
    or_exchangeid_s ExchangeIDLeg3;
    /// 腿期权类型
    or_optionstype_e OptionsTypeLeg3;
    /// 腿持仓权利义务方向
    or_posidirection_e PosiDirectionLeg3;
    /// 腿备兑标志
    or_coveredflag_e CoveredFlagLeg3;
    /// 腿合约数量（张）此字段响应时返回；委托不需要填
    or_volume_i VolumeLeg3;
    /// 腿合约代码
    or_instrumentid_s InstrumentIDLeg4;
    /// 腿交易所代码
    or_exchangeid_s ExchangeIDLeg4;
    /// 腿期权类型
    or_optionstype_e OptionsTypeLeg4;
    /// 腿持仓权利义务方向
    or_posidirection_e PosiDirectionLeg4;
    /// 腿备兑标志
    or_coveredflag_e CoveredFlagLeg4;
    /// 腿合约数量（张）此字段响应时返回；委托不需要填
    or_volume_i VolumeLeg4;
    /// 前置编号
    or_frontid_i FrontID;
    /// 会话编号
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

/// 期权组合报单查询请求
#pragma pack(push, 1)
struct OROptionsCombineQryField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 期权组合策略组合编码，OffsetFlag开平方向为解除时需要填，组合时不需要填
    or_optionscombsecondaryorderid_s SecondaryOrderId;
    /// 腿交易所代码
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

/// 期权组合信息
#pragma pack(push, 1)
struct OROptionsCombineField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 合约代码
    or_instrumentid_s InstrumentID;
    /// 期权组合策略代码（必填），比如'PNSJC认沽牛市价差策略'等。
    or_optionscombstrategyid_s StrategyId;
    /// 期权组合策略组合编码，OffsetFlag开平方向为解除时需要填，组合时不需要填
    or_optionscombsecondaryorderid_s SecondaryOrderId;
    /// 当前期权组合合约腿数
    or_optionscomblegnum_i OptionsCombLegNum;
    /// 腿合约代码
    or_instrumentid_s InstrumentIDLeg1;
    /// 腿交易所代码
    or_exchangeid_s ExchangeIDLeg1;
    /// 腿期权类型
    or_optionstype_e OptionsTypeLeg1;
    /// 腿持仓权利义务方向
    or_posidirection_e PosiDirectionLeg1;
    /// 腿备兑标志
    or_coveredflag_e CoveredFlagLeg1;
    /// 腿合约数量（张）此字段响应时返回；委托不需要填
    or_volume_i VolumeLeg1;
    /// 腿交易所代码
    or_exchangeid_s ExchangeIDLeg2;
    /// 腿合约代码
    or_instrumentid_s InstrumentIDLeg2;
    /// 腿期权类型
    or_optionstype_e OptionsTypeLeg2;
    /// 腿持仓权利义务方向
    or_posidirection_e PosiDirectionLeg2;
    /// 腿备兑标志
    or_coveredflag_e CoveredFlagLeg2;
    /// 腿合约数量（张）此字段响应时返回；委托不需要填
    or_volume_i VolumeLeg2;
    /// 腿交易所代码
    or_exchangeid_s ExchangeIDLeg3;
    /// 腿合约代码
    or_instrumentid_s InstrumentIDLeg3;
    /// 腿期权类型
    or_optionstype_e OptionsTypeLeg3;
    /// 腿持仓权利义务方向
    or_posidirection_e PosiDirectionLeg3;
    /// 腿备兑标志
    or_coveredflag_e CoveredFlagLeg3;
    /// 腿合约数量（张）此字段响应时返回；委托不需要填
    or_volume_i VolumeLeg3;
    /// 腿交易所代码
    or_exchangeid_s ExchangeIDLeg4;
    /// 腿合约代码
    or_instrumentid_s InstrumentIDLeg4;
    /// 腿期权类型
    or_optionstype_e OptionsTypeLeg4;
    /// 腿持仓权利义务方向
    or_posidirection_e PosiDirectionLeg4;
    /// 腿备兑标志
    or_coveredflag_e CoveredFlagLeg4;
    /// 腿合约数量（张）此字段响应时返回；委托不需要填
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

/// 母账户持仓
#pragma pack(push, 1)
struct ORAccountPositionField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 合约代码
    or_instrumentid_s InstrumentID;
    /// 持仓多空方向
    or_posidirection_e PosiDirection;
    /// 持仓日期标志
    or_positiondate_e PositionDate;
    /// 总持仓
    or_volume_i TotalPosition;
    /// 可用数量
    or_volume_i EnableVolume;
    /// 上日持仓
    or_volume_i YdPosition;
    /// 昨仓可用数量
    or_volume_i YdEnableVolume;
    /// 今持仓
    or_volume_i TodayPosition;
    /// 今仓可用数量
    or_volume_i TodayEnableVolume;
    /// 多头冻结
    or_volume_i LongFrozen;
    /// 开仓冻结金额
    or_money_f LongFrozenAmount;
    /// 空头冻结
    or_money_f ShortFrozen;
    /// 开仓冻结金额
    or_money_f ShortFrozenAmount;
    /// 手工冻结数量
    or_money_f ManualFrozenAmount;
    /// 股东代码
    or_tradecode_s TradeCode;
    /// 交易编码类型
    or_tradingcodetype_e TradingCodeType;
    /// 交易日
    or_date_i TradingDay;
    /// 投机套保标志
    or_hedgeflag_e HedgeFlag;
    /// 备兑标志
    or_coveredflag_e CoveredFlag;
    /// 上次占用的保证金
    or_money_f PreMargin;
    /// 仓位占用保证金
    or_money_f UseMargin;
    /// 开仓量
    or_volume_i OpenVolume;
    /// 平仓量
    or_volume_i CloseVolume;
    /// 平昨仓量
    or_volume_i CloseYdVolume;
    /// 本次结算价
    or_price_f SettlementPrice;
    /// 上次结算价
    or_price_f PreSettlementPrice;
    /// 手续费
    or_money_f Commission;
    /// 冻结的手续费
    or_money_f FrozenCommission;
    /// 冻结的保证金
    or_money_f FrozenMargin;
    /// 开仓成本
    or_money_f OpenCost;
    /// 持仓成本
    or_money_f PositionCost;
    /// 平仓盈亏
    or_money_f CloseProfit;
    /// 持仓盈亏
    or_money_f PositionProfit;
    /// 开仓金额
    or_money_f OpenAmount;
    /// 平仓金额
    or_money_f CloseAmount;
    /// 平昨仓金额
    or_money_f CloseYdAmount;
    /// 资金差额
    or_money_f CashIn;
    /// 冻结的资金
    or_money_f FrozenCash;
    /// 结算编号
    or_settlementid_i SettlementID;
    /// 交易所保证金
    or_money_f ExchangeMargin;
    /// 合约乘数
    or_volumemultiple_i VolumeMultiple;
    /// 执行冻结的昨仓
    or_volume_i YdStrikeFrozen;
    /// 大商所持仓成本差值，只有大商所使用
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

/// 账户持仓明细
#pragma pack(push, 1)
struct ORAccountPositionDtlField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 合约代码
    or_instrumentid_s InstrumentID;
    /// 备兑标志
    or_coveredflag_e CoveredFlag;
    /// 持仓多空方向
    or_posidirection_e PosiDirection;
    /// 上市日
    or_date_i OpenDate;
    /// 成交编号
    or_tradeid_s TradeID;
    /// 成交类型
    or_tradetypefutures_e TradeTypeFutures;
    /// 股东代码
    or_tradecode_s TradeCode;
    /// 交易编码类型
    or_tradingcodetype_e TradingCodeType;
    /// 成交量
    or_volume_i Volume;
    /// 上次结算价
    or_price_f PreSettlementPrice;
    /// 今开盘
    or_price_f OpenPrice;
    /// 投资者保证金
    or_money_f Margin;
    /// 平仓量
    or_volume_i CloseVolume;
    /// 平仓金额
    or_money_f CloseAmount;
    /// 结算编号
    or_settlementid_i SettlementID;
    /// 投机套保标志
    or_hedgeflag_e HedgeFlag;
    /// 买卖方向
    or_direction_e Direction;
    /// 交易日
    or_date_i TradingDay;
    /// 保证金率
    or_ratio_f MarginRateByMoney;
    /// 保证金率(按手数)
    or_ratio_f MarginRateByVolume;
    /// 昨结算价
    or_price_f LastSettlementPrice;
    /// 本次结算价
    or_price_f SettlementPrice;
    /// 按照时间顺序平仓的笔数,大商所专用
    or_volume_i TimeFirstVolume;
    /// 投资单元代码
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

/// 保证金率
#pragma pack(push, 1)
struct ORMarginRateField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 合约代码
    or_instrumentid_s InstrumentID;
    /// 多头保证金率
    or_ratio_f LongMarginRatioByMoney;
    /// 空头保证金率
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

/// 查询产品手续费信息
#pragma pack(push, 1)
struct ORQryCommissionRateField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 合约代码
    or_instrumentid_s InstrumentID;
    /// 买卖方向
    or_direction_e Direction;
    /// 开平标志
    or_offsetflag_e OffsetFlag;
    /// 备兑标志
    or_coveredflag_e CoveredFlag;
    /// 投机套保标志
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

/// 查询产品保证金率信息
#pragma pack(push, 1)
struct ORQryMarginRateField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 合约代码
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

/// 查询报单
#pragma pack(push, 1)
struct ORQryOrderField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 合约代码
    or_instrumentid_s InstrumentID;
    /// 报单编号
    or_ordersysid_s OrderSysID;
    /// 定位串
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

/// 查询成交
#pragma pack(push, 1)
struct ORQryTradeField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 合约代码
    or_instrumentid_s InstrumentID;
    /// 成交编号
    or_tradeid_s TradeID;
    /// 定位串
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

/// 查询投资者持仓
#pragma pack(push, 1)
struct ORQryPositionField
{
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 合约代码
    or_instrumentid_s InstrumentID;
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 产品类型
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

/// 查询投资者持仓明细
#pragma pack(push, 1)
struct ORQryPositionDtlField
{
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 合约代码
    or_instrumentid_s InstrumentID;
    /// 投资者代码
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

/// 查询下一交易日
#pragma pack(push, 1)
struct ORQryTradeDateField
{
    /// 交易日
    or_date_i TradingDay;
    /// 投资者代码
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

/// 查询下一交易日期的回复
#pragma pack(push, 1)
struct ORRspTradeDateField
{
    /// 交易日
    or_date_i TradingDay;
    /// 下一交易日
    or_date_i NextTradingDay;
    /// 投资者代码
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

/// 查询投资者信息信息
#pragma pack(push, 1)
struct ORQryInvestorField
{
    /// 投资者代码
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

/// 查询资产账户资金信息
#pragma pack(push, 1)
struct ORQryAccountAssetField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 查询请求编号
    or_qtprequestid_i QTPRequestID;
    /// 查询会话编号
    or_qtpsessionid_i QTPSessionID;
    /// 查询前置编号
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

/// 查询期货保证金
#pragma pack(push, 1)
struct ORQryFuturesAccountMarginField
{
    /// 投资者代码
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

/// 查询投资者股东代码
#pragma pack(push, 1)
struct ORQryTradeCodeField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 交易所代码
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

/// 查询投资者交易编码。UFT查询时，ExchangeID可以不输入，O32必须输入
#pragma pack(push, 1)
struct ORQryTradingCodeTypeField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 交易所代码
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

/// 查询负债合约信息
#pragma pack(push, 1)
struct ORQryCrdtCompactField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 证券代码
    or_instrumentid_s InstrumentID;
    /// 查询请求编号
    or_qtprequestid_i QTPRequestID;
    /// 查询会话编号
    or_qtpsessionid_i QTPSessionID;
    /// 查询前置编号
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

/// 查询负债合约信息回复
#pragma pack(push, 1)
struct ORCrdtCompactField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 证券代码
    or_instrumentid_s InstrumentID;
    /// 交易日
    or_date_i TradingDay;
    /// 负债合约编号
    or_compactid_s CompactID;
    /// 保证金比率
    or_ratio_f CreditRatio;
    /// 本地报单编号
    or_orderlocalid_s OrderLocalID;
    /// 价格
    or_price_f LimitPrice;
    /// 原始数量
    or_volume_i VolumeTotalOriginal;
    /// 今成交数量
    or_volume_i VolumeTraded;
    /// 今成交金额
    or_money_f AmountTraded;
    /// 手续费
    or_money_f Commission;
    /// 合约类别
    or_compacttype_e CompactType;
    /// 合约状态
    or_compactstatus_e CompactStatus;
    /// 实时合约金额
    or_money_f RealCompactbalance;
    /// 实时合约数量
    or_volume_i RealCompactVolume;
    /// 实时合约手续费
    or_money_f RealCompactFee;
    /// 实时合约利息
    or_money_f RealCompactInterest;
    /// 已还利息
    or_money_f RepaidInterest;
    /// 已还数量
    or_volume_i RepaidVolume;
    /// 已还金额
    or_money_f RepaidBalance;
    /// 合约利息
    or_money_f CompactInterest;
    /// 年利率
    or_rate_f YearRate;
    /// 归还截止日期
    or_date_i ReturnEndDate;
    /// 头寸编号
    or_cashgroupid_i CashGroupID;
    /// 头寸性质
    or_compactsource_e CompactSource;
    /// 续签到期日
    or_date_i PostPoneEndDate;
    /// 负债总额
    or_money_f TotalDebit;
    /// 合约预计利息
    or_money_f CompactPreInterest;
    /// 查询请求编号
    or_qtprequestid_i QTPRequestID;
    /// 查询会话编号
    or_qtpsessionid_i QTPSessionID;
    /// 查询前置编号
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

/// 查询投资者融资头寸
#pragma pack(push, 1)
struct ORQryCrdtEnFinFundField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 头寸性质
    or_cashgroup_e CashGroup;
    /// 查询请求编号
    or_qtprequestid_i QTPRequestID;
    /// 查询会话编号
    or_qtpsessionid_i QTPSessionID;
    /// 查询前置编号
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

/// 查询投资者融资头寸回复
#pragma pack(push, 1)
struct ORCrdtEnFinFundField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 头寸性质
    or_cashgroup_e CashGroup;
    /// 可用资金
    or_money_f EnableBalance;
    /// 交易日
    or_date_i TradingDay;
    /// 查询请求编号
    or_qtprequestid_i QTPRequestID;
    /// 查询会话编号
    or_qtpsessionid_i QTPSessionID;
    /// 查询前置编号
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

/// 查询投资者融券头寸
#pragma pack(push, 1)
struct ORQryCrdtEnSloInstrumentField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 证券代码
    or_instrumentid_s InstrumentID;
    /// 头寸性质
    or_cashgroup_e CashGroup;
    /// 查询请求编号
    or_qtprequestid_i QTPRequestID;
    /// 查询会话编号
    or_qtpsessionid_i QTPSessionID;
    /// 查询前置编号
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

/// 查询投资者融券头寸回复
#pragma pack(push, 1)
struct ORCrdtEnSloInstrumentField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 证券代码
    or_instrumentid_s InstrumentID;
    /// 头寸性质
    or_cashgroup_e CashGroup;
    /// 可用数量
    or_money_f EnableAmount;
    /// 交易日
    or_date_i TradingDay;
    /// 查询请求编号
    or_qtprequestid_i QTPRequestID;
    /// 查询会话编号
    or_qtpsessionid_i QTPSessionID;
    /// 查询前置编号
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

/// 查询投资者信用资产
#pragma pack(push, 1)
struct ORQryCrdtClientInfoField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 查询请求编号
    or_qtprequestid_i QTPRequestID;
    /// 查询会话编号
    or_qtpsessionid_i QTPSessionID;
    /// 查询前置编号
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

/// 查询投资者信用资产回复
#pragma pack(push, 1)
struct ORCrdtClientInfoField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 个人维持担保比例
    or_ratio_f AssureScale;
    /// 融券卖出使用金额
    or_money_f SloUsedBalance;
    /// 融券卖出金额
    or_money_f SloSellBalance;
    /// 保证金可用余额
    or_money_f Credit;
    /// 买担保品可用资金
    or_money_f AssureEnbuyBalance;
    /// 买券还券可用资金
    or_money_f SloEnrepaidBalance;
    /// 现金还款可用资金
    or_money_f FinEnrepaidBalance;
    /// 查询请求编号
    or_qtprequestid_i QTPRequestID;
    /// 查询会话编号
    or_qtpsessionid_i QTPSessionID;
    /// 查询前置编号
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

/// 查询投资者标的证券信息
#pragma pack(push, 1)
struct ORQryCrdtTargetStockInfoField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 证券代码
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

/// 查询投资者标的证券信息回复
#pragma pack(push, 1)
struct ORCrdtTargetStockInfoField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 证券代码
    or_instrumentid_s InstrumentID;
    /// 融资保证金比例
    or_ratio_f FinRatio;
    /// 融资浮动比率
    or_ratio_f FinFloatRatio;
    /// 融资状态
    or_finstatus_e FinStatus;
    /// 融券保证金比例
    or_ratio_f SloRatio;
    /// 融券浮动比率
    or_ratio_f SloFloatRatio;
    /// 融券状态
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

/// 查询投资者担保证券信息
#pragma pack(push, 1)
struct ORQryCrdtStockInfoField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 证券代码
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

/// 查询投资者担保证券信息回复
#pragma pack(push, 1)
struct ORCrdtStockInfoField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 证券代码
    or_instrumentid_s InstrumentID;
    /// 担保折算率
    or_ratio_f AssureRatio;
    /// 浮动比率
    or_ratio_f FloatRatio;
    /// 担保品状态
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

/// 合约
#pragma pack(push, 1)
struct ORInstrumentField
{
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 产品代码
    or_productid_s ProductID;
    /// 证券代码
    or_instrumentid_s InstrumentID;
    /// 证券交易代码
    or_instrumentcode_s InstrumentCode;
    /// 合约名称
    or_instrumentname_s InstrumentName;
    /// 证券类别
    or_productclass_e ProductClass;
    /// 合约数量乘数
    or_volumemultiple_i VolumeMultiple;
    /// 最小变动价位
    or_price_f PriceTick;
    /// 上市日
    or_date_i OpenDate;
    /// 到期日
    or_date_i ExpireDate;
    /// 当前是否交易
    or_istrading_b IsTrading;
    /// 期权执行价格
    or_price_f ExecPrice;
    /// 期权单手保证金
    or_money_f UnitMargin;
    /// 交易日
    or_date_i TradingDay;
    /// 行权日
    or_date_i ExerciseDay;
    /// 开始交割日
    or_date_i StartDeliveryDay;
    /// 结束交割日
    or_date_i EndDeliveryDay;
    /// 市价最大下单量
    or_volume_i MaxMarketOrderVolume;
    /// 市价最小下单量
    or_volume_i MinMarketOrderVolume;
    /// 限价最大下单量
    or_volume_i MaxLimitOrderVolume;
    /// 限价最小下单量
    or_volume_i MinLimitOrderVolume;
    /// 涨停板价
    or_price_f UpperLimitPrice;
    /// 跌停板价
    or_price_f LowerLimitPrice;
    /// 期权类型
    or_optionstype_e OptionsType;
    /// 最小买入变动手数
    or_volume_i BuyVolumeTick;
    /// 最小卖出变动手数
    or_volume_i SellVolumeTick;
    /// 基础商品代码
    or_instrumentid_s UnderlyingInstrumentID;
    /// 回报证券标志
    or_stockrealback_e StockRealBack;
    /// 回报资金标志
    or_fundrealback_e FundRealBack;
    /// 基础商品乘数
    or_underlyingmultiple_i UnderlyingMultiple;
    /// 昨收盘价
    or_price_f PreClosePrice;
    /// 上次结算价
    or_price_f PreSettlementPrice;
    /// 临近到期保证金上浮比率
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

/// 查询产品、证券代码和合约信息
#pragma pack(push, 1)
struct ORQryInstrumentField
{
    /// 合约代码
    or_instrumentid_s InstrumentID;
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 投资者代码
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

/// 查询证券代码
#pragma pack(push, 1)
struct ORQryStockCodeField
{
    /// 合约代码
    or_instrumentid_s InstrumentID;
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 交易所代码
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

/// 查询证券代码表回复
#pragma pack(push, 1)
struct ORRspStockCodeField
{
    /// 合约代码
    or_instrumentid_s InstrumentID;
    /// 回报证券标志
    or_stockrealback_e StockRealBack;
    /// 回报资金标志
    or_fundrealback_e FundRealBack;
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 产品代码
    or_productid_s ProductID;
    /// 证券交易代码
    or_instrumentcode_s InstrumentCode;
    /// 合约名称
    or_instrumentname_s InstrumentName;
    /// 合约在交易所的代码
    or_exchangeinstid_s ExchangeInstID;
    /// 证券类别
    or_productclass_e ProductClass;
    /// 合约数量乘数
    or_volumemultiple_i VolumeMultiple;
    /// 最小变动价位
    or_price_f PriceTick;
    /// 上市日
    or_date_i OpenDate;
    /// 到期日
    or_date_i ExpireDate;
    /// 当前是否交易
    or_istrading_b IsTrading;
    /// 期权执行价格
    or_price_f ExecPrice;
    /// 期权单手保证金
    or_money_f UnitMargin;
    /// 交易日
    or_date_i TradingDay;
    /// 行权日
    or_date_i ExerciseDay;
    /// 开始交割日
    or_date_i StartDeliveryDay;
    /// 结束交割日
    or_date_i EndDeliveryDay;
    /// 市价最大下单量
    or_volume_i MaxMarketOrderVolume;
    /// 市价最小下单量
    or_volume_i MinMarketOrderVolume;
    /// 限价最大下单量
    or_volume_i MaxLimitOrderVolume;
    /// 限价最小下单量
    or_volume_i MinLimitOrderVolume;
    /// 期权类型
    or_optionstype_e OptionsType;
    /// 最小买入变动手数
    or_volume_i BuyVolumeTick;
    /// 最小卖出变动手数
    or_volume_i SellVolumeTick;
    /// 基础商品乘数
    or_underlyingmultiple_i UnderlyingMultiple;
    /// 昨收盘价
    or_price_f PreClosePrice;
    /// 上次结算价
    or_price_f PreSettlementPrice;
    /// 临近到期保证金上浮比率
    or_ratio_f MarginRatioExpiring;
    /// 交割年份
    or_year_i DeliveryYear;
    /// 交割月
    or_month_i DeliveryMonth;
    /// 合约生命周期状态
    or_instlifephase_e InstLifePhase;
    /// 持仓类型
    or_positiontype_e PositionType;
    /// 是否使用历史持仓
    or_positionhistorytype_e PositionHistoryType;
    /// 多头保证金率
    or_ratio_f LongMarginRatioByMoney;
    /// 多头保证金费
    or_ratio_f LongMarginRatioByVolume;
    /// 空头保证金率
    or_ratio_f ShortMarginRatioByMoney;
    /// 空头保证金费
    or_ratio_f ShortMarginRatioByVolume;
    /// 是否使用大额单边保证金算法
    or_maxmarginsidealgorithm_e MaxMarginSideAlgorithm;
    /// 基础商品代码
    or_instrumentid_s UnderlyingInstrumentID;
    /// 执行价
    or_price_f StrikePrice;
    /// 组合类型
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

/// 查询新股申购额度
#pragma pack(push, 1)
struct ORQryStockPurQuotationField
{
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 账户信息
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

/// 查询新股申购额度
#pragma pack(push, 1)
struct ORStockPurQuotationField
{
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 主板可申购额度
    or_money_f EnableAmount;
    /// 科创板可申购额度
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

/// 查询新股申购汇总信息
#pragma pack(push, 1)
struct ORQryStockPurInfoField
{
    /// 投资者代码
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

/// 查询新股申购汇总信息
#pragma pack(push, 1)
struct ORStockPurInfoField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 合约代码
    or_instrumentid_s InstrumentID;
    /// 最高申购数量
    or_volume_i HighQuantity;
    /// 最低申购数量
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

/// 查询新股申购汇总信息
#pragma pack(push, 1)
struct ORQryStockPurStatisticsField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 交易所代码
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

/// 查询新股申购汇总信息
#pragma pack(push, 1)
struct ORStockPurStatisticsField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 合约代码
    or_instrumentid_s InstrumentID;
    /// 申购代码
    or_collectcode_s CollectCode;
    /// 申购数量
    or_volume_i AppAmount;
    /// 中签状态
    or_luckystatus_e LuckyStatus;
    /// 中签数量
    or_volume_i LuckyVolume;
    /// 中签金额
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

/// 交易通道登录成功
#pragma pack(push, 1)
struct ORRspLoginField
{
    /// 交易通道编号
    or_channelid_i ChannelID;
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 客户号
    or_clientid_s ClientID;
    /// 交易日
    or_date_i TradingDay;
    /// 营业部代码
    or_branchid_s BranchID;
    /// O32登录令牌
    or_o32usertoken_s O32UserToken;
    /// O32-UFX版本
    or_o32versionno_s O32VersionNo;
    /// 资金账户代码
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

/// 登录柜台资金帐号请求
#pragma pack(push, 1)
struct ORReqLoginField
{
    /// 交易通道编号
    or_channelid_i ChannelID;
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 登录机器MAC地址
    or_loginmac_s LoginMAC;
    /// 登录机器IP地址
    or_loginip_s LoginIp;
    /// 登录机器硬盘序列号
    or_orderhdvolserial_s OrderHdVolSerial;
    /// 密码
    or_password_s Password;
    /// 资金账户代码
    or_accountcode_s AccountCode;
    /// 业务方向
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

/// 资金划拨
#pragma pack(push, 1)
struct ORAssetTransferField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 结算准备金
    or_money_f Balance;
    /// 资金划拨信息
    or_transferinfo_s TransferInfo;
    /// 资金划拨方向
    or_transferdirection_e TransferDirection;
    /// 序号
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

/// 撤单确认
#pragma pack(push, 1)
struct ORRspOrderCancelField
{
    /// OrderRouter委托编号
    or_orrequestid_i ORRequestID;
    /// 柜台报单编号
    or_counterorderid_s CounterOrderID;
    /// 引用柜台报单编号
    or_refcounterorderid_s RefCounterOrderID;
    /// 引用交易所报单编号
    or_ordersysid_s RefOrderSysID;
    /// 席位号
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

/// 柜台委托确认
#pragma pack(push, 1)
struct ORRspOrderInsertField
{
    /// OrderRouter委托编号
    or_orrequestid_i ORRequestID;
    /// 柜台报单编号
    or_counterorderid_s CounterOrderID;
    /// 报单编号
    or_ordersysid_s OrderSysID;
    /// 席位号
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

/// 资金划转回复
#pragma pack(push, 1)
struct ORRspAssetTransferField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 错误代码
    or_errorid_ei ErrorID;
    /// 错误信息
    or_errormsg_s ErrorMsg;
    /// 序号
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

/// 校验账号可用
#pragma pack(push, 1)
struct ORCheckAccountField
{
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 序号
    or_sequenceno_i SequenceNo;
    /// 资金账户代码
    or_accountcode_s AccountCode;
    /// 密码
    or_password_s Password;
    /// 交易通道编号
    or_channelid_i ChannelID;
    /// 业务方向
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

/// UFT20相关的配置
#pragma pack(push, 1)
struct ORUft20ConfigField
{
    /// 接入柜台的IP和端口号列表
    or_ufxt2sdkservers_s UfxT2sdkServers;
    /// 许可证文件名称
    or_ufxt2sdklicensefilename_s UfxT2sdkLicenseFileName;
    /// 许可证密码
    or_ufxt2sdklicensepwd_s UfxT2sdkLicensePwd;
    /// 自动重连
    or_ufxt2sdkautoconnect_b UfxT2sdkAutoConnect;
    /// 委托方式
    or_ufxt2sdkentrustway_e UfxT2sdkEntrustWay;
    /// UFT20柜台BatchNo偏移量
    or_ufxbatchnooffset_i UfxBatchNoOffset;
    /// 使用UF20柜台的功能号
    or_uft20uf20functions_s Uft20UF20Functions;
    /// UF20系统号
    or_uft20uf20systemno_i Uft20UF20SystemNo;
    /// UFT2系统号
    or_uft20uft2systemno_i Uft20UFT2SystemNo;
    /// 自动查询交易和委托的时间间隔
    or_uft20syncinterval_i Uft20SyncInterval;
    /// T2SDK收发日志开关
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

/// O32相关的配置
#pragma pack(push, 1)
struct ORO32ConfigField
{
    /// 许可证文件名称
    or_ufxt2sdklicensefilename_s UfxT2sdkLicenseFileName;
    /// 许可证密码
    or_ufxt2sdklicensepwd_s UfxT2sdkLicensePwd;
    /// 自动重连
    or_ufxt2sdkautoconnect_b UfxT2sdkAutoConnect;
    /// 委托方式
    or_ufxt2sdkentrustway_e UfxT2sdkEntrustWay;
    /// UFT20柜台BatchNo偏移量
    or_ufxbatchnooffset_i UfxBatchNoOffset;
    /// 接入柜台的IP和端口号列表
    or_ufxt2sdkservers_s UfxT2sdkServers;
    /// O32订阅服务器
    or_o32subscribeservers_s O32SubscribeServers;
    /// 订阅主题
    or_o32topicname_s O32TopicName;
    /// 业务名称
    or_o32bizname_s O32BizName;
    /// O32开发者授权编号
    or_o32authorizationid_s O32AuthorizationId;
    /// T2SDK收发日志开关
    or_ufxt2sdksendrecvlog_b UfxT2sdkSendRecvLog;
    /// 客户端ID
    or_o32appid_s O32AppID;
    /// 终端授权码
    or_o32authorizecode_s O32AuthorizeCode;
    /// 接入端口
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

/// 模拟交易所特有配置
#pragma pack(push, 1)
struct ORMockMarketConfigField
{
    /// 模拟交易所服务器IP地址
    or_ipv4address_s MockMarketServerAddress;
    /// 模拟交易所服务器IP端口
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

/// 模拟柜台特有配置
#pragma pack(push, 1)
struct ORMockCounterConfigField
{
    /// 模拟柜台服务器IP地址
    or_ipv4address_s MockCounterServerAddress;
    /// 模拟柜台服务器IP端口
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

/// STP期权柜台服务器配置
#pragma pack(push, 1)
struct ORStpOptionServerConfigField
{
    /// STP期权柜台服务器地址
    or_ipv4address_s StpOptionServerAddress;
    /// STP期权柜台服务器端口
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

/// QMT增强交易配置
#pragma pack(push, 1)
struct ORQmtEnhanceConfigField
{
    /// QMT增强模块标识
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

/// TradeX特有配置
#pragma pack(push, 1)
struct ORTradeXConfigField
{
    /// 证券公司TDX编号
    or_tdxcompanyid_i TdxCompanyID;
    /// 通达信客户端的版本号
    or_tdxclientversion_s TdxClientVersion;
    /// 通达信查询睡眠时间
    or_tdxsleepmsqry_i TdxSleepMsQry;
    /// 通达信交易睡眠时间
    or_tdxsleepmstrd_i TdxSleepMsTrd;
    /// 使用担保品买卖
    or_buysellcollateral_i BuySellCollateral;
    /// 使用分页查询
    or_tdxpagedquery_i TdxPagedQuery;
    /// Broker IND
    or_tdxbrokerind_s TdxBrokerIND;
    /// 柜台连接验证后查询持仓委托成交
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

/// CTP特有配置
#pragma pack(push, 1)
struct ORCtpConfigField
{
    /// CTP运行配置类型
    or_ctprunningmode_s CtpRunningMode;
    /// 交易接入地址
    or_ctptradeaddr_s CtpTradeAddr;
    /// 行情接入地址
    or_ctpmdaddr_s CtpMdAddr;
    /// 代理商编号
    or_brokerid_s BrokerID;
    /// 用户验证码
    or_ctpauthcode_s CtpAuthCode;
    /// 应用编号
    or_ctpappid_s CtpAppId;
    /// 产品信息
    or_ctpproductinfo_s CtpProductInfo;
    /// 柜台连接验证后查询持仓委托成交
    or_startupqryposordertrade_b StartupQryPosOrderTrade;
    /// 平仓时自动优先平今平昨
    or_closehistorytype_e CloseHistoryType;
    /// 先收到已成委托时进行补单
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

/// LTS特有配置
#pragma pack(push, 1)
struct ORLtsConfigField
{
    /// LTS运行配置文件路径
    or_ltsconfigpath_s LtsConfigPath;
    /// 经纪公司代码
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

/// TFTrade特有配置
#pragma pack(push, 1)
struct ORTFTradeConfigField
{
    /// 交易通道编号
    or_channelid_i ChannelID;
    /// 操作员编号
    or_tfoperatorid_i OperatorID;
    /// 操作员账号编号
    or_tfaccountid_i AccountID;
    /// 操作员账号编号
    or_tfcomboid_i ComboID;
    /// 操作员账号密码
    or_password_s Password;
    /// 交易接入地址
    or_filepath_s TFTradeAddr;
    /// 查询接入地址
    or_filepath_s TFQueryAddr;
    /// 交易流文件地址
    or_filepath_s TradeFlowPath;
    /// 柜台连接验证后查询持仓委托成交
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

/// TF行情特有配置
#pragma pack(push, 1)
struct ORTFMarketConfigField
{
    /// 行情类型
    or_tfmdptype_e MdpType;
    /// 操作员编号
    or_userid_s MarketUser;
    /// 操作员账号密码
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

/// Qmt文件单特有配置
#pragma pack(push, 1)
struct ORQmtFileConfigField
{
    /// 下单文件完整路径和文件名
    or_filepath_s QmtInsertFilePath;
    /// AccountInfo查询结果文件完整路径和文件名
    or_filepath_s QmtResultAccountInfoFilePath;
    /// Position查询结果文件完整路径和文件名
    or_filepath_s QmtResultPositionFilePath;
    /// Order查询结果文件完整路径和文件名
    or_filepath_s QmtResultOrderFilePath;
    /// Trade查询结果文件完整路径和文件名
    or_filepath_s QmtResultTradeFilePath;
    /// QMT通道号
    or_qmtchannelid_i QmtChannelID;
    /// QMT策略名称
    or_qmtstrategyname_s QmtStrategyName;
    /// QMT交易类型
    or_qmttradingtype_i QmtTradingType;
    /// QMT账号组
    or_qmtaccountgroup_s QmtAccountGroup;
    /// QMT分单类型
    or_qmtslicetype_i QmtSliceType;
    /// QMT文件单查询回复周期(毫秒)
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

/// IBTws通道配置
#pragma pack(push, 1)
struct ORIBTwsConfigField
{
    /// IBTWS通道编号
    or_ibtwschannelid_s IBTwsChannelID;
    /// 客户端ID
    or_ibtwsclientid_i ClientID;
    /// 币种代码
    or_currencyid_s CurrencyID;
    /// TWS行情数据类型
    or_ibtwsmarketdatatype_i MarketDataType;
    /// 收取实时快照
    or_ibtwssnapshot_b Snapshot;
    /// 存储Tick
    or_ibtwssavetick_i SaveTick;
    /// Tick文件路径
    or_ibtwstickfile_s TickFile;
    /// 存储Snapshot
    or_ibtwssavesnapshot_i SaveSnapshot;
    /// Snapshot文件路径
    or_ibtwssnapshotfile_s SnapshotFile;
    /// 自动订阅合约
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

/// JinZ增强交易配置
#pragma pack(push, 1)
struct ORJinZEnhanceConfigField
{
    /// JinZ增强模块标识
    or_jinzserveraddress_s jinzserverAddress;
    /// JinZ增强模块标识
    or_jinzserverport_i jinzserverPort;
    /// JinZ增强模块标识
    or_jinzchannel_e jinzchannel;
    /// JinZ增强模块标识
    or_jinzstropsite_s jinzstrOpSite;
    /// JinZ增强模块标识
    or_jinzusercode_s jinzuserCode;
    /// JinZ增强模块标识
    or_jinzauthdata_s jinzauthData;
    /// JinZ增强模块标识
    or_jinzencryptkey_s jinzencryptKey;
    /// JinZ增强模块标识
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

/// ATP交易配置
#pragma pack(push, 1)
struct ORAtpConfigField
{
    /// ATP交易所服务器IP地址
    or_ipv4address_s AtpServerAddress;
    /// IPv4端口号
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

/// 请求订阅行情
#pragma pack(push, 1)
struct ORReqSubscribeMarketDataField
{
    /// 交易通道编号
    or_channelid_i ChannelID;
    /// 投资者代码
    or_investorid_i InvestorID;
    /// 合约代码
    or_instrumentid_s InstrumentID;
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 币种代码
    or_currencyid_s CurrencyID;
    /// 产品类型
    or_productclass_e ProductClass;
    /// 行情数据类型
    or_marketdatatype_i MarketDataType;
    /// 请求开关
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

/// 深度行情
#pragma pack(push, 1)
struct ORDepthMarketDataField
{
    /// 交易日
    or_date_i TradingDay;
    /// 产品类型
    or_productclass_e ProductClass;
    /// 行情数据类型
    or_marketdatatype_i MarketDataType;
    /// 合约代码
    or_instrumentid_s InstrumentID;
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 合约在交易所的代码
    or_exchangeinstid_s ExchangeInstID;
    /// 最新价
    or_price_f LastPrice;
    /// 上次结算价
    or_price_f PreSettlementPrice;
    /// 昨收盘
    or_price_f PreClosePrice;
    /// 昨持仓量
    or_volume_i PreOpenInterest;
    /// 今开盘
    or_price_f OpenPrice;
    /// 最高价
    or_price_f HighestPrice;
    /// 最低价
    or_price_f LowestPrice;
    /// 数量
    or_volume_i Volume;
    /// 成交金额
    or_money_f Turnover;
    /// 持仓量
    or_volume_i OpenInterest;
    /// 今收盘
    or_price_f ClosePrice;
    /// 本次结算价
    or_price_f SettlementPrice;
    /// 涨停板价
    or_price_f UpperLimitPrice;
    /// 跌停板价
    or_price_f LowerLimitPrice;
    /// 昨虚实度
    or_ratio_f PreDelta;
    /// 今虚实度
    or_ratio_f CurrDelta;
    /// 最后修改时间
    or_time_i UpdateTime;
    /// 最后修改毫秒
    or_millisec_i UpdateMillisec;
    /// 申买价一
    or_price_f BidPrice1;
    /// 申买量一
    or_volume_i BidVolume1;
    /// 申卖价一
    or_price_f AskPrice1;
    /// 申卖量一
    or_volume_i AskVolume1;
    /// 申买价二
    or_price_f BidPrice2;
    /// 申买量二
    or_volume_i BidVolume2;
    /// 申卖价二
    or_price_f AskPrice2;
    /// 申卖量二
    or_volume_i AskVolume2;
    /// 申买价三
    or_price_f BidPrice3;
    /// 申买量三
    or_volume_i BidVolume3;
    /// 申卖价三
    or_price_f AskPrice3;
    /// 申卖量三
    or_volume_i AskVolume3;
    /// 申买价四
    or_price_f BidPrice4;
    /// 申买量四
    or_volume_i BidVolume4;
    /// 申卖价四
    or_price_f AskPrice4;
    /// 申卖量四
    or_volume_i AskVolume4;
    /// 申买价五
    or_price_f BidPrice5;
    /// 申买量五
    or_volume_i BidVolume5;
    /// 申卖价五
    or_price_f AskPrice5;
    /// 申卖量五
    or_volume_i AskVolume5;
    /// 申买价六
    or_price_f BidPrice6;
    /// 申买量六
    or_volume_i BidVolume6;
    /// 申卖价六
    or_price_f AskPrice6;
    /// 申卖量六
    or_volume_i AskVolume6;
    /// 申买价七
    or_price_f BidPrice7;
    /// 申买量七
    or_volume_i BidVolume7;
    /// 申卖价七
    or_price_f AskPrice7;
    /// 申卖量七
    or_volume_i AskVolume7;
    /// 申买价八
    or_price_f BidPrice8;
    /// 申买量八
    or_volume_i BidVolume8;
    /// 申卖价八
    or_price_f AskPrice8;
    /// 申卖量八
    or_volume_i AskVolume8;
    /// 申买价九
    or_price_f BidPrice9;
    /// 申买量九
    or_volume_i BidVolume9;
    /// 申卖价九
    or_price_f AskPrice9;
    /// 申卖量九
    or_volume_i AskVolume9;
    /// 申买价十
    or_price_f BidPrice10;
    /// 申买量十
    or_volume_i BidVolume10;
    /// 申卖价十
    or_price_f AskPrice10;
    /// 申卖量十
    or_volume_i AskVolume10;
    /// 当日均价
    or_price_f AveragePrice;
    /// 业务日期
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

/// 逐笔成交
#pragma pack(push, 1)
struct ORTransactionDataField
{
    /// 行情数据
    or_marketdatatype_i Type;
    /// 交易日
    or_date_i TradingDay;
    /// 合约代码
    or_instrumentid_s InstrumentID;
    /// 交易所代码
    or_exchangeid_s ExchangeID;
    /// 成交价格
    or_price_f Price;
    /// 数量
    or_volume_i Volume;
    /// 行情时间
    or_timestampnano_i Time;
    /// 逐笔成交执行标志
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

/// OpenOrderService配置信息
#pragma pack(push, 1)
struct OROpenOrderServiceConfigField
{
    /// 配置文件路径
    or_filepath_s ConfigFilePath;
    /// 流文件目录
    or_filepath_s FlowDataDir;
    /// OR日志路径
    or_filepath_s OrderRouterLogFile;
    /// 通道连接自定义参数
    or_channelcustomconfig_s ChannelCustomConfig;
    /// 心跳间隔毫秒数
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
