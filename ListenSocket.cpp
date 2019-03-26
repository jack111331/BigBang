#include "ListenSocket.h"

bool ListenSocket::StartListening()
{
  //Listening to possible client connect
  //true if success, otherwise failed
  return listen(GetSocketFD(), MaxListenAmount) != -1;
}
ListenSocket::~ListenSocket()
{
  shutdown(GetSocketFD(), SHUT_RDWR);
}
