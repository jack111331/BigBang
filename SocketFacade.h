#pragma once
#include "ListenSocket.h"
#include "HandleClientSocket.h"
#include "LoungeManage.h"
#include "User.h"
#include <sys/types.h>
#include <string>
#include <map>
#include <thread>

class CSocketFacade
{
  public:
    CSocketFacade(int port, CLoungeManage * loungeManager);
    void createListenSocket(int port);
    const std::string receive(CUser *);
    bool send(CUser *, const std::string & message);
    ~CSocketFacade();
  private:
    CListenSocket * ListenSocket;
    static CLoungeManage * LoungeManager;
    static void ListenThreadFunc(int ListenSocketFD);
    static void SocketProcessFunc();
    static std::map<CUser *, CHandleClientSocket *> SocketSet;
    static timeval timeout;//second, usecond
    std::thread ListenThread;
    std::thread ProcessThread;
};
