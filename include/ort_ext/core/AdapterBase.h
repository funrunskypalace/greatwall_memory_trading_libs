#pragma once
#include <memory>
#include "ort_ext/message/OrtPackage.h"
#include "orchid/common/logger.h"
#include "orchid/event/timer.h"
#include "ort/libor.h"
#include "ort_ext/core/OrderRouterExtApi.h"

using namespace orchid;

namespace cycnoches
{
namespace ort
{

using InvestorTradingCodesPtr =
    std::unordered_map<std::string /*or_exchangeid_s*/, std::shared_ptr<ORTradingCodeField>>;
class AdapterBase
{
public:
    AdapterBase(frm_event::TimeSystem& timeSystem) : time_source_(timeSystem){};
    virtual const char* getID() const = 0;
    virtual int initialize(ORCounterConfigField counterConfig, OrderRouterExtApi* tradeApi) = 0;
    /**
     * \brief ���ӵ�ͨ����
     * \return OR_ERR_OK if connect.
     */
    virtual int connectChannel() = 0;
    virtual or_channelid_i getChannelID() const = 0;
    virtual ~AdapterBase() {}
    /**
     * \brief �������󵽹�̨.
     * \remarks package
     * \param package
     * ���ͱ������ݡ�package�б������RequestID��AccountCode��ChannelID��Ϣ��
     * \return
     */
    virtual int sendRequest(const OrtPackagePtr& package) = 0;
    virtual void subscribe(const ORInvestorFieldPtr& investor, const InvestorTradingCodesPtr& tradingCodes) = 0;
    /**
     * \brief �Ƿ���Ҫ��ʱ����ί�кͳɽ���©��ȱ����
     * \return
     */
    virtual bool needCheckOrder() = 0;
    virtual bool isConnected() = 0;
    virtual bool initialized() = 0;
    void notifyClose() { closing_ = true; }
    bool isClosing() { return closing_; }
    virtual void close() = 0;
    template <class real_datatype_t> static real_datatype_t* RealData(const OrtPackagePtr& package)
    {
        return reinterpret_cast<real_datatype_t*>(package->bodyAddress());
    }
    frm_event::TimeSystem& timeSource() const { return time_source_; }
    virtual void heartBeatAsync() {}

protected:
    virtual ORInvestorFieldPtr getInvestor(or_orrequestid_i requestId) const = 0;
    /**
     * \brief ����̨���صĲ�ѯ������ݷ�װΪpackage���ظ�ORCore(Router)��
     * \param package ����̨���ص������ύ��API
     * \return
     */
    virtual int writeQueryRsp(const OrtPackagePtr& package) = 0;
    /**
     * \brief ����̨���صĽ���������ݷ�װΪpackage���ظ� Router�ࡣ
     * \package ���ر������ݡ�package�б���������������������µĶ�ѡһ��
     * -
     * ����������AccountCode��ChannelID��CounterOrderID�����ֶΣ�������Router::forwardRaw()����ʱ
     *   ƥ��õ�ί��(���ǳ������̣���Ӧ�ṩ������ί�У���ORRequestID��
     * - ���߰�������ί�У����ǳ������̣���Ӧ�ṩ������ί�У���ORRequestID��
     */
    virtual int writeTradeRtn(const OrtPackagePtr& package) = 0;

private:
    frm_event::TimeSystem& time_source_;
    std::atomic<bool> closing_ = { false };
};
using AdapterBasePtr = std::shared_ptr<AdapterBase>;

extern std::string g_op_station_template;

extern std::string op_station_template_fill(const char* templ, const OROrderReqField* orderReq);
extern std::string op_station_template_fill(const char* templ, const ORReqLoginField* orderReq);

} // namespace ort
} // namespace cycnoches