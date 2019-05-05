#pragma once
#include "ListenSocket.h"
#include "HandleClientSocket.h"
#include "MessageMediatorColleague.h"
#include "User.h"
#include <thread>

class CCommunicateFacade : public CColleague
{
  public:
    CCommunicateFacade(CMessageMediator * mediator);
    void createListenSocket(int port);
    //send 改設計成user自己會透過mediator send
    ~CCommunicateFacade();
  private:
    CListenSocket * ListenSocket;
    static void ListenThreadFunc(int ListenSocketFD, CCommunicateFacade * myself);
    std::thread ListenThread;
};
