#pragma once

#include "orchid/common/logger.h"

namespace orchid
{
namespace net
{

class CReactor;
class EventHandler
{
public:
    EventHandler(CReactor* pReactor) { reactor_ = pReactor; };
    virtual ~EventHandler() { ; };

public:
    inline CReactor* getReactor() { return reactor_; };

    virtual int onRead() { return 0; };
    virtual int onWrite() { return 0; };
    virtual void onTimer(int timerId) { return; };
    virtual int handleEvent(int eid, void* pParam);

    virtual bool post(int eid, void* param, int reserve = 0);
    virtual bool dispatch(int eid, void* param, int reserve = 0);

protected:
    CReactor* reactor_;
};

} // namespace net
} // namespace orchid