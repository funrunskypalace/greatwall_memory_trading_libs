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
    bool sendKey; // 在UFT2中，标识是否发送Key而非Content
    int32_t tID;
    int32_t fieldCount;
    int32_t bodyLen;
    or_orrequestid_i requestID;
    or_channelid_i channelID;
    or_investorid_i investorID; // 唯一标识
    int64_t time;               // nano-time
    int64_t sequenceNo;         // 用于标识FlatFlow流中的序号。
    int64_t lastSn;             // 用于每个Rtn报文的持久性编号，避免多次重发。
    int16_t topicId;
    int16_t ownerId;
    char channelType;
    char accountCode[OR_ACCOUNTCODE_LEN]; // 对于UFT是fund_account，对于O32是多字段的拼合。
    char password[OR_PASSWORD_LEN];
};
#pragma pack(pop)

class OrtPackage;
std::string g_packageHeaderDesc(OrtPackage* package, const char* delim);

class ORAPI OrtPackage : public CPackage {
    /***
     *使用方法
     *  解包操作：
     *		1. setBuffer(): copy buffer整个数据到package中
     *		3. 根据GetTID()\GetTopicID()\GetRequestID()
     *等，对BodyAddress()指针做强制转换，进行业务处理/构造消息体并unpack，然后进行业务处理
     *  打包操作：
     *		1. preparePackage(): 将bizPackage中的_header进行赋值
     *		2. addFields():
     *将包体（例如oder）打包到package中，可进行多次add操作，相应的，解包的时候，会进行多次Address的取出和强转操作
     *		3. makePackage(): 将包头打进Package中
     **/

public:
    OrtPackage();
    virtual ~OrtPackage();

    /*
    设置整个buffer内容， 包括头。 一般用于拷贝构造 或者从流中构造整个Package
    */
    void setBuffer(const char* buffer, int len);
    bool addFields(const char* buffer, int len);
    /**
     * \brief 预留空间，返回空间首地址。若返回非空，则fieldCount加1。
     * \param len
     * \return 空间首地址。
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
