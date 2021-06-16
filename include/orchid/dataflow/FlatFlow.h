#pragma once

#include "orchid/dataflow/Flow.h"
#include "orchid/common/logger.h"

namespace orchid { namespace utility {

class CFlatFlow : public CFlow {
public:
    virtual ~CFlatFlow(){};

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
    virtual FlowType getFlowType() { return FLAT; }

    /*
     * flat flow not supported pop serial method
     */

    /**
     * pop the front node and free the memory
     * @param buffer to save data
     * @param nMaxLength max buffer size
     * @return the true length
     */
    virtual CPackagePtr popFront()
    {
        std::cerr << "POP Not Supported in Flat Flow" << std::endl;
        return nullptr;
    };

    virtual CPackagePtr popFront(int waitMs)
    {
        std::cerr << "POP Not Supported in Flat Flow" << std::endl;
        return nullptr;
    };
};

}} // namespace orchid::utility
