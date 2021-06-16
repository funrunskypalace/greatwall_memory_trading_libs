#pragma once

#include "orchid/message/Package.h"
using namespace orchid::net;

namespace orchid
{
namespace utility
{

enum FlowType
{
    FLAT,  //只增不减
    SHRINK //生产者消费者
};

class CFlow
{
public:
    virtual ~CFlow(){};

public:
    /**
     * Append data to this flow
     * @param pData Data
     * @param nLength Data Length
     */
    virtual int append(const CPackagePtr& package) = 0;

    /**
     * Read data from this flow
     * @param id index of data in the flow
     * @param buffer to save data
     * @param nMaxLength max buffer size
     * 非阻塞版本，如果能获取到，返回长度，获取不到返回-1
     */
    virtual CPackagePtr get(size_t id, bool pop) = 0;

    /**
     * 阻塞版本，等待timeoutMilliseconds毫秒
     * 如果能获取到，返回长度，获取不到返回-1
     */
    virtual CPackagePtr get(size_t id, int timeoutMilliseconds, bool pop) = 0;

    /**
     * get package count of this flow
     */
    virtual int getCount() = 0;

    /**
     * @param nLetfCount left packages count
     */
    virtual bool truncate(int nLetfCount) = 0;

    /*
     * flat or shink
     */
    virtual FlowType getFlowType() = 0;

    /**
     * pop the front node and free the memory
     * @paramp buffer to save data
     * @param nMaxLength max buffer size
     * @return the true length
     */
    virtual CPackagePtr popFront() = 0;

    virtual CPackagePtr popFront(int waitMs) = 0;
};

} // namespace utility
} // namespace orchid
