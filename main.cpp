#include <iostream>
#include <vector>
#include <map>
#include <thread>
#include "Socket.h"
#include "ListenSocket.h"
#include "HandleClientSocket.h"
#include "SocketIO.h"
#include <sys/types.h>

static constexpr int port = 27743;
static timeval timeout = {0, 5};//second, usecond

void ListenThreadFunc(int ListenSocketFD, std::vector<CSocket *> & SocketSet, std::map<int, ISocketIO *> & SocketIOSet)
{
  while(1)
  {
    CHandleClientSocket * HCS = new CHandleClientSocket;
    HCS->InitSocket(ListenSocketFD, 0);
    SocketIOSet.insert(std::pair<int, ISocketIO *>(HCS->GetSocketID(), HCS));
    SocketSet.push_back(HCS);
    std::cout << __FILE__ << ": Got one client" << std::endl;
  }
}

int main()
{
  std::vector<CSocket *> SocketSet;
  SocketSet.push_back(new CListenSocket);
  //Setup Listen Server
  SocketSet[0]->InitSocket(0, port);

  std::map<int, ISocketIO *> SocketIOSet;
  //TODO: create thread for listen socket to accept
  std::thread ListenThread(ListenThreadFunc, SocketSet[0]->GetSocketFD(), std::ref(SocketSet), std::ref(SocketIOSet));
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
        const char * ReceivedData = SocketIOSet[ClientSocketID]->Receive();
        if(ReceivedData != nullptr)
        {
          std::cout << __FILE__ << " Receive from client " << SocketSet[i]->GetSocketFD() << ": " << ReceivedData << std::endl;
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
