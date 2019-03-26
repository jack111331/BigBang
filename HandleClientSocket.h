#ifndef HANDLECLIENTSOCKET_H
  #define HANDLECLIENTSOCKET_H

  #include "Socket.h"

  class HandleClientSocket : public Socket
  {
  public:
    bool AcceptConnect(int ServerSocketFD);
    bool Receive();
    bool Send(const char * Buffer);
    ~HandleClientSocket();
  private:
    sockaddr_in ClientAddress;
    static constexpr int BufferSize = 4096;
    char ReceiveBuffer[BufferSize];
  };
#endif
