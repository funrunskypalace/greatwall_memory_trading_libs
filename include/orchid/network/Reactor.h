#pragma once

namespace orchid
{
namespace net
{

enum IoOps
{
    IO_READ = 0x01,
    IO_WRITE = 0x02
};

class EventHandler;

class CReactor
{
public:
    static CReactor* createReactor();
    virtual void setName(const char* pName) = 0;
    virtual std::string getName() const = 0;
    virtual bool create(void) = 0;
    virtual void join(void) = 0;
    /// 注册一个timer事件 timeout和elapse 单位为us
    virtual bool registerTimer(EventHandler* timerHandler, int timerID,
                               int64_t timeout, int64_t repeat) = 0;
    virtual bool registerIO(EventHandler* handler, int fd,
                            IoOps ops = IO_READ) = 0;
    virtual bool post(EventHandler* eventHandler, int eid, void* param,
                      int needDelete = 0) = 0;
    virtual bool dispatch(EventHandler* eventHandler, int eid, void* param,
                          int needDelete = 0) = 0;
    virtual void stop(int stopCode = 0) = 0;
    virtual int handleEvent(int eid, void* pParam) = 0;

public:
    virtual bool removeTimer(EventHandler* timerHandler, int timerID) = 0;
    virtual bool removeIO(EventHandler* handler, int fd,
                          IoOps ops = IO_READ) = 0;
};

} // namespace net
} // namespace orchid
