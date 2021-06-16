#pragma once

#include "ort_ext/message/OrtPackage.h"
#include "ort_ext/message/ORTypeDefs.h"
#include "orchid/network/Reactor.h"

namespace orchid
{
namespace net
{

class ClientService
{
public:
    virtual void onResponse(const CPackagePtr& package) = 0;
    virtual void onSessionConnected(TSessionID sessionID) = 0;
    virtual void onSessionDisconnected(TSessionID sessionID, int reason) = 0;
    virtual void close() = 0;
};

class CReactorImpl;
class ClientApi
{
public:
    ///�����ӿ�
    static ClientApi* createClientApi(const PackagePoolPtr& packagePool,
                                      CReactor* pReactor, int clientID);
    ///ɾ���ӿ�
    virtual void release() = 0;
    virtual ~ClientApi(){};
    virtual int getClientID() = 0;

    ///ע������� tcp://xxxxxxxxxxx:xxxx
    virtual void registerServer(const char* pszAddress) = 0;
    virtual void registerService(ClientService* pService) = 0;
    virtual void start() = 0;

    /* !!!depricate ����ʹ��ͬ������!!! */
    // virtual int request(CPackage *package) = 0;
    // virtual int request(char *address, int length) = 0;

    /// return package length.
    virtual int requestLater(const CPackagePtr& package) = 0;
};

} // namespace net
} // namespace orchid
