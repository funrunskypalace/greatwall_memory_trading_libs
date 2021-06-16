#pragma once

#include "orchid/common/logger.h"

namespace orchid
{
namespace net
{

////////////////////////////////////////////////////////////////
/// ������ͳһ�����socket�����꣬����ͳһwindows��linux��ƽ̨����
////////////////////////////////////////////////////////////////
#ifdef __linux__
#define closesocket close
#endif

#ifdef __linux__
#define ioctlsocket ioctl
#endif

//��Windows�£����е�socket�Ĵ����ȫ����WSA��ʼ�����ǽ���Ҫ����Щͳһ��linux�ı�׼
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

//�ڴ���sockaddrʱ��ʹ�õı�ʾ���ȵ����Ͳ�ͬ
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
