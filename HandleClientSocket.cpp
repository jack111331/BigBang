#include "HandleClientSocket.h"
#include <string>
#include <string.h>
#include <iostream>
CHandleClientSocket::CHandleClientSocket(CMessageMediator * mediator) : CSocket(), CColleague(mediator)
{

}
bool CHandleClientSocket::InitSocket(int SocketFD, int port)
{
  if(!AcceptConnect(SocketFD))
  {
    return false;
  }
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
  int ReceiveLength;
  if((ReceiveLength = recv(GetSocketFD(), ReceiveBuffer, BufferSize-1, 0)) <= 0)
  {
    ReceiveBuffer[0] = '\0';
  }
  /*somehow it receive byte string without '\0'*/
  ReceiveBuffer[ReceiveLength] = '\0';
  return ReceiveBuffer;
}
bool CHandleClientSocket::sendMessage(const std::string & Buffer)
{
  // true if successfully send data, otherwise failed
  std::cout << "Send: " << std::endl << Buffer << std::endl;
  return send(GetSocketFD(), Buffer.c_str(), Buffer.size()+1, 0) != -1;
}

CHandleClientSocket::~CHandleClientSocket()
{
  shutdown(GetSocketFD(), SHUT_RDWR);
}
