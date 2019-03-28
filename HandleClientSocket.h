#ifndef HANDLECLIENTSOCKET_H
  #define HANDLECLIENTSOCKET_H

  #include "Socket.h"
  #include "SocketIO.h"

  class HandleClientSocket : public Socket, public ISocketIO
  {
  public:
    bool InitSocket(int SocketFD, int port);
    bool AcceptConnect(int ServerSocketFD);
    bool Receive();
    const char * GetReceiveBuffer() const;
    bool Send(const char * Buffer);
    ~HandleClientSocket();
  private:
    sockaddr_in ClientAddress;
    static constexpr int BufferSize = 4096;
    char ReceiveBuffer[BufferSize];
  };
#endif
