#include "Lounge.h"
#include "Room.h"
#include "WrapInfo.h"
CLounge::CLounge()
{
  userList.clear();
  readyMap.clear();
}
void CLounge::joinLounge(CUser * user)
{
  userList.push_back(user);
}
int CLounge::getLoungeSize()
{
  return userList.size();
}
CUser * CLounge::getFirstUser()
{
  return userList[0];
}
std::vector<CUser *> & CLounge::GetAllUser()
{
  return userList;
}
bool CLounge::searchUserInLounge(CUser * user)
{
  for(int i = 0;i < static_cast<int>(userList.size());++i)
  {
    if(userList[i]->GetID() == user->GetID())
    {
      return true;
    }
  }
  return false;
}
void CLounge::changeRoomOwner(CUser * user)
{
  this->RoomOwner = user;
}
CUser * CLounge::getRoomOwner()
{
  return this->RoomOwner;
}
bool CLounge::isAllReady()
{
  for(std::map<CUser *, bool>::iterator it = readyMap.begin();it != readyMap.end();++it)
  {
    if(!it->second)
    {
      return false;
    }
  }
  return true;
}
void CLounge::setReadyState(CUser * user, bool state)
{
  readyMap[user] = state;
}
void CLounge::exitLounge(CUser * user)
{
  for(std::vector<CUser *>::iterator it = userList.begin();it != userList.end();++it)
  {
    if(*it == user)
    {
      userList.erase(it);
      break;
    }
  }
  readyMap.erase(user);
}
CRoom * CLounge::getRoom()
{
  return this->room;
}
bool CLounge::startGame()
{
  if(!isAllReady() || userList.size() < 4 || userList.size() > 7)
  {
    RoomOwner->SendMessage("Send Message", NSWrapInfo::WrapStartGame(nullptr, 0));
    return false;
  }
  //Start game
  room = new CRoom();
  for(std::vector<CUser *>::iterator it = userList.begin();it != userList.end();++it)
  {
    room->PlayerJoin(*it);
  }
  //game loop
  GameLoopThread = std::thread(CRoom::GameLoop, room);
  return true;
}
