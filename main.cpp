#include <iostream>
#include "Socket.h"
#include "ListenSocket.h"
#include "HandleClientSocket.h"
#include <errno.h>

static constexpr int port = 27743;

int main()
{
  ListenSocket listenSocket;
  listenSocket.InitServerAddress(port);
  if(!listenSocket.CreateSocket())
  {
//    std::cout << perror(0) << std::endl;
    return -1;
  }
  if(!listenSocket.BindSocket())
  {
//    std::cout << perror(0) << std::endl;
    return -1;
  }
  if(!listenSocket.StartListening())
  {
//    std::cout << perror(0) << std::endl;
    return -1;
  }
}
