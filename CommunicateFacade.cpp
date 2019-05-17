#include "CommunicateFacade.h"
#include "HandleMessage.h"
#include <string>
#include <thread>
CCommunicateFacade::CCommunicateFacade(CMessageMediator * mediator) : CColleague(mediator)
{
  static constexpr int port = 28716;
  createListenSocket(port);
  this->mediator = mediator;
}
void CCommunicateFacade::createListenSocket(int port)
{
  this->ListenSocket = new CListenSocket();
  this->ListenSocket->InitSocket(0, port);
  ListenThread = std::thread(ListenThreadFunc, ListenSocket->GetSocketFD(), this);
  this->SendMessage("Processing Socket", "");
}
void CCommunicateFacade::ListenThreadFunc(int ListenSocketFD, CCommunicateFacade * myself)
{
  while(1)
  {
    CHandleClientSocket * HCS = new CHandleClientSocket(myself->mediator);
    HCS->InitSocket(ListenSocketFD, 0);
    HCS->SendMessage("Create Client", "");
  }
}
CCommunicateFacade::~CCommunicateFacade()
{
  delete this->ListenSocket;
  // ListenThread destruct
}
