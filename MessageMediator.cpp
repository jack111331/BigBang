#include "MessageMediator.h"
#include "User.h"
#include "LoungeManage.h"
#include "HandleClientSocket.h"
timeval CMessageMediator::timeout = {0, 5};

CMessageMediator::CMessageMediator(CLoungeManage * LoungeManager)
{
  this->LoungeManager = LoungeManager;
}
CConcreteMessageMediator::CConcreteMessageMediator(CLoungeManage * LoungeManager) : CMessageMediator(LoungeManager)
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
  switch(actionNumber)
  {
    case 1:
    {
      CUser * newUser = new CUser(this);
      //原本想把SocketSet包成一個類別 但發現這樣要創建一個Entry太麻煩了..
      SocketSet.insert(std::pair<CUser *, CHandleClientSocket *>(newUser, static_cast<CHandleClientSocket *>(colleague)));
      LoungeManager->addUserToNewLounge(newUser);
      break;
    }
    case 2:
    {
      ProcessThread = std::thread(SocketProcessFunc, this);
      break;
    }
    case 3:
    {
      LoungeManager->removeUserFromLounge(static_cast<CUser *>(colleague));
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
      SocketSet[static_cast<CUser *>(colleague)]->sendMessage(message);
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
    for(std::map<CUser *, CHandleClientSocket *>::iterator i = myself->GetSocketSet().begin();i != myself->GetSocketSet().end();++i)
    {
      if(FD_ISSET(i->second->GetSocketFD(), &ReadFDSet))
      {
        const char * ReceivedData = i->second->receiveMessage();
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
          myself->GetSocketSet().erase(i);
          --i;
        }
      }
    }
  }
}
