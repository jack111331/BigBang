#include "LoungeManage.h"
#include "Lounge.h"
#include "User.h"

CLoungeManage::CLoungeManage()
{
  loungeSet.clear();
}
void CLoungeManage::addUserToNewLounge(CUser * user)
{
  loungeSet[user->GetID()] = new CLounge();
  loungeSet[user->GetID()]->joinLounge(user);
}
void CLoungeManage::addUserToLounge(CUser * user, uint32_t ID)
{
  if(loungeSet.find(ID) != loungeSet.end())
  {
    loungeSet[ID]->joinLounge(user);
  }
}
uint32_t CLoungeManage::searchLounge(CUser * user)
{
  for(std::map<uint32_t, CLounge *>::iterator it = loungeSet.begin();it != loungeSet.end();++it)
  {
    if(it->second->searchUserInLounge(user))
    {
      return it->first;
    }
  }
  return 0;//may cause bug?
}
void CLoungeManage::removeUserFromLounge(CUser * user)
{
  uint32_t searchResult = searchLounge(user);
  if(user->GetID() != searchResult)
  {
    loungeSet[searchResult]->exitLounge(user);
  }
  else
  {
    CLounge * RemoveTemp = loungeSet[searchResult];
    loungeSet[searchResult]->exitLounge(user);
    loungeSet.erase(searchResult);
    if(RemoveTemp->loungeSize() >= 1)
    {
      loungeSet[RemoveTemp->getFirstUserID()] = RemoveTemp;
    }
  }
}
CLoungeManage::~CLoungeManage()
{
  for(std::map<uint32_t, CLounge *>::iterator it = loungeSet.begin();it != loungeSet.end();++it)
  {
    delete it->second;
    loungeSet.erase(it);
  }
}
