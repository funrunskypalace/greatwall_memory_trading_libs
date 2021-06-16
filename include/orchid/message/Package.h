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
    ///����һ���ռ�,����ĳ���Ϊ body + nReserve
    ///@param nSize : body�ĳ���
    ///@param nReserve : Ԥ���ĳ���
    void constructAllocate(int nSize, int nReserve);

    ///��ȡ�ռ䣬ֻ����nNewSize�Ĵ�С������nReserve��
    void truncate(int nNewSize);

    inline int length() const;
    inline char* address() const;

public:
    ///��buffer������һ�����Ŀռ�
    ///@return : ����ռ�ĵ�ַ
    char* pushMax(void);

    ///��buffer������nSize�Ŀռ�
    ///@return : NULL ����ռ䲻�㣻 ����Ϊ����ռ�ĵ�ַ
    char* push(int nSize);

    ///�ӿռ����ͷ�nSize�Ŀռ䡣 Ϊջ���������Ƚ��ȳ���
    ///������pop��ϵͳʣ��nReserve�Ŀռ�
    bool pop(int nSize);
    ///������ݣ�ֻ����reserve�ռ�
    virtual void clear();

    inline char* bodyAddress() const;
    inline int bodyLength() const;

public:
    /// Biz method
    /**ҵ��ϵͳ��������������������Զ���
     */
    virtual bool makePackage();

    /**ҵ��ϵͳ�Ľ�����������������Զ���
     */
    virtual int validPackage();

    /**��ȡ���׵���Ϣ����
     */
    virtual int getTID() const;

    /**��ȡ���׵���Ϣ���⡣ֻ�Է�����Ϣ�����塣
     */
    virtual int16_t getTopicID() const;

    /**��ȡ�������͡�
     */
    virtual char getPackageType() const;

protected:
    char* pHead_;
    char* pTail_;
    int reserve;
    CPackageBuffer* packageBuffer_;
};
using CPackagePtr = std::shared_ptr<CPackage>;

/**�������ݣ�����reserver���ĳ���
 */
int CPackage::length() const { return (int)(pTail_ - pHead_); }

/**�������ݣ�����reserver������ʼ����
 */
char* CPackage::address() const { return pHead_; }

/**�޳�reserve����ʼ����
 */
char* CPackage::bodyAddress() const { return pHead_ + reserve; }

int CPackage::bodyLength() const { return (int)(pTail_ - pHead_ - reserve); }

class PackagePool
{
public:
    using PackageCreationFunc = std::function<CPackagePtr()>;

    /// �������б����ʼ��Package��Head Length��
    virtual CPackagePtr acquire(int16_t ownerId) PURE;

private:
    virtual void initPackage(CPackagePtr& package, int maxData,
                             int reserve) PURE;
};
using PackagePoolPtr = std::shared_ptr<PackagePool>;

class ClientPackagePool : public PackagePool
{
public:
    /// �������б����ʼ��Package��Head Length��
    virtual CPackagePtr acquire(int16_t ownerId) override;

private:
    virtual void initPackage(CPackagePtr& package, int maxData,
        int reserve) override;
};

} // namespace net
} // namespace orchid
