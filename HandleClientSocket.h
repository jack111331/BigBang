#pragma once

#include "Socket.h"
#include <string>
#include <queue>
class CHandleClientSocket : public CSocket
{
public:
  bool InitSocket(int SocketFD, int port);
  bool AcceptConnect(int ServerSocketFD);
  const std::string & receiveMessage();
  bool sendMessage(const std::string & Buffer);
  ~CHandleClientSocket();
private:
  int BufferSize = 4096;
  sockaddr_in ClientAddress;
  std::string ReceiveBuffer;
  std::queue<std::string> sendBufferQueue;
};
