#include "ListenSocket.h"
#include <stdio.h>
CListenSocket::CListenSocket()
{
}
bool CListenSocket::InitSocket(int SocketFD, int port)
{
  InitServerAddress(port);
  SetSocketID(CurrentID++);
  if(!CreateSocket())
  {
    perror(NULL);
    return 0;
  }
  if(!BindSocket())
  {
    perror(NULL);
    return 0;
  }
  if(!StartListening())
  {
    perror(NULL);
    return 0;
  }
  return 1;
}
bool CListenSocket::StartListening()
{
  //Listening to possible client connect
  //true if success, otherwise failed
  return listen(GetSocketFD(), MaxListenAmount) != -1;
}
CListenSocket::~CListenSocket()
{
  shutdown(GetSocketFD(), SHUT_RDWR);
}
