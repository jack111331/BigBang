#pragma once
#include "ListenSocket.h"
#include "HandleClientSocket.h"
#include <sys/types.h>
#include <string>
#include <map>
#include <thread>

class CSocketFacade
{
  public:
    CSocketFacade(int port);
    void createListenSocket(int port);
    const std::string receive(int ID);
    bool send(int ID, const std::string & message);
    ~CSocketFacade();
  private:
    CListenSocket * ListenSocket;
    static void ListenThreadFunc(int ListenSocketFD);
    static void SocketProcessFunc();
    static std::map<int, CHandleClientSocket *> SocketSet;
    static timeval timeout;//second, usecond
    std::thread ListenThread;
    std::thread ProcessThread;
};
