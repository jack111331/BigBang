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
  return searchUserInLounge(user->GetID());
}
bool CLounge::searchUserInLounge(uint32_t ID)
{
  for(int i = 0;i < static_cast<int>(userList.size());++i)
  {
    if(userList[i]->GetID() == ID)
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
    if(!it->second && it->first != RoomOwner)
    {
      return false;
    }
  }
  return true;
}
bool CLounge::getReadyState(CUser * user)
{
  return readyMap[user];
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
CLounge::~CLounge()
{
  for(std::vector<CUser *>::iterator it = userList.begin();it != userList.end();)
  {
    delete *it;
    it = userList.erase(it);
  }
  delete room;
  GameLoopThread.detach();
}
