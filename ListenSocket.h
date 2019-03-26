#ifndef LISTENSOCKET_H
  #define LISTENSOCKET_H

  #include "Socket.h"

  class ListenSocket : public Socket
  {
  public:
    bool StartListening();
    ~ListenSocket();
  private:
    static constexpr int MaxListenAmount = 14;
  };
#endif
