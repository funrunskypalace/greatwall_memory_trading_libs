#pragma once

#include "orchid/message/Package.h"
#include "orchid/dataflow/Flow.h"
#include "orchid/message/Package.h"
#include "orchid/common/logger.h"

using namespace orchid::net;

namespace orchid { namespace utility {

class CFlowReader {
public:
    // SetIDʱ�õļ������λ�õı�ʶ��������fseek���õ�SEEK_XXX��
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

    /// ��Flow���Ƿ��ж����ɶ�
    ///	return	true ��ʾ���У�false ��ʾû��
    bool available();

public: // flat flow�ķ���
    ///������һ��Ҫ��ȡ�ı��
    ///@param	id
    ///��һ��Ҫ��ȡ�ı�ţ������ſ��Դ���ĿǰpFlow�е������
    /// @param	from	��ŵļ��㷽����������
    ///		FROM_HEAD	��ͷ����
    ///		FROM_HERE	�ӵ�ǰλ�ü���
    ///		FROM_END	��β����
    void setId(int id, SeekFlag from = FROM_HEAD);
    int getId();
    CPackagePtr getNext(bool pop);
    //��cond_var�ȴ����Ƶ�GetNext
    CPackagePtr getNext(int timeoutMilliSeconds, bool pop);

protected:
    // shink flow�ķ���
    CPackagePtr popFront();
    CPackagePtr popFront(int waitMs);

private:
    int m_NextId;
    CFlow* m_pUnderFlow;
};

}} // namespace orchid::utility
