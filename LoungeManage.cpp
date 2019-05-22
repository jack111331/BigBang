#include "LoungeManage.h"
#include "Lounge.h"
#include "User.h"
CLoungeManage * CLoungeManage::instance = new CLoungeManage;
CLoungeManage * CLoungeManage::getInstance()
{
  return instance;
}
void CLoungeManage::addUserToNewLounge(CUser * user)
{
  loungeSet[user->GetID()] = new CLounge();
  loungeSet[user->GetID()]->joinLounge(user);
  loungeSet[user->GetID()]->changeRoomOwner(user);
}
void CLoungeManage::addUserToLounge(CUser * user, uint32_t ID)
{
  if(loungeSet.find(ID) != loungeSet.end())
  {
    loungeSet[ID]->joinLounge(user);
  }
}
uint32_t CLoungeManage::searchLoungeNumber(CUser * user)
{
  for(std::map<uint32_t, CLounge *>::iterator it = loungeSet.begin();it != loungeSet.end();++it)
  {
    if(it->second->searchUserInLounge(user))
    {
      return it->first;
    }
  }
  return 0xFFFFFFFF;
}
CLounge * CLoungeManage::searchLounge(CUser * user)
{
  for(std::map<uint32_t, CLounge *>::iterator it = loungeSet.begin();it != loungeSet.end();++it)
  {
    if(it->second->searchUserInLounge(user))
    {
      return it->second;
    }
  }
  return nullptr;
}
void CLoungeManage::removeUserFromLounge(CUser * user)
{
  uint32_t searchResult = searchLoungeNumber(user);
  if(searchResult == 0xFFFFFFFF)
  {
    return;
  }
  if(user->GetID() != searchResult)
  {
    //this user is not the room owner
    loungeSet[searchResult]->exitLounge(user);
  }
  else
  {
    CLounge * RemoveTemp = loungeSet[searchResult];
    loungeSet[searchResult]->exitLounge(user);
    loungeSet.erase(searchResult);
    if(RemoveTemp->getLoungeSize() >= 1)
    {
      loungeSet[RemoveTemp->getFirstUser()->GetID()] = RemoveTemp;
      loungeSet[RemoveTemp->getFirstUser()->GetID()]->changeRoomOwner(RemoveTemp->getFirstUser());
    }
  }
}
const std::map<uint32_t, CLounge *> & CLoungeManage::GetLoungeSet()
{
  return loungeSet;
}
CLoungeManage::~CLoungeManage()
{
  for(std::map<uint32_t, CLounge *>::iterator it = loungeSet.begin();it != loungeSet.end();++it)
  {
    delete it->second;
    loungeSet.erase(it);
  }
  delete instance;
}
