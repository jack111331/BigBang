#include "HandleClientSocket.h"
#include <string.h>

bool HandleClientSocket::AcceptConnect(int ServerSocketFD)
{
  //Set up handle client socket
  socklen_t AddressLength = sizeof(ClientAddress);
  int ClientSocketFD = accept(ServerSocketFD, (sockaddr *)&ClientAddress, &AddressLength);
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
bool HandleClientSocket::Receive()
{
  // true if there is some data need to be receive, otherwise the other side's socket has closed
  return recv(GetSocketFD(), ReceiveBuffer, BufferSize, 0) > 0;
}
bool HandleClientSocket::Send(const char * Buffer)
{
  // true if successfully send data, otherwise failed
  return send(GetSocketFD(), Buffer, strlen(Buffer)+1, 0) != -1;
}
HandleClientSocket::~HandleClientSocket()
{
  shutdown(GetSocketFD(), SHUT_RDWR);
}
