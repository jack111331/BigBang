#include "MessageMediator.h"
#include "User.h"
#include "LoungeManage.h"
#include "HandleClientSocket.h"
timeval CMessageMediator::timeout = {0, 5};

CMessageMediator::CMessageMediator(CLoungeManage * LoungeManager)
{
  this->LoungeManager = LoungeManager;
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
      //I don't sure if this is legal(?), but typically I think this is the best sol i can come up with:D
      //已確定這是權宜之計  之後會修
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
      static_cast<CUser *>(colleague)->ReceiveMessageAndUpdate(message);
      break;
    }
    case 5:
    {
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
