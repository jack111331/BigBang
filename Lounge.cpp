#include "Lounge.h"
#include "User.h"
CLounge::CLounge()
{
  userList.clear();
  isReady.reset();
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
void CLounge::setReady(CUser * user)
{

}
void CLounge::setUnready(CUser * user)
{

}
void CLounge::exitLounge(CUser * user)
{

}
