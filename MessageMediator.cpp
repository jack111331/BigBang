#include "MessageMediator.h"
#include "User.h"
#include "LoungeManage.h"
#include "HandleClientSocket.h"
#include "ClientEventObserver.h"
#include <unistd.h>
timeval CMessageMediator::timeout = {0, 5};

CMessageMediator::CMessageMediator()
{
}
CMessageMediator::~CMessageMediator()
{
  for(std::map<CUser *, CHandleClientSocket *>::iterator it = SocketSet.begin();it != SocketSet.end();++it)
  {
    delete it->second;
    SocketSet.erase(it);
  }
}
CConcreteMessageMediator::CConcreteMessageMediator()
{
}
void CConcreteMessageMediator::HandleObjectMessage(std::string action, CColleague * colleague, std::string message)
{
  int actionNumber = 0;
  if(action == "Create Client")
  {
    actionNumber = 1;
  }
  else if(action == "Processing Socket")
  {
    actionNumber = 2;
  }
  else if(action == "Remove User")
  {
    actionNumber = 3;
  }
  else if(action == "Receive Message")
  {
    actionNumber = 4;
  }
  else if(action == "Send Message")
  {
    actionNumber = 5;
  }
  else if(action == "Handled Data")
  {
    actionNumber = 6;
  }
  else if(action == "Handled Data Result")
  {
    actionNumber = 7;
  }
  switch(actionNumber)
  {
    case 1:
    {
      CUser * newUser = new CUser(this);
      //原本想把SocketSet包成一個類別 但發現這樣要創建一個Entry太麻煩了..
      SocketSet.insert(std::pair<CUser *, CHandleClientSocket *>(newUser, static_cast<CHandleClientSocket *>(colleague)));
      break;
    }
    case 2:
    {
      ProcessThread = std::thread(SocketProcessFunc, this);
      ProcessThread.detach();
      break;
    }
    case 3:
    {
      CClientEventObserver::CallDisconnect(static_cast<CUser *>(colleague));
      CLoungeManage::getInstance()->removeUserFromLounge(static_cast<CUser *>(colleague));
      break;
    }
    case 4:
    {
      //讓user自己處理receive到的資訊
      colleague->ReceiveMessage(message);
      break;
    }
    case 5:
    {
      //所以SocketSet還是由這個class來管理好了ww
      printf("Send To: %u\n", static_cast<CUser *>(colleague)->GetID());
      SocketSet[static_cast<CUser *>(colleague)]->sendMessage(message);
      break;
    }
    case 6:
    {
      SocketSet[static_cast<CUser *>(colleague)]->SetHandledAction(std::stoi(message));
      colleague->SetHandledAction(std::stoi(message));
      break;
    }
    case 7:
    {
      SocketSet[static_cast<CUser *>(colleague)]->SetActionResult(std::stoi(message));
      colleague->SetActionResult(std::stoi(message));
      break;
    }
    default:
    {

    }
  }
}
std::map<CUser *, CHandleClientSocket *> & CConcreteMessageMediator::GetSocketSet()
{
  return SocketSet;
}
void CConcreteMessageMediator::SocketProcessFunc(CConcreteMessageMediator * myself)
{
  fd_set ReadFDSet;
  while(1)
  {
    if(myself->GetSocketSet().empty())
    {
      sleep(1);
      continue;
    }
    FD_ZERO(&ReadFDSet);
    for(std::map<CUser *, CHandleClientSocket *>::iterator i = myself->GetSocketSet().begin();i != myself->GetSocketSet().end();++i)
    {
      FD_SET(i->second->GetSocketFD(), &ReadFDSet);
    }
    if(select((--myself->GetSocketSet().end())->second->GetSocketFD() + 1, &ReadFDSet, NULL, NULL, &timeout) < 0)
    {
      //select() fail
      break;
    }
    for(std::map<CUser *, CHandleClientSocket *>::iterator i = myself->GetSocketSet().begin();i != myself->GetSocketSet().end();)
    {
      if(FD_ISSET(i->second->GetSocketFD(), &ReadFDSet))
      {
        const char * ReceivedData = i->second->receiveMessage();
        if(ReceivedData)
        {
          if(ReceivedData[0] != '\0')
          {
            //receive
            i->first->SendMessage("Receive Message", std::string(ReceivedData));
          }
          else
          {
            //receive failed, socket disconnect
            i->first->SendMessage("Remove User", "");
            delete i->first;//release this user's memory allocation
            delete i->second;//release this user's client socket memory allocation
            i = myself->GetSocketSet().erase(i);
            continue;
          }
        }
      }
      ++i;
    }
  }
}
