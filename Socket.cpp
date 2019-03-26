#include "Socket.h"
#include <string.h>
#include <stdint.h>

void Socket::InitServerAddress(int port)
{
  memset(&ServerAddress, 0, sizeof(ServerAddress));

  //PF = Protocol Family
  ServerAddress.sin_family = PF_INET;
  //Kernel decided address
  ServerAddress.sin_addr.s_addr = INADDR_ANY;
  //Unified endian
  ServerAddress.sin_port = htons(port);
}
bool Socket::CreateSocket()
{
  SocketFD = socket(IPV4, TCP, 0);
  if(SocketFD == -1)
  {
    return false;
  }
  return true;
}
bool Socket::BindSocket()
{
  //bind socket address and port
  //true if success, otherwise failed
  return bind(SocketFD, (sockaddr *)&ServerAddress, sizeof(ServerAddress)) != -1;
}
int Socket::GetSocketFD() const
{
  return SocketFD;
}
void Socket::SetSocketFD(int SocketFD)
{
  this->SocketFD = SocketFD;
}
Socket::~Socket()
{
  shutdown(SocketFD, SHUT_RDWR);
}
