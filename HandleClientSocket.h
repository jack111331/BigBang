#pragma once

#include "Socket.h"
#include <string>
#include <queue>
class CHandleClientSocket : public CSocket
{
public:
  bool InitSocket(int SocketFD, int port);
  bool AcceptConnect(int ServerSocketFD);
  const char * receiveMessage();
  bool sendMessage(const std::string & Buffer);
  ~CHandleClientSocket();
private:
  static constexpr int BufferSize = 4096;
  sockaddr_in ClientAddress;
  char ReceiveBuffer[BufferSize];
};
