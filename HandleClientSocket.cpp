#include "HandleClientSocket.h"
#include <string>
#include <string.h>
#include <iostream>
#include <netinet/tcp.h>
#include <unistd.h>
CHandleClientSocket::CHandleClientSocket(CMessageMediator * mediator) : CSocket(), CColleague(mediator)
{

}
bool CHandleClientSocket::InitSocket(int SocketFD, int port)
{
  if(!AcceptConnect(SocketFD))
  {
    return false;
  }
  int flags = 1;
  if(setsockopt(SocketFD, IPPROTO_TCP, TCP_NODELAY, (void *)&flags, sizeof(flags)))
  {
    perror("ERROR: setsocketopt(), TCP_NODELAY");
  }
  if(setsockopt(SocketFD, SOL_TCP, TCP_NODELAY, (void *)&flags, sizeof(flags)))
  {
    perror("ERROR: setsocketopt(), TCP_NODELAY");
  }
  int res;
  socklen_t res_len = sizeof(res);
  getsockopt(SocketFD, IPPROTO_TCP, TCP_NODELAY, &res, &res_len);
  std::cout << "res: " << res << std::endl;
  getsockopt(SocketFD, SOL_TCP, TCP_NODELAY, &res, &res_len);
  std::cout << "res: " << res << std::endl;
  SetSocketID(CurrentID++);
  return true;
}
bool CHandleClientSocket::AcceptConnect(int ListenSocketFD)
{
  //Set up handle client socket
  memset(&ClientAddress, 0, sizeof(ClientAddress));
  socklen_t AddressLength = sizeof(ClientAddress);
  int ClientSocketFD = accept(ListenSocketFD, (sockaddr *)&ClientAddress, &AddressLength);
  perror("AcceptConnect: ");
  if(ClientSocketFD != -1)
  {
    SetSocketFD(ClientSocketFD);
    return true;
  }
  else
  {
    return false;
  }
}
const char * CHandleClientSocket::receiveMessage()
{
  // true if there is some data need to be receive, otherwise the other side's socket has closed
  int ReceiveLength, CurrentReceive = 0;
  if((ReceiveLength = recv(GetSocketFD(), ReceiveBuffer + CurrentReceive, BufferSize-1, 0)) <= 0)
  {
    ReceiveBuffer[0] = '\0';
  }
  /*somehow it receive byte string without '\0'*/
  if(ReceiveLength > 0)
  {
    CurrentReceive += ReceiveLength;
    while(ReceiveBuffer[CurrentReceive-1] != '\0')
    {
      ReceiveLength = recv(GetSocketFD(), ReceiveBuffer + CurrentReceive, BufferSize-1, 0);
      CurrentReceive += ReceiveLength;
    }
  }
  return ReceiveBuffer;
}
bool CHandleClientSocket::sendMessage(const std::string & Buffer)
{
  // true if successfully send data, otherwise failed
  std::cout << "Send: " << std::endl << Buffer << std::endl;
  usleep(1000);
  return send(GetSocketFD(), Buffer.c_str(), Buffer.size()+1, 0) != -1;
}

CHandleClientSocket::~CHandleClientSocket()
{
  shutdown(GetSocketFD(), SHUT_RDWR);
}
