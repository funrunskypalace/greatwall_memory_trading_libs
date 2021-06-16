#pragma once

/// 2020-03-24 关于Topic和Package Type的设计
/// 在PBTradingSystem代码中，Topic有Trading和ReqResp两种，Package
/// Type也只有Req和Rsp两种。 而在之前的OR的设计中，没有用Topic，采用了5中Package
/// Type。
/// 现在，因为Front代码从PBTradingSystem中移植过来，所以OR中也想要引入Topic的概念，
/// 这就出现了问题了。

#include <stdint.h>
typedef int TSessionID;

const int TID_Finished = 0x0000ffff; // LAST TID

const char ORT_PKG_VERSION = 'A';

const int ORT_TOPIC_REQRESP = 0x0000; //请求应答a
const int ORT_TOPIC_TRADING = 0x0001; //交易回报

const char ORT_PKGCHAIN_NORMAL = 'N';
const char ORT_PKGCHAIN_LAST = 'L';

const char ORT_PKGTYPE_REQ = '1'; // 交易请求
const char ORT_PKGTYPE_RTN = '2'; // 应答回复,
const char ORT_PKGTYPE_RAW = '6'; // 通道返回的数据/报文

//@Model 应用根据自身逻辑定义消息TIpackage_pool_
//交互消息TID定义
// const int TID_OR_ReqHeartBeat =3;				//心跳请求
// const int TID_OR_RspHeartBeat =4;				//心跳应答
const int TID_OR_ReqSubscribeTopic = 12;     //订阅主题请求，UFT用于定于成交和回报
const int TID_OR_Login = 17;                 //登录柜台
const int TID_OR_Logout = 18;                //登出柜台
const int TID_OR_RspRuntimeStatus = 19;      //通道和资金账号登录成功
const int TID_OR_ReqHeartBeat = 20;          // front-心跳
const int TID_OR_RspHeartBeat = 21;          // front-心跳
const int TID_OR_FrontConnect = 22;          // front-connected
const int TID_OR_FrontDisconnect = 23;       // front-disconnected
const int TID_OR_OperatorLogin = 24;         //登录柜台
const int TID_OR_RspOperatorLogin = 25;      //资金账号登录响应
const int TID_OR_OperatorLogout = 26;        //登出柜台
const int TID_OR_RspOperatorLogout = 27;     //资金账号登录响应
const int TID_OR_RspCheckAccount = 28;       // front需要将onCheckAccount封装给client
const int TID_OR_QryCommissionRate = 100;    //查询手续费
const int TID_OR_RspQryCommissionRate = 101; //查询手续费回复
const int TID_OR_QryMarginRate = 102;        //查询保证金
const int TID_OR_RspQryMarginRate = 103;     //查询保证金回复
const int TID_OR_QryAccount = 143;           //查询账户资金
const int TID_OR_RspQryAccount = 144;        //查询账户资金回复
const int TID_OR_QryTradeCode = 145;         //查询股东代码
const int TID_OR_RspQryTradeCode = 146;      //查询股东代码回复
const int TID_OR_QryPosition = 147;          //查询持仓
const int TID_OR_RspQryPosition = 148;       //查询持仓回复
const int TID_OR_QryTradeDate = 149;         //查询交易日期
const int TID_OR_RspQryTradeDate = 150;      //查询交易日期恢复
const int TID_OR_ErrorMsg = 151;             //错误回报消息
const int TID_OR_QryStockCode = 153;         //查询证券代码信息
const int TID_OR_RspQryStockCode = 154;      //证券代码查询响应
const int TID_OR_RspLogin = 155;             //资金账号登录响应
const int TID_OR_ReqAssetTransfer = 156;     //资金划拨
const int TID_OR_RspAssetTransfer = 157;     //划拨响应
// const int TID_OR_RspQryFuturesPosition = 159;	//查询持仓回复
const int TID_OR_QryPositionDtl = 160;             //查询持仓明细
const int TID_OR_RspQryPositionDtl = 161;          //查询持仓明细回复
const int TID_OR_QryFuturesAccountMargin = 162;    //查询期货保证金
const int TID_OR_RspQryFuturesAccountMargin = 163; //查询期货保证金回复
const int TID_OR_QryTradingCodeType = 164;         //查询投资编码类型
const int TID_OR_RspQryTradingCodeType = 165;      //查询投资编码类型回复
const int TID_OR_QryStockPurQuotation = 166;       //查询新股申购额度
const int TID_OR_RspQryStockPurQuotation = 167;    //查询新股申购额度回复
const int TID_OR_QryStockPurStatistics = 168;      //查询新股申购汇总信息
const int TID_OR_RspQryStockPurStatistics = 169;   //查询新股申购汇总信息回复
const int TID_OR_QryStockPurInfo = 170;            //查询新股申购信息
const int TID_OR_RspQryStockPurInfo = 171;         //查询新股申购信息回复
const int TID_OR_QryInvestor = 172;                //查询投资者信息
const int TID_OR_RspQryInvestor = 173;             //查询投资者信息回复
const int TID_OR_Req_START = 200;                  //需要ORRequestID的委托类型起始编号
const int TID_OR_ReqOrderInsert = 201;             //发送订单请求
const int TID_OR_ReqOrderCancel = 202;             //发送撤单请求
const int TID_OR_RtnOrder = 203;                   //推送订单响应消息
const int TID_OR_RtnTrade = 204;                   //推送成交响应消息
const int TID_OR_RspOrderInsert = 205; //订单应答(UFT:提交到柜台接口时立即返回，RspInfo.ErrrorID用于表明成功或失败)
const int TID_OR_RspOrderCancel = 206;            //柜台撤单确认应答
const int TID_OR_RspOrderCancelFailure = 207;     //柜台撤单失败确认应答
const int TID_OR_ErrRtnOrder = 208;               //推送订单失败消息
const int TID_OR_ErrRtnOrderCancel = 209;         //推送撤单失败消息
const int TID_OR_QryOrder = 210;                  //查询订单
const int TID_OR_RspQryOrder = 211;               //查询订单回复
const int TID_OR_QryTrade = 212;                  //查询成交
const int TID_OR_RspQryTrade = 213;               //查询成交回复
const int TID_OR_RtnOrderCancel = 214;            //撤单已报（柜台/交易所）确认
const int TID_OR_ReqJsonTrading = 215;            //发送JSON格式的命令
const int TID_OR_RspJsonTrading = 216;            //回复JSON格式的命令
const int TID_OR_Req_END = 299;                   //需要ORRequestID的委托类型终止编号
const int TID_OR_RspQryStrategyPosition = 3001;   //（LTS）查询策略持仓信息
const int TID_OR_PushMarket = 5001;               // 行情推送
const int TID_OR_PushTickByTick = 5002;           // 逐笔成交
const int TID_OR_PushOrderBook = 5003;            // 订单簿
const int TID_OR_SubMarketData = 5011;            //请求订阅行情
const int TID_OR_RspSubMarketData = 5012;         //请求订阅行情回复
const int TID_OR_RspOrderPositionStr = 10000 + 1; // 更新委托查询位置
const int TID_OR_RspTradePositionStr = 10000 + 2; // 更新成交回报查询位置
