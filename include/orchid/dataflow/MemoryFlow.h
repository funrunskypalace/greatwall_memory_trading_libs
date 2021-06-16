#pragma once

#include "orchid/message/Package.h"
#include "orchid/dataflow/FlatFlow.h"
#include <mutex>

using namespace std;
using namespace orchid::net;

namespace orchid { namespace utility {

#define MNQ_MAX_NODE 0x10000000
#define MNQ_BLOCK_SIZE 0x00010000
#define MNQ_BUCKET_SIZE (MNQ_MAX_NODE / MNQ_BLOCK_SIZE)

using CPackageVector = std::vector<CPackagePtr>;
using packageVector = CPackageVector*;
class CMemoryNodeQueue {
public:
    CMemoryNodeQueue();
    ~CMemoryNodeQueue();

public:
    inline void pushBack(const CPackagePtr& package)
    {
        if ((m_nNodeCount % MNQ_BLOCK_SIZE) == 0) {
            m_pBuckets[m_nNodeCount / MNQ_BLOCK_SIZE] = new CPackageVector(MNQ_BLOCK_SIZE);
        }

        (*this)[m_nNodeCount] = package;
        m_nNodeCount++;
    }

    inline CPackagePtr& operator[](size_t id) { return (*m_pBuckets[id / MNQ_BLOCK_SIZE])[id & (MNQ_BLOCK_SIZE - 1)]; }

    inline size_t size(void) { return m_nNodeCount; }

    void clear();

    void popFront(size_t id)
    {
        if (m_nNodeCount > 0) {
            m_nNodeCount--;
            m_nFirstID++;
        }
        else {
            return;
        }
    }

private:
    volatile size_t m_nNodeCount;
    size_t m_nFirstID;
    packageVector m_pBuckets[MNQ_BUCKET_SIZE];
};

class CMemoryFlow : public CFlatFlow {
public:
    CMemoryFlow(int nMaxObject, int nBlockSize, bool bSyncFlag = false);
    virtual ~CMemoryFlow();

public:
    virtual int append(const CPackagePtr& package);
    virtual CPackagePtr get(size_t id, bool pop);
    virtual CPackagePtr get(size_t id, int timeoutMilliseconds, bool pop);
    virtual int getCount();
    virtual bool truncate(int nLetfCount);

public:
    void attachUnderFlow(CFlow* pFlow);
    int getUnderCount();

private:
    int appendWithoutSync(const CPackagePtr& package);

private:
    volatile int m_nCount;
    mutex m_Mutex;
    condition_variable m_Condv;
    CMemoryNodeQueue m_NodeQueue;
    int m_nBlockSize;
    size_t m_nFirstID;
    bool m_bSyncFlag;
    int m_wCommPhaseNo;

protected:
    /// File Flow
    CFlow* m_pUnderFlow;
};

}} // namespace orchid::utility
