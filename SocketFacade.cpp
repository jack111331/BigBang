#include "SocketFacade.h"
#include <string>
#include <thread>
std::map<int, CHandleClientSocket *> CSocketFacade::SocketSet;
timeval CSocketFacade::timeout = {0, 5};
CSocketFacade::CSocketFacade(int port)
{
  timeout = {0, 5};
  createListenSocket(port);
}
void CSocketFacade::createListenSocket(int port)
{
  this->ListenSocket = new CListenSocket();
  this->ListenSocket->InitSocket(0, port);
  ListenThread = std::thread(ListenThreadFunc, ListenSocket->GetSocketFD());
  ProcessThread = std::thread(SocketProcessFunc);
}
const std::string CSocketFacade::receive(int ID)
{
  if(SocketSet.find(ID) != SocketSet.end())
  {
    return SocketSet[ID]->receiveMessage();
  }
  return std::string("");
}
bool CSocketFacade::send(int ID, const std::string & message)
{
  if(SocketSet.find(ID) != SocketSet.end())
  {
    return SocketSet[ID]->sendMessage(message);
  }
  return false;
}
void CSocketFacade::ListenThreadFunc(int ListenSocketFD)
{
  while(1)
  {
    CHandleClientSocket * HCS = new CHandleClientSocket;
    HCS->InitSocket(ListenSocketFD, 0);
    SocketSet.insert(std::pair<int, CHandleClientSocket *>(HCS->GetSocketID(), HCS));
  }
}
void CSocketFacade::SocketProcessFunc()
{
  fd_set ReadFDSet;
  while(1)
  {
    FD_ZERO(&ReadFDSet);
    for(std::map<int, CHandleClientSocket *>::iterator i = SocketSet.begin();i != SocketSet.end();++i)
    {
      FD_SET(i->second->GetSocketFD(), &ReadFDSet);
    }
    if(select((--SocketSet.end())->second->GetSocketFD() + 1, &ReadFDSet, NULL, NULL, &timeout) < 0)
    {
      //select fail message
      break;
    }
    for(std::map<int, CHandleClientSocket *>::iterator i = SocketSet.begin();i != SocketSet.end();++i)
    {
      if(FD_ISSET(i->second->GetSocketFD(), &ReadFDSet))
      {
        const std::string & ReceivedData = i->second->receiveMessage();
        if(ReceivedData != "")
        {
          //receive
        }
        else
        {
          //receive failed, socket disconnect
          delete i->second;
          SocketSet.erase(i);
          --i;
        }
      }
    }
  }
}

CSocketFacade::~CSocketFacade()
{
  delete this->ListenSocket;
  // ListenThread destruct
}
