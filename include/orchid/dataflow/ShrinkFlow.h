#pragma once

#include "orchid/dataflow/Flow.h"
#include <iostream>

namespace orchid
{
namespace utility
{

class CShrinkFlow : public CFlow
{
public:
    virtual ~CShrinkFlow(){};

public:
    /**
     * Append data to this flow
     * @param pData Data
     * @param nLength Data Length
     */
    virtual int append(const CPackagePtr& package) = 0;

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
    virtual FlowType getFlowType() { return SHRINK; }

public:
    /*
     * flat flow not supported pop serial method
     */

    /**
     * Read data from this flow
     * @param id index of data in the flow
     * @param buffer to save data
     * @param nMaxLength max buffer size
     * 非阻塞版本，如果能获取到，返回长度，获取不到返回-1
     */
    virtual CPackagePtr get(size_t id, bool pop)
    {
        if (!pop)
        {
            std::cerr << "Get with Index Not Supported in Flat Flow"
                      << std::endl;
            return nullptr;
        }
        return popFront();
    };

    /**
     * 阻塞版本，等待timeoutMilliseconds毫秒
     * 如果能获取到，返回长度，获取不到返回-1
     */
    virtual CPackagePtr get(size_t id, int timeoutMilliseconds, bool pop)
    {
        if (!pop)
        {
            std::cerr << "Get with Index Not Supported in Flat Flow"
                      << std::endl;
            return nullptr;
        }
        return popFront(timeoutMilliseconds);
    };

protected:
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
