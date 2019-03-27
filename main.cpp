#include <iostream>
#include <vector>
#include <map>
#include "Socket.h"
#include "ListenSocket.h"
#include "HandleClientSocket.h"
#include "SocketIO.h"
#include <sys/types.h>
#include <errno.h>

static constexpr int port = 27743;
static timeval timeout = {0, 5};//second, usecond

int main()
{
  std::vector<Socket *> SocketSet;
  SocketSet.push_back(new ListenSocket);
  //Setup Listen Server
  SocketSet[0]->InitSocket(0, port);

  std::map<int, ISocketIO *> SocketIOSet;
  //TODO: create thread for listen socket to accept
  fd_set ReadFDSet;
  fd_set WriteFDSet;
  while(1)
  {
    FD_ZERO(&ReadFDSet);
    FD_ZERO(&WriteFDSet);
    //SocketSet[0] is a listen socket
    for(uint32_t i = 1;i < SocketSet.size();i++)
    {
      FD_SET(SocketSet[i]->GetSocketFD(), &ReadFDSet);
      FD_SET(SocketSet[i]->GetSocketFD(), &WriteFDSet);
    }
    if(select(SocketSet[SocketSet.size()-1]->GetSocketFD() + 1, &ReadFDSet, &WriteFDSet, NULL, &timeout) < 0)
		{
      std::cout << __FILE__ << ": select() failed" << std::endl;
			break;
		}
    for(uint32_t i = 1;i < SocketSet.size();i++)
    {
      if(FD_ISSET(SocketSet[i]->GetSocketFD(), &ReadFDSet))
      {
        int ClientSocketID = SocketSet[i]->GetSocketID();
        if(SocketIOSet[ClientSocketID]->Receive())
        {
          std::cout << __FILE__ << " Receive from client " << SocketSet[i]->GetSocketFD() << ": " << SocketIOSet[ClientSocketID]->GetReceiveBuffer() << std::endl;
        }
        else
        {
          std::cout << __FILE__ << " Receive failed, client " << SocketSet[i]->GetSocketFD() << " closed" << std::endl;
          delete SocketSet[i];
          SocketIOSet.erase(ClientSocketID);
          SocketSet.erase(SocketSet.begin()+i);
          i--;
        }
      }
    }
  }
}
