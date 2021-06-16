#pragma once

#include "orchid/common/logger.h"

namespace orchid
{
namespace net
{

////////////////////////////////////////////////////////////////
/// 这里是统一定义的socket操作宏，用于统一windows和linux的平台操作
////////////////////////////////////////////////////////////////
#ifdef __linux__
#define closesocket close
#endif

#ifdef __linux__
#define ioctlsocket ioctl
#endif

//在Windows下，所有的socket的错误号全部以WSA开始，我们将需要的那些统一成linux的标准
#ifdef WIN32
#define EWOULDBLOCK WSAEWOULDBLOCK
#else
#define EWOULDBLOCK EAGAIN
#endif

#ifdef WIN32
#define GET_LAST_SOCK_ERROR() h_errno
#else
#define GET_LAST_SOCK_ERROR() errno
#endif

//在传送sockaddr时，使用的表示长度的类型不同
#if defined(LINUX)
#define SOCKADDRLEN socklen_t
#else
#define SOCKADDRLEN int
#endif

class SocketInit
{
public:
    SocketInit();
    virtual ~SocketInit();
};

} // namespace net
} // namespace orchid
