#pragma once

#include "orchid/common/common.h"
#include "orchid/common/logger.h"

namespace orchid
{
namespace net
{

const int PACK_MAX_LEN = 16 * 1024;

class CPackageBuffer
{
public:
    CPackageBuffer(int nSize);

    ~CPackageBuffer();

public:
    char* data();

    int length();

    void clear();

private:
    char* m_pHead;

    int m_nBufferSize;

    int m_nRefCount;

    bool m_bReleaseData;
};

class CPackage
{
public:
    CPackage();
    virtual ~CPackage();
    virtual void setOwnerId(int16_t ownwerId){};

public:
    ///构造一个空间,整体的长度为 body + nReserve
    ///@param nSize : body的长度
    ///@param nReserve : 预留的长度
    void constructAllocate(int nSize, int nReserve);

    ///截取空间，只留下nNewSize的大小（包括nReserve）
    void truncate(int nNewSize);

    inline int length() const;
    inline char* address() const;

public:
    ///从buffer内申请一个最大的空间
    ///@return : 申请空间的地址
    char* pushMax(void);

    ///从buffer内申请nSize的空间
    ///@return : NULL 如果空间不足； 否则为申请空间的地址
    char* push(int nSize);

    ///从空间中释放nSize的空间。 为栈操作，即先进先出。
    ///至多能pop到系统剩余nReserve的空间
    bool pop(int nSize);
    ///清空内容，只留下reserve空间
    virtual void clear();

    inline char* bodyAddress() const;
    inline int bodyLength() const;

public:
    /// Biz method
    /**业务系统的组包操作。由派生类自定义
     */
    virtual bool makePackage();

    /**业务系统的解包操作。由派生类自定义
     */
    virtual int validPackage();

    /**获取交易的消息类型
     */
    virtual int getTID() const;

    /**获取交易的消息主题。只对发布消息有意义。
     */
    virtual int16_t getTopicID() const;

    /**获取包的类型。
     */
    virtual char getPackageType() const;

protected:
    char* pHead_;
    char* pTail_;
    int reserve;
    CPackageBuffer* packageBuffer_;
};
using CPackagePtr = std::shared_ptr<CPackage>;

/**整个内容（包含reserver）的长度
 */
int CPackage::length() const { return (int)(pTail_ - pHead_); }

/**整个内容（包含reserver）的起始长度
 */
char* CPackage::address() const { return pHead_; }

/**剔除reserve的起始长度
 */
char* CPackage::bodyAddress() const { return pHead_ + reserve; }

int CPackage::bodyLength() const { return (int)(pTail_ - pHead_ - reserve); }

class PackagePool
{
public:
    using PackageCreationFunc = std::function<CPackagePtr()>;

    /// 在子类中必须初始化Package的Head Length。
    virtual CPackagePtr acquire(int16_t ownerId) PURE;

private:
    virtual void initPackage(CPackagePtr& package, int maxData,
                             int reserve) PURE;
};
using PackagePoolPtr = std::shared_ptr<PackagePool>;

class ClientPackagePool : public PackagePool
{
public:
    /// 在子类中必须初始化Package的Head Length。
    virtual CPackagePtr acquire(int16_t ownerId) override;

private:
    virtual void initPackage(CPackagePtr& package, int maxData,
        int reserve) override;
};

} // namespace net
} // namespace orchid
