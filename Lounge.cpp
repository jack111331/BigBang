#include "Lounge.h"
#include "User.h"
#include "Room.h"
CLounge::CLounge()
{
  userList.clear();
  readyMap.clear();
}
void CLounge::joinLounge(CUser * user)
{
  userList.push_back(user);
}
int CLounge::loungeSize()
{
  return userList.size();
}
CUser * CLounge::getFirstUser()
{
  return userList[0];
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
void CLounge::setReady(CUser * user)
{
  readyMap[user] = true;
}
void CLounge::setUnready(CUser * user)
{
  readyMap[user] = false;
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
bool CLounge::startGame()
{
  if(!isAllReady())
  {
    return false;
  }
  //Start game
  room = new CRoom();
  for(std::vector<CUser *>::iterator it = userList.begin();it != userList.end();++it)
  {
    room->PlayerJoin(*it);
  }
  //maybe we need a for loop for game loop
}
