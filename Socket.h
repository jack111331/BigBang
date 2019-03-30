#pragma once

#include <sys/socket.h>
#include <netinet/in.h>

class CSocket
{
public:
  virtual bool InitSocket(int SocketFD, int port) = 0;
  void InitServerAddress(int port);
  bool CreateSocket();
  bool BindSocket();
  int GetSocketFD() const;
  void SetSocketFD(int SocketFD);
  int GetSocketID() const;
  void SetSocketID(int ID);
  virtual ~CSocket();
protected:
  static int CurrentID;
private:
  //AF = Address Family
  static constexpr int IPV4 = AF_INET;
  static constexpr int TCP = SOCK_STREAM;
  sockaddr_in ServerAddress;
  int SocketFD;
  int ID;
};
