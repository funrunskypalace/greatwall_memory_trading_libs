

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
/// ��������
/////////////////////////////////////////////////////////////////////////
const int INVALID_ORREQUESTID = 0;
const int INVALID_INVESTORID = 0;
const int INVALID_CHANNELID = 0;
/// ��Ȩ��ϲ����������
const int OR_OPTIONSCOMB_LEG_NUM = 4;

/// ��Ȩ��Լ��֧�ֵ���ϲ����б��ַ�������
#define XTP_CNTRT_COMB_STRA_LIST_LEN         2048


/// �˻���Ϣ���ȵĶ���
const int OR_ACCOUNTINFO_LEN = (500 + 1);
/// �ͻ���ID���ȵĶ���
const int OR_O32APPID_LEN = (30 + 1);
/// �ն���Ȩ�볤�ȵĶ���
const int OR_O32AUTHORIZECODE_LEN = (30 + 1);
/// ��̨������ų��ȵĶ���
const int OR_COUNTERORDERID_LEN = (16 + 1);
/// ���ù�̨������ų��ȵĶ���
const int OR_REFCOUNTERORDERID_LEN = (16 + 1);
/// ������ų��ȵĶ���
const int OR_ORDERSYSID_LEN = (16 + 1);
/// ���ر�����ų��ȵĶ���
const int OR_ORDERLOCALID_LEN = (50 + 1);
/// �ɽ���ų��ȵĶ���
const int OR_TRADEID_LEN = (20 + 1);
/// �������ó��ȵĶ���
const int OR_ORDERREF_LEN = (50 + 1);
/// �ļ�·�����ȵĶ���
const int OR_FILEPATHNAME_LEN = (255 + 1);
/// ��Լ���볤�ȵĶ���
const int OR_INSTRUMENTID_LEN = (30 + 1);
/// ���������볤�ȵĶ���
const int OR_EXCHANGEID_LEN = (8 + 1);
/// ��Լ���Ƴ��ȵĶ���
const int OR_INSTRUMENTNAME_LEN = (20 + 1);
/// ��Ʒ���볤�ȵĶ���
const int OR_PRODUCTID_LEN = (30 + 1);
/// ���͹�˾���볤�ȵĶ���
const int OR_BROKERID_LEN = (10 + 1);
/// ĸ�˻����볤�ȵĶ���
const int OR_BROKERINVESTORID_LEN = (32 + 1);
/// UFX����Ա���볤�ȵĶ���
const int OR_UFXOPERATORID_LEN = (32 + 1);
/// ��ʹ�õ�UFX��ϴ��볤�ȵĶ���
const int OR_UFXCOMBOID_LEN = (16 + 1);
/// ĸ�˻����Ƴ��ȵĶ���
const int OR_BROKERINVESTORNAME_LEN = (80 + 1);
/// ���볤�ȵĶ���
const int OR_PASSWORD_LEN = (130 + 1);
/// ��Ȩ���˻����볤�ȵĶ���
const int OR_OPTSUBINVESTORID_LEN = (8 + 1);
/// ϯλ�ų��ȵĶ���
const int OR_BUSINESSUNIT_LEN = (5 + 1);
/// Ӫҵ�����볤�ȵĶ���
const int OR_BRANCHID_LEN = (5 + 1);
/// Ͷ�������Ƴ��ȵĶ���
const int OR_INVESTORNAME_LEN = (80 + 1);
/// �û����볤�ȵĶ���
const int OR_USERID_LEN = (14 + 1);
/// ���ص�¼�û����볤�ȵĶ���
const int OR_GATEWAYUSERID_LEN = (14 + 1);
/// �û����Ƴ��ȵĶ���
const int OR_USERNAME_LEN = (80 + 1);
/// ���Դ��볤�ȵĶ���
const int OR_COMBOID_LEN = (8 + 1);
/// �������Ƴ��ȵĶ���
const int OR_COMBONAME_LEN = (80 + 1);
/// �ʲ���Ԫ��ţ�UFX Only�����ȵĶ���
const int OR_ASSETNO_LEN = (16 + 1);
/// ��ע���ȵĶ���
const int OR_MEMO_LEN = (80 + 1);
/// ����������Ա���볤�ȵĶ���
const int OR_BRANCHPBU_LEN = (20 + 1);
/// �ʽ��˻����볤�ȵĶ���
const int OR_ACCOUNTCODE_LEN = (127 + 1);
/// ���Ͷ���ױ���־���ȵĶ���
const int OR_COMBHEDGEFLAG_LEN = (4 + 1);
/// �Զ������ñ�ų��ȵĶ���
const int OR_ORDERACTIONREF_LEN = (10 + 1);
/// ״̬��Ϣ���ȵĶ���
const int OR_STATUSMSG_LEN = (80 + 1);
/// ������Ϣ���ȵĶ���
const int OR_ERRORMSG_LEN = (80 + 1);
/// ��������б���|�ָ���ȵĶ���
const int OR_COMBOIDLIST_LEN = (512 + 1);
/// ��Լ���״��볤�ȵĶ���
const int OR_INSTRUMENTCODE_LEN = (20 + 1);
/// ���������Ƴ��ȵĶ���
const int OR_EXCHANGENAME_LEN = (50 + 1);
/// ϯλ���Ƴ��ȵĶ���
const int OR_SEATNAME_LEN = (50 + 1);
/// ֤���ų��ȵĶ���
const int OR_IDCARDNO_LEN = (100 + 1);
/// �ɶ����볤�ȵĶ���
const int OR_TRADECODE_LEN = (19 + 1);
/// Ͷ�����˻��ӱ��볤�ȵĶ���
const int OR_OPTCLIENTID_LEN = (10 + 1);
/// �����ų��ȵĶ���
const int OR_GROUPID_LEN = (14 + 1);
/// �������Ƴ��ȵĶ���
const int OR_GROUPNAME_LEN = (50 + 1);
/// ��֯�ܹ����볤�ȵĶ���
const int OR_DEPARTMENTID_LEN = (14 + 1);
/// �ϼ���֯�ܹ����볤�ȵĶ���
const int OR_PARENTID_LEN = (14 + 1);
/// ��֯�ܹ����Ƴ��ȵĶ���
const int OR_DEPTNAME_LEN = (50 + 1);
/// ����Ա���Ƴ��ȵĶ���
const int OR_OPERATORNAME_LEN = (20 + 1);
/// ��Ʒ���Ƴ��ȵĶ���
const int OR_PRODUCTNAME_LEN = (50 + 1);
/// Ͷ�ʵ�Ԫ���볤�ȵĶ���
const int OR_INVESTUNITID_LEN = (14 + 1);
/// ϯλ�ų��ȵĶ���
const int OR_SEATID_LEN = (10 + 1);
/// �ʽ��˻����Ƴ��ȵĶ���
const int OR_ACCOUNTNAME_LEN = (50 + 1);
/// ���ִ��볤�ȵĶ���
const int OR_CURRENCYID_LEN = (3 + 1);
/// Ͷ�ʵ�Ԫ���Ƴ��ȵĶ���
const int OR_INVESTUNITNAME_LEN = (50 + 1);
/// Ͷ����ϴ��볤�ȵĶ���
const int OR_PORTFOLIOID_LEN = (14 + 1);
/// ������볤�ȵĶ���
const int OR_RULECODE_LEN = (128 + 1);
/// �������Ƴ��ȵĶ���
const int OR_RULENAME_LEN = (50 + 1);
/// �޸�������ϸ��json�ַ��������ȵĶ���
const int OR_VALUE_LEN = (256 + 1);
/// Ԥ���ֶ�1���ȵĶ���
const int OR_THIRDREFF1_LEN = (20 + 1);
/// Ԥ���ֶ�2���ȵĶ���
const int OR_THIRDREFF2_LEN = (50 + 1);
/// Ͷ���ߴ��뼯�ϳ��ȵĶ���
const int OR_INVESTORIDS_LEN = (256 + 1);
/// ��Լ���뼯�ϳ��ȵĶ���
const int OR_INSTRUMENTIDS_LEN = (512 + 1);
/// ǰ�õ�ַ���ȵĶ���
const int OR_FRONTADDRESS_LEN = (31 + 1);
/// ���ļ�·�����ȵĶ���
const int OR_FLOWPATH_LEN = (127 + 1);
/// ָ����볤�ȵĶ���
const int OR_ADMINCODE_LEN = (32 + 1);
/// ָ����볤�ȵĶ���
const int OR_ADMINSTATUSCODE_LEN = (32 + 1);
/// ��˾���Ƴ��ȵĶ���
const int OR_COMPANYNAME_LEN = (50 + 1);
/// ����Ա���Բ�ѯ���˻����ϳ��ȵĶ���
const int OR_QRYACCOUNTIDS_LEN = (500 + 1);
/// ����Ա���Բ������˻����ϳ��ȵĶ���
const int OR_OPACCOUNTIDS_LEN = (500 + 1);
/// �ͻ��ų��ȵĶ���
const int OR_CLIENTID_LEN = (50 + 1);
/// ͨ�����Ƴ��ȵĶ���
const int OR_CHANNELNAME_LEN = (50 + 1);
/// �ֲֽӿ�IP���ȵĶ���
const int OR_SYSIP_LEN = (20 + 1);
/// �ֲֽӿڶ˿ڳ��ȵĶ���
const int OR_SYSPORT_LEN = (10 + 1);
/// ��ע���ȵĶ���
const int OR_REMARK_LEN = (200 + 1);
/// ����IP���ȵĶ���
const int OR_ORDERIP_LEN = (20 + 1);
/// ����MAC���ȵĶ���
const int OR_ORDERMAC_LEN = (20 + 1);
/// ����Ӳ�����кų��ȵĶ���
const int OR_ORDERHDNUM_LEN = (50 + 1);
/// ���������볤�ȵĶ���
const int OR_ORDERMACCODE_LEN = (50 + 1);
/// ��������ϵͳ���ȵĶ���
const int OR_ORDEROS_LEN = (50 + 1);
/// ��λ�����ȵĶ���
const int OR_POSITIONSTR_LEN = (100 + 1);
/// �ʽ𻮲���Ϣ���ȵĶ���
const int OR_TRANSFERINFO_LEN = (500 + 1);
/// �����̨��IP�Ͷ˿ں��б��ȵĶ���
const int OR_UFXT2SDKSERVERS_LEN = (256 + 1);
/// ���֤�ļ����Ƴ��ȵĶ���
const int OR_UFXT2SDKLICENSEFILENAME_LEN = (128 + 1);
/// ���֤���볤�ȵĶ���
const int OR_UFXT2SDKLICENSEPWD_LEN = (64 + 1);
/// ʹ��UF20��̨�Ĺ��ܺų��ȵĶ���
const int OR_UFT20UF20FUNCTIONS_LEN = (200 + 1);
/// IPv4��ַ���ȵĶ���
const int OR_IPV4ADDRESS_LEN = (64 + 1);
/// ͨ�������Զ���������ȵĶ���
const int OR_CHANNELCUSTOMCONFIG_LEN = (2048 + 1);
/// STP��Ȩ��̨��������ַ���ȵĶ���
const int OR_STPOPTIONSERVERADDRESS_LEN = (64 + 1);
/// QMT��ǿģ���ʶ���ȵĶ���
const int OR_QMTENHANCEMODULETAG_LEN = (64 + 1);
/// ͨ���ſͻ��˵İ汾�ų��ȵĶ���
const int OR_TDXCLIENTVERSION_LEN = (64 + 1);
/// Broker IND���ȵĶ���
const int OR_TDXBROKERIND_LEN = (16 + 1);
/// O32���ķ��������ȵĶ���
const int OR_O32SUBSCRIBESERVERS_LEN = (255 + 1);
/// O32����Ա���볤�ȵĶ���
const int OR_O32OPERATORNO_LEN = (15 + 1);
/// O32����Ա���볤�ȵĶ���
const int OR_O32OPERATORPWD_LEN = (15 + 1);
/// O32��ϱ�ų��ȵĶ���
const int OR_O32COMBINO_LEN = (15 + 1);
/// O32�ʲ���Ԫ��ų��ȵĶ���
const int OR_O32ASSETNO_LEN = (15 + 1);
/// ��¼����MAC��ַ���ȵĶ���
const int OR_LOGINMAC_LEN = (19 + 1);
/// ��¼����IP��ַ���ȵĶ���
const int OR_LOGINIP_LEN = (14 + 1);
/// ��¼����Ӳ�����кų��ȵĶ���
const int OR_ORDERHDVOLSERIAL_LEN = (127 + 1);
/// ��¼վ�㳤�ȵĶ���
const int OR_O32OPSTATION_LEN = (255 + 1);
/// O32��������Ȩ��ų��ȵĶ���
const int OR_O32AUTHORIZATIONID_LEN = (63 + 1);
/// O32��¼���Ƴ��ȵĶ���
const int OR_O32USERTOKEN_LEN = (511 + 1);
/// O32-UFX�汾���ȵĶ���
const int OR_O32VERSIONNO_LEN = (31 + 1);
/// O32������볤�ȵĶ���
const int OR_O32ACCOUNTCODE_LEN = (31 + 1);
/// �������ⳤ�ȵĶ���
const int OR_O32TOPICNAME_LEN = (63 + 1);
/// ҵ�����Ƴ��ȵĶ���
const int OR_O32BIZNAME_LEN = (63 + 1);
/// ��Ͽ�ƽ��ʶ���ȵĶ���
const int OR_COMBOFFSETFLAG_LEN = (4 + 1);
/// �깺���볤�ȵĶ���
const int OR_COLLECTCODE_LEN = (30 + 1);
/// CTP�����������ͳ��ȵĶ���
const int OR_CTPRUNNINGMODE_LEN = (100 + 1);
/// ���׽����ַ���ȵĶ���
const int OR_CTPTRADEADDR_LEN = (100 + 1);
/// ��������ַ���ȵĶ���
const int OR_CTPMDADDR_LEN = (100 + 1);
/// �û���֤�볤�ȵĶ���
const int OR_CTPAUTHCODE_LEN = (100 + 1);
/// Ӧ�ñ�ų��ȵĶ���
const int OR_CTPAPPID_LEN = (100 + 1);
/// ��Ʒ��Ϣ���ȵĶ���
const int OR_CTPPRODUCTINFO_LEN = (100 + 1);
/// ��ծ��Լ��ų��ȵĶ���
const int OR_COMPACTID_LEN = (32 + 1);
/// LTS���������ļ�·�����ȵĶ���
const int OR_LTSCONFIGPATH_LEN = (255 + 1);
/// ��Լ�ڽ������Ĵ��볤�ȵĶ���
const int OR_EXCHANGEINSTID_LEN = (30 + 1);
/// ��Ա���볤�ȵĶ���
const int OR_PARTICIPANTID_LEN = (10 + 1);
/// ������ͳ��ȵĶ���
const int OR_COMBINETYPE_LEN = (24 + 1);
/// �ļ�����·�����ļ������ȵĶ���
const int OR_FILEPATH_LEN = (256 + 1);
/// QMT�������Ƴ��ȵĶ���
const int OR_QMTSTRATEGYNAME_LEN = (64 + 1);
/// QMT�˺��鳤�ȵĶ���
const int OR_QMTACCOUNTGROUP_LEN = (64 + 1);
/// IBTWSͨ����ų��ȵĶ���
const int OR_IBTWSCHANNELID_LEN = (64 + 1);
/// Tick�ļ�·�����ȵĶ���
const int OR_IBTWSTICKFILE_LEN = (128 + 1);
/// Snapshot�ļ�·�����ȵĶ���
const int OR_IBTWSSNAPSHOTFILE_LEN = (128 + 1);
/// �Զ����ĺ�Լ���ȵĶ���
const int OR_IBTWSINSTRUMENTS_LEN = (256 + 1);
/// ϵͳģ�����Ƴ��ȵĶ���
const int OR_MODULENAME_LEN = (18 + 1);
/// ״̬���Ƴ��ȵĶ���
const int OR_STATUSCODE_LEN = (18 + 1);
/// ���ĵ�TID�����б��ȵĶ���
const int OR_SUBSCRIBETIDS_LEN = (500 + 1);
/// ����ͨ��Ψһ��ʶ���ȵĶ���
const int OR_CHANNELLOADID_LEN = (64 + 1);
/// JinZ��ǿģ���ʶ���ȵĶ���
const int OR_JINZSERVERADDRESS_LEN = (64 + 1);
/// JinZ��ǿģ���ʶ���ȵĶ���
const int OR_JINZSTROPSITE_LEN = (256 + 1);
/// JinZ��ǿģ���ʶ���ȵĶ���
const int OR_JINZUSERCODE_LEN = (32 + 1);
/// JinZ��ǿģ���ʶ���ȵĶ���
const int OR_JINZAUTHDATA_LEN = (32 + 1);
/// JinZ��ǿģ���ʶ���ȵĶ���
const int OR_JINZENCRYPTKEY_LEN = (32 + 1);
/// JinZ��ǿģ���ʶ���ȵĶ���
const int OR_JINZTHIRDPARTY_LEN = (32 + 1);
/// ��չ��Ϣ���ȵĶ���
const int OR_EXTENDFIELD_LEN = (256 + 1);
/// JSON�������ݳ��ȵĶ���
const int OR_JSONCONTENT_LEN = (4096 + 1);
/// ��Ȩ��ϲ��Դ��루���������'PNSJC�Ϲ�ţ�м۲����'�ȡ����ȵĶ���
const int OR_OPTIONSCOMBSTRATEGYID_LEN = (64 + 1);
/// ��Ȩ��ϲ�����ϱ��룬OffsetFlag��ƽ����Ϊ���ʱ��Ҫ����ʱ����Ҫ��ȵĶ���
const int OR_OPTIONSCOMBSECONDARYORDERID_LEN = (18 + 1);
/// �˻���Ϣ
typedef char or_accountinfo_s[OR_ACCOUNTINFO_LEN];
/// �ͻ���ID
typedef char or_o32appid_s[OR_O32APPID_LEN];
/// �ն���Ȩ��
typedef char or_o32authorizecode_s[OR_O32AUTHORIZECODE_LEN];
/// ����˿�
typedef int64_t or_o32portid_i;
/// OrderRouterί�б��
typedef int64_t or_orrequestid_i;
/// ����OrderRouterί�б��
typedef int64_t or_reforrequestid_i;
/// ��̨�������
typedef char or_counterorderid_s[OR_COUNTERORDERID_LEN];
/// ���ù�̨�������
typedef char or_refcounterorderid_s[OR_REFCOUNTERORDERID_LEN];
/// �������
typedef char or_ordersysid_s[OR_ORDERSYSID_LEN];
/// ���ر������
typedef char or_orderlocalid_s[OR_ORDERLOCALID_LEN];
/// �ɽ����
typedef char or_tradeid_s[OR_TRADEID_LEN];
/// ��������
typedef char or_orderref_s[OR_ORDERREF_LEN];
/// ��󱨵�����
typedef int64_t or_maxorderref_i;
/// ���͹�˾�������
typedef int64_t or_brokerorderseq_i;
/// ��������ţ������̨֧�֣����õĹ�̨���Զ����ֶΣ�
typedef int64_t or_thirdreff_i;
/// �ļ�·��
typedef char or_filepathname_s[OR_FILEPATHNAME_LEN];
/// ��Լ����
typedef char or_instrumentid_s[OR_INSTRUMENTID_LEN];
/// ����������
typedef char or_exchangeid_s[OR_EXCHANGEID_LEN];
/// ��Լ����
typedef char or_instrumentname_s[OR_INSTRUMENTNAME_LEN];
/// ��Ʒ����
typedef char or_productid_s[OR_PRODUCTID_LEN];
/////////////////////////////////////////////////////////////////////////
/// ProductClassType��һ����Ʒ��������
/////////////////////////////////////////////////////////////////////////
/// ��Ʒ����
typedef char or_productclass_e;
/// �ڻ�
const char OR_PC_Futures = '1';
/// ��Ȩ
const char OR_PC_Options = '2';
/// ��Ʊ
const char OR_PC_Stock = '3';
/// ծȯ
const char OR_PC_Bond = '4';
/// ����
const char OR_PC_Fund = '5';
/// ָ��
const char OR_PC_Index = '6';
/// Ȩ֤
const char OR_PC_Warrant = '7';
/// �ع�
const char OR_PC_Repo = '8';
/// ����
const char OR_PC_Other = '9';
/// �깺
const char OR_PC_SubscribePurchase = 'a';
ORAPI const char* or_productclass_enumstr(or_productclass_e value);

/// ��ǰ�Ƿ���
typedef bool or_istrading_b;
/// ����
typedef int64_t or_date_i;
/// ʱ��
typedef int64_t or_time_i;
/////////////////////////////////////////////////////////////////////////
/// InvestorRangeType��һ��Ͷ���߷�Χ����
/////////////////////////////////////////////////////////////////////////
/// Ͷ���߷�Χ
typedef char or_investorrange_e;
/// ����
const char OR_IR_All = '1';
/// Ͷ������
const char OR_IR_Group = '2';
/// ��һͶ����
const char OR_IR_Single = '3';
/// ����Ͷ�ʵ�Ԫ
const char OR_IR_AllInvestUnit = '4';
/// ��һͶ�ʵ�Ԫ
const char OR_IR_SingleInvestUnit = '5';
ORAPI const char* or_investorrange_enumstr(or_investorrange_e value);

/// ���͹�˾����
typedef char or_brokerid_s[OR_BROKERID_LEN];
/// ĸ�˻�����
typedef char or_brokerinvestorid_s[OR_BROKERINVESTORID_LEN];
/// UFX����Ա����
typedef char or_ufxoperatorid_s[OR_UFXOPERATORID_LEN];
/// ��ʹ�õ�UFX��ϴ���
typedef char or_ufxcomboid_s[OR_UFXCOMBOID_LEN];
/////////////////////////////////////////////////////////////////////////
/// DirectionType��һ��������������
/////////////////////////////////////////////////////////////////////////
/// ��������
typedef char or_direction_e;
/// ��
const char OR_D_Buy = '0';
/// ��
const char OR_D_Sell = '1';
/// ETF�깺
const char OR_D_ETFPur = '2';
/// ETF���
const char OR_D_ETFRed = '3';
/// �ֽ������ֻ�����ر�
const char OR_D_CashIn = '4';
/// ծȯ���
const char OR_D_PledgeBondIn = '5';
/// ծȯ����
const char OR_D_PledgeBondOut = '6';
/// ���
const char OR_D_Doublened = '7';
/// ת�й�
const char OR_D_DepositoryTransfer = '8';
/// �����˻����
const char OR_D_CreditDoublened = '9';
/// ����Ʒ����
const char OR_D_BuyCollateral = 'A';
/// ����Ʒ����
const char OR_D_SellCollateral = 'B';
/// ����Ʒת��
const char OR_D_CollateralTransferIn = 'C';
/// ����Ʒת��
const char OR_D_CollateralTransferOut = 'D';
/// ��������
const char OR_D_MarginTrade = 'E';
/// ��ȯ����
const char OR_D_ShortSell = 'F';
/// ��ȯ����
const char OR_D_RepayMargin = 'G';
/// ��ȯ��ȯ
const char OR_D_RepayStock = 'H';
/// ֱ�ӻ���
const char OR_D_DirectRepayMargin = 'I';
/// ֱ�ӻ�ȯ
const char OR_D_DirectRepayStock = 'J';
/// ��ȯ��ת
const char OR_D_ExcessStockTransfer = 'K';
/// OF�깺
const char OR_D_OFPur = 'L';
/// OF���
const char OR_D_OFRed = 'M';
/// SF���
const char OR_D_SFSplit = 'N';
/// SF�ϲ�
const char OR_D_SFMerge = 'O';
/// ����
const char OR_D_Covered = 'P';
/// ֤ȯ����(��)/�ⶳ(ƽ)
const char OR_D_Freeze = 'Q';
/// ��Ȩ
const char OR_D_Execute = 'R';
/// CB����
const char OR_D_CBRed = 'S';
/// CBת��
const char OR_D_CBConv = 'T';
/// OF�Ϲ�
const char OR_D_OFSub = 'U';
/// �����깺����תծ��
const char OR_D_StockPur = 'V';
/// ��Ȩ����(SH)
const char OR_D_LockOP = 'W';
/// ��Ȩ���(SH)
const char OR_D_UnLockOP = 'X';
/// ��Ȩ��ϲ��� ��ϺͲ��ҵ��
const char OR_D_OptionsCombine = 'Y';
/// ��Ȩ��Ȩ�ϲ�ҵ��
const char OR_D_ExecuteCombine = 'Z';
ORAPI const char* or_direction_enumstr(or_direction_e value);

/////////////////////////////////////////////////////////////////////////
/// OffsetFlagType��һ����ƽ��־����
/////////////////////////////////////////////////////////////////////////
/// ��ƽ��־
typedef char or_offsetflag_e;
/// ����
const char OR_OF_Open = '0';
/// ƽ��
const char OR_OF_Close = '1';
/// ǿƽ
const char OR_OF_ForceClose = '2';
/// ƽ��
const char OR_OF_CloseToday = '3';
/// ƽ��
const char OR_OF_CloseYesterday = '4';
/// ǿ��
const char OR_OF_ForceOff = '5';
/// ����ǿƽ
const char OR_OF_LocalForceClose = '6';
/// �Զ����п�ƽ���ж�
const char OR_OF_Auto = '7';
/// �Ϲ�
const char OR_OF_Call = '8';
/// �Ϲ�
const char OR_OF_Put = '9';
/// ��ϲ��Ե����
const char OR_OF_OptCombine = 'A';
/// ��ϲ��ԵĲ��
const char OR_OF_OptSplit = 'B';
/// ��ϲ��ԵĹ���Աǿ�Ʋ��
const char OR_OF_OptSplitForce = 'C';
/// ��ϲ��ԵĽ�����ǿ�Ʋ��
const char OR_OF_OptSplitForceExch = 'D';
ORAPI const char* or_offsetflag_enumstr(or_offsetflag_e value);

/////////////////////////////////////////////////////////////////////////
/// HedgeFlagType��һ��Ͷ���ױ���־����
/////////////////////////////////////////////////////////////////////////
/// Ͷ���ױ���־
typedef char or_hedgeflag_e;
/// Ͷ��
const char OR_HF_Speculation = '1';
/// ����
const char OR_HF_Arbitrage = '2';
/// �ױ�
const char OR_HF_Hedge = '3';
/// ������
const char OR_HF_MarketMaker = '4';
ORAPI const char* or_hedgeflag_enumstr(or_hedgeflag_e value);

/// �Ƿ���Խ�������ȡ
typedef bool or_isrelative_b;
/// ĸ�˻�����
typedef char or_brokerinvestorname_s[OR_BROKERINVESTORNAME_LEN];
/// ����Ա����
typedef int64_t or_operatorid_i;
/// ����
typedef char or_password_s[OR_PASSWORD_LEN];
/// ����Ա����
typedef int64_t or_tfoperatorid_i;
/// ����Ա�˺ű��
typedef int64_t or_tfaccountid_i;
/// ����Ա��ϱ��
typedef int64_t or_tfcomboid_i;
/////////////////////////////////////////////////////////////////////////
/// TFMarketDataTypeType��һ������Դ��������
/////////////////////////////////////////////////////////////////////////
/// ����Դ����
typedef char or_tfmarketdatatype_e;
/// ʵʱ���鶩��
const char OR_MDT_RMSSubscribe = '1';
/// ʵʱ�����鲥
const char OR_MDT_RMSMulticast = '2';
/// ��ʷ���鶩��
const char OR_MDT_HMSSubscribe = '3';
/// ʵʱָ�궩��
const char OR_MDT_RISSubscribe = '4';
/// ��ʷָ�궩��
const char OR_MDT_HISSubscribe = '5';
/// OTC���鶩��
const char OR_MDT_ORMSSubscribe = '6';
/// ʵʱ����ѹ������
const char OR_MDT_RMSCompressSubscribe = 'a';
ORAPI const char* or_tfmarketdatatype_enumstr(or_tfmarketdatatype_e value);

/////////////////////////////////////////////////////////////////////////
/// UserTypeType��һ���û���������
/////////////////////////////////////////////////////////////////////////
/// �û�����
typedef char or_usertype_e;
/// Ͷ����
const char OR_UT_Investor = '0';
/// ����Ա
const char OR_UT_Operator = '1';
/// ����Ա
const char OR_UT_SuperUser = '2';
ORAPI const char* or_usertype_enumstr(or_usertype_e value);

/// �Ƿ��Ծ
typedef bool or_isactive_b;
/// Ͷ���ߴ���
typedef int64_t or_investorid_i;
/// ��Ȩ���˻�����
typedef char or_optsubinvestorid_s[OR_OPTSUBINVESTORID_LEN];
/// ϯλ��
typedef char or_businessunit_s[OR_BUSINESSUNIT_LEN];
/// Ӫҵ������
typedef char or_branchid_s[OR_BRANCHID_LEN];
/////////////////////////////////////////////////////////////////////////
/// CoveredFlagType��һ�����ұ�־����
/////////////////////////////////////////////////////////////////////////
/// ���ұ�־
typedef char or_coveredflag_e;
/// �Ǳ���
const char OR_CF_Uncovered = '\0';
/// ����
const char OR_CF_Covered = '1';
/// ��ͨҵ��ͷ��
const char OR_CF_NorCash = '2';
/// ר��ҵ��ͷ��
const char OR_CF_SpecCash = '3';
ORAPI const char* or_coveredflag_enumstr(or_coveredflag_e value);

/////////////////////////////////////////////////////////////////////////
/// OwnerTypeType��һ�������־����
/////////////////////////////////////////////////////////////////////////
/// �����־
typedef char or_ownertype_e;
/// ����Ͷ����
const char OR_OT_0 = '0';
/// ����������
const char OR_OT_1 = '1';
/// ��Ȩ��Ӫ����
const char OR_OT_2 = '2';
/// ����Ͷ���߷���
const char OR_OT_3 = '3';
/// ��Ӫ���׷���
const char OR_OT_4 = '4';
/// �����Է����ṩ�̷���
const char OR_OT_5 = '5';
ORAPI const char* or_ownertype_enumstr(or_ownertype_e value);

/// Ͷ��������
typedef char or_investorname_s[OR_INVESTORNAME_LEN];
/////////////////////////////////////////////////////////////////////////
/// InvestorLevelType��һ��Ͷ���߽��׵ȼ�����
/////////////////////////////////////////////////////////////////////////
/// Ͷ���߽��׵ȼ�
typedef char or_investorlevel_e;
/// һ��
const char OR_IL_1 = '0';
/// ����
const char OR_IL_2 = '1';
/// ����
const char OR_IL_3 = '2';
/// �ǽ��׼��𣬴˼���investor���ɽ���
const char OR_IL_9 = '9';
ORAPI const char* or_investorlevel_enumstr(or_investorlevel_e value);

/// �û�����
typedef char or_userid_s[OR_USERID_LEN];
/// ���ص�¼�û�����
typedef char or_gatewayuserid_s[OR_GATEWAYUSERID_LEN];
/// �û�����
typedef char or_username_s[OR_USERNAME_LEN];
/// ���Դ���
typedef char or_comboid_s[OR_COMBOID_LEN];
/// ��������
typedef char or_comboname_s[OR_COMBONAME_LEN];
/// �ʲ���Ԫ��ţ�UFX Only��
typedef char or_assetno_s[OR_ASSETNO_LEN];
/// �ֲ�����
typedef double or_positionlimit_f;
/// �ʽ�����
typedef double or_creditlimit_f;
/// ��ע
typedef char or_memo_s[OR_MEMO_LEN];
/// �۸�
typedef double or_price_f;
/// �ɽ���
typedef int64_t or_volume_i;
/// ��Լ��������
typedef int64_t or_volumemultiple_i;
/// ʱ�䣨���룩
typedef int64_t or_millisec_i;
/// ����������Ա����
typedef char or_branchpbu_s[OR_BRANCHPBU_LEN];
/// ���
typedef int64_t or_sequenceno_i;
/// �ʽ��˻�����
typedef char or_accountcode_s[OR_ACCOUNTCODE_LEN];
/////////////////////////////////////////////////////////////////////////
/// OrderPriceTypeType��һ�������۸���������
/////////////////////////////////////////////////////////////////////////
/// �����۸�����
typedef char or_orderpricetype_e;
/// �����
const char OR_OPT_AnyPrice = '1';
/// �޼�
const char OR_OPT_LimitPrice = '2';
/// ���ż�
const char OR_OPT_BestPrice = '3';
/// ���¼�
const char OR_OPT_LastPrice = '4';
/// �������¼�
const char OR_OPT_LocalBestPrice = '5';
/// �嵵���ż�
const char OR_OPT_FiveLevelPrice = '6';
/// ETF�깺
const char OR_OPT_PurchasesETF = 'd';
/// ETF���
const char OR_OPT_RedeemETF = 'e';
/// �ƴ����̺�̶��۸�ί��
const char OR_OPT_KcCloseFixPrice = 'f';
/// ���¼۸����ϸ�1��ticks
const char OR_OPT_LastPricePlusOneTicks = 'A';
/// ���¼۸����ϸ�2��ticks
const char OR_OPT_LastPricePlusTwoTicks = 'B';
/// ���¼۸����ϸ�3��ticks
const char OR_OPT_LastPricePlusThreeTicks = 'C';
/// ��һ��
const char OR_OPT_AskPrice1 = 'D';
/// ��һ�۸����ϸ�1��ticks
const char OR_OPT_AskPrice1PlusOneTicks = 'E';
/// ��һ�۸����ϸ�2��ticks
const char OR_OPT_AskPrice1PlusTwoTicks = 'F';
/// ��һ�۸����ϸ�3��ticks
const char OR_OPT_AskPrice1PlusThreeTicks = 'G';
/// ��һ��
const char OR_OPT_BidPrice1 = 'H';
/// ��һ�۸����ϸ�1��ticks
const char OR_OPT_BidPrice1PlusOneTicks = 'I';
/// ��һ�۸����ϸ�2��ticks
const char OR_OPT_BidPrice1PlusTwoTicks = 'J';
/// ��һ�۸����ϸ�3��ticks
const char OR_OPT_BidPrice1PlusThreeTicks = 'K';
ORAPI const char* or_orderpricetype_enumstr(or_orderpricetype_e value);

/// ���Ͷ���ױ���־
typedef char or_combhedgeflag_s[OR_COMBHEDGEFLAG_LEN];
/////////////////////////////////////////////////////////////////////////
/// TimeConditionType��һ����Ч����������
/////////////////////////////////////////////////////////////////////////
/// ��Ч������
typedef char or_timecondition_e;
/// ������ɣ�������
const char OR_TC_IOC = '1';
/// ������Ч
const char OR_TC_GFS = '2';
/// ������Ч
const char OR_TC_GFD = '3';
/// ָ������ǰ��Ч
const char OR_TC_GTD = '4';
/// ����ǰ��Ч
const char OR_TC_GTC = '5';
/// ���Ͼ�����Ч
const char OR_TC_GFA = '6';
ORAPI const char* or_timecondition_enumstr(or_timecondition_e value);

/////////////////////////////////////////////////////////////////////////
/// VolumeConditionType��һ���ɽ�����������
/////////////////////////////////////////////////////////////////////////
/// �ɽ�������
typedef char or_volumecondition_e;
/// �κ�����
const char OR_VC_AV = '1';
/// ��С����
const char OR_VC_MV = '2';
/// ȫ������
const char OR_VC_CV = '3';
ORAPI const char* or_volumecondition_enumstr(or_volumecondition_e value);

/////////////////////////////////////////////////////////////////////////
/// ContingentConditionType��һ��������������
/////////////////////////////////////////////////////////////////////////
/// ��������
typedef char or_contingentcondition_e;
/// ����
const char OR_CC_Immediately = '1';
/// ֹ��
const char OR_CC_Touch = '2';
/// ֹӮ
const char OR_CC_TouchProfit = '3';
/// Ԥ��
const char OR_CC_ParkedOrder = '4';
/// ���¼۴���������
const char OR_CC_LastPriceGreaterThanStopPrice = '5';
/// ���¼۴��ڵ���������
const char OR_CC_LastPriceGreaterEqualStopPrice = '6';
/// ���¼�С��������
const char OR_CC_LastPriceLesserThanStopPrice = '7';
/// ���¼�С�ڵ���������
const char OR_CC_LastPriceLesserEqualStopPrice = '8';
/// ��һ�۴���������
const char OR_CC_AskPriceGreaterThanStopPrice = '9';
/// ��һ�۴��ڵ���������
const char OR_CC_AskPriceGreaterEqualStopPrice = 'A';
/// ��һ��С��������
const char OR_CC_AskPriceLesserThanStopPrice = 'B';
/// ��һ��С�ڵ���������
const char OR_CC_AskPriceLesserEqualStopPrice = 'C';
/// ��һ�۴���������
const char OR_CC_BidPriceGreaterThanStopPrice = 'D';
/// ��һ�۴��ڵ���������
const char OR_CC_BidPriceGreaterEqualStopPrice = 'E';
/// ��һ��С��������
const char OR_CC_BidPriceLesserThanStopPrice = 'F';
/// ��һ��С�ڵ���������
const char OR_CC_BidPriceLesserEqualStopPrice = 'H';
ORAPI const char* or_contingentcondition_enumstr(or_contingentcondition_e value);

/////////////////////////////////////////////////////////////////////////
/// OrderStatusType��һ������״̬����
/////////////////////////////////////////////////////////////////////////
/// ����״̬
typedef char or_orderstatus_e;
/// δ֪
const char OR_OST_Unkfalsewn = '0';
/// ���ύ
const char OR_OST_PendingNew = '1';
/// �ѽ���
const char OR_OST_New = '2';
/// ���ֳɽ�
const char OR_OST_PartilyFilled = '3';
/// ȫ���ɽ�
const char OR_OST_Filled = '4';
/// ���ֳɽ����ֳ���
const char OR_OST_PartilyCanceled = '5';
/// �ѳ���
const char OR_OST_Canceled = '6';
/// �Ѿܾ�
const char OR_OST_Rejected = '7';
ORAPI const char* or_orderstatus_enumstr(or_orderstatus_e value);

/////////////////////////////////////////////////////////////////////////
/// OrderTypeType��һ��������������
/////////////////////////////////////////////////////////////////////////
/// ��������
typedef char or_ordertype_e;
/// ����
const char OR_ORDT_Normal = '0';
/// ��������
const char OR_ORDT_DeriveFromQuote = '1';
/// �������
const char OR_ORDT_DeriveFromCombination = '2';
/// ��ϱ���
const char OR_ORDT_Combination = '3';
/// ������
const char OR_ORDT_ConditionalOrder = '4';
/// ������
const char OR_ORDT_Swap = '5';
ORAPI const char* or_ordertype_enumstr(or_ordertype_e value);

/// ǰ�ñ��
typedef int64_t or_frontid_i;
/// �Ự���
typedef int64_t or_sessionid_i;
/// �Զ������ñ��
typedef char or_orderactionref_s[OR_ORDERACTIONREF_LEN];
/// ״̬��Ϣ
typedef char or_statusmsg_s[OR_STATUSMSG_LEN];
/////////////////////////////////////////////////////////////////////////
/// PosiDirectionType��һ���ֲֶ�շ�������
/////////////////////////////////////////////////////////////////////////
/// �ֲֶ�շ���
typedef char or_posidirection_e;
/// ��ͷ����Ȩ��Ϊ���񷽣�
const char OR_PD_Short = '1';
/// ��ͷ����Ȩ��ΪȨ������
const char OR_PD_Long = '0';
/// ��
const char OR_PD_Net = '2';
ORAPI const char* or_posidirection_enumstr(or_posidirection_e value);

/////////////////////////////////////////////////////////////////////////
/// CapitalDirectionType��һ���ʽ�仯��������
/////////////////////////////////////////////////////////////////////////
/// �ʽ�仯����
typedef char or_capitaldirection_e;
/// ����
const char OR_CPD_Nochange = '0';
/// ����
const char OR_CPD_Increase = '1';
/// ����
const char OR_CPD_Decrease = '2';
ORAPI const char* or_capitaldirection_enumstr(or_capitaldirection_e value);

/////////////////////////////////////////////////////////////////////////
/// PositionDirectionType��һ���ֱֲ仯��������
/////////////////////////////////////////////////////////////////////////
/// �ֱֲ仯����
typedef char or_positiondirection_e;
/// ����
const char OR_PSD_Nochange = '0';
/// ����
const char OR_PSD_Increase = '1';
/// ����
const char OR_PSD_Decrease = '2';
ORAPI const char* or_positiondirection_enumstr(or_positiondirection_e value);

/////////////////////////////////////////////////////////////////////////
/// PositionDateType��һ���ֲ����ڱ�־����
/////////////////////////////////////////////////////////////////////////
/// �ֲ����ڱ�־
typedef char or_positiondate_e;
/// ���ճֲ�
const char OR_PSD_Today = '1';
/// ��ʷ�ֲ�
const char OR_PSD_History = '2';
ORAPI const char* or_positiondate_enumstr(or_positiondate_e value);

/// ����޸ĺ���
typedef int64_t or_updatemillisec_i;
/////////////////////////////////////////////////////////////////////////
/// TradingPhaseType��һ�����׽׶�����
/////////////////////////////////////////////////////////////////////////
/// ���׽׶�
typedef char or_tradingphase_e;
/// �ǽ���ʱ��
const char OR_TP_NonTrade = '0';
/// ���Ͼ���ʱ��
const char OR_TP_Bidding = '1';
/// ��������ʱ��
const char OR_TP_Continuous = '2';
/// ͣ��ʱ��
const char OR_TP_Suspension = '3';
/// �۶�ʱ��
const char OR_TP_Fuse = '4';
ORAPI const char* or_tradingphase_enumstr(or_tradingphase_e value);

/////////////////////////////////////////////////////////////////////////
/// OpenRestrictionType��һ��������������
/////////////////////////////////////////////////////////////////////////
/// ��������
typedef char or_openrestriction_e;
/// �޿�������
const char OR_OR_None = '0';
/// ���Ʊ��ҿ���
const char OR_OR_NoCoverOpen = '1';
/// ������������
const char OR_OR_NoSellOpen = '2';
/// �����������֡����ҿ���
const char OR_OR_NoSellAndCoverOpen = '3';
/// �������뿪��
const char OR_OR_NoBuyOpen = '4';
/// �������뿪�֡����ҿ���
const char OR_OR_NoBuyAndCoverOpen = '5';
/// �������뿪�֡���������
const char OR_OR_NoBuyAndSellOpen = '6';
/// �������뿪�֡��������֡����ҿ���
const char OR_OR_NoBuySellAndCoverOpen = '7';
ORAPI const char* or_openrestriction_enumstr(or_openrestriction_e value);

/////////////////////////////////////////////////////////////////////////
/// ErrorIDType��һ�������������
/////////////////////////////////////////////////////////////////////////
/// �������
typedef int or_errorid_ei;
/// �޴���
const int OR_ERR_OK = 0;
/// ͨ�ô���ֵ��
const int OR_ERR_FAIL = -1;
/// ����Ŀ�ָ�봫��
const int OR_ERR_NULLPTR = -2;
/// δ�趨��Ӧ��SPI�ص��ӿ�
const int OR_ERR_ADAPTER_HASNOSPI = -3;
/// δ֪��������
const int OR_ERR_UNKNOWN_PACKAGETYPE = -4;
/// �־û��ռ䲻�㣬����֧�ָ���ͨ��
const int OR_ERR_NO_MORE_COUNTER_PERSIST = -5;
/// ����δ����RequestID
const int OR_ERR_PACKAGE_NEED_ORREQUESTID = -6;
/// ����δ����AccountCode
const int OR_ERR_PACKAGE_NEED_ACCOUNTCODE = -7;
/// ��Ч��Ͷ���߱��
const int OR_ERR_INVALID_INVESTORID = -100;
/// ��Ч��ͨ�����
const int OR_ERR_INVALID_CHANNELID = -101;
/// ��̨/�������޷�����
const int OR_ERR_FAIL_COUNTERNOTCONNECTED = -102;
/// ��֧�ֵ�ͨ������
const int OR_ERR_UNSUPPORTED_CHANNELTYPE = -103;
/// ͨ����ʼ��ʧ�ܣ�
const int OR_ERR_FAIL_INIT_CHANNEL = -104;
/// T2SDK���ĳ�ʼ��ʧ��
const int OR_ERR_T2SDK_NEWPACKERFAILED = -200;
/// T2SDK���ķ���ʧ��
const int OR_ERR_T2SDK_SENDBIZMSGFAIL = -201;
/// ί�б���̨/�������ܾ�
const int OR_ERR_ENTRUST_REJECTED = 10000;
/// ����ʧ��
const int OR_ERR_CANCEL_REJECTED = 10001;
/// �ظ��ɽ����
const int OR_ERR_DUPLICATE_TRADE = 10002;
/// ������ͨ��ί��ʧ��
const int OR_ERR_RTNORDER_REJECTED = 10003;
/// ��ʵ�ʳɽ��������˵ĳɽ��ر���
const int OR_ERR_DUMMY_TRADE = 10004;
/// ��̨��¼ʧ��
const int OR_ERR_COUNTER_LOGIN_FAILED = 10005;
/// ͨ����Investor����Ӧ
const int OR_ERR_NO_INVESTORID = 10006;
/// ��̨/�������ȷ��سɽ�ί��״̬���ٷ��سɽ��ر�
const int OR_ERR_ORDER_BEFORE_TRADE = 10007;
/// �޷��������͵���̨�ı��ģ�һ����ΪInvestorID�޷�ƥ��
const int OR_ERR_FAIL_PACK_TO_COUNTER = 10008;
/// �ʽ𻮲�ʧ��
const int OR_ERR_ASSET_TRANSFER_FAIL = 10009;
/// ��̨/������δ����
const int OR_ERR_COUNTER_NOT_CONNECTED = 10010;
/// ί���Ѵ����ս�״̬�������ѱ�ɾ����
const int OR_ERR_DELETED_FINAL_ORDER = 10011;
/// Adapter��֧�ֵĹ��ܡ�
const int OR_ERR_NOT_SUPPORTED_BY_ADAPTER = 10012;
/// Adapter��ѯʧ�ܡ�
const int OR_ERR_QUERY_FAIL_BY_ADAPTER = 10013;
/// Adapter����JSON����ʧ�ܡ�
const int OR_ERR_JSON_PARSE_FAIL_BY_ADAPTER = 10014;
ORAPI const char* or_errorid_enumstr(or_errorid_ei value);

/// ������־
typedef bool or_islast_b;
/// ������Ϣ
typedef char or_errormsg_s[OR_ERRORMSG_LEN];
/// ��������б���|�ָ
typedef char or_comboidlist_s[OR_COMBOIDLIST_LEN];
/// ��Լ���״���
typedef char or_instrumentcode_s[OR_INSTRUMENTCODE_LEN];
/////////////////////////////////////////////////////////////////////////
/// PositionTypeType��һ���ֲ���������
/////////////////////////////////////////////////////////////////////////
/// �ֲ�����
typedef char or_positiontype_e;
/// ���ֲ�
const char OR_PT_Net = '1';
/// �ۺϳֲ�
const char OR_PT_Gross = '2';
ORAPI const char* or_positiontype_enumstr(or_positiontype_e value);

/////////////////////////////////////////////////////////////////////////
/// PositionHistoryTypeType��һ���Ƿ�ʹ����ʷ�ֲ�����
/////////////////////////////////////////////////////////////////////////
/// �Ƿ�ʹ����ʷ�ֲ�
typedef char or_positionhistorytype_e;
/// ʹ����ʷ�ֲ�
const char OR__UseHistory = '1';
/// ��ʹ����ʷ�ֲ�
const char OR__NoUseHistory = '2';
ORAPI const char* or_positionhistorytype_enumstr(or_positionhistorytype_e value);

/// ����������
typedef char or_exchangename_s[OR_EXCHANGENAME_LEN];
/// ϯλ����
typedef char or_seatname_s[OR_SEATNAME_LEN];
/////////////////////////////////////////////////////////////////////////
/// InvestorTypeType��һ��Ͷ������������
/////////////////////////////////////////////////////////////////////////
/// Ͷ��������
typedef char or_investortype_e;
/// ��Ȼ��
const char OR_IT_Person = '1';
/// ����
const char OR_IT_Company = '2';
/// Ͷ�ʻ���
const char OR_IT_Fund = '3';
/// ���ⷨ��
const char OR_IT_SpecialOrgan = '4';
/// �ʹܻ�
const char OR_IT_Asset = '5';
/// ϵͳ����Ա
const char OR_IT_Admin = 'a';
ORAPI const char* or_investortype_enumstr(or_investortype_e value);

/////////////////////////////////////////////////////////////////////////
/// IDCardTypeType��һ��֤����������
/////////////////////////////////////////////////////////////////////////
/// ֤������
typedef char or_idcardtype_e;
/// ��֯��������
const char OR_DCT_EID = '0';
/// �й��������֤
const char OR_DCT_IDCard = '1';
/// ����֤
const char OR_DCT_OfficerIDCard = '2';
/// ����֤
const char OR_DCT_PoliceIDCard = '3';
/// ʿ��֤
const char OR_DCT_SoldierIDCard = '4';
/// ���ڲ�
const char OR_DCT_HouseholdRegister = '5';
/// ����
const char OR_DCT_Passport = '6';
/// ̨��֤
const char OR_DCT_TaiwanCompatriotIDCard = '7';
/// ����֤
const char OR_DCT_HomeComingCard = '8';
/// Ӫҵִ�պ�
const char OR_DCT_LicenseNo = '9';
/// ˰��ǼǺ�/������˰ID
const char OR_DCT_TaxNo = 'A';
/// �۰ľ��������ڵ�ͨ��֤
const char OR_DCT_HMMainlandTravelPermit = 'B';
/// ̨�����������½ͨ��֤
const char OR_DCT_TwMainlandTravelPermit = 'C';
/// ����
const char OR_DCT_DrivingLicense = 'D';
/// �����籣ID
const char OR_DCT_SocialID = 'F';
/// �������֤
const char OR_DCT_LocalID = 'G';
/// ��ҵ�Ǽ�֤
const char OR_DCT_BusinessRegistration = 'H';
/// �۰������Ծ������֤
const char OR_DCT_HKMCIDCard = 'I';
/// ���п������֤
const char OR_DCT_AccountsPermits = 'J';
/// ��������þ���֤
const char OR_DCT_PermanantResidence = 'K';
/// �ʹܲ�Ʒ������
const char OR_DCT_AssetProductRecord = 'L';
/// ����֤��
const char OR_DCT_OtherCard = 'x';
ORAPI const char* or_idcardtype_enumstr(or_idcardtype_e value);

/// ֤����
typedef char or_idcardno_s[OR_IDCARDNO_LEN];
/// �ɶ�����
typedef char or_tradecode_s[OR_TRADECODE_LEN];
/// ȱʡ״̬
typedef bool or_isdefault_b;
/// Ͷ�����˻��ӱ���
typedef char or_optclientid_s[OR_OPTCLIENTID_LEN];
/////////////////////////////////////////////////////////////////////////
/// OptCommissionTypeType��һ����Ȩ������������
/////////////////////////////////////////////////////////////////////////
/// ��Ȩ��������
typedef char or_optcommissiontype_e;
/// ��Ȩ��
const char OR_OPT_CT_StrikeFee = '1';
/// ����Ȩ��
const char OR_OPT_CT_BeStrikeDFee = '2';
/// ��Ȩ������
const char OR_OPT_CT_TransferFee = '3';
/// ���ַ�
const char OR_OPT_CT_Brokerage = '4';
/// ���׷�
const char OR_OPT_CT_TradeFee = '5';
/// �����
const char OR_OPT_CT_SettleFee = '6';
ORAPI const char* or_optcommissiontype_enumstr(or_optcommissiontype_e value);

/////////////////////////////////////////////////////////////////////////
/// CommDirectionType��һ��ί�з�������
/////////////////////////////////////////////////////////////////////////
/// ί�з���
typedef char or_commdirection_e;
/// ��
const char OR_CD_BuyOpen = '1';
/// ��ƽ
const char OR_CD_BuyClose = '2';
/// ����
const char OR_CD_SellOpen = '3';
/// ��ƽ
const char OR_CD_SellClose = '4';
/// ��Ȩ�Ϲ�
const char OR_CD_CallStrike = '5';
/// ��Ȩ�Ϲ�
const char OR_CD_PutStrike = '6';
ORAPI const char* or_commdirection_enumstr(or_commdirection_e value);

/// �Ƿ񰴱����ϸ�
typedef bool or_isfloat_b;
/// ������
typedef char or_groupid_s[OR_GROUPID_LEN];
/// ��������
typedef char or_groupname_s[OR_GROUPNAME_LEN];
/// ��֯�ܹ�����
typedef char or_departmentid_s[OR_DEPARTMENTID_LEN];
/// �ϼ���֯�ܹ�����
typedef char or_parentid_s[OR_PARENTID_LEN];
/// ��֯�ܹ�����
typedef char or_deptname_s[OR_DEPTNAME_LEN];
/// ����Ա����
typedef char or_operatorname_s[OR_OPERATORNAME_LEN];
/// ��Ʒ����
typedef char or_productname_s[OR_PRODUCTNAME_LEN];
/// Ͷ�ʵ�Ԫ����
typedef char or_investunitid_s[OR_INVESTUNITID_LEN];
/// ϯλ��
typedef char or_seatid_s[OR_SEATID_LEN];
/// �ʽ��˻�����
typedef char or_accountname_s[OR_ACCOUNTNAME_LEN];
/// ���ִ���
typedef char or_currencyid_s[OR_CURRENCYID_LEN];
/// Ͷ�ʵ�Ԫ����
typedef char or_investunitname_s[OR_INVESTUNITNAME_LEN];
/////////////////////////////////////////////////////////////////////////
/// OptionsTypeType��һ����Ȩ��������
/////////////////////////////////////////////////////////////////////////
/// ��Ȩ����
typedef char or_optionstype_e;
/// �Ϲ�
const char OR_OPT_TY_Call = 'C';
/// �Ϲ�
const char OR_OPT_TY_Put = 'P';
ORAPI const char* or_optionstype_enumstr(or_optionstype_e value);

/// Ͷ����ϴ���
typedef char or_portfolioid_s[OR_PORTFOLIOID_LEN];
/////////////////////////////////////////////////////////////////////////
/// SystemStatusType��һ��ϵͳ״̬����
/////////////////////////////////////////////////////////////////////////
/// ϵͳ״̬
typedef char or_systemstatus_e;
/// �����������
const char OR_STS_SyncDone = '1';
/// ���н���״̬
const char OR_STS_Trading = '2';
/// �������
const char OR_STS_Closed = '3';
/// �������
const char OR_STS_Settled = '4';
ORAPI const char* or_systemstatus_enumstr(or_systemstatus_e value);

/// ������
typedef int64_t or_ruleid_i;
/// �������
typedef char or_rulecode_s[OR_RULECODE_LEN];
/// ����ID
typedef int64_t or_riskid_i;
/// ��������
typedef char or_rulename_s[OR_RULENAME_LEN];
/// �޸�������ϸ��json�ַ�����
typedef char or_value_s[OR_VALUE_LEN];
/// Ԥ���ֶ�1
typedef char or_thirdreff1_s[OR_THIRDREFF1_LEN];
/// Ԥ���ֶ�2
typedef char or_thirdreff2_s[OR_THIRDREFF2_LEN];
/// Ͷ���ߴ��뼯��
typedef char or_investorids_s[OR_INVESTORIDS_LEN];
/// ��Լ���뼯��
typedef char or_instrumentids_s[OR_INSTRUMENTIDS_LEN];
/////////////////////////////////////////////////////////////////////////
/// InstrumentRangeType��һ����Լ��Χ����
/////////////////////////////////////////////////////////////////////////
/// ��Լ��Χ
typedef char or_instrumentrange_e;
/// ����
const char OR_INSTR_ALL = '1';
/// ��Ʒ����
const char OR_INSTR_PRODUCT_CLASS = '2';
/// ��һ��Լ
const char OR_INSTR_SINGLE = '3';
ORAPI const char* or_instrumentrange_enumstr(or_instrumentrange_e value);

/// ��Լ���Ϸ��
typedef bool or_instrumentcontrolflag_b;
/// Ͷ���˻����Ϸ��
typedef bool or_investorcontrolflag_b;
/////////////////////////////////////////////////////////////////////////
/// SeatTypeType��һ��ϯλ��������
/////////////////////////////////////////////////////////////////////////
/// ϯλ����
typedef char or_seattype_e;
/// �Ͻ�����Ȩ
const char OR_ST_SHOPT = '1';
/// �Ͻ�����Ʊ
const char OR_ST_SHSTK = '2';
/// �����Ȩ
const char OR_ST_SZOPT = '3';
/// �����Ʊ
const char OR_ST_SZSTK = '4';
/// ����
const char OR_ST_FEMAS = '5';
ORAPI const char* or_seattype_enumstr(or_seattype_e value);

/// ���ر��
typedef int64_t or_gatewayid_i;
/// ǰ�õ�ַ
typedef char or_frontaddress_s[OR_FRONTADDRESS_LEN];
/////////////////////////////////////////////////////////////////////////
/// ResumeTypeType��һ��˽�����ش���ʽ����
/////////////////////////////////////////////////////////////////////////
/// ˽�����ش���ʽ
typedef char or_resumetype_e;
/// �ش�
const char OR_RT_Restart = '0';
/// ����
const char OR_RT_Resume = '1';
/// ��ǰ��ʼ
const char OR_RT_Quick = '2';
ORAPI const char* or_resumetype_enumstr(or_resumetype_e value);

/// ���ļ�·��
typedef char or_flowpath_s[OR_FLOWPATH_LEN];
/// ָ�����
typedef char or_admincode_s[OR_ADMINCODE_LEN];
/// ָ�����
typedef char or_adminstatuscode_s[OR_ADMINSTATUSCODE_LEN];
/// ����ֵ
typedef double or_threshold_f;
/// ����ָ��ֵ
typedef double or_calcvalue_f;
/// ������Ʒ����
typedef int64_t or_underlyingmultiple_i;
/// ��˾���
typedef int64_t or_companyid_i;
/// ��˾����
typedef char or_companyname_s[OR_COMPANYNAME_LEN];
/////////////////////////////////////////////////////////////////////////
/// OpTypeType��һ������Ա��������
/////////////////////////////////////////////////////////////////////////
/// ����Ա����
typedef char or_optype_e;
/// �ͻ�����Ա
const char OR_OT_MANAGE = '1';
/// �ͻ�����Ա
const char OR_OT_TRADE = '2';
/// �ͻ����Ա
const char OR_OT_RISK = '3';
/// ϵͳ��Ӫ��Ա
const char OR_OT_OPERATE = '4';
ORAPI const char* or_optype_enumstr(or_optype_e value);

/// ����Ա���Բ�ѯ���˻�����
typedef char or_qryaccountids_s[OR_QRYACCOUNTIDS_LEN];
/// ����Ա���Բ������˻�����
typedef char or_opaccountids_s[OR_OPACCOUNTIDS_LEN];
/// �˻����
typedef int64_t or_accountid_i;
/////////////////////////////////////////////////////////////////////////
/// AccountTypeType��һ���˻���������
/////////////////////////////////////////////////////////////////////////
/// �˻�����
typedef char or_accounttype_e;
/// ��֤ͨȯ�˻�
const char OR_AT_STOCK = '1';
/// �����˻�
const char OR_AT_CREDIT = '2';
/// ����Ʒ�˻�
const char OR_AT_DERIVATIVE = '3';
/// �ڻ��˻�
const char OR_AT_FUTURES = '4';
ORAPI const char* or_accounttype_enumstr(or_accounttype_e value);

/////////////////////////////////////////////////////////////////////////
/// StatusType��һ���˻�״̬����
/////////////////////////////////////////////////////////////////////////
/// �˻�״̬
typedef char or_status_e;
/// ����
const char OR_ST_NORMAL = '1';
/// ����
const char OR_ST_FROZEN = '2';
ORAPI const char* or_status_enumstr(or_status_e value);

/// ����ͨ�����
typedef int64_t or_channelid_i;
/// Ĭ�����
typedef int64_t or_defaultcombo_i;
/// �ͻ���
typedef char or_clientid_s[OR_CLIENTID_LEN];
/// ͨ������
typedef char or_channelname_s[OR_CHANNELNAME_LEN];
/////////////////////////////////////////////////////////////////////////
/// ChannelTypeType��һ��ͨ����������
/////////////////////////////////////////////////////////////////////////
/// ͨ������
typedef char or_channeltype_e;
/// Dynamic
const char OR_CHT_Dynamic = '0';
/// UFT�ֲ�
const char OR_CHT_UFT = '1';
/// CTP�ֲ�
const char OR_CHT_CTP = '2';
/// ����ֲ�
const char OR_CHT_FEMAS = '3';
/// O32�ֲ�
const char OR_CHT_O32 = '4';
/// ģ�⽻����
const char OR_CHT_SIMULATE = '5';
/// UF2.0��Ȩ����ͨ��
const char OR_CHT_Uf20Opt = '6';
/// ����ATP����ͨ��
const char OR_CHT_HuaruiATP = '7';
/// QMT�ļ���ͨ��
const char OR_CHT_QmtFile = 'F';
/// IBTWSͨ��
const char OR_CHT_IBTws = 'I';
/// JINZͨ��
const char OR_CHT_JINZ = 'J';
/// LTS����ͨ��
const char OR_CHT_LTS = 'L';
/// CTP-MINI�ֲ�
const char OR_CHT_CTPMINI = 'M';
/// QMT��ǿ����ͨ��
const char OR_CHT_QMTEnhance = 'Q';
/// STP��Ȩ����ͨ��
const char OR_CHT_StpOpt = 'S';
/// TFTrade����ͨ��
const char OR_CHT_TFTrade = 'T';
/// TradeX����ͨ��
const char OR_CHT_TradeX = 'X';
ORAPI const char* or_channeltype_enumstr(or_channeltype_e value);

/// �ֲֽӿ�IP
typedef char or_sysip_s[OR_SYSIP_LEN];
/// �ֲֽӿڶ˿�
typedef char or_sysport_s[OR_SYSPORT_LEN];
/////////////////////////////////////////////////////////////////////////
/// FeeTypeType��һ�������������
/////////////////////////////////////////////////////////////////////////
/// �������
typedef char or_feetype_e;
/// ���׷�
const char OR_FT_TRADEFEE = '1';
/// ӡ��˰
const char OR_FT_STAMPTAX = '2';
/// ������
const char OR_FT_TRANSFERFEE = '3';
/// Ӷ��
const char OR_FT_BROKERFEE = '4';
/// ���ַ�
const char OR_FT_HANDLINGFEE = '5';
/// ֤�ܷ�
const char OR_FT_ADMINFEE = '6';
/// ������
const char OR_FT_OTHERFEE = '7';
/// �����
const char OR_FT_CLEARINGFEE = 'a';
/// �����
const char OR_FT_SETTLEFEE = 'b';
/// ί���걨��
const char OR_FT_PERORDER = 'c';
/// �����걨��
const char OR_FT_PERCANCEL = 'd';
ORAPI const char* or_feetype_enumstr(or_feetype_e value);

/////////////////////////////////////////////////////////////////////////
/// CalculateTypeType��һ�����ü���ģʽ����
/////////////////////////////////////////////////////////////////////////
/// ���ü���ģʽ
typedef char or_calculatetype_e;
/// �ֱ�
const char OR_CT_TOTAL = '1';
/// �ϱ�
const char OR_CT_PER = '2';
ORAPI const char* or_calculatetype_enumstr(or_calculatetype_e value);

/// ��ע
typedef char or_remark_s[OR_REMARK_LEN];
/////////////////////////////////////////////////////////////////////////
/// CancelFlagType��һ��������־����
/////////////////////////////////////////////////////////////////////////
/// ������־
typedef char or_cancelflag_e;
/// ��ͨί��
const char OR_CF_ORDER = '1';
/// ����ί��
const char OR_CF_CANCEL = '2';
ORAPI const char* or_cancelflag_enumstr(or_cancelflag_e value);

/// ����IP
typedef char or_orderip_s[OR_ORDERIP_LEN];
/// ����MAC
typedef char or_ordermac_s[OR_ORDERMAC_LEN];
/// ����Ӳ�����к�
typedef char or_orderhdnum_s[OR_ORDERHDNUM_LEN];
/// ����������
typedef char or_ordermaccode_s[OR_ORDERMACCODE_LEN];
/// ��������ϵͳ
typedef char or_orderos_s[OR_ORDEROS_LEN];
/////////////////////////////////////////////////////////////////////////
/// TradeTypeType��һ���ɽ��ر���������
/////////////////////////////////////////////////////////////////////////
/// �ɽ��ر�����
typedef char or_tradetype_e;
/// ί��ȷ��
const char OR_RTS_Entrust = '1';
/// ί�зϵ�
const char OR_RTS_Fail = '2';
/// �ɽ�
const char OR_RTS_Fill = '3';
/// �����ɽ�
const char OR_RTS_CancelFill = '4';
/// �����ϵ�
const char OR_RTS_CancelFail = '5';
ORAPI const char* or_tradetype_enumstr(or_tradetype_e value);

/////////////////////////////////////////////////////////////////////////
/// TradeTypeFuturesType��һ���ɽ���������
/////////////////////////////////////////////////////////////////////////
/// �ɽ�����
typedef char or_tradetypefutures_e;
/// ��ϳֲֲ��Ϊ��һ�ֲ�,��ʼ����Ӧ���������͵ĳֲ�
const char OR_TRDT_SplitCombination = '#';
/// ��ͨ�ɽ�
const char OR_TRDT_Common = '0';
/// ��Ȩִ��
const char OR_TRDT_OptionsExecution = '1';
/// OTC�ɽ�
const char OR_TRDT_OTC = '2';
/// ��ת�������ɽ�
const char OR_TRDT_EFPDerived = '3';
/// ��������ɽ�
const char OR_TRDT_CombinationDerived = '4';
ORAPI const char* or_tradetypefutures_enumstr(or_tradetypefutures_e value);

/////////////////////////////////////////////////////////////////////////
/// StockRealBackType��һ���ر�֤ȯ��־����
/////////////////////////////////////////////////////////////////////////
/// �ر�֤ȯ��־
typedef char or_stockrealback_e;
/// ����֤ȯ���첻����
const char OR_SRB_FALSE = '0';
/// ����֤�������
const char OR_SRB_TRUE = '1';
ORAPI const char* or_stockrealback_enumstr(or_stockrealback_e value);

/////////////////////////////////////////////////////////////////////////
/// FundRealBackType��һ���ر��ʽ��־����
/////////////////////////////////////////////////////////////////////////
/// �ر��ʽ��־
typedef char or_fundrealback_e;
/// �����ʽ𲻿���
const char OR_FRB_FALSE = '0';
/// �����ʽ������
const char OR_FRB_TRUE = '1';
ORAPI const char* or_fundrealback_enumstr(or_fundrealback_e value);

/// ��λ��
typedef char or_positionstr_s[OR_POSITIONSTR_LEN];
/// �ʽ𻮲���Ϣ
typedef char or_transferinfo_s[OR_TRANSFERINFO_LEN];
/////////////////////////////////////////////////////////////////////////
/// TransferDirectionType��һ���ʽ𻮲���������
/////////////////////////////////////////////////////////////////////////
/// �ʽ𻮲�����
typedef char or_transferdirection_e;
/// 1-UF20��UFT
const char OR_ATD_UF20ToUFT = '1';
/// 2-UFT��UF20
const char OR_ATD_UFTToUF20 = '2';
/// ATPת��
const char OR_ATD_ATPInto = '3';
/// ATPת��
const char OR_ATD_ATPOut = '4';
/// ATP�ڵ�䰴��֤ȯ�˻���ת�ʽ�
const char OR_ATD_ATPExternalAccountTransfer = '5';
ORAPI const char* or_transferdirection_enumstr(or_transferdirection_e value);

/// �����̨��IP�Ͷ˿ں��б�
typedef char or_ufxt2sdkservers_s[OR_UFXT2SDKSERVERS_LEN];
/// ���֤�ļ�����
typedef char or_ufxt2sdklicensefilename_s[OR_UFXT2SDKLICENSEFILENAME_LEN];
/// ���֤����
typedef char or_ufxt2sdklicensepwd_s[OR_UFXT2SDKLICENSEPWD_LEN];
/// �Զ�����
typedef bool or_ufxt2sdkautoconnect_b;
/////////////////////////////////////////////////////////////////////////
/// UfxT2sdkEntrustWayType��һ��ί�з�ʽ����
/////////////////////////////////////////////////////////////////////////
/// ί�з�ʽ
typedef char or_ufxt2sdkentrustway_e;
ORAPI const char* or_ufxt2sdkentrustway_enumstr(or_ufxt2sdkentrustway_e value);

/// UFT20��̨BatchNoƫ����
typedef int64_t or_ufxbatchnooffset_i;
/// ʹ��UF20��̨�Ĺ��ܺ�
typedef char or_uft20uf20functions_s[OR_UFT20UF20FUNCTIONS_LEN];
/// UF20ϵͳ��
typedef int64_t or_uft20uf20systemno_i;
/// UFT2ϵͳ��
typedef int64_t or_uft20uft2systemno_i;
/// �Զ���ѯ���׺�ί�е�ʱ����
typedef int64_t or_uft20syncinterval_i;
/// T2SDK�շ���־����
typedef bool or_ufxt2sdksendrecvlog_b;
/// IPv4��ַ
typedef char or_ipv4address_s[OR_IPV4ADDRESS_LEN];
/// IPv4�˿ں�
typedef int64_t or_ipv4port_i;
/// ͨ�������Զ������
typedef char or_channelcustomconfig_s[OR_CHANNELCUSTOMCONFIG_LEN];
/// STP��Ȩ��̨��������ַ
typedef char or_stpoptionserveraddress_s[OR_STPOPTIONSERVERADDRESS_LEN];
/// STP��Ȩ��̨�������˿�
typedef int64_t or_stpoptionserverport_i;
/// QMT��ǿģ���ʶ
typedef char or_qmtenhancemoduletag_s[OR_QMTENHANCEMODULETAG_LEN];
/// ֤ȯ��˾TDX���
typedef int64_t or_tdxcompanyid_i;
/// ͨ���ſͻ��˵İ汾��
typedef char or_tdxclientversion_s[OR_TDXCLIENTVERSION_LEN];
/// ͨ���Ų�ѯ˯��ʱ��
typedef int64_t or_tdxsleepmsqry_i;
/// ͨ���Ž���˯��ʱ��
typedef int64_t or_tdxsleepmstrd_i;
/// ʹ�õ���Ʒ����
typedef int64_t or_buysellcollateral_i;
/// ʹ�÷�ҳ��ѯ
typedef int64_t or_tdxpagedquery_i;
/// Broker IND
typedef char or_tdxbrokerind_s[OR_TDXBROKERIND_LEN];
/////////////////////////////////////////////////////////////////////////
/// BizTypeType��һ��ҵ����������
/////////////////////////////////////////////////////////////////////////
/// ҵ������
typedef char or_biztype_e;
/// ��Ȩ
const char OR_BT_Exercise = 'R';
/// ����/����
const char OR_BT_Covered = 'C';
ORAPI const char* or_biztype_enumstr(or_biztype_e value);

/////////////////////////////////////////////////////////////////////////
/// BizDirectionType��һ��ҵ��������
/////////////////////////////////////////////////////////////////////////
/// ҵ����
typedef char or_bizdirection_e;
/// ��Ȩ/����
const char OR_BD_Operate = '1';
/// ����/����
const char OR_BD_Cancel = '2';
ORAPI const char* or_bizdirection_enumstr(or_bizdirection_e value);

/// O32���ķ�����
typedef char or_o32subscribeservers_s[OR_O32SUBSCRIBESERVERS_LEN];
/// O32����Ա����
typedef char or_o32operatorno_s[OR_O32OPERATORNO_LEN];
/// O32����Ա����
typedef char or_o32operatorpwd_s[OR_O32OPERATORPWD_LEN];
/// O32��ϱ��
typedef char or_o32combino_s[OR_O32COMBINO_LEN];
/// O32�ʲ���Ԫ���
typedef char or_o32assetno_s[OR_O32ASSETNO_LEN];
/// ��¼����MAC��ַ
typedef char or_loginmac_s[OR_LOGINMAC_LEN];
/// ��¼����IP��ַ
typedef char or_loginip_s[OR_LOGINIP_LEN];
/// ��¼����Ӳ�����к�
typedef char or_orderhdvolserial_s[OR_ORDERHDVOLSERIAL_LEN];
/// ��¼վ��
typedef char or_o32opstation_s[OR_O32OPSTATION_LEN];
/// O32��������Ȩ���
typedef char or_o32authorizationid_s[OR_O32AUTHORIZATIONID_LEN];
/// O32��¼����
typedef char or_o32usertoken_s[OR_O32USERTOKEN_LEN];
/// O32-UFX�汾
typedef char or_o32versionno_s[OR_O32VERSIONNO_LEN];
/// O32�������
typedef char or_o32accountcode_s[OR_O32ACCOUNTCODE_LEN];
/// ��������
typedef char or_o32topicname_s[OR_O32TOPICNAME_LEN];
/// ҵ������
typedef char or_o32bizname_s[OR_O32BIZNAME_LEN];
/////////////////////////////////////////////////////////////////////////
/// EnbFlagType��һ��ҵ��������
/////////////////////////////////////////////////////////////////////////
/// ҵ����
typedef char or_enbflag_e;
/// ����
const char OR_EFG_Normal = 'N';
/// ����δͬ��
const char OR_EFG_New = '1';
ORAPI const char* or_enbflag_enumstr(or_enbflag_e value);

/// ��Ͽ�ƽ��ʶ
typedef char or_comboffsetflag_s[OR_COMBOFFSETFLAG_LEN];
/////////////////////////////////////////////////////////////////////////
/// TradingCodeTypeType��һ�����ױ�����������
/////////////////////////////////////////////////////////////////////////
/// ���ױ�������
typedef char or_tradingcodetype_e;
/// Ͷ��
const char OR_TC_Speculation = '1';
/// ����
const char OR_TC_Arbitrage = '2';
/// �ױ�
const char OR_TC_Hedge = '3';
/// ������
const char OR_TC_MarketMaker = '4';
ORAPI const char* or_tradingcodetype_enumstr(or_tradingcodetype_e value);

/// �깺����
typedef char or_collectcode_s[OR_COLLECTCODE_LEN];
/////////////////////////////////////////////////////////////////////////
/// LuckyStatusType��һ����ǩ״̬����
/////////////////////////////////////////////////////////////////////////
/// ��ǩ״̬
typedef char or_luckystatus_e;
/// ����ȷ
const char OR_LS_Waiting = '0';
/// δ��ǩ
const char OR_LS_Unlucky = '1';
/// ����ǩ
const char OR_LS_Lucky = '2';
ORAPI const char* or_luckystatus_enumstr(or_luckystatus_e value);

/// CTP������������
typedef char or_ctprunningmode_s[OR_CTPRUNNINGMODE_LEN];
/// ���׽����ַ
typedef char or_ctptradeaddr_s[OR_CTPTRADEADDR_LEN];
/// ��������ַ
typedef char or_ctpmdaddr_s[OR_CTPMDADDR_LEN];
/// �û���֤��
typedef char or_ctpauthcode_s[OR_CTPAUTHCODE_LEN];
/// Ӧ�ñ��
typedef char or_ctpappid_s[OR_CTPAPPID_LEN];
/// ��Ʒ��Ϣ
typedef char or_ctpproductinfo_s[OR_CTPPRODUCTINFO_LEN];
/// ���յ��ѳ�ί��ʱ���в���
typedef bool or_faketradeonrtnorder_b;
/////////////////////////////////////////////////////////////////////////
/// SubProductClassType��һ��֤ȯ�����������
/////////////////////////////////////////////////////////////////////////
/// ֤ȯ�������
typedef char or_subproductclass_e;
/// �ƴ����Ʊ
const char OR_SPC_KC = '1';
/// ����
const char OR_SPC_Other = '0';
ORAPI const char* or_subproductclass_enumstr(or_subproductclass_e value);

/// ��ծ��Լ���
typedef char or_compactid_s[OR_COMPACTID_LEN];
/// LTS���������ļ�·��
typedef char or_ltsconfigpath_s[OR_LTSCONFIGPATH_LEN];
/////////////////////////////////////////////////////////////////////////
/// RateTypeType��һ�����㷽ʽ����
/////////////////////////////////////////////////////////////////////////
/// ���㷽ʽ
typedef char or_ratetype_e;
/// ������
const char OR_RT_ByVolume = '1';
/// �����
const char OR_RT_ByMoney = '2';
/// ����ֵ
const char OR_RT_ByFace = '3';
ORAPI const char* or_ratetype_enumstr(or_ratetype_e value);

/// ����ֵ
typedef double or_rate_f;
/// ����
typedef double or_ratio_f;
/// �ʽ�
typedef double or_money_f;
/// ��Լ�ڽ������Ĵ���
typedef char or_exchangeinstid_s[OR_EXCHANGEINSTID_LEN];
/// ��Ա����
typedef char or_participantid_s[OR_PARTICIPANTID_LEN];
/// ��̨������֤���ѯ�ֲ�ί�гɽ�
typedef bool or_startupqryposordertrade_b;
/// ������
typedef int64_t or_settlementid_i;
/// ���
typedef int64_t or_year_i;
/// �·�
typedef int64_t or_month_i;
/////////////////////////////////////////////////////////////////////////
/// InstLifePhaseType��һ����Լ��������״̬����
/////////////////////////////////////////////////////////////////////////
/// ��Լ��������״̬
typedef char or_instlifephase_e;
/// δ����
const char OR_IP_NotStart = '0';
/// ����
const char OR_IP_Started = '1';
/// ͣ��
const char OR_IP_Pause = '2';
/// ����
const char OR_IP_Expired = '3';
ORAPI const char* or_instlifephase_enumstr(or_instlifephase_e value);

/////////////////////////////////////////////////////////////////////////
/// MaxMarginSideAlgorithmType��һ�����߱�֤���㷨����
/////////////////////////////////////////////////////////////////////////
/// ���߱�֤���㷨
typedef char or_maxmarginsidealgorithm_e;
/// ��ʹ�ô��߱�֤���㷨
const char OR_MMSA_NO = '0';
/// ʹ�ô��߱�֤���㷨
const char OR_MMSA_YES = '1';
ORAPI const char* or_maxmarginsidealgorithm_enumstr(or_maxmarginsidealgorithm_e value);

/// �������
typedef char or_combinetype_s[OR_COMBINETYPE_LEN];
/////////////////////////////////////////////////////////////////////////
/// CombinationTypeType��һ�������������
/////////////////////////////////////////////////////////////////////////
/// �������
typedef char or_combinationtype_e;
/// �ڻ����
const char OR_COMBT_Future = '0';
/// ��ֱ�۲�BUL
const char OR_COMBT_BUL = '1';
/// ��ֱ�۲�BER
const char OR_COMBT_BER = '2';
/// ��ʽ���
const char OR_COMBT_STD = '3';
/// ���ʽ���
const char OR_COMBT_STG = '4';
/// �������
const char OR_COMBT_PRT = '5';
/// ʱ��۲����
const char OR_COMBT_CLD = '6';
ORAPI const char* or_combinationtype_enumstr(or_combinationtype_e value);

/// �ļ�����·�����ļ���
typedef char or_filepath_s[OR_FILEPATH_LEN];
/// QMTͨ����
typedef int64_t or_qmtchannelid_i;
/// QMT��������
typedef char or_qmtstrategyname_s[OR_QMTSTRATEGYNAME_LEN];
/// QMT��������
typedef int64_t or_qmttradingtype_i;
/// QMT�˺���
typedef char or_qmtaccountgroup_s[OR_QMTACCOUNTGROUP_LEN];
/// QMT�ֵ�����
typedef int64_t or_qmtslicetype_i;
/// QMT�ļ�����ѯ�ظ�����(����)
typedef int64_t or_qmtfetchresultintervalms_i;
/// IBTWSͨ�����
typedef char or_ibtwschannelid_s[OR_IBTWSCHANNELID_LEN];
/// TWS������������
typedef int64_t or_ibtwsmarketdatatype_i;
/// ��ȡʵʱ����
typedef bool or_ibtwssnapshot_b;
/// �ͻ���ID
typedef int64_t or_ibtwsclientid_i;
/// �洢Tick
typedef int64_t or_ibtwssavetick_i;
/// Tick�ļ�·��
typedef char or_ibtwstickfile_s[OR_IBTWSTICKFILE_LEN];
/// �洢Snapshot
typedef int64_t or_ibtwssavesnapshot_i;
/// Snapshot�ļ�·��
typedef char or_ibtwssnapshotfile_s[OR_IBTWSSNAPSHOTFILE_LEN];
/// �Զ����ĺ�Լ
typedef char or_ibtwsinstruments_s[OR_IBTWSINSTRUMENTS_LEN];
/////////////////////////////////////////////////////////////////////////
/// ReqSwitchType��һ�����󿪹�����
/////////////////////////////////////////////////////////////////////////
/// ���󿪹�
typedef char or_reqswitch_e;
/// �򿪿���
const char OR_RS_OFF = '0';
/// �رտ���
const char OR_RS_ON = '1';
ORAPI const char* or_reqswitch_enumstr(or_reqswitch_e value);

/////////////////////////////////////////////////////////////////////////
/// CloseHistoryTypeType��һ��ƽ��ʱ�Զ�����ƽ��ƽ������
/////////////////////////////////////////////////////////////////////////
/// ƽ��ʱ�Զ�����ƽ��ƽ��
typedef char or_closehistorytype_e;
/// ���Զ�ִ��ƽ�ִ���
const char OR_CLSH_None = '0';
/// ����ƽ��
const char OR_CLSH_CloseYesterday = '1';
/// ����ƽ��
const char OR_CLSH_CloseToday = '2';
ORAPI const char* or_closehistorytype_enumstr(or_closehistorytype_e value);

/// ϵͳģ������
typedef char or_modulename_s[OR_MODULENAME_LEN];
/// ״̬����
typedef char or_statuscode_s[OR_STATUSCODE_LEN];
/////////////////////////////////////////////////////////////////////////
/// QuoteDirectionType��һ�������̿���������
/////////////////////////////////////////////////////////////////////////
/// �����̿�����
typedef char or_quotedirection_e;
/// ����
const char OR_QTD_Ask = 'S';
/// ����
const char OR_QTD_Bid = 'L';
ORAPI const char* or_quotedirection_enumstr(or_quotedirection_e value);

/////////////////////////////////////////////////////////////////////////
/// QuotePosIndexType��һ�������̿ڵ�λ����
/////////////////////////////////////////////////////////////////////////
/// �����̿ڵ�λ
typedef char or_quoteposindex_e;
/// ��λ1
const char OR_QPI_Index1 = '0';
/// ��λ2
const char OR_QPI_Index2 = '1';
/// ��λ3
const char OR_QPI_Index3 = '2';
/// ��λ4
const char OR_QPI_Index4 = '3';
/// ��λ5
const char OR_QPI_Index5 = '4';
/// ��λ6
const char OR_QPI_Index6 = '5';
/// ��λ7
const char OR_QPI_Index7 = '6';
/// ��λ8
const char OR_QPI_Index8 = '7';
/// ��λ9
const char OR_QPI_Index9 = '8';
/// ��λ10
const char OR_QPI_Index10 = '9';
ORAPI const char* or_quoteposindex_enumstr(or_quoteposindex_e value);

/// ������������
typedef int64_t or_marketdatatype_i;
/// Nanoʱ���
typedef int64_t or_timestampnano_i;
/// ʱ����
typedef int64_t or_intervalmilliseconds_i;
/// ���ĵ�TID�����б�
typedef char or_subscribetids_s[OR_SUBSCRIBETIDS_LEN];
/////////////////////////////////////////////////////////////////////////
/// TradeFlagType��һ����ʳɽ�ִ�б�־����
/////////////////////////////////////////////////////////////////////////
/// ��ʳɽ�ִ�б�־
typedef char or_tradeflag_e;
/// SH,����,������
const char OR_TTF_Buy = 'B';
/// SH,����,������
const char OR_TTF_Sell = 'S';
/// SH,����,������
const char OR_TTF_Unknown = 'N';
/// SZ,�������Զ�����ִ��
const char OR_TTF_Auto = '4';
/// SZ,�ɽ�ִ��
const char OR_TTF_Fill = 'F';
ORAPI const char* or_tradeflag_enumstr(or_tradeflag_e value);

/////////////////////////////////////////////////////////////////////////
/// ChannelLoadTypeType��һ��ͨ��������������
/////////////////////////////////////////////////////////////////////////
/// ͨ����������
typedef char or_channelloadtype_e;
/// �Ӷ�̬�����
const char OR_LLD_Dynamic = 'D';
/// �����ô��������
const char OR_LLD_Static = 'S';
ORAPI const char* or_channelloadtype_enumstr(or_channelloadtype_e value);

/// ����ͨ��Ψһ��ʶ
typedef char or_channelloadid_s[OR_CHANNELLOADID_LEN];
/// JinZ��ǿģ���ʶ
typedef char or_jinzserveraddress_s[OR_JINZSERVERADDRESS_LEN];
/// JinZ��ǿģ���ʶ
typedef int64_t or_jinzserverport_i;
/////////////////////////////////////////////////////////////////////////
/// jinzchannelType��һ��JinZ��ǿģ���ʶ����
/////////////////////////////////////////////////////////////////////////
/// JinZ��ǿģ���ʶ
typedef char or_jinzchannel_e;
ORAPI const char* or_jinzchannel_enumstr(or_jinzchannel_e value);

/// JinZ��ǿģ���ʶ
typedef char or_jinzstropsite_s[OR_JINZSTROPSITE_LEN];
/// JinZ��ǿģ���ʶ
typedef char or_jinzusercode_s[OR_JINZUSERCODE_LEN];
/// JinZ��ǿģ���ʶ
typedef char or_jinzauthdata_s[OR_JINZAUTHDATA_LEN];
/// JinZ��ǿģ���ʶ
typedef char or_jinzencryptkey_s[OR_JINZENCRYPTKEY_LEN];
/// JinZ��ǿģ���ʶ
typedef char or_jinzthirdparty_s[OR_JINZTHIRDPARTY_LEN];
/////////////////////////////////////////////////////////////////////////
/// FislCashTypeType��һ��ͷ����������
/////////////////////////////////////////////////////////////////////////
/// ͷ������
typedef char or_fislcashtype_e;
ORAPI const char* or_fislcashtype_enumstr(or_fislcashtype_e value);

/////////////////////////////////////////////////////////////////////////
/// CompactTypeType��һ����Լ�������
/////////////////////////////////////////////////////////////////////////
/// ��Լ���
typedef char or_compacttype_e;
/// ����
const char OR_CMT_FinCompact = '0';
/// ��ȯ
const char OR_CMT_SloCompact = '1';
/// ������ծ
const char OR_CMT_OtherCompact = '2';
ORAPI const char* or_compacttype_enumstr(or_compacttype_e value);

/////////////////////////////////////////////////////////////////////////
/// CompactStatusType��һ����Լ״̬����
/////////////////////////////////////////////////////////////////////////
/// ��Լ״̬
typedef char or_compactstatus_e;
/// ����δ�黹
const char OR_CS_NoReturn = '0';
/// ���ֹ黹
const char OR_CS_PartReturn = '1';
/// ��Լ�ѹ���
const char OR_CS_OutofDate = '2';
/// �ͻ������˽�
const char OR_CS_SelfDone = '3';
/// �ֹ��˽�
const char OR_CS_ManualDone = '4';
/// δ�γɸ�ծ
const char OR_CS_NoCom = '5';
ORAPI const char* or_compactstatus_enumstr(or_compactstatus_e value);

/////////////////////////////////////////////////////////////////////////
/// CompactSourceType��һ��ͷ����������
/////////////////////////////////////////////////////////////////////////
/// ͷ������
typedef char or_compactsource_e;
/// ����
const char OR_CSR_Share = '0';
/// ר��ͷ��
const char OR_CSR_Special = '1';
ORAPI const char* or_compactsource_enumstr(or_compactsource_e value);

/// ͷ����
typedef int64_t or_cashgroupid_i;
/////////////////////////////////////////////////////////////////////////
/// CashGroupType��һ��ͷ����������
/////////////////////////////////////////////////////////////////////////
/// ͷ������
typedef char or_cashgroup_e;
/// ����ͷ��
const char OR_CG_CoreCash = '0';
/// ��ͨҵ��ͷ��
const char OR_CG_NorCash = '1';
/// ר��ҵ��ͷ��
const char OR_CG_SpecCash = '2';
ORAPI const char* or_cashgroup_enumstr(or_cashgroup_e value);

/// ��չ��Ϣ
typedef char or_extendfield_s[OR_EXTENDFIELD_LEN];
/////////////////////////////////////////////////////////////////////////
/// AssureStatusType��һ������Ʒ״̬����
/////////////////////////////////////////////////////////////////////////
/// ����Ʒ״̬
typedef char or_assurestatus_e;
/// ����
const char OR_AS_Normal = '0';
/// ��ͣ
const char OR_AS_PAUSE = '1';
/// ����
const char OR_AS_INVALID = '2';
ORAPI const char* or_assurestatus_enumstr(or_assurestatus_e value);

/////////////////////////////////////////////////////////////////////////
/// FinStatusType��һ������״̬����
/////////////////////////////////////////////////////////////////////////
/// ����״̬
typedef char or_finstatus_e;
/// ����
const char OR_FS_Normal = '0';
/// ��ͣ
const char OR_FS_PAUSE = '1';
/// ����
const char OR_FS_INVALID = '2';
ORAPI const char* or_finstatus_enumstr(or_finstatus_e value);

/////////////////////////////////////////////////////////////////////////
/// SloStatusType��һ����ȯ״̬����
/////////////////////////////////////////////////////////////////////////
/// ��ȯ״̬
typedef char or_slostatus_e;
/// ����
const char OR_SS_Normal = '0';
/// ��ͣ
const char OR_SS_PAUSE = '1';
/// ����
const char OR_SS_INVALID = '2';
ORAPI const char* or_slostatus_enumstr(or_slostatus_e value);

/// ��ѯ������
typedef int64_t or_qtprequestid_i;
/// ��ѯ�Ự���
typedef int64_t or_qtpsessionid_i;
/// ��ѯǰ�ñ��
typedef int64_t or_qtpfrontid_i;
/////////////////////////////////////////////////////////////////////////
/// TFMdpTypeType��һ��������������
/////////////////////////////////////////////////////////////////////////
/// ��������
typedef char or_tfmdptype_e;
/// ʵʱ����
const char OR_MDPT_RealTime = '1';
/// ʵʱ�鲥����
const char OR_MDPT_RealMulticast = '2';
/// ѹ��ʵʱ����
const char OR_MDPT_ZipRealTime = 'a';
ORAPI const char* or_tfmdptype_enumstr(or_tfmdptype_e value);

/// JSON������Զ�������
typedef int64_t or_jsontypeid_i;
/// JSON��������
typedef char or_jsoncontent_s[OR_JSONCONTENT_LEN];
/// ��Ȩ��ϲ��Դ��루���������'PNSJC�Ϲ�ţ�м۲����'�ȡ�
typedef char or_optionscombstrategyid_s[OR_OPTIONSCOMBSTRATEGYID_LEN];
/// ��Ȩ��ϲ�����ϱ��룬OffsetFlag��ƽ����Ϊ���ʱ��Ҫ����ʱ����Ҫ��
typedef char or_optionscombsecondaryorderid_s[OR_OPTIONSCOMBSECONDARYORDERID_LEN];
/// ��ǰ��Ȩ��Ϻ�Լ����
typedef int64_t or_optionscomblegnum_i;

/// �Ϻ�֤ȯ������
static const char* OR_EXCHANGE_SSE = "SH";
/// ����֤ȯ������
static const char* OR_EXCHANGE_SZSE = "SZ";
/// �й������ڻ�������
static const char* OR_EXCHANGE_CFFEX = "CFFEX";
/// �Ϻ��ڻ�������
static const char* OR_EXCHANGE_SHFE = "SHFE";
/// ������Ʒ������
static const char* OR_EXCHANGE_DCE = "DCE";
/// ֣����Ʒ������
static const char* OR_EXCHANGE_CZCE = "CZCE";
/// ��Դ������
static const char* OR_EXCHANGE_INE = "INE";

} // namespace ort
} // namespace cycnoches
#endif
