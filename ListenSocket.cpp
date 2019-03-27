#include "ListenSocket.h"
bool ListenSocket::InitSocket(int SocketFD, int port)
{
  InitServerAddress(port);
  SetSocketID(CurrentID++);
  if(!CreateSocket())
  {
//    std::cout << perror(0) << std::endl;
    return 0;
  }
  if(!BindSocket())
  {
//    std::cout << perror(0) << std::endl;
    return 0;
  }
  if(!StartListening())
  {
//    std::cout << perror(0) << std::endl;
    return 0;
  }
  return 1;
}
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
