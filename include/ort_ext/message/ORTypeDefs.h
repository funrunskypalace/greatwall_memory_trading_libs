#pragma once

/// 2020-03-24 ����Topic��Package Type�����
/// ��PBTradingSystem�����У�Topic��Trading��ReqResp���֣�Package
/// TypeҲֻ��Req��Rsp���֡� ����֮ǰ��OR������У�û����Topic��������5��Package
/// Type��
/// ���ڣ���ΪFront�����PBTradingSystem����ֲ����������OR��Ҳ��Ҫ����Topic�ĸ��
/// ��ͳ����������ˡ�

#include <stdint.h>
typedef int TSessionID;

const int TID_Finished = 0x0000ffff; // LAST TID

const char ORT_PKG_VERSION = 'A';

const int ORT_TOPIC_REQRESP = 0x0000; //����Ӧ��a
const int ORT_TOPIC_TRADING = 0x0001; //���׻ر�

const char ORT_PKGCHAIN_NORMAL = 'N';
const char ORT_PKGCHAIN_LAST = 'L';

const char ORT_PKGTYPE_REQ = '1'; // ��������
const char ORT_PKGTYPE_RTN = '2'; // Ӧ��ظ�,
const char ORT_PKGTYPE_RAW = '6'; // ͨ�����ص�����/����

//@Model Ӧ�ø��������߼�������ϢTIpackage_pool_
//������ϢTID����
// const int TID_OR_ReqHeartBeat =3;				//��������
// const int TID_OR_RspHeartBeat =4;				//����Ӧ��
const int TID_OR_ReqSubscribeTopic = 12;     //������������UFT���ڶ��ڳɽ��ͻر�
const int TID_OR_Login = 17;                 //��¼��̨
const int TID_OR_Logout = 18;                //�ǳ���̨
const int TID_OR_RspRuntimeStatus = 19;      //ͨ�����ʽ��˺ŵ�¼�ɹ�
const int TID_OR_ReqHeartBeat = 20;          // front-����
const int TID_OR_RspHeartBeat = 21;          // front-����
const int TID_OR_FrontConnect = 22;          // front-connected
const int TID_OR_FrontDisconnect = 23;       // front-disconnected
const int TID_OR_OperatorLogin = 24;         //��¼��̨
const int TID_OR_RspOperatorLogin = 25;      //�ʽ��˺ŵ�¼��Ӧ
const int TID_OR_OperatorLogout = 26;        //�ǳ���̨
const int TID_OR_RspOperatorLogout = 27;     //�ʽ��˺ŵ�¼��Ӧ
const int TID_OR_RspCheckAccount = 28;       // front��Ҫ��onCheckAccount��װ��client
const int TID_OR_QryCommissionRate = 100;    //��ѯ������
const int TID_OR_RspQryCommissionRate = 101; //��ѯ�����ѻظ�
const int TID_OR_QryMarginRate = 102;        //��ѯ��֤��
const int TID_OR_RspQryMarginRate = 103;     //��ѯ��֤��ظ�
const int TID_OR_QryAccount = 143;           //��ѯ�˻��ʽ�
const int TID_OR_RspQryAccount = 144;        //��ѯ�˻��ʽ�ظ�
const int TID_OR_QryTradeCode = 145;         //��ѯ�ɶ�����
const int TID_OR_RspQryTradeCode = 146;      //��ѯ�ɶ�����ظ�
const int TID_OR_QryPosition = 147;          //��ѯ�ֲ�
const int TID_OR_RspQryPosition = 148;       //��ѯ�ֲֻظ�
const int TID_OR_QryTradeDate = 149;         //��ѯ��������
const int TID_OR_RspQryTradeDate = 150;      //��ѯ�������ڻָ�
const int TID_OR_ErrorMsg = 151;             //����ر���Ϣ
const int TID_OR_QryStockCode = 153;         //��ѯ֤ȯ������Ϣ
const int TID_OR_RspQryStockCode = 154;      //֤ȯ�����ѯ��Ӧ
const int TID_OR_RspLogin = 155;             //�ʽ��˺ŵ�¼��Ӧ
const int TID_OR_ReqAssetTransfer = 156;     //�ʽ𻮲�
const int TID_OR_RspAssetTransfer = 157;     //������Ӧ
// const int TID_OR_RspQryFuturesPosition = 159;	//��ѯ�ֲֻظ�
const int TID_OR_QryPositionDtl = 160;             //��ѯ�ֲ���ϸ
const int TID_OR_RspQryPositionDtl = 161;          //��ѯ�ֲ���ϸ�ظ�
const int TID_OR_QryFuturesAccountMargin = 162;    //��ѯ�ڻ���֤��
const int TID_OR_RspQryFuturesAccountMargin = 163; //��ѯ�ڻ���֤��ظ�
const int TID_OR_QryTradingCodeType = 164;         //��ѯͶ�ʱ�������
const int TID_OR_RspQryTradingCodeType = 165;      //��ѯͶ�ʱ������ͻظ�
const int TID_OR_QryStockPurQuotation = 166;       //��ѯ�¹��깺���
const int TID_OR_RspQryStockPurQuotation = 167;    //��ѯ�¹��깺��Ȼظ�
const int TID_OR_QryStockPurStatistics = 168;      //��ѯ�¹��깺������Ϣ
const int TID_OR_RspQryStockPurStatistics = 169;   //��ѯ�¹��깺������Ϣ�ظ�
const int TID_OR_QryStockPurInfo = 170;            //��ѯ�¹��깺��Ϣ
const int TID_OR_RspQryStockPurInfo = 171;         //��ѯ�¹��깺��Ϣ�ظ�
const int TID_OR_QryInvestor = 172;                //��ѯͶ������Ϣ
const int TID_OR_RspQryInvestor = 173;             //��ѯͶ������Ϣ�ظ�
const int TID_OR_Req_START = 200;                  //��ҪORRequestID��ί��������ʼ���
const int TID_OR_ReqOrderInsert = 201;             //���Ͷ�������
const int TID_OR_ReqOrderCancel = 202;             //���ͳ�������
const int TID_OR_RtnOrder = 203;                   //���Ͷ�����Ӧ��Ϣ
const int TID_OR_RtnTrade = 204;                   //���ͳɽ���Ӧ��Ϣ
const int TID_OR_RspOrderInsert = 205; //����Ӧ��(UFT:�ύ����̨�ӿ�ʱ�������أ�RspInfo.ErrrorID���ڱ����ɹ���ʧ��)
const int TID_OR_RspOrderCancel = 206;            //��̨����ȷ��Ӧ��
const int TID_OR_RspOrderCancelFailure = 207;     //��̨����ʧ��ȷ��Ӧ��
const int TID_OR_ErrRtnOrder = 208;               //���Ͷ���ʧ����Ϣ
const int TID_OR_ErrRtnOrderCancel = 209;         //���ͳ���ʧ����Ϣ
const int TID_OR_QryOrder = 210;                  //��ѯ����
const int TID_OR_RspQryOrder = 211;               //��ѯ�����ظ�
const int TID_OR_QryTrade = 212;                  //��ѯ�ɽ�
const int TID_OR_RspQryTrade = 213;               //��ѯ�ɽ��ظ�
const int TID_OR_RtnOrderCancel = 214;            //�����ѱ�����̨/��������ȷ��
const int TID_OR_ReqJsonTrading = 215;            //����JSON��ʽ������
const int TID_OR_RspJsonTrading = 216;            //�ظ�JSON��ʽ������
const int TID_OR_Req_END = 299;                   //��ҪORRequestID��ί��������ֹ���
const int TID_OR_RspQryStrategyPosition = 3001;   //��LTS����ѯ���Գֲ���Ϣ
const int TID_OR_PushMarket = 5001;               // ��������
const int TID_OR_PushTickByTick = 5002;           // ��ʳɽ�
const int TID_OR_PushOrderBook = 5003;            // ������
const int TID_OR_SubMarketData = 5011;            //����������
const int TID_OR_RspSubMarketData = 5012;         //����������ظ�
const int TID_OR_RspOrderPositionStr = 10000 + 1; // ����ί�в�ѯλ��
const int TID_OR_RspTradePositionStr = 10000 + 2; // ���³ɽ��ر���ѯλ��
