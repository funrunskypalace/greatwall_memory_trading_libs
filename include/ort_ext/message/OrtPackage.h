#pragma once

#include "ort/pre.h"
#include "pch/compat.h"
#include <string>

#include "orchid/message/Package.h"
#include "ort/ORDataStruct.h"
#include "ort_ext/message/ORTypeDefs.h"

using namespace orchid;
using namespace orchid::net;

namespace cycnoches { namespace ort {

#pragma pack(push, 1)
struct PackageHeader {
    char version;
    char packageType;
    char chain;
    bool sendKey; // ��UFT2�У���ʶ�Ƿ���Key����Content
    int32_t tID;
    int32_t fieldCount;
    int32_t bodyLen;
    or_orrequestid_i requestID;
    or_channelid_i channelID;
    or_investorid_i investorID; // Ψһ��ʶ
    int64_t time;               // nano-time
    int64_t sequenceNo;         // ���ڱ�ʶFlatFlow���е���š�
    int64_t lastSn;             // ����ÿ��Rtn���ĵĳ־��Ա�ţ��������ط���
    int16_t topicId;
    int16_t ownerId;
    char channelType;
    char accountCode[OR_ACCOUNTCODE_LEN]; // ����UFT��fund_account������O32�Ƕ��ֶε�ƴ�ϡ�
    char password[OR_PASSWORD_LEN];
};
#pragma pack(pop)

class OrtPackage;
std::string g_packageHeaderDesc(OrtPackage* package, const char* delim);

class ORAPI OrtPackage : public CPackage {
    /***
     *ʹ�÷���
     *  ���������
     *		1. setBuffer(): copy buffer�������ݵ�package��
     *		3. ����GetTID()\GetTopicID()\GetRequestID()
     *�ȣ���BodyAddress()ָ����ǿ��ת��������ҵ����/������Ϣ�岢unpack��Ȼ�����ҵ����
     *  ���������
     *		1. preparePackage(): ��bizPackage�е�_header���и�ֵ
     *		2. addFields():
     *�����壨����oder�������package�У��ɽ��ж��add��������Ӧ�ģ������ʱ�򣬻���ж��Address��ȡ����ǿת����
     *		3. makePackage(): ����ͷ���Package��
     **/

public:
    OrtPackage();
    virtual ~OrtPackage();

    /*
    ��������buffer���ݣ� ����ͷ�� һ�����ڿ������� ���ߴ����й�������Package
    */
    void setBuffer(const char* buffer, int len);
    bool addFields(const char* buffer, int len);
    /**
     * \brief Ԥ���ռ䣬���ؿռ��׵�ַ�������طǿգ���fieldCount��1��
     * \param len
     * \return �ռ��׵�ַ��
     */
    char* allocFieldBuffer(int len);

    /************************************************************************/
    /* !!!!!WARNING : do not remove filed unless u know the pkg  detail !!!!*/
    /************************************************************************/
    bool removeFields(const char* buffer, int len);

    void cleanFields();

    // todo: need add , or_investorid_i investorId?
    virtual void preparePackage(int32_t tid, int32_t packageType, int32_t topicId, or_channelid_i channelId,
                                or_investorid_i investorId = INVALID_INVESTORID, char chain = ORT_PKGCHAIN_LAST);
    virtual bool makePackage();
    virtual int validPackage();

    int32_t getFieldCount() const { return packageHeader_->fieldCount; }
    bool getSendKey() const { return packageHeader_->sendKey; }
    void setSendKey(bool val) { packageHeader_->sendKey = val; }
    int32_t getTID() const;
    void setTID(int32_t TID) { packageHeader_->tID = TID; }
    or_investorid_i getInvestorID() const;
    void setInvestorID(or_investorid_i investorId);
    char* getAccountCode() const;
    void setAccountCode(const char* code);
    char* getPassword() const;
    void setPassword(const char* pwd);

    void setLastSn(int64_t lastSn);
    void setVersion(char version);
    void setPackageType(char type);
    void setRequestID(or_orrequestid_i id);
    void setTime(int64_t recvTime) const;
    void setTopicID(int16_t topicId);
    virtual void setOwnerId(int16_t ownerId) override;
    void setSequenceNo(int64_t seqNo);

    int64_t getLastSn() const;
    char getVersion() const;
    char getPackageType() const override;
    or_orrequestid_i getRequestID() const;
    int64_t getTime() const;
    int16_t getTopicID() const;
    virtual int getOwnerID() const;
    virtual int64_t getSequenceNo() const;

    void setChannelID(or_channelid_i channelID) const;
    void setChannelType(char channelType) const;
    or_channelid_i getChannelID() const;
    char getChannelType() const;

public:
    OrtPackage(const OrtPackage&);
    OrtPackage& operator=(const OrtPackage&);
    virtual void clear() override;

private:
    /// the contexts of the header.
    PackageHeader* packageHeader_;
};
using OrtPackagePtr = std::shared_ptr<OrtPackage>;
using OrtPackageList = std::list<OrtPackagePtr>;

}} // namespace cycnoches::ort
