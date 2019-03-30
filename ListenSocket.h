#pragma once

#include "Socket.h"

class CListenSocket : public CSocket
{
public:
  bool InitSocket(int SocketFD, int port);
  bool StartListening();
  ~CListenSocket();
private:
  static constexpr int MaxListenAmount = 14;
};
