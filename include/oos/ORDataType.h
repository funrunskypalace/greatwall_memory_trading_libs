

#ifndef OR_DATA_TYPE_H
#define OR_DATA_TYPE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "pre.h"

namespace cycnoches
{
namespace ort
{

enum OR_RESUME_TYPE
{
    OR_TERT_RESTART = 0,
    OR_TERT_RESUME,
    OR_TERT_QUICK
};

/////////////////////////////////////////////////////////////////////////
/// 常量定义
/////////////////////////////////////////////////////////////////////////
const int INVALID_ORREQUESTID = 0;
const int INVALID_INVESTORID = 0;
const int INVALID_CHANNELID = 0;
/// 期权组合策略最多腿数
const int OR_OPTIONSCOMB_LEG_NUM = 4;

/// 期权合约可支持的组合策略列表字符串长度
#define XTP_CNTRT_COMB_STRA_LIST_LEN         2048


/// 账户信息长度的定义
const int OR_ACCOUNTINFO_LEN = (500 + 1);
/// 客户端ID长度的定义
const int OR_O32APPID_LEN = (30 + 1);
/// 终端授权码长度的定义
const int OR_O32AUTHORIZECODE_LEN = (30 + 1);
/// 柜台报单编号长度的定义
const int OR_COUNTERORDERID_LEN = (16 + 1);
/// 引用柜台报单编号长度的定义
const int OR_REFCOUNTERORDERID_LEN = (16 + 1);
/// 报单编号长度的定义
const int OR_ORDERSYSID_LEN = (16 + 1);
/// 本地报单编号长度的定义
const int OR_ORDERLOCALID_LEN = (50 + 1);
/// 成交编号长度的定义
const int OR_TRADEID_LEN = (20 + 1);
/// 报单引用长度的定义
const int OR_ORDERREF_LEN = (50 + 1);
/// 文件路径长度的定义
const int OR_FILEPATHNAME_LEN = (255 + 1);
/// 合约代码长度的定义
const int OR_INSTRUMENTID_LEN = (30 + 1);
/// 交易所代码长度的定义
const int OR_EXCHANGEID_LEN = (8 + 1);
/// 合约名称长度的定义
const int OR_INSTRUMENTNAME_LEN = (20 + 1);
/// 产品代码长度的定义
const int OR_PRODUCTID_LEN = (30 + 1);
/// 经纪公司代码长度的定义
const int OR_BROKERID_LEN = (10 + 1);
/// 母账户代码长度的定义
const int OR_BROKERINVESTORID_LEN = (32 + 1);
/// UFX操作员代码长度的定义
const int OR_UFXOPERATORID_LEN = (32 + 1);
/// 可使用的UFX组合代码长度的定义
const int OR_UFXCOMBOID_LEN = (16 + 1);
/// 母账户名称长度的定义
const int OR_BROKERINVESTORNAME_LEN = (80 + 1);
/// 密码长度的定义
const int OR_PASSWORD_LEN = (130 + 1);
/// 期权子账户编码长度的定义
const int OR_OPTSUBINVESTORID_LEN = (8 + 1);
/// 席位号长度的定义
const int OR_BUSINESSUNIT_LEN = (5 + 1);
/// 营业部代码长度的定义
const int OR_BRANCHID_LEN = (5 + 1);
/// 投资者名称长度的定义
const int OR_INVESTORNAME_LEN = (80 + 1);
/// 用户代码长度的定义
const int OR_USERID_LEN = (14 + 1);
/// 网关登录用户代码长度的定义
const int OR_GATEWAYUSERID_LEN = (14 + 1);
/// 用户名称长度的定义
const int OR_USERNAME_LEN = (80 + 1);
/// 策略代码长度的定义
const int OR_COMBOID_LEN = (8 + 1);
/// 策略名称长度的定义
const int OR_COMBONAME_LEN = (80 + 1);
/// 资产单元编号（UFX Only）长度的定义
const int OR_ASSETNO_LEN = (16 + 1);
/// 备注长度的定义
const int OR_MEMO_LEN = (80 + 1);
/// 交易所交易员代码长度的定义
const int OR_BRANCHPBU_LEN = (20 + 1);
/// 资金账户代码长度的定义
const int OR_ACCOUNTCODE_LEN = (127 + 1);
/// 组合投机套保标志长度的定义
const int OR_COMBHEDGEFLAG_LEN = (4 + 1);
/// 自定义引用编号长度的定义
const int OR_ORDERACTIONREF_LEN = (10 + 1);
/// 状态信息长度的定义
const int OR_STATUSMSG_LEN = (80 + 1);
/// 错误信息长度的定义
const int OR_ERRORMSG_LEN = (80 + 1);
/// 可用组合列表（以|分割）长度的定义
const int OR_COMBOIDLIST_LEN = (512 + 1);
/// 合约交易代码长度的定义
const int OR_INSTRUMENTCODE_LEN = (20 + 1);
/// 交易所名称长度的定义
const int OR_EXCHANGENAME_LEN = (50 + 1);
/// 席位名称长度的定义
const int OR_SEATNAME_LEN = (50 + 1);
/// 证件号长度的定义
const int OR_IDCARDNO_LEN = (100 + 1);
/// 股东代码长度的定义
const int OR_TRADECODE_LEN = (19 + 1);
/// 投资者账户子编码长度的定义
const int OR_OPTCLIENTID_LEN = (10 + 1);
/// 分组编号长度的定义
const int OR_GROUPID_LEN = (14 + 1);
/// 分组名称长度的定义
const int OR_GROUPNAME_LEN = (50 + 1);
/// 组织架构代码长度的定义
const int OR_DEPARTMENTID_LEN = (14 + 1);
/// 上级组织架构代码长度的定义
const int OR_PARENTID_LEN = (14 + 1);
/// 组织架构名称长度的定义
const int OR_DEPTNAME_LEN = (50 + 1);
/// 操作员名称长度的定义
const int OR_OPERATORNAME_LEN = (20 + 1);
/// 产品名称长度的定义
const int OR_PRODUCTNAME_LEN = (50 + 1);
/// 投资单元代码长度的定义
const int OR_INVESTUNITID_LEN = (14 + 1);
/// 席位号长度的定义
const int OR_SEATID_LEN = (10 + 1);
/// 资金账户名称长度的定义
const int OR_ACCOUNTNAME_LEN = (50 + 1);
/// 币种代码长度的定义
const int OR_CURRENCYID_LEN = (3 + 1);
/// 投资单元名称长度的定义
const int OR_INVESTUNITNAME_LEN = (50 + 1);
/// 投资组合代码长度的定义
const int OR_PORTFOLIOID_LEN = (14 + 1);
/// 规则代码长度的定义
const int OR_RULECODE_LEN = (128 + 1);
/// 规则名称长度的定义
const int OR_RULENAME_LEN = (50 + 1);
/// 修改内容明细（json字符串）长度的定义
const int OR_VALUE_LEN = (256 + 1);
/// 预留字段1长度的定义
const int OR_THIRDREFF1_LEN = (20 + 1);
/// 预留字段2长度的定义
const int OR_THIRDREFF2_LEN = (50 + 1);
/// 投资者代码集合长度的定义
const int OR_INVESTORIDS_LEN = (256 + 1);
/// 合约代码集合长度的定义
const int OR_INSTRUMENTIDS_LEN = (512 + 1);
/// 前置地址长度的定义
const int OR_FRONTADDRESS_LEN = (31 + 1);
/// 流文件路径长度的定义
const int OR_FLOWPATH_LEN = (127 + 1);
/// 指令代码长度的定义
const int OR_ADMINCODE_LEN = (32 + 1);
/// 指令代码长度的定义
const int OR_ADMINSTATUSCODE_LEN = (32 + 1);
/// 公司名称长度的定义
const int OR_COMPANYNAME_LEN = (50 + 1);
/// 操作员可以查询的账户集合长度的定义
const int OR_QRYACCOUNTIDS_LEN = (500 + 1);
/// 操作员可以操作的账户集合长度的定义
const int OR_OPACCOUNTIDS_LEN = (500 + 1);
/// 客户号长度的定义
const int OR_CLIENTID_LEN = (50 + 1);
/// 通道名称长度的定义
const int OR_CHANNELNAME_LEN = (50 + 1);
/// 分仓接口IP长度的定义
const int OR_SYSIP_LEN = (20 + 1);
/// 分仓接口端口长度的定义
const int OR_SYSPORT_LEN = (10 + 1);
/// 备注长度的定义
const int OR_REMARK_LEN = (200 + 1);
/// 订单IP长度的定义
const int OR_ORDERIP_LEN = (20 + 1);
/// 订单MAC长度的定义
const int OR_ORDERMAC_LEN = (20 + 1);
/// 订单硬盘序列号长度的定义
const int OR_ORDERHDNUM_LEN = (50 + 1);
/// 订单机器码长度的定义
const int OR_ORDERMACCODE_LEN = (50 + 1);
/// 订单操作系统长度的定义
const int OR_ORDEROS_LEN = (50 + 1);
/// 定位串长度的定义
const int OR_POSITIONSTR_LEN = (100 + 1);
/// 资金划拨信息长度的定义
const int OR_TRANSFERINFO_LEN = (500 + 1);
/// 接入柜台的IP和端口号列表长度的定义
const int OR_UFXT2SDKSERVERS_LEN = (256 + 1);
/// 许可证文件名称长度的定义
const int OR_UFXT2SDKLICENSEFILENAME_LEN = (128 + 1);
/// 许可证密码长度的定义
const int OR_UFXT2SDKLICENSEPWD_LEN = (64 + 1);
/// 使用UF20柜台的功能号长度的定义
const int OR_UFT20UF20FUNCTIONS_LEN = (200 + 1);
/// IPv4地址长度的定义
const int OR_IPV4ADDRESS_LEN = (64 + 1);
/// 通道连接自定义参数长度的定义
const int OR_CHANNELCUSTOMCONFIG_LEN = (2048 + 1);
/// STP期权柜台服务器地址长度的定义
const int OR_STPOPTIONSERVERADDRESS_LEN = (64 + 1);
/// QMT增强模块标识长度的定义
const int OR_QMTENHANCEMODULETAG_LEN = (64 + 1);
/// 通达信客户端的版本号长度的定义
const int OR_TDXCLIENTVERSION_LEN = (64 + 1);
/// Broker IND长度的定义
const int OR_TDXBROKERIND_LEN = (16 + 1);
/// O32订阅服务器长度的定义
const int OR_O32SUBSCRIBESERVERS_LEN = (255 + 1);
/// O32操作员代码长度的定义
const int OR_O32OPERATORNO_LEN = (15 + 1);
/// O32操作员密码长度的定义
const int OR_O32OPERATORPWD_LEN = (15 + 1);
/// O32组合编号长度的定义
const int OR_O32COMBINO_LEN = (15 + 1);
/// O32资产单元编号长度的定义
const int OR_O32ASSETNO_LEN = (15 + 1);
/// 登录机器MAC地址长度的定义
const int OR_LOGINMAC_LEN = (19 + 1);
/// 登录机器IP地址长度的定义
const int OR_LOGINIP_LEN = (14 + 1);
/// 登录机器硬盘序列号长度的定义
const int OR_ORDERHDVOLSERIAL_LEN = (127 + 1);
/// 登录站点长度的定义
const int OR_O32OPSTATION_LEN = (255 + 1);
/// O32开发者授权编号长度的定义
const int OR_O32AUTHORIZATIONID_LEN = (63 + 1);
/// O32登录令牌长度的定义
const int OR_O32USERTOKEN_LEN = (511 + 1);
/// O32-UFX版本长度的定义
const int OR_O32VERSIONNO_LEN = (31 + 1);
/// O32基金代码长度的定义
const int OR_O32ACCOUNTCODE_LEN = (31 + 1);
/// 订阅主题长度的定义
const int OR_O32TOPICNAME_LEN = (63 + 1);
/// 业务名称长度的定义
const int OR_O32BIZNAME_LEN = (63 + 1);
/// 组合开平标识长度的定义
const int OR_COMBOFFSETFLAG_LEN = (4 + 1);
/// 申购代码长度的定义
const int OR_COLLECTCODE_LEN = (30 + 1);
/// CTP运行配置类型长度的定义
const int OR_CTPRUNNINGMODE_LEN = (100 + 1);
/// 交易接入地址长度的定义
const int OR_CTPTRADEADDR_LEN = (100 + 1);
/// 行情接入地址长度的定义
const int OR_CTPMDADDR_LEN = (100 + 1);
/// 用户验证码长度的定义
const int OR_CTPAUTHCODE_LEN = (100 + 1);
/// 应用编号长度的定义
const int OR_CTPAPPID_LEN = (100 + 1);
/// 产品信息长度的定义
const int OR_CTPPRODUCTINFO_LEN = (100 + 1);
/// 负债合约编号长度的定义
const int OR_COMPACTID_LEN = (32 + 1);
/// LTS运行配置文件路径长度的定义
const int OR_LTSCONFIGPATH_LEN = (255 + 1);
/// 合约在交易所的代码长度的定义
const int OR_EXCHANGEINSTID_LEN = (30 + 1);
/// 会员代码长度的定义
const int OR_PARTICIPANTID_LEN = (10 + 1);
/// 组合类型长度的定义
const int OR_COMBINETYPE_LEN = (24 + 1);
/// 文件完整路径和文件名长度的定义
const int OR_FILEPATH_LEN = (256 + 1);
/// QMT策略名称长度的定义
const int OR_QMTSTRATEGYNAME_LEN = (64 + 1);
/// QMT账号组长度的定义
const int OR_QMTACCOUNTGROUP_LEN = (64 + 1);
/// IBTWS通道编号长度的定义
const int OR_IBTWSCHANNELID_LEN = (64 + 1);
/// Tick文件路径长度的定义
const int OR_IBTWSTICKFILE_LEN = (128 + 1);
/// Snapshot文件路径长度的定义
const int OR_IBTWSSNAPSHOTFILE_LEN = (128 + 1);
/// 自动订阅合约长度的定义
const int OR_IBTWSINSTRUMENTS_LEN = (256 + 1);
/// 系统模块名称长度的定义
const int OR_MODULENAME_LEN = (18 + 1);
/// 状态名称长度的定义
const int OR_STATUSCODE_LEN = (18 + 1);
/// 订阅的TID类型列表长度的定义
const int OR_SUBSCRIBETIDS_LEN = (500 + 1);
/// 交易通道唯一标识长度的定义
const int OR_CHANNELLOADID_LEN = (64 + 1);
/// JinZ增强模块标识长度的定义
const int OR_JINZSERVERADDRESS_LEN = (64 + 1);
/// JinZ增强模块标识长度的定义
const int OR_JINZSTROPSITE_LEN = (256 + 1);
/// JinZ增强模块标识长度的定义
const int OR_JINZUSERCODE_LEN = (32 + 1);
/// JinZ增强模块标识长度的定义
const int OR_JINZAUTHDATA_LEN = (32 + 1);
/// JinZ增强模块标识长度的定义
const int OR_JINZENCRYPTKEY_LEN = (32 + 1);
/// JinZ增强模块标识长度的定义
const int OR_JINZTHIRDPARTY_LEN = (32 + 1);
/// 扩展信息长度的定义
const int OR_EXTENDFIELD_LEN = (256 + 1);
/// JSON请求内容长度的定义
const int OR_JSONCONTENT_LEN = (4096 + 1);
/// 期权组合策略代码（必填），比如'PNSJC认沽牛市价差策略'等。长度的定义
const int OR_OPTIONSCOMBSTRATEGYID_LEN = (64 + 1);
/// 期权组合策略组合编码，OffsetFlag开平方向为解除时需要填，组合时不需要填长度的定义
const int OR_OPTIONSCOMBSECONDARYORDERID_LEN = (18 + 1);
/// 账户信息
typedef char or_accountinfo_s[OR_ACCOUNTINFO_LEN];
/// 客户端ID
typedef char or_o32appid_s[OR_O32APPID_LEN];
/// 终端授权码
typedef char or_o32authorizecode_s[OR_O32AUTHORIZECODE_LEN];
/// 接入端口
typedef int64_t or_o32portid_i;
/// OrderRouter委托编号
typedef int64_t or_orrequestid_i;
/// 引用OrderRouter委托编号
typedef int64_t or_reforrequestid_i;
/// 柜台报单编号
typedef char or_counterorderid_s[OR_COUNTERORDERID_LEN];
/// 引用柜台报单编号
typedef char or_refcounterorderid_s[OR_REFCOUNTERORDERID_LEN];
/// 报单编号
typedef char or_ordersysid_s[OR_ORDERSYSID_LEN];
/// 本地报单编号
typedef char or_orderlocalid_s[OR_ORDERLOCALID_LEN];
/// 成交编号
typedef char or_tradeid_s[OR_TRADEID_LEN];
/// 报单引用
typedef char or_orderref_s[OR_ORDERREF_LEN];
/// 最大报单引用
typedef int64_t or_maxorderref_i;
/// 经纪公司报单编号
typedef int64_t or_brokerorderseq_i;
/// 第三方编号（如果柜台支持，采用的柜台的自定义字段）
typedef int64_t or_thirdreff_i;
/// 文件路径
typedef char or_filepathname_s[OR_FILEPATHNAME_LEN];
/// 合约代码
typedef char or_instrumentid_s[OR_INSTRUMENTID_LEN];
/// 交易所代码
typedef char or_exchangeid_s[OR_EXCHANGEID_LEN];
/// 合约名称
typedef char or_instrumentname_s[OR_INSTRUMENTNAME_LEN];
/// 产品代码
typedef char or_productid_s[OR_PRODUCTID_LEN];
/////////////////////////////////////////////////////////////////////////
/// ProductClassType是一个产品类型类型
/////////////////////////////////////////////////////////////////////////
/// 产品类型
typedef char or_productclass_e;
/// 期货
const char OR_PC_Futures = '1';
/// 期权
const char OR_PC_Options = '2';
/// 股票
const char OR_PC_Stock = '3';
/// 债券
const char OR_PC_Bond = '4';
/// 基金
const char OR_PC_Fund = '5';
/// 指数
const char OR_PC_Index = '6';
/// 权证
const char OR_PC_Warrant = '7';
/// 回购
const char OR_PC_Repo = '8';
/// 其他
const char OR_PC_Other = '9';
/// 申购
const char OR_PC_SubscribePurchase = 'a';
ORAPI const char* or_productclass_enumstr(or_productclass_e value);

/// 当前是否交易
typedef bool or_istrading_b;
/// 日期
typedef int64_t or_date_i;
/// 时间
typedef int64_t or_time_i;
/////////////////////////////////////////////////////////////////////////
/// InvestorRangeType是一个投资者范围类型
/////////////////////////////////////////////////////////////////////////
/// 投资者范围
typedef char or_investorrange_e;
/// 所有
const char OR_IR_All = '1';
/// 投资者组
const char OR_IR_Group = '2';
/// 单一投资者
const char OR_IR_Single = '3';
/// 所有投资单元
const char OR_IR_AllInvestUnit = '4';
/// 单一投资单元
const char OR_IR_SingleInvestUnit = '5';
ORAPI const char* or_investorrange_enumstr(or_investorrange_e value);

/// 经纪公司代码
typedef char or_brokerid_s[OR_BROKERID_LEN];
/// 母账户代码
typedef char or_brokerinvestorid_s[OR_BROKERINVESTORID_LEN];
/// UFX操作员代码
typedef char or_ufxoperatorid_s[OR_UFXOPERATORID_LEN];
/// 可使用的UFX组合代码
typedef char or_ufxcomboid_s[OR_UFXCOMBOID_LEN];
/////////////////////////////////////////////////////////////////////////
/// DirectionType是一个买卖方向类型
/////////////////////////////////////////////////////////////////////////
/// 买卖方向
typedef char or_direction_e;
/// 买
const char OR_D_Buy = '0';
/// 卖
const char OR_D_Sell = '1';
/// ETF申购
const char OR_D_ETFPur = '2';
/// ETF赎回
const char OR_D_ETFRed = '3';
/// 现金替代，只用作回报
const char OR_D_CashIn = '4';
/// 债券入库
const char OR_D_PledgeBondIn = '5';
/// 债券出库
const char OR_D_PledgeBondOut = '6';
/// 配股
const char OR_D_Doublened = '7';
/// 转托管
const char OR_D_DepositoryTransfer = '8';
/// 信用账户配股
const char OR_D_CreditDoublened = '9';
/// 担保品买入
const char OR_D_BuyCollateral = 'A';
/// 担保品卖出
const char OR_D_SellCollateral = 'B';
/// 担保品转入
const char OR_D_CollateralTransferIn = 'C';
/// 担保品转出
const char OR_D_CollateralTransferOut = 'D';
/// 融资买入
const char OR_D_MarginTrade = 'E';
/// 融券卖出
const char OR_D_ShortSell = 'F';
/// 卖券还款
const char OR_D_RepayMargin = 'G';
/// 买券还券
const char OR_D_RepayStock = 'H';
/// 直接还款
const char OR_D_DirectRepayMargin = 'I';
/// 直接还券
const char OR_D_DirectRepayStock = 'J';
/// 余券划转
const char OR_D_ExcessStockTransfer = 'K';
/// OF申购
const char OR_D_OFPur = 'L';
/// OF赎回
const char OR_D_OFRed = 'M';
/// SF拆分
const char OR_D_SFSplit = 'N';
/// SF合并
const char OR_D_SFMerge = 'O';
/// 备兑
const char OR_D_Covered = 'P';
/// 证券冻结(开)/解冻(平)
const char OR_D_Freeze = 'Q';
/// 行权
const char OR_D_Execute = 'R';
/// CB回售
const char OR_D_CBRed = 'S';
/// CB转股
const char OR_D_CBConv = 'T';
/// OF认购
const char OR_D_OFSub = 'U';
/// 个股申购（可转债）
const char OR_D_StockPur = 'V';
/// 期权锁仓(SH)
const char OR_D_LockOP = 'W';
/// 期权解仓(SH)
const char OR_D_UnLockOP = 'X';
/// 期权组合策略 组合和拆分业务
const char OR_D_OptionsCombine = 'Y';
/// 期权行权合并业务
const char OR_D_ExecuteCombine = 'Z';
ORAPI const char* or_direction_enumstr(or_direction_e value);

/////////////////////////////////////////////////////////////////////////
/// OffsetFlagType是一个开平标志类型
/////////////////////////////////////////////////////////////////////////
/// 开平标志
typedef char or_offsetflag_e;
/// 开仓
const char OR_OF_Open = '0';
/// 平仓
const char OR_OF_Close = '1';
/// 强平
const char OR_OF_ForceClose = '2';
/// 平今
const char OR_OF_CloseToday = '3';
/// 平昨
const char OR_OF_CloseYesterday = '4';
/// 强减
const char OR_OF_ForceOff = '5';
/// 本地强平
const char OR_OF_LocalForceClose = '6';
/// 自动进行开平仓判断
const char OR_OF_Auto = '7';
/// 认购
const char OR_OF_Call = '8';
/// 认沽
const char OR_OF_Put = '9';
/// 组合策略的组合
const char OR_OF_OptCombine = 'A';
/// 组合策略的拆分
const char OR_OF_OptSplit = 'B';
/// 组合策略的管理员强制拆分
const char OR_OF_OptSplitForce = 'C';
/// 组合策略的交易所强制拆分
const char OR_OF_OptSplitForceExch = 'D';
ORAPI const char* or_offsetflag_enumstr(or_offsetflag_e value);

/////////////////////////////////////////////////////////////////////////
/// HedgeFlagType是一个投机套保标志类型
/////////////////////////////////////////////////////////////////////////
/// 投机套保标志
typedef char or_hedgeflag_e;
/// 投机
const char OR_HF_Speculation = '1';
/// 套利
const char OR_HF_Arbitrage = '2';
/// 套保
const char OR_HF_Hedge = '3';
/// 做市商
const char OR_HF_MarketMaker = '4';
ORAPI const char* or_hedgeflag_enumstr(or_hedgeflag_e value);

/// 是否相对交易所收取
typedef bool or_isrelative_b;
/// 母账户名称
typedef char or_brokerinvestorname_s[OR_BROKERINVESTORNAME_LEN];
/// 操作员代码
typedef int64_t or_operatorid_i;
/// 密码
typedef char or_password_s[OR_PASSWORD_LEN];
/// 操作员代码
typedef int64_t or_tfoperatorid_i;
/// 操作员账号编号
typedef int64_t or_tfaccountid_i;
/// 操作员组合编号
typedef int64_t or_tfcomboid_i;
/////////////////////////////////////////////////////////////////////////
/// TFMarketDataTypeType是一个行情源类型类型
/////////////////////////////////////////////////////////////////////////
/// 行情源类型
typedef char or_tfmarketdatatype_e;
/// 实时行情订阅
const char OR_MDT_RMSSubscribe = '1';
/// 实时行情组播
const char OR_MDT_RMSMulticast = '2';
/// 历史行情订阅
const char OR_MDT_HMSSubscribe = '3';
/// 实时指标订阅
const char OR_MDT_RISSubscribe = '4';
/// 历史指标订阅
const char OR_MDT_HISSubscribe = '5';
/// OTC行情订阅
const char OR_MDT_ORMSSubscribe = '6';
/// 实时行情压缩订阅
const char OR_MDT_RMSCompressSubscribe = 'a';
ORAPI const char* or_tfmarketdatatype_enumstr(or_tfmarketdatatype_e value);

/////////////////////////////////////////////////////////////////////////
/// UserTypeType是一个用户类型类型
/////////////////////////////////////////////////////////////////////////
/// 用户类型
typedef char or_usertype_e;
/// 投资者
const char OR_UT_Investor = '0';
/// 操作员
const char OR_UT_Operator = '1';
/// 管理员
const char OR_UT_SuperUser = '2';
ORAPI const char* or_usertype_enumstr(or_usertype_e value);

/// 是否活跃
typedef bool or_isactive_b;
/// 投资者代码
typedef int64_t or_investorid_i;
/// 期权子账户编码
typedef char or_optsubinvestorid_s[OR_OPTSUBINVESTORID_LEN];
/// 席位号
typedef char or_businessunit_s[OR_BUSINESSUNIT_LEN];
/// 营业部代码
typedef char or_branchid_s[OR_BRANCHID_LEN];
/////////////////////////////////////////////////////////////////////////
/// CoveredFlagType是一个备兑标志类型
/////////////////////////////////////////////////////////////////////////
/// 备兑标志
typedef char or_coveredflag_e;
/// 非备兑
const char OR_CF_Uncovered = '\0';
/// 备兑
const char OR_CF_Covered = '1';
/// 普通业务头寸
const char OR_CF_NorCash = '2';
/// 专项业务头寸
const char OR_CF_SpecCash = '3';
ORAPI const char* or_coveredflag_enumstr(or_coveredflag_e value);

/////////////////////////////////////////////////////////////////////////
/// OwnerTypeType是一个发起标志类型
/////////////////////////////////////////////////////////////////////////
/// 发起标志
typedef char or_ownertype_e;
/// 个人投资者
const char OR_OT_0 = '0';
/// 交易所发起
const char OR_OT_1 = '1';
/// 期权经营机构
const char OR_OT_2 = '2';
/// 机构投资者发起
const char OR_OT_3 = '3';
/// 自营交易发起
const char OR_OT_4 = '4';
/// 流动性服务提供商发起
const char OR_OT_5 = '5';
ORAPI const char* or_ownertype_enumstr(or_ownertype_e value);

/// 投资者名称
typedef char or_investorname_s[OR_INVESTORNAME_LEN];
/////////////////////////////////////////////////////////////////////////
/// InvestorLevelType是一个投资者交易等级类型
/////////////////////////////////////////////////////////////////////////
/// 投资者交易等级
typedef char or_investorlevel_e;
/// 一级
const char OR_IL_1 = '0';
/// 二级
const char OR_IL_2 = '1';
/// 三级
const char OR_IL_3 = '2';
/// 非交易级别，此级别investor不可交易
const char OR_IL_9 = '9';
ORAPI const char* or_investorlevel_enumstr(or_investorlevel_e value);

/// 用户代码
typedef char or_userid_s[OR_USERID_LEN];
/// 网关登录用户代码
typedef char or_gatewayuserid_s[OR_GATEWAYUSERID_LEN];
/// 用户名称
typedef char or_username_s[OR_USERNAME_LEN];
/// 策略代码
typedef char or_comboid_s[OR_COMBOID_LEN];
/// 策略名称
typedef char or_comboname_s[OR_COMBONAME_LEN];
/// 资产单元编号（UFX Only）
typedef char or_assetno_s[OR_ASSETNO_LEN];
/// 持仓限制
typedef double or_positionlimit_f;
/// 资金限制
typedef double or_creditlimit_f;
/// 备注
typedef char or_memo_s[OR_MEMO_LEN];
/// 价格
typedef double or_price_f;
/// 成交量
typedef int64_t or_volume_i;
/// 合约数量乘数
typedef int64_t or_volumemultiple_i;
/// 时间（毫秒）
typedef int64_t or_millisec_i;
/// 交易所交易员代码
typedef char or_branchpbu_s[OR_BRANCHPBU_LEN];
/// 序号
typedef int64_t or_sequenceno_i;
/// 资金账户代码
typedef char or_accountcode_s[OR_ACCOUNTCODE_LEN];
/////////////////////////////////////////////////////////////////////////
/// OrderPriceTypeType是一个报单价格条件类型
/////////////////////////////////////////////////////////////////////////
/// 报单价格条件
typedef char or_orderpricetype_e;
/// 任意价
const char OR_OPT_AnyPrice = '1';
/// 限价
const char OR_OPT_LimitPrice = '2';
/// 最优价
const char OR_OPT_BestPrice = '3';
/// 最新价
const char OR_OPT_LastPrice = '4';
/// 本方最新价
const char OR_OPT_LocalBestPrice = '5';
/// 五档最优价
const char OR_OPT_FiveLevelPrice = '6';
/// ETF申购
const char OR_OPT_PurchasesETF = 'd';
/// ETF赎回
const char OR_OPT_RedeemETF = 'e';
/// 科创板盘后固定价格委托
const char OR_OPT_KcCloseFixPrice = 'f';
/// 最新价浮动上浮1个ticks
const char OR_OPT_LastPricePlusOneTicks = 'A';
/// 最新价浮动上浮2个ticks
const char OR_OPT_LastPricePlusTwoTicks = 'B';
/// 最新价浮动上浮3个ticks
const char OR_OPT_LastPricePlusThreeTicks = 'C';
/// 卖一价
const char OR_OPT_AskPrice1 = 'D';
/// 卖一价浮动上浮1个ticks
const char OR_OPT_AskPrice1PlusOneTicks = 'E';
/// 卖一价浮动上浮2个ticks
const char OR_OPT_AskPrice1PlusTwoTicks = 'F';
/// 卖一价浮动上浮3个ticks
const char OR_OPT_AskPrice1PlusThreeTicks = 'G';
/// 买一价
const char OR_OPT_BidPrice1 = 'H';
/// 买一价浮动上浮1个ticks
const char OR_OPT_BidPrice1PlusOneTicks = 'I';
/// 买一价浮动上浮2个ticks
const char OR_OPT_BidPrice1PlusTwoTicks = 'J';
/// 买一价浮动上浮3个ticks
const char OR_OPT_BidPrice1PlusThreeTicks = 'K';
ORAPI const char* or_orderpricetype_enumstr(or_orderpricetype_e value);

/// 组合投机套保标志
typedef char or_combhedgeflag_s[OR_COMBHEDGEFLAG_LEN];
/////////////////////////////////////////////////////////////////////////
/// TimeConditionType是一个有效期类型类型
/////////////////////////////////////////////////////////////////////////
/// 有效期类型
typedef char or_timecondition_e;
/// 立即完成，否则撤销
const char OR_TC_IOC = '1';
/// 本节有效
const char OR_TC_GFS = '2';
/// 当日有效
const char OR_TC_GFD = '3';
/// 指定日期前有效
const char OR_TC_GTD = '4';
/// 撤销前有效
const char OR_TC_GTC = '5';
/// 集合竞价有效
const char OR_TC_GFA = '6';
ORAPI const char* or_timecondition_enumstr(or_timecondition_e value);

/////////////////////////////////////////////////////////////////////////
/// VolumeConditionType是一个成交量类型类型
/////////////////////////////////////////////////////////////////////////
/// 成交量类型
typedef char or_volumecondition_e;
/// 任何数量
const char OR_VC_AV = '1';
/// 最小数量
const char OR_VC_MV = '2';
/// 全部数量
const char OR_VC_CV = '3';
ORAPI const char* or_volumecondition_enumstr(or_volumecondition_e value);

/////////////////////////////////////////////////////////////////////////
/// ContingentConditionType是一个触发条件类型
/////////////////////////////////////////////////////////////////////////
/// 触发条件
typedef char or_contingentcondition_e;
/// 立即
const char OR_CC_Immediately = '1';
/// 止损
const char OR_CC_Touch = '2';
/// 止赢
const char OR_CC_TouchProfit = '3';
/// 预埋单
const char OR_CC_ParkedOrder = '4';
/// 最新价大于条件价
const char OR_CC_LastPriceGreaterThanStopPrice = '5';
/// 最新价大于等于条件价
const char OR_CC_LastPriceGreaterEqualStopPrice = '6';
/// 最新价小于条件价
const char OR_CC_LastPriceLesserThanStopPrice = '7';
/// 最新价小于等于条件价
const char OR_CC_LastPriceLesserEqualStopPrice = '8';
/// 卖一价大于条件价
const char OR_CC_AskPriceGreaterThanStopPrice = '9';
/// 卖一价大于等于条件价
const char OR_CC_AskPriceGreaterEqualStopPrice = 'A';
/// 卖一价小于条件价
const char OR_CC_AskPriceLesserThanStopPrice = 'B';
/// 卖一价小于等于条件价
const char OR_CC_AskPriceLesserEqualStopPrice = 'C';
/// 买一价大于条件价
const char OR_CC_BidPriceGreaterThanStopPrice = 'D';
/// 买一价大于等于条件价
const char OR_CC_BidPriceGreaterEqualStopPrice = 'E';
/// 买一价小于条件价
const char OR_CC_BidPriceLesserThanStopPrice = 'F';
/// 买一价小于等于条件价
const char OR_CC_BidPriceLesserEqualStopPrice = 'H';
ORAPI const char* or_contingentcondition_enumstr(or_contingentcondition_e value);

/////////////////////////////////////////////////////////////////////////
/// OrderStatusType是一个报单状态类型
/////////////////////////////////////////////////////////////////////////
/// 报单状态
typedef char or_orderstatus_e;
/// 未知
const char OR_OST_Unkfalsewn = '0';
/// 已提交
const char OR_OST_PendingNew = '1';
/// 已接收
const char OR_OST_New = '2';
/// 部分成交
const char OR_OST_PartilyFilled = '3';
/// 全部成交
const char OR_OST_Filled = '4';
/// 部分成交部分撤单
const char OR_OST_PartilyCanceled = '5';
/// 已撤单
const char OR_OST_Canceled = '6';
/// 已拒绝
const char OR_OST_Rejected = '7';
ORAPI const char* or_orderstatus_enumstr(or_orderstatus_e value);

/////////////////////////////////////////////////////////////////////////
/// OrderTypeType是一个报单类型类型
/////////////////////////////////////////////////////////////////////////
/// 报单类型
typedef char or_ordertype_e;
/// 正常
const char OR_ORDT_Normal = '0';
/// 报价衍生
const char OR_ORDT_DeriveFromQuote = '1';
/// 组合衍生
const char OR_ORDT_DeriveFromCombination = '2';
/// 组合报单
const char OR_ORDT_Combination = '3';
/// 条件单
const char OR_ORDT_ConditionalOrder = '4';
/// 互换单
const char OR_ORDT_Swap = '5';
ORAPI const char* or_ordertype_enumstr(or_ordertype_e value);

/// 前置编号
typedef int64_t or_frontid_i;
/// 会话编号
typedef int64_t or_sessionid_i;
/// 自定义引用编号
typedef char or_orderactionref_s[OR_ORDERACTIONREF_LEN];
/// 状态信息
typedef char or_statusmsg_s[OR_STATUSMSG_LEN];
/////////////////////////////////////////////////////////////////////////
/// PosiDirectionType是一个持仓多空方向类型
/////////////////////////////////////////////////////////////////////////
/// 持仓多空方向
typedef char or_posidirection_e;
/// 空头（期权则为义务方）
const char OR_PD_Short = '1';
/// 多头（期权则为权利方）
const char OR_PD_Long = '0';
/// 净
const char OR_PD_Net = '2';
ORAPI const char* or_posidirection_enumstr(or_posidirection_e value);

/////////////////////////////////////////////////////////////////////////
/// CapitalDirectionType是一个资金变化方向类型
/////////////////////////////////////////////////////////////////////////
/// 资金变化方向
typedef char or_capitaldirection_e;
/// 不变
const char OR_CPD_Nochange = '0';
/// 增加
const char OR_CPD_Increase = '1';
/// 减少
const char OR_CPD_Decrease = '2';
ORAPI const char* or_capitaldirection_enumstr(or_capitaldirection_e value);

/////////////////////////////////////////////////////////////////////////
/// PositionDirectionType是一个持仓变化方向类型
/////////////////////////////////////////////////////////////////////////
/// 持仓变化方向
typedef char or_positiondirection_e;
/// 不变
const char OR_PSD_Nochange = '0';
/// 增加
const char OR_PSD_Increase = '1';
/// 减少
const char OR_PSD_Decrease = '2';
ORAPI const char* or_positiondirection_enumstr(or_positiondirection_e value);

/////////////////////////////////////////////////////////////////////////
/// PositionDateType是一个持仓日期标志类型
/////////////////////////////////////////////////////////////////////////
/// 持仓日期标志
typedef char or_positiondate_e;
/// 今日持仓
const char OR_PSD_Today = '1';
/// 历史持仓
const char OR_PSD_History = '2';
ORAPI const char* or_positiondate_enumstr(or_positiondate_e value);

/// 最后修改毫秒
typedef int64_t or_updatemillisec_i;
/////////////////////////////////////////////////////////////////////////
/// TradingPhaseType是一个交易阶段类型
/////////////////////////////////////////////////////////////////////////
/// 交易阶段
typedef char or_tradingphase_e;
/// 非交易时段
const char OR_TP_NonTrade = '0';
/// 集合竞价时段
const char OR_TP_Bidding = '1';
/// 连续交易时段
const char OR_TP_Continuous = '2';
/// 停牌时段
const char OR_TP_Suspension = '3';
/// 熔断时段
const char OR_TP_Fuse = '4';
ORAPI const char* or_tradingphase_enumstr(or_tradingphase_e value);

/////////////////////////////////////////////////////////////////////////
/// OpenRestrictionType是一个开仓限制类型
/////////////////////////////////////////////////////////////////////////
/// 开仓限制
typedef char or_openrestriction_e;
/// 无开仓限制
const char OR_OR_None = '0';
/// 限制备兑开仓
const char OR_OR_NoCoverOpen = '1';
/// 限制卖出开仓
const char OR_OR_NoSellOpen = '2';
/// 限制卖出开仓、备兑开仓
const char OR_OR_NoSellAndCoverOpen = '3';
/// 限制买入开仓
const char OR_OR_NoBuyOpen = '4';
/// 限制买入开仓、备兑开仓
const char OR_OR_NoBuyAndCoverOpen = '5';
/// 限制买入开仓、卖出开仓
const char OR_OR_NoBuyAndSellOpen = '6';
/// 限制买入开仓、卖出开仓、备兑开仓
const char OR_OR_NoBuySellAndCoverOpen = '7';
ORAPI const char* or_openrestriction_enumstr(or_openrestriction_e value);

/////////////////////////////////////////////////////////////////////////
/// ErrorIDType是一个错误代码类型
/////////////////////////////////////////////////////////////////////////
/// 错误代码
typedef int or_errorid_ei;
/// 无错误
const int OR_ERR_OK = 0;
/// 通用错误值。
const int OR_ERR_FAIL = -1;
/// 意外的空指针传入
const int OR_ERR_NULLPTR = -2;
/// 未设定对应的SPI回调接口
const int OR_ERR_ADAPTER_HASNOSPI = -3;
/// 未知报文类型
const int OR_ERR_UNKNOWN_PACKAGETYPE = -4;
/// 持久化空间不足，不能支持更多通道
const int OR_ERR_NO_MORE_COUNTER_PERSIST = -5;
/// 报文未填入RequestID
const int OR_ERR_PACKAGE_NEED_ORREQUESTID = -6;
/// 报文未填入AccountCode
const int OR_ERR_PACKAGE_NEED_ACCOUNTCODE = -7;
/// 无效的投资者编号
const int OR_ERR_INVALID_INVESTORID = -100;
/// 无效的通道编号
const int OR_ERR_INVALID_CHANNELID = -101;
/// 柜台/交易所无法连接
const int OR_ERR_FAIL_COUNTERNOTCONNECTED = -102;
/// 不支持的通道类型
const int OR_ERR_UNSUPPORTED_CHANNELTYPE = -103;
/// 通道初始化失败！
const int OR_ERR_FAIL_INIT_CHANNEL = -104;
/// T2SDK报文初始化失败
const int OR_ERR_T2SDK_NEWPACKERFAILED = -200;
/// T2SDK报文发送失败
const int OR_ERR_T2SDK_SENDBIZMSGFAIL = -201;
/// 委托被柜台/交易所拒绝
const int OR_ERR_ENTRUST_REJECTED = 10000;
/// 撤单失败
const int OR_ERR_CANCEL_REJECTED = 10001;
/// 重复成交编号
const int OR_ERR_DUPLICATE_TRADE = 10002;
/// 交易所通告委托失败
const int OR_ERR_RTNORDER_REJECTED = 10003;
/// 非实际成交（被过滤的成交回报）
const int OR_ERR_DUMMY_TRADE = 10004;
/// 柜台登录失败
const int OR_ERR_COUNTER_LOGIN_FAILED = 10005;
/// 通道与Investor不对应
const int OR_ERR_NO_INVESTORID = 10006;
/// 柜台/交易所先返回成交委托状态，再返回成交回报
const int OR_ERR_ORDER_BEFORE_TRADE = 10007;
/// 无法创建发送到柜台的报文，一般因为InvestorID无法匹配
const int OR_ERR_FAIL_PACK_TO_COUNTER = 10008;
/// 资金划拨失败
const int OR_ERR_ASSET_TRANSFER_FAIL = 10009;
/// 柜台/交易所未连接
const int OR_ERR_COUNTER_NOT_CONNECTED = 10010;
/// 委托已处于终结状态，缓存已被删除。
const int OR_ERR_DELETED_FINAL_ORDER = 10011;
/// Adapter不支持的功能。
const int OR_ERR_NOT_SUPPORTED_BY_ADAPTER = 10012;
/// Adapter查询失败。
const int OR_ERR_QUERY_FAIL_BY_ADAPTER = 10013;
/// Adapter解析JSON请求失败。
const int OR_ERR_JSON_PARSE_FAIL_BY_ADAPTER = 10014;
ORAPI const char* or_errorid_enumstr(or_errorid_ei value);

/// 结束标志
typedef bool or_islast_b;
/// 错误信息
typedef char or_errormsg_s[OR_ERRORMSG_LEN];
/// 可用组合列表（以|分割）
typedef char or_comboidlist_s[OR_COMBOIDLIST_LEN];
/// 合约交易代码
typedef char or_instrumentcode_s[OR_INSTRUMENTCODE_LEN];
/////////////////////////////////////////////////////////////////////////
/// PositionTypeType是一个持仓类型类型
/////////////////////////////////////////////////////////////////////////
/// 持仓类型
typedef char or_positiontype_e;
/// 净持仓
const char OR_PT_Net = '1';
/// 综合持仓
const char OR_PT_Gross = '2';
ORAPI const char* or_positiontype_enumstr(or_positiontype_e value);

/////////////////////////////////////////////////////////////////////////
/// PositionHistoryTypeType是一个是否使用历史持仓类型
/////////////////////////////////////////////////////////////////////////
/// 是否使用历史持仓
typedef char or_positionhistorytype_e;
/// 使用历史持仓
const char OR__UseHistory = '1';
/// 不使用历史持仓
const char OR__NoUseHistory = '2';
ORAPI const char* or_positionhistorytype_enumstr(or_positionhistorytype_e value);

/// 交易所名称
typedef char or_exchangename_s[OR_EXCHANGENAME_LEN];
/// 席位名称
typedef char or_seatname_s[OR_SEATNAME_LEN];
/////////////////////////////////////////////////////////////////////////
/// InvestorTypeType是一个投资者类型类型
/////////////////////////////////////////////////////////////////////////
/// 投资者类型
typedef char or_investortype_e;
/// 自然人
const char OR_IT_Person = '1';
/// 法人
const char OR_IT_Company = '2';
/// 投资基金
const char OR_IT_Fund = '3';
/// 特殊法人
const char OR_IT_SpecialOrgan = '4';
/// 资管户
const char OR_IT_Asset = '5';
/// 系统管理员
const char OR_IT_Admin = 'a';
ORAPI const char* or_investortype_enumstr(or_investortype_e value);

/////////////////////////////////////////////////////////////////////////
/// IDCardTypeType是一个证件类型类型
/////////////////////////////////////////////////////////////////////////
/// 证件类型
typedef char or_idcardtype_e;
/// 组织机构代码
const char OR_DCT_EID = '0';
/// 中国公民身份证
const char OR_DCT_IDCard = '1';
/// 军官证
const char OR_DCT_OfficerIDCard = '2';
/// 警官证
const char OR_DCT_PoliceIDCard = '3';
/// 士兵证
const char OR_DCT_SoldierIDCard = '4';
/// 户口簿
const char OR_DCT_HouseholdRegister = '5';
/// 护照
const char OR_DCT_Passport = '6';
/// 台胞证
const char OR_DCT_TaiwanCompatriotIDCard = '7';
/// 回乡证
const char OR_DCT_HomeComingCard = '8';
/// 营业执照号
const char OR_DCT_LicenseNo = '9';
/// 税务登记号/当地纳税ID
const char OR_DCT_TaxNo = 'A';
/// 港澳居民来往内地通行证
const char OR_DCT_HMMainlandTravelPermit = 'B';
/// 台湾居民来往大陆通行证
const char OR_DCT_TwMainlandTravelPermit = 'C';
/// 驾照
const char OR_DCT_DrivingLicense = 'D';
/// 当地社保ID
const char OR_DCT_SocialID = 'F';
/// 当地身份证
const char OR_DCT_LocalID = 'G';
/// 商业登记证
const char OR_DCT_BusinessRegistration = 'H';
/// 港澳永久性居民身份证
const char OR_DCT_HKMCIDCard = 'I';
/// 人行开户许可证
const char OR_DCT_AccountsPermits = 'J';
/// 外国人永久居留证
const char OR_DCT_PermanantResidence = 'K';
/// 资管产品备案函
const char OR_DCT_AssetProductRecord = 'L';
/// 其他证件
const char OR_DCT_OtherCard = 'x';
ORAPI const char* or_idcardtype_enumstr(or_idcardtype_e value);

/// 证件号
typedef char or_idcardno_s[OR_IDCARDNO_LEN];
/// 股东代码
typedef char or_tradecode_s[OR_TRADECODE_LEN];
/// 缺省状态
typedef bool or_isdefault_b;
/// 投资者账户子编码
typedef char or_optclientid_s[OR_OPTCLIENTID_LEN];
/////////////////////////////////////////////////////////////////////////
/// OptCommissionTypeType是一个期权费用类型类型
/////////////////////////////////////////////////////////////////////////
/// 期权费用类型
typedef char or_optcommissiontype_e;
/// 行权费
const char OR_OPT_CT_StrikeFee = '1';
/// 被行权费
const char OR_OPT_CT_BeStrikeDFee = '2';
/// 行权过户费
const char OR_OPT_CT_TransferFee = '3';
/// 经手费
const char OR_OPT_CT_Brokerage = '4';
/// 交易费
const char OR_OPT_CT_TradeFee = '5';
/// 结算费
const char OR_OPT_CT_SettleFee = '6';
ORAPI const char* or_optcommissiontype_enumstr(or_optcommissiontype_e value);

/////////////////////////////////////////////////////////////////////////
/// CommDirectionType是一个委托方向类型
/////////////////////////////////////////////////////////////////////////
/// 委托方向
typedef char or_commdirection_e;
/// 买开
const char OR_CD_BuyOpen = '1';
/// 买平
const char OR_CD_BuyClose = '2';
/// 卖开
const char OR_CD_SellOpen = '3';
/// 卖平
const char OR_CD_SellClose = '4';
/// 行权认购
const char OR_CD_CallStrike = '5';
/// 行权认沽
const char OR_CD_PutStrike = '6';
ORAPI const char* or_commdirection_enumstr(or_commdirection_e value);

/// 是否按比例上浮
typedef bool or_isfloat_b;
/// 分组编号
typedef char or_groupid_s[OR_GROUPID_LEN];
/// 分组名称
typedef char or_groupname_s[OR_GROUPNAME_LEN];
/// 组织架构代码
typedef char or_departmentid_s[OR_DEPARTMENTID_LEN];
/// 上级组织架构代码
typedef char or_parentid_s[OR_PARENTID_LEN];
/// 组织架构名称
typedef char or_deptname_s[OR_DEPTNAME_LEN];
/// 操作员名称
typedef char or_operatorname_s[OR_OPERATORNAME_LEN];
/// 产品名称
typedef char or_productname_s[OR_PRODUCTNAME_LEN];
/// 投资单元代码
typedef char or_investunitid_s[OR_INVESTUNITID_LEN];
/// 席位号
typedef char or_seatid_s[OR_SEATID_LEN];
/// 资金账户名称
typedef char or_accountname_s[OR_ACCOUNTNAME_LEN];
/// 币种代码
typedef char or_currencyid_s[OR_CURRENCYID_LEN];
/// 投资单元名称
typedef char or_investunitname_s[OR_INVESTUNITNAME_LEN];
/////////////////////////////////////////////////////////////////////////
/// OptionsTypeType是一个期权类型类型
/////////////////////////////////////////////////////////////////////////
/// 期权类型
typedef char or_optionstype_e;
/// 认购
const char OR_OPT_TY_Call = 'C';
/// 认沽
const char OR_OPT_TY_Put = 'P';
ORAPI const char* or_optionstype_enumstr(or_optionstype_e value);

/// 投资组合代码
typedef char or_portfolioid_s[OR_PORTFOLIOID_LEN];
/////////////////////////////////////////////////////////////////////////
/// SystemStatusType是一个系统状态类型
/////////////////////////////////////////////////////////////////////////
/// 系统状态
typedef char or_systemstatus_e;
/// 导入数据完成
const char OR_STS_SyncDone = '1';
/// 盘中交易状态
const char OR_STS_Trading = '2';
/// 收市完成
const char OR_STS_Closed = '3';
/// 结算完成
const char OR_STS_Settled = '4';
ORAPI const char* or_systemstatus_enumstr(or_systemstatus_e value);

/// 规则编号
typedef int64_t or_ruleid_i;
/// 规则代码
typedef char or_rulecode_s[OR_RULECODE_LEN];
/// 规则ID
typedef int64_t or_riskid_i;
/// 规则名称
typedef char or_rulename_s[OR_RULENAME_LEN];
/// 修改内容明细（json字符串）
typedef char or_value_s[OR_VALUE_LEN];
/// 预留字段1
typedef char or_thirdreff1_s[OR_THIRDREFF1_LEN];
/// 预留字段2
typedef char or_thirdreff2_s[OR_THIRDREFF2_LEN];
/// 投资者代码集合
typedef char or_investorids_s[OR_INVESTORIDS_LEN];
/// 合约代码集合
typedef char or_instrumentids_s[OR_INSTRUMENTIDS_LEN];
/////////////////////////////////////////////////////////////////////////
/// InstrumentRangeType是一个合约范围类型
/////////////////////////////////////////////////////////////////////////
/// 合约范围
typedef char or_instrumentrange_e;
/// 所有
const char OR_INSTR_ALL = '1';
/// 产品类型
const char OR_INSTR_PRODUCT_CLASS = '2';
/// 单一合约
const char OR_INSTR_SINGLE = '3';
ORAPI const char* or_instrumentrange_enumstr(or_instrumentrange_e value);

/// 合约联合风控
typedef bool or_instrumentcontrolflag_b;
/// 投资账户联合风控
typedef bool or_investorcontrolflag_b;
/////////////////////////////////////////////////////////////////////////
/// SeatTypeType是一个席位类型类型
/////////////////////////////////////////////////////////////////////////
/// 席位类型
typedef char or_seattype_e;
/// 上交所期权
const char OR_ST_SHOPT = '1';
/// 上交所股票
const char OR_ST_SHSTK = '2';
/// 深交所期权
const char OR_ST_SZOPT = '3';
/// 深交所股票
const char OR_ST_SZSTK = '4';
/// 飞马
const char OR_ST_FEMAS = '5';
ORAPI const char* or_seattype_enumstr(or_seattype_e value);

/// 网关编号
typedef int64_t or_gatewayid_i;
/// 前置地址
typedef char or_frontaddress_s[OR_FRONTADDRESS_LEN];
/////////////////////////////////////////////////////////////////////////
/// ResumeTypeType是一个私有流重传方式类型
/////////////////////////////////////////////////////////////////////////
/// 私有流重传方式
typedef char or_resumetype_e;
/// 重传
const char OR_RT_Restart = '0';
/// 续传
const char OR_RT_Resume = '1';
/// 当前开始
const char OR_RT_Quick = '2';
ORAPI const char* or_resumetype_enumstr(or_resumetype_e value);

/// 流文件路径
typedef char or_flowpath_s[OR_FLOWPATH_LEN];
/// 指令代码
typedef char or_admincode_s[OR_ADMINCODE_LEN];
/// 指令代码
typedef char or_adminstatuscode_s[OR_ADMINSTATUSCODE_LEN];
/// 规则阀值
typedef double or_threshold_f;
/// 计算指标值
typedef double or_calcvalue_f;
/// 基础商品乘数
typedef int64_t or_underlyingmultiple_i;
/// 公司编号
typedef int64_t or_companyid_i;
/// 公司名称
typedef char or_companyname_s[OR_COMPANYNAME_LEN];
/////////////////////////////////////////////////////////////////////////
/// OpTypeType是一个操作员类型类型
/////////////////////////////////////////////////////////////////////////
/// 操作员类型
typedef char or_optype_e;
/// 客户管理员
const char OR_OT_MANAGE = '1';
/// 客户交易员
const char OR_OT_TRADE = '2';
/// 客户风控员
const char OR_OT_RISK = '3';
/// 系统运营人员
const char OR_OT_OPERATE = '4';
ORAPI const char* or_optype_enumstr(or_optype_e value);

/// 操作员可以查询的账户集合
typedef char or_qryaccountids_s[OR_QRYACCOUNTIDS_LEN];
/// 操作员可以操作的账户集合
typedef char or_opaccountids_s[OR_OPACCOUNTIDS_LEN];
/// 账户编号
typedef int64_t or_accountid_i;
/////////////////////////////////////////////////////////////////////////
/// AccountTypeType是一个账户类型类型
/////////////////////////////////////////////////////////////////////////
/// 账户类型
typedef char or_accounttype_e;
/// 普通证券账户
const char OR_AT_STOCK = '1';
/// 信用账户
const char OR_AT_CREDIT = '2';
/// 衍生品账户
const char OR_AT_DERIVATIVE = '3';
/// 期货账户
const char OR_AT_FUTURES = '4';
ORAPI const char* or_accounttype_enumstr(or_accounttype_e value);

/////////////////////////////////////////////////////////////////////////
/// StatusType是一个账户状态类型
/////////////////////////////////////////////////////////////////////////
/// 账户状态
typedef char or_status_e;
/// 正常
const char OR_ST_NORMAL = '1';
/// 冻结
const char OR_ST_FROZEN = '2';
ORAPI const char* or_status_enumstr(or_status_e value);

/// 交易通道编号
typedef int64_t or_channelid_i;
/// 默认组合
typedef int64_t or_defaultcombo_i;
/// 客户号
typedef char or_clientid_s[OR_CLIENTID_LEN];
/// 通道名称
typedef char or_channelname_s[OR_CHANNELNAME_LEN];
/////////////////////////////////////////////////////////////////////////
/// ChannelTypeType是一个通道类型类型
/////////////////////////////////////////////////////////////////////////
/// 通道类型
typedef char or_channeltype_e;
/// Dynamic
const char OR_CHT_Dynamic = '0';
/// UFT分仓
const char OR_CHT_UFT = '1';
/// CTP分仓
const char OR_CHT_CTP = '2';
/// 飞马分仓
const char OR_CHT_FEMAS = '3';
/// O32分仓
const char OR_CHT_O32 = '4';
/// 模拟交易所
const char OR_CHT_SIMULATE = '5';
/// UF2.0期权交易通道
const char OR_CHT_Uf20Opt = '6';
/// 华锐ATP交易通道
const char OR_CHT_HuaruiATP = '7';
/// QMT文件单通道
const char OR_CHT_QmtFile = 'F';
/// IBTWS通道
const char OR_CHT_IBTws = 'I';
/// JINZ通道
const char OR_CHT_JINZ = 'J';
/// LTS交易通道
const char OR_CHT_LTS = 'L';
/// CTP-MINI分仓
const char OR_CHT_CTPMINI = 'M';
/// QMT增强交易通道
const char OR_CHT_QMTEnhance = 'Q';
/// STP期权交易通道
const char OR_CHT_StpOpt = 'S';
/// TFTrade交易通道
const char OR_CHT_TFTrade = 'T';
/// TradeX交易通道
const char OR_CHT_TradeX = 'X';
ORAPI const char* or_channeltype_enumstr(or_channeltype_e value);

/// 分仓接口IP
typedef char or_sysip_s[OR_SYSIP_LEN];
/// 分仓接口端口
typedef char or_sysport_s[OR_SYSPORT_LEN];
/////////////////////////////////////////////////////////////////////////
/// FeeTypeType是一个费用类别类型
/////////////////////////////////////////////////////////////////////////
/// 费用类别
typedef char or_feetype_e;
/// 交易费
const char OR_FT_TRADEFEE = '1';
/// 印花税
const char OR_FT_STAMPTAX = '2';
/// 过户费
const char OR_FT_TRANSFERFEE = '3';
/// 佣金
const char OR_FT_BROKERFEE = '4';
/// 经手费
const char OR_FT_HANDLINGFEE = '5';
/// 证管费
const char OR_FT_ADMINFEE = '6';
/// 其它费
const char OR_FT_OTHERFEE = '7';
/// 结算费
const char OR_FT_CLEARINGFEE = 'a';
/// 交割费
const char OR_FT_SETTLEFEE = 'b';
/// 委托申报费
const char OR_FT_PERORDER = 'c';
/// 撤单申报费
const char OR_FT_PERCANCEL = 'd';
ORAPI const char* or_feetype_enumstr(or_feetype_e value);

/////////////////////////////////////////////////////////////////////////
/// CalculateTypeType是一个费用计算模式类型
/////////////////////////////////////////////////////////////////////////
/// 费用计算模式
typedef char or_calculatetype_e;
/// 分笔
const char OR_CT_TOTAL = '1';
/// 合笔
const char OR_CT_PER = '2';
ORAPI const char* or_calculatetype_enumstr(or_calculatetype_e value);

/// 备注
typedef char or_remark_s[OR_REMARK_LEN];
/////////////////////////////////////////////////////////////////////////
/// CancelFlagType是一个撤单标志类型
/////////////////////////////////////////////////////////////////////////
/// 撤单标志
typedef char or_cancelflag_e;
/// 普通委托
const char OR_CF_ORDER = '1';
/// 撤单委托
const char OR_CF_CANCEL = '2';
ORAPI const char* or_cancelflag_enumstr(or_cancelflag_e value);

/// 订单IP
typedef char or_orderip_s[OR_ORDERIP_LEN];
/// 订单MAC
typedef char or_ordermac_s[OR_ORDERMAC_LEN];
/// 订单硬盘序列号
typedef char or_orderhdnum_s[OR_ORDERHDNUM_LEN];
/// 订单机器码
typedef char or_ordermaccode_s[OR_ORDERMACCODE_LEN];
/// 订单操作系统
typedef char or_orderos_s[OR_ORDEROS_LEN];
/////////////////////////////////////////////////////////////////////////
/// TradeTypeType是一个成交回报类型类型
/////////////////////////////////////////////////////////////////////////
/// 成交回报类型
typedef char or_tradetype_e;
/// 委托确认
const char OR_RTS_Entrust = '1';
/// 委托废单
const char OR_RTS_Fail = '2';
/// 成交
const char OR_RTS_Fill = '3';
/// 撤单成交
const char OR_RTS_CancelFill = '4';
/// 撤单废单
const char OR_RTS_CancelFail = '5';
ORAPI const char* or_tradetype_enumstr(or_tradetype_e value);

/////////////////////////////////////////////////////////////////////////
/// TradeTypeFuturesType是一个成交类型类型
/////////////////////////////////////////////////////////////////////////
/// 成交类型
typedef char or_tradetypefutures_e;
/// 组合持仓拆分为单一持仓,初始化不应包含该类型的持仓
const char OR_TRDT_SplitCombination = '#';
/// 普通成交
const char OR_TRDT_Common = '0';
/// 期权执行
const char OR_TRDT_OptionsExecution = '1';
/// OTC成交
const char OR_TRDT_OTC = '2';
/// 期转现衍生成交
const char OR_TRDT_EFPDerived = '3';
/// 组合衍生成交
const char OR_TRDT_CombinationDerived = '4';
ORAPI const char* or_tradetypefutures_enumstr(or_tradetypefutures_e value);

/////////////////////////////////////////////////////////////////////////
/// StockRealBackType是一个回报证券标志类型
/////////////////////////////////////////////////////////////////////////
/// 回报证券标志
typedef char or_stockrealback_e;
/// 买入证券当天不可用
const char OR_SRB_FALSE = '0';
/// 买入证当天可用
const char OR_SRB_TRUE = '1';
ORAPI const char* or_stockrealback_enumstr(or_stockrealback_e value);

/////////////////////////////////////////////////////////////////////////
/// FundRealBackType是一个回报资金标志类型
/////////////////////////////////////////////////////////////////////////
/// 回报资金标志
typedef char or_fundrealback_e;
/// 卖出资金不可用
const char OR_FRB_FALSE = '0';
/// 卖出资金当天可用
const char OR_FRB_TRUE = '1';
ORAPI const char* or_fundrealback_enumstr(or_fundrealback_e value);

/// 定位串
typedef char or_positionstr_s[OR_POSITIONSTR_LEN];
/// 资金划拨信息
typedef char or_transferinfo_s[OR_TRANSFERINFO_LEN];
/////////////////////////////////////////////////////////////////////////
/// TransferDirectionType是一个资金划拨方向类型
/////////////////////////////////////////////////////////////////////////
/// 资金划拨方向
typedef char or_transferdirection_e;
/// 1-UF20到UFT
const char OR_ATD_UF20ToUFT = '1';
/// 2-UFT到UF20
const char OR_ATD_UFTToUF20 = '2';
/// ATP转入
const char OR_ATD_ATPInto = '3';
/// ATP转出
const char OR_ATD_ATPOut = '4';
/// ATP节点间按照证券账户划转资金
const char OR_ATD_ATPExternalAccountTransfer = '5';
ORAPI const char* or_transferdirection_enumstr(or_transferdirection_e value);

/// 接入柜台的IP和端口号列表
typedef char or_ufxt2sdkservers_s[OR_UFXT2SDKSERVERS_LEN];
/// 许可证文件名称
typedef char or_ufxt2sdklicensefilename_s[OR_UFXT2SDKLICENSEFILENAME_LEN];
/// 许可证密码
typedef char or_ufxt2sdklicensepwd_s[OR_UFXT2SDKLICENSEPWD_LEN];
/// 自动重连
typedef bool or_ufxt2sdkautoconnect_b;
/////////////////////////////////////////////////////////////////////////
/// UfxT2sdkEntrustWayType是一个委托方式类型
/////////////////////////////////////////////////////////////////////////
/// 委托方式
typedef char or_ufxt2sdkentrustway_e;
ORAPI const char* or_ufxt2sdkentrustway_enumstr(or_ufxt2sdkentrustway_e value);

/// UFT20柜台BatchNo偏移量
typedef int64_t or_ufxbatchnooffset_i;
/// 使用UF20柜台的功能号
typedef char or_uft20uf20functions_s[OR_UFT20UF20FUNCTIONS_LEN];
/// UF20系统号
typedef int64_t or_uft20uf20systemno_i;
/// UFT2系统号
typedef int64_t or_uft20uft2systemno_i;
/// 自动查询交易和委托的时间间隔
typedef int64_t or_uft20syncinterval_i;
/// T2SDK收发日志开关
typedef bool or_ufxt2sdksendrecvlog_b;
/// IPv4地址
typedef char or_ipv4address_s[OR_IPV4ADDRESS_LEN];
/// IPv4端口号
typedef int64_t or_ipv4port_i;
/// 通道连接自定义参数
typedef char or_channelcustomconfig_s[OR_CHANNELCUSTOMCONFIG_LEN];
/// STP期权柜台服务器地址
typedef char or_stpoptionserveraddress_s[OR_STPOPTIONSERVERADDRESS_LEN];
/// STP期权柜台服务器端口
typedef int64_t or_stpoptionserverport_i;
/// QMT增强模块标识
typedef char or_qmtenhancemoduletag_s[OR_QMTENHANCEMODULETAG_LEN];
/// 证券公司TDX编号
typedef int64_t or_tdxcompanyid_i;
/// 通达信客户端的版本号
typedef char or_tdxclientversion_s[OR_TDXCLIENTVERSION_LEN];
/// 通达信查询睡眠时间
typedef int64_t or_tdxsleepmsqry_i;
/// 通达信交易睡眠时间
typedef int64_t or_tdxsleepmstrd_i;
/// 使用担保品买卖
typedef int64_t or_buysellcollateral_i;
/// 使用分页查询
typedef int64_t or_tdxpagedquery_i;
/// Broker IND
typedef char or_tdxbrokerind_s[OR_TDXBROKERIND_LEN];
/////////////////////////////////////////////////////////////////////////
/// BizTypeType是一个业务类型类型
/////////////////////////////////////////////////////////////////////////
/// 业务类型
typedef char or_biztype_e;
/// 行权
const char OR_BT_Exercise = 'R';
/// 锁定/解锁
const char OR_BT_Covered = 'C';
ORAPI const char* or_biztype_enumstr(or_biztype_e value);

/////////////////////////////////////////////////////////////////////////
/// BizDirectionType是一个业务方向类型
/////////////////////////////////////////////////////////////////////////
/// 业务方向
typedef char or_bizdirection_e;
/// 行权/锁定
const char OR_BD_Operate = '1';
/// 撤销/解锁
const char OR_BD_Cancel = '2';
ORAPI const char* or_bizdirection_enumstr(or_bizdirection_e value);

/// O32订阅服务器
typedef char or_o32subscribeservers_s[OR_O32SUBSCRIBESERVERS_LEN];
/// O32操作员代码
typedef char or_o32operatorno_s[OR_O32OPERATORNO_LEN];
/// O32操作员密码
typedef char or_o32operatorpwd_s[OR_O32OPERATORPWD_LEN];
/// O32组合编号
typedef char or_o32combino_s[OR_O32COMBINO_LEN];
/// O32资产单元编号
typedef char or_o32assetno_s[OR_O32ASSETNO_LEN];
/// 登录机器MAC地址
typedef char or_loginmac_s[OR_LOGINMAC_LEN];
/// 登录机器IP地址
typedef char or_loginip_s[OR_LOGINIP_LEN];
/// 登录机器硬盘序列号
typedef char or_orderhdvolserial_s[OR_ORDERHDVOLSERIAL_LEN];
/// 登录站点
typedef char or_o32opstation_s[OR_O32OPSTATION_LEN];
/// O32开发者授权编号
typedef char or_o32authorizationid_s[OR_O32AUTHORIZATIONID_LEN];
/// O32登录令牌
typedef char or_o32usertoken_s[OR_O32USERTOKEN_LEN];
/// O32-UFX版本
typedef char or_o32versionno_s[OR_O32VERSIONNO_LEN];
/// O32基金代码
typedef char or_o32accountcode_s[OR_O32ACCOUNTCODE_LEN];
/// 订阅主题
typedef char or_o32topicname_s[OR_O32TOPICNAME_LEN];
/// 业务名称
typedef char or_o32bizname_s[OR_O32BIZNAME_LEN];
/////////////////////////////////////////////////////////////////////////
/// EnbFlagType是一个业务方向类型
/////////////////////////////////////////////////////////////////////////
/// 业务方向
typedef char or_enbflag_e;
/// 正常
const char OR_EFG_Normal = 'N';
/// 新增未同步
const char OR_EFG_New = '1';
ORAPI const char* or_enbflag_enumstr(or_enbflag_e value);

/// 组合开平标识
typedef char or_comboffsetflag_s[OR_COMBOFFSETFLAG_LEN];
/////////////////////////////////////////////////////////////////////////
/// TradingCodeTypeType是一个交易编码类型类型
/////////////////////////////////////////////////////////////////////////
/// 交易编码类型
typedef char or_tradingcodetype_e;
/// 投机
const char OR_TC_Speculation = '1';
/// 套利
const char OR_TC_Arbitrage = '2';
/// 套保
const char OR_TC_Hedge = '3';
/// 做市商
const char OR_TC_MarketMaker = '4';
ORAPI const char* or_tradingcodetype_enumstr(or_tradingcodetype_e value);

/// 申购代码
typedef char or_collectcode_s[OR_COLLECTCODE_LEN];
/////////////////////////////////////////////////////////////////////////
/// LuckyStatusType是一个中签状态类型
/////////////////////////////////////////////////////////////////////////
/// 中签状态
typedef char or_luckystatus_e;
/// 待明确
const char OR_LS_Waiting = '0';
/// 未中签
const char OR_LS_Unlucky = '1';
/// 已中签
const char OR_LS_Lucky = '2';
ORAPI const char* or_luckystatus_enumstr(or_luckystatus_e value);

/// CTP运行配置类型
typedef char or_ctprunningmode_s[OR_CTPRUNNINGMODE_LEN];
/// 交易接入地址
typedef char or_ctptradeaddr_s[OR_CTPTRADEADDR_LEN];
/// 行情接入地址
typedef char or_ctpmdaddr_s[OR_CTPMDADDR_LEN];
/// 用户验证码
typedef char or_ctpauthcode_s[OR_CTPAUTHCODE_LEN];
/// 应用编号
typedef char or_ctpappid_s[OR_CTPAPPID_LEN];
/// 产品信息
typedef char or_ctpproductinfo_s[OR_CTPPRODUCTINFO_LEN];
/// 先收到已成委托时进行补单
typedef bool or_faketradeonrtnorder_b;
/////////////////////////////////////////////////////////////////////////
/// SubProductClassType是一个证券二级类别类型
/////////////////////////////////////////////////////////////////////////
/// 证券二级类别
typedef char or_subproductclass_e;
/// 科创板股票
const char OR_SPC_KC = '1';
/// 其他
const char OR_SPC_Other = '0';
ORAPI const char* or_subproductclass_enumstr(or_subproductclass_e value);

/// 负债合约编号
typedef char or_compactid_s[OR_COMPACTID_LEN];
/// LTS运行配置文件路径
typedef char or_ltsconfigpath_s[OR_LTSCONFIGPATH_LEN];
/////////////////////////////////////////////////////////////////////////
/// RateTypeType是一个计算方式类型
/////////////////////////////////////////////////////////////////////////
/// 计算方式
typedef char or_ratetype_e;
/// 按手数
const char OR_RT_ByVolume = '1';
/// 按金额
const char OR_RT_ByMoney = '2';
/// 按面值
const char OR_RT_ByFace = '3';
ORAPI const char* or_ratetype_enumstr(or_ratetype_e value);

/// 费率值
typedef double or_rate_f;
/// 比率
typedef double or_ratio_f;
/// 资金
typedef double or_money_f;
/// 合约在交易所的代码
typedef char or_exchangeinstid_s[OR_EXCHANGEINSTID_LEN];
/// 会员代码
typedef char or_participantid_s[OR_PARTICIPANTID_LEN];
/// 柜台连接验证后查询持仓委托成交
typedef bool or_startupqryposordertrade_b;
/// 结算编号
typedef int64_t or_settlementid_i;
/// 年份
typedef int64_t or_year_i;
/// 月份
typedef int64_t or_month_i;
/////////////////////////////////////////////////////////////////////////
/// InstLifePhaseType是一个合约生命周期状态类型
/////////////////////////////////////////////////////////////////////////
/// 合约生命周期状态
typedef char or_instlifephase_e;
/// 未上市
const char OR_IP_NotStart = '0';
/// 上市
const char OR_IP_Started = '1';
/// 停牌
const char OR_IP_Pause = '2';
/// 到期
const char OR_IP_Expired = '3';
ORAPI const char* or_instlifephase_enumstr(or_instlifephase_e value);

/////////////////////////////////////////////////////////////////////////
/// MaxMarginSideAlgorithmType是一个大额单边保证金算法类型
/////////////////////////////////////////////////////////////////////////
/// 大额单边保证金算法
typedef char or_maxmarginsidealgorithm_e;
/// 不使用大额单边保证金算法
const char OR_MMSA_NO = '0';
/// 使用大额单边保证金算法
const char OR_MMSA_YES = '1';
ORAPI const char* or_maxmarginsidealgorithm_enumstr(or_maxmarginsidealgorithm_e value);

/// 组合类型
typedef char or_combinetype_s[OR_COMBINETYPE_LEN];
/////////////////////////////////////////////////////////////////////////
/// CombinationTypeType是一个组合类型类型
/////////////////////////////////////////////////////////////////////////
/// 组合类型
typedef char or_combinationtype_e;
/// 期货组合
const char OR_COMBT_Future = '0';
/// 垂直价差BUL
const char OR_COMBT_BUL = '1';
/// 垂直价差BER
const char OR_COMBT_BER = '2';
/// 跨式组合
const char OR_COMBT_STD = '3';
/// 宽跨式组合
const char OR_COMBT_STG = '4';
/// 备兑组合
const char OR_COMBT_PRT = '5';
/// 时间价差组合
const char OR_COMBT_CLD = '6';
ORAPI const char* or_combinationtype_enumstr(or_combinationtype_e value);

/// 文件完整路径和文件名
typedef char or_filepath_s[OR_FILEPATH_LEN];
/// QMT通道号
typedef int64_t or_qmtchannelid_i;
/// QMT策略名称
typedef char or_qmtstrategyname_s[OR_QMTSTRATEGYNAME_LEN];
/// QMT交易类型
typedef int64_t or_qmttradingtype_i;
/// QMT账号组
typedef char or_qmtaccountgroup_s[OR_QMTACCOUNTGROUP_LEN];
/// QMT分单类型
typedef int64_t or_qmtslicetype_i;
/// QMT文件单查询回复周期(毫秒)
typedef int64_t or_qmtfetchresultintervalms_i;
/// IBTWS通道编号
typedef char or_ibtwschannelid_s[OR_IBTWSCHANNELID_LEN];
/// TWS行情数据类型
typedef int64_t or_ibtwsmarketdatatype_i;
/// 收取实时快照
typedef bool or_ibtwssnapshot_b;
/// 客户端ID
typedef int64_t or_ibtwsclientid_i;
/// 存储Tick
typedef int64_t or_ibtwssavetick_i;
/// Tick文件路径
typedef char or_ibtwstickfile_s[OR_IBTWSTICKFILE_LEN];
/// 存储Snapshot
typedef int64_t or_ibtwssavesnapshot_i;
/// Snapshot文件路径
typedef char or_ibtwssnapshotfile_s[OR_IBTWSSNAPSHOTFILE_LEN];
/// 自动订阅合约
typedef char or_ibtwsinstruments_s[OR_IBTWSINSTRUMENTS_LEN];
/////////////////////////////////////////////////////////////////////////
/// ReqSwitchType是一个请求开关类型
/////////////////////////////////////////////////////////////////////////
/// 请求开关
typedef char or_reqswitch_e;
/// 打开开关
const char OR_RS_OFF = '0';
/// 关闭开关
const char OR_RS_ON = '1';
ORAPI const char* or_reqswitch_enumstr(or_reqswitch_e value);

/////////////////////////////////////////////////////////////////////////
/// CloseHistoryTypeType是一个平仓时自动优先平今平昨类型
/////////////////////////////////////////////////////////////////////////
/// 平仓时自动优先平今平昨
typedef char or_closehistorytype_e;
/// 不自动执行平仓处理
const char OR_CLSH_None = '0';
/// 优先平昨
const char OR_CLSH_CloseYesterday = '1';
/// 优先平昨
const char OR_CLSH_CloseToday = '2';
ORAPI const char* or_closehistorytype_enumstr(or_closehistorytype_e value);

/// 系统模块名称
typedef char or_modulename_s[OR_MODULENAME_LEN];
/// 状态名称
typedef char or_statuscode_s[OR_STATUSCODE_LEN];
/////////////////////////////////////////////////////////////////////////
/// QuoteDirectionType是一个行情盘口类型类型
/////////////////////////////////////////////////////////////////////////
/// 行情盘口类型
typedef char or_quotedirection_e;
/// 卖盘
const char OR_QTD_Ask = 'S';
/// 买盘
const char OR_QTD_Bid = 'L';
ORAPI const char* or_quotedirection_enumstr(or_quotedirection_e value);

/////////////////////////////////////////////////////////////////////////
/// QuotePosIndexType是一个行情盘口档位类型
/////////////////////////////////////////////////////////////////////////
/// 行情盘口档位
typedef char or_quoteposindex_e;
/// 价位1
const char OR_QPI_Index1 = '0';
/// 价位2
const char OR_QPI_Index2 = '1';
/// 价位3
const char OR_QPI_Index3 = '2';
/// 价位4
const char OR_QPI_Index4 = '3';
/// 价位5
const char OR_QPI_Index5 = '4';
/// 价位6
const char OR_QPI_Index6 = '5';
/// 价位7
const char OR_QPI_Index7 = '6';
/// 价位8
const char OR_QPI_Index8 = '7';
/// 价位9
const char OR_QPI_Index9 = '8';
/// 价位10
const char OR_QPI_Index10 = '9';
ORAPI const char* or_quoteposindex_enumstr(or_quoteposindex_e value);

/// 行情数据类型
typedef int64_t or_marketdatatype_i;
/// Nano时间戳
typedef int64_t or_timestampnano_i;
/// 时间间隔
typedef int64_t or_intervalmilliseconds_i;
/// 订阅的TID类型列表
typedef char or_subscribetids_s[OR_SUBSCRIBETIDS_LEN];
/////////////////////////////////////////////////////////////////////////
/// TradeFlagType是一个逐笔成交执行标志类型
/////////////////////////////////////////////////////////////////////////
/// 逐笔成交执行标志
typedef char or_tradeflag_e;
/// SH,外盘,主动买
const char OR_TTF_Buy = 'B';
/// SH,内盘,主动卖
const char OR_TTF_Sell = 'S';
/// SH,外盘,主动买
const char OR_TTF_Unknown = 'N';
/// SZ,主动或自动撤单执行
const char OR_TTF_Auto = '4';
/// SZ,成交执行
const char OR_TTF_Fill = 'F';
ORAPI const char* or_tradeflag_enumstr(or_tradeflag_e value);

/////////////////////////////////////////////////////////////////////////
/// ChannelLoadTypeType是一个通道创建类型类型
/////////////////////////////////////////////////////////////////////////
/// 通道创建类型
typedef char or_channelloadtype_e;
/// 从动态库加载
const char OR_LLD_Dynamic = 'D';
/// 从内置代码类加载
const char OR_LLD_Static = 'S';
ORAPI const char* or_channelloadtype_enumstr(or_channelloadtype_e value);

/// 交易通道唯一标识
typedef char or_channelloadid_s[OR_CHANNELLOADID_LEN];
/// JinZ增强模块标识
typedef char or_jinzserveraddress_s[OR_JINZSERVERADDRESS_LEN];
/// JinZ增强模块标识
typedef int64_t or_jinzserverport_i;
/////////////////////////////////////////////////////////////////////////
/// jinzchannelType是一个JinZ增强模块标识类型
/////////////////////////////////////////////////////////////////////////
/// JinZ增强模块标识
typedef char or_jinzchannel_e;
ORAPI const char* or_jinzchannel_enumstr(or_jinzchannel_e value);

/// JinZ增强模块标识
typedef char or_jinzstropsite_s[OR_JINZSTROPSITE_LEN];
/// JinZ增强模块标识
typedef char or_jinzusercode_s[OR_JINZUSERCODE_LEN];
/// JinZ增强模块标识
typedef char or_jinzauthdata_s[OR_JINZAUTHDATA_LEN];
/// JinZ增强模块标识
typedef char or_jinzencryptkey_s[OR_JINZENCRYPTKEY_LEN];
/// JinZ增强模块标识
typedef char or_jinzthirdparty_s[OR_JINZTHIRDPARTY_LEN];
/////////////////////////////////////////////////////////////////////////
/// FislCashTypeType是一个头寸类型类型
/////////////////////////////////////////////////////////////////////////
/// 头寸类型
typedef char or_fislcashtype_e;
ORAPI const char* or_fislcashtype_enumstr(or_fislcashtype_e value);

/////////////////////////////////////////////////////////////////////////
/// CompactTypeType是一个合约类别类型
/////////////////////////////////////////////////////////////////////////
/// 合约类别
typedef char or_compacttype_e;
/// 融资
const char OR_CMT_FinCompact = '0';
/// 融券
const char OR_CMT_SloCompact = '1';
/// 其他负债
const char OR_CMT_OtherCompact = '2';
ORAPI const char* or_compacttype_enumstr(or_compacttype_e value);

/////////////////////////////////////////////////////////////////////////
/// CompactStatusType是一个合约状态类型
/////////////////////////////////////////////////////////////////////////
/// 合约状态
typedef char or_compactstatus_e;
/// 开仓未归还
const char OR_CS_NoReturn = '0';
/// 部分归还
const char OR_CS_PartReturn = '1';
/// 合约已过期
const char OR_CS_OutofDate = '2';
/// 客户自行了结
const char OR_CS_SelfDone = '3';
/// 手工了结
const char OR_CS_ManualDone = '4';
/// 未形成负债
const char OR_CS_NoCom = '5';
ORAPI const char* or_compactstatus_enumstr(or_compactstatus_e value);

/////////////////////////////////////////////////////////////////////////
/// CompactSourceType是一个头寸性质类型
/////////////////////////////////////////////////////////////////////////
/// 头寸性质
typedef char or_compactsource_e;
/// 公用
const char OR_CSR_Share = '0';
/// 专项头寸
const char OR_CSR_Special = '1';
ORAPI const char* or_compactsource_enumstr(or_compactsource_e value);

/// 头寸编号
typedef int64_t or_cashgroupid_i;
/////////////////////////////////////////////////////////////////////////
/// CashGroupType是一个头寸性质类型
/////////////////////////////////////////////////////////////////////////
/// 头寸性质
typedef char or_cashgroup_e;
/// 核心头寸
const char OR_CG_CoreCash = '0';
/// 普通业务头寸
const char OR_CG_NorCash = '1';
/// 专项业务头寸
const char OR_CG_SpecCash = '2';
ORAPI const char* or_cashgroup_enumstr(or_cashgroup_e value);

/// 扩展信息
typedef char or_extendfield_s[OR_EXTENDFIELD_LEN];
/////////////////////////////////////////////////////////////////////////
/// AssureStatusType是一个担保品状态类型
/////////////////////////////////////////////////////////////////////////
/// 担保品状态
typedef char or_assurestatus_e;
/// 正常
const char OR_AS_Normal = '0';
/// 暂停
const char OR_AS_PAUSE = '1';
/// 作废
const char OR_AS_INVALID = '2';
ORAPI const char* or_assurestatus_enumstr(or_assurestatus_e value);

/////////////////////////////////////////////////////////////////////////
/// FinStatusType是一个融资状态类型
/////////////////////////////////////////////////////////////////////////
/// 融资状态
typedef char or_finstatus_e;
/// 正常
const char OR_FS_Normal = '0';
/// 暂停
const char OR_FS_PAUSE = '1';
/// 作废
const char OR_FS_INVALID = '2';
ORAPI const char* or_finstatus_enumstr(or_finstatus_e value);

/////////////////////////////////////////////////////////////////////////
/// SloStatusType是一个融券状态类型
/////////////////////////////////////////////////////////////////////////
/// 融券状态
typedef char or_slostatus_e;
/// 正常
const char OR_SS_Normal = '0';
/// 暂停
const char OR_SS_PAUSE = '1';
/// 作废
const char OR_SS_INVALID = '2';
ORAPI const char* or_slostatus_enumstr(or_slostatus_e value);

/// 查询请求编号
typedef int64_t or_qtprequestid_i;
/// 查询会话编号
typedef int64_t or_qtpsessionid_i;
/// 查询前置编号
typedef int64_t or_qtpfrontid_i;
/////////////////////////////////////////////////////////////////////////
/// TFMdpTypeType是一个行情类型类型
/////////////////////////////////////////////////////////////////////////
/// 行情类型
typedef char or_tfmdptype_e;
/// 实时行情
const char OR_MDPT_RealTime = '1';
/// 实时组播行情
const char OR_MDPT_RealMulticast = '2';
/// 压缩实时行情
const char OR_MDPT_ZipRealTime = 'a';
ORAPI const char* or_tfmdptype_enumstr(or_tfmdptype_e value);

/// JSON请求的自定义类型
typedef int64_t or_jsontypeid_i;
/// JSON请求内容
typedef char or_jsoncontent_s[OR_JSONCONTENT_LEN];
/// 期权组合策略代码（必填），比如'PNSJC认沽牛市价差策略'等。
typedef char or_optionscombstrategyid_s[OR_OPTIONSCOMBSTRATEGYID_LEN];
/// 期权组合策略组合编码，OffsetFlag开平方向为解除时需要填，组合时不需要填
typedef char or_optionscombsecondaryorderid_s[OR_OPTIONSCOMBSECONDARYORDERID_LEN];
/// 当前期权组合合约腿数
typedef int64_t or_optionscomblegnum_i;

/// 上海证券交易所
static const char* OR_EXCHANGE_SSE = "SH";
/// 深圳证券交易所
static const char* OR_EXCHANGE_SZSE = "SZ";
/// 中国金融期货交易所
static const char* OR_EXCHANGE_CFFEX = "CFFEX";
/// 上海期货交易所
static const char* OR_EXCHANGE_SHFE = "SHFE";
/// 大连商品交易所
static const char* OR_EXCHANGE_DCE = "DCE";
/// 郑州商品交易所
static const char* OR_EXCHANGE_CZCE = "CZCE";
/// 能源交易所
static const char* OR_EXCHANGE_INE = "INE";

} // namespace ort
} // namespace cycnoches
#endif
