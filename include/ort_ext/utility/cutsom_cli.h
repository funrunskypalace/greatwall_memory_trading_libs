#pragma once
#include "ort/pre.h"

#include <iostream>
#include <string.h>

#include "orchid/common/logger.h"
#include "ort/libor.h"

namespace cycnoches
{

namespace ort
{

class CustomCli;
using CustomCliPtr = std::shared_ptr<CustomCli>;

struct CustomHandleInfo
{
    std::atomic_int64_t orderLocalId;
    std::atomic_int64_t localTradeID;
    std::atomic_int64_t localEntrustNo;

    CustomHandleInfo()
    {
        orderLocalId = 10000;
        localTradeID = 200000;
        localEntrustNo = 3000000;
    }
};

/**
 * CLI handler
 */
class CustomCli
{
protected:
    CustomCli(OrderRouterApi* pTradeApi) : pTradeApi(pTradeApi) {}

public:
    virtual ~CustomCli() = default;
    // return false means command has not handled yet!
    virtual bool custom_handle(char command, CustomHandleInfo& handleInfo)
    {
        return false;
    }
    virtual bool print_usage() { return false; }

protected:
    OrderRouterApi* pTradeApi;
};

struct TestResult
{
    int onError;    // 0
    int onRtnOrder; // 0
    int onRtnTrade; // 0
    // int onOrderSend;// 1
    // int onOrderCancel;// 0
    int onErrRtnOrderSend;   // 0
    int onErrRtnOrderCancel; // 0
    TestResult() { Clear(); }
    void Clear() { memset(this, 0, sizeof(TestResult)); }
};

} // namespace ort
} // namespace cycnoches
