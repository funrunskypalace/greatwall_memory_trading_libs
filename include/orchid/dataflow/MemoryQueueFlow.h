#pragma once
#include "orchid/dataflow/ShrinkFlow.h"
#include <condition_variable>
#include <mutex>
#include <queue>

using namespace std;
namespace orchid { namespace utility {

class CMemoryQueueFlow : public CShrinkFlow {
public:
    CMemoryQueueFlow(const char* name) : _mutex(), _condvar(), _pQueue(NULL), _name(name)
    {
        _pQueue = new std::queue<CPackagePtr>();
    };

    virtual ~CMemoryQueueFlow()
    {
        if (_pQueue) delete _pQueue;
    };

public:
    virtual int append(const CPackagePtr& package);
    virtual int getCount();

public:
    virtual bool truncate(int nLetfCount) { return false; };

protected:
    virtual CPackagePtr popFront();
    virtual CPackagePtr popFront(int waitMs);

private:
    mutable std::mutex _mutex;
    std::condition_variable _condvar;
    std::queue<CPackagePtr>* _pQueue;
    std::string _name;
};

}} // namespace orchid::utility
