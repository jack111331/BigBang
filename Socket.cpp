#include "Socket.h"
#include <string.h>
#include <stdint.h>
#include <stdio.h>

int CSocket::CurrentID = 0;
CSocket::CSocket()
{

}
void CSocket::InitServerAddress(int port)
{
  memset(&ServerAddress, 0, sizeof(ServerAddress));

  //PF = Protocol Family
  ServerAddress.sin_family = PF_INET;
  //Kernel decided address
  ServerAddress.sin_addr.s_addr = INADDR_ANY;
  //Unified endian
  ServerAddress.sin_port = htons(port);
}
bool CSocket::CreateSocket()
{
  SocketFD = socket(IPV4, TCP, 0);
  if(SocketFD == -1)
  {
    return false;
  }
  return true;
}
bool CSocket::BindSocket()
{
  //bind socket address and port
  //true if success, otherwise failed
  setsockopt(SocketFD, SOL_SOCKET, SO_REUSEADDR, &ServerAddress, sizeof(ServerAddress));
  return bind(SocketFD, (sockaddr *)&ServerAddress, sizeof(ServerAddress)) != -1;
}
int CSocket::GetSocketFD() const
{
  return SocketFD;
}
void CSocket::SetSocketFD(int SocketFD)
{
  this->SocketFD = SocketFD;
}
int CSocket::GetSocketID() const
{
  return this->ID;
}
void CSocket::SetSocketID(int ID)
{
  this->ID = ID;
}
CSocket::~CSocket()
{
  shutdown(SocketFD, SHUT_RDWR);
}
