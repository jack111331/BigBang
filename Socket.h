#ifndef SOCKET_H
  #define SOCKET_H
  #include <sys/socket.h>
  #include <netinet/in.h>

  class Socket
  {
  public:
    void InitServerAddress(int port);
    bool CreateSocket();
    bool BindSocket();
    int GetSocketFD() const;
    void SetSocketFD(int SocketFD);
    ~Socket();
  private:
    //AF = Address Family
    static constexpr int IPV4 = AF_INET;
    static constexpr int TCP = SOCK_STREAM;
    int SocketFD;
    sockaddr_in ServerAddress;
  };

#endif
