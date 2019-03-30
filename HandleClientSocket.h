#pragma once

#include "Socket.h"
#include "SocketIO.h"

class CHandleClientSocket : public CSocket, public ISocketIO
{
public:
  bool InitSocket(int SocketFD, int port);
  bool AcceptConnect(int ServerSocketFD);
  const char * Receive();
  bool Send(const char * Buffer);
  ~CHandleClientSocket();
private:
  sockaddr_in ClientAddress;
  static constexpr int BufferSize = 4096;
  char ReceiveBuffer[BufferSize];
};
