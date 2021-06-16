#pragma once

#include "orchid/message/Package.h"
#include "orchid/dataflow/Flow.h"
#include "orchid/message/Package.h"
#include "orchid/common/logger.h"

using namespace orchid::net;

namespace orchid { namespace utility {

class CFlowReader {
public:
    // SetID时用的计算相对位置的标识，类似于fseek中用的SEEK_XXX宏
    enum SeekFlag { FROM_HEAD, FROM_HERE, FROM_END };

public:
    CFlowReader();
    ~CFlowReader();

public:
    /**
     * Attach flow which need to read.
     * @param pFlow under flow
     */
    bool attachFlow(CFlow* pFlow, int nStartId = 0);

    /**
     * Dettach under flow
     */
    void dettachFlow(void);

    /**
     * get under flow pointer
     */
    CFlow* getFlow();

    /**
     *  get the number of the flow in this moment
     */
    int getCount();

    /**
     * get the count which has not been readed
     */
    int getAvaliableCount();

    /// 从Flow中是否还有东西可读
    ///	return	true 表示还有，false 表示没有
    bool available();

public: // flat flow的方法
    ///设置下一个要读取的编号
    ///@param	id
    ///下一个要读取的编号，这个编号可以大于目前pFlow中的最大编号
    /// @param	from	编号的计算方法，可以是
    ///		FROM_HEAD	从头计算
    ///		FROM_HERE	从当前位置计算
    ///		FROM_END	从尾计算
    void setId(int id, SeekFlag from = FROM_HEAD);
    int getId();
    CPackagePtr getNext(bool pop);
    //带cond_var等待机制的GetNext
    CPackagePtr getNext(int timeoutMilliSeconds, bool pop);

protected:
    // shink flow的方法
    CPackagePtr popFront();
    CPackagePtr popFront(int waitMs);

private:
    int m_NextId;
    CFlow* m_pUnderFlow;
};

}} // namespace orchid::utility
