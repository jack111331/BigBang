#pragma once

#include "Socket.h"
#include "MessageMediatorColleague.h"
#include <string>
#include <queue>

class CHandleClientSocket : public CSocket, public CColleague
{
public:
  CHandleClientSocket(CMessageMediator * mediator);
  bool InitSocket(int SocketFD, int port);
  bool AcceptConnect(int ServerSocketFD);
  const char * receiveMessage();
  bool sendMessage(const std::string & Buffer);

  ~CHandleClientSocket();
private:
  static constexpr int BufferSize = 8192;
  sockaddr_in ClientAddress;
  char ReceiveBuffer[BufferSize];
  int CurrentReceive = 0;
};
