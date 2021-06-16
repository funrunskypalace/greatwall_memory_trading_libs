#pragma once
#include "orchid/dataflow/FlatFlow.h"
#include "orchid/message/Package.h"

using namespace orchid::net;

namespace orchid { namespace utility {

///抛出一个设计运行时异常，用于确定错误位置。
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
    FILE* m_fpIdFile;                  /// 存储偏移量的文件
    FILE* m_fpContentFile;             /// 存储内容的文件
    std::vector<fpos_t> m_BlockOffset; /// 对象块的偏移量
    int m_nCount;                      /// 已经存在的包个数
    fpos_t m_nContentSize;             ///所有已有包的内容长度总和
    int m_nReadId;                     /// 最近一次读取的包的序号
    fpos_t m_nReadOffset;              /// 最近一次读取的包在文件中的偏移量
    int m_nCommPhaseNo;                /// 通讯阶段编号

    std::mutex m_criticalVar; /// 临界区变量
};

}} // namespace orchid::utility
