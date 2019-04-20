#include "HandleClientSocket.h"
#include <string>
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
  socklen_t AddressLength = sizeof(ClientAddress);
  int ClientSocketFD = accept(ListenSocketFD, (sockaddr *)&ClientAddress, &AddressLength);
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
const std::string & CHandleClientSocket::receiveMessage()
{
  // true if there is some data need to be receive, otherwise the other side's socket has closed
  if(recv(GetSocketFD(), &ReceiveBuffer[0], BufferSize, 0) <= 0)
  {
    ReceiveBuffer = std::string("");
  }
  return ReceiveBuffer;
}
bool CHandleClientSocket::sendMessage(const std::string & Buffer)
{
  // true if successfully send data, otherwise failed
  return send(GetSocketFD(), Buffer.c_str(), Buffer.size()+1, 0) != -1;
}
CHandleClientSocket::~CHandleClientSocket()
{
  shutdown(GetSocketFD(), SHUT_RDWR);
}
