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
     * \brief 连接到通道。
     * \return OR_ERR_OK if connect.
     */
    virtual int connectChannel() = 0;
    virtual or_channelid_i getChannelID() const = 0;
    virtual ~AdapterBase() {}
    /**
     * \brief 发送请求到柜台.
     * \remarks package
     * \param package
     * 发送报文内容。package中必须包含RequestID、AccountCode、ChannelID信息。
     * \return
     */
    virtual int sendRequest(const OrtPackagePtr& package) = 0;
    virtual void subscribe(const ORInvestorFieldPtr& investor, const InvestorTradingCodesPtr& tradingCodes) = 0;
    /**
     * \brief 是否需要定时进行委托和成交查漏补缺操作
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
     * \brief 将柜台返回的查询相关数据封装为package返回个ORCore(Router)。
     * \param package 将柜台返回的数据提交给API
     * \return
     */
    virtual int writeQueryRsp(const OrtPackagePtr& package) = 0;
    /**
     * \brief 将柜台返回的交易相关数据封装为package返回给 Router类。
     * \package 返回报文内容。package中必须包含包含的内容是如下的二选一：
     * -
     * 包含完整的AccountCode、ChannelID、CounterOrderID三个字段，用于在Router::forwardRaw()处理时
     *   匹配得到委托(若是撤单流程，则应提供被撤单委托）的ORRequestID。
     * - 或者包含发送委托（若是撤单流程，则应提供被撤单委托）的ORRequestID。
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