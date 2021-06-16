#pragma once
#include "orchid/dataflow/FlatFlow.h"
#include "orchid/message/Package.h"

using namespace orchid::net;

namespace orchid { namespace utility {

///�׳�һ���������ʱ�쳣������ȷ������λ�á�
#define RAISE_RUNTIME_ERROR(msg)                                                                                                 \
    {                                                                                                                            \
        fprintf(stderr, "RuntimeError:%s in line %d of file %s\n", msg, __LINE__, __FILE__);                                     \
        char* __pNull = NULL;                                                                                                    \
        *__pNull = 0;                                                                                                            \
        exit(-1);                                                                                                                \
    }

class CFileFlow : public CFlatFlow {
public:
    /// CFileFlow Constructor based file name
    CFileFlow(const PackagePoolPtr& packagePool, const char* pszName, const char* pszPath, bool bReuse);

    /// CFileFlow Constructor based id
    CFileFlow(const PackagePoolPtr& packagePool, int _id, const char* pszPath, bool bReuse);

    virtual ~CFileFlow();

public:
    /** Append data to this flow
    @param pData Data
    @param nLength Data Length
    */
    virtual int append(const CPackagePtr& package);

    /** Read data from this flow
    @param id index of data in the flow
    @param buffer to save data
    @param nMaxLength max buffer size
    */
    virtual CPackagePtr get(size_t id, bool pop);

    virtual CPackagePtr get(size_t id, int timeoutMilliseconds, bool pop);

    /** get package count of this flow
     */
    virtual int getCount();

    /**
    @param nLetfCount  left packages count
    */
    virtual bool truncate(int nLetfCount);

protected:
    /** Open flow file
     */
    void openFile(const char* szFilename, const char* szPath, bool bReuse);

    /** Init flow file
     */
    bool initFile();

    /** Close flow file
     */
    void closeFile();

    /** Get content file size
     */
    fpos_t getContentSize(void);

    /** Get offset of id package
     */
    fpos_t getOffset(int id);

private:
    PackagePoolPtr package_pool_;
    FILE* m_fpIdFile;                  /// �洢ƫ�������ļ�
    FILE* m_fpContentFile;             /// �洢���ݵ��ļ�
    std::vector<fpos_t> m_BlockOffset; /// ������ƫ����
    int m_nCount;                      /// �Ѿ����ڵİ�����
    fpos_t m_nContentSize;             ///�������а������ݳ����ܺ�
    int m_nReadId;                     /// ���һ�ζ�ȡ�İ������
    fpos_t m_nReadOffset;              /// ���һ�ζ�ȡ�İ����ļ��е�ƫ����
    int m_nCommPhaseNo;                /// ͨѶ�׶α��

    std::mutex m_criticalVar; /// �ٽ�������
};

}} // namespace orchid::utility
