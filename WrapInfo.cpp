#include "WrapInfo.h"
#include "LoungeManage.h"

using json = nlohmann::json;

json NSWrapInfo::WrapUserInfo(CUser * user)
{
  json Buffer;
  Buffer["Action"] = 1;
  Buffer["Nick Name"] = user->GetName();
  Buffer["User Money"] = user->GetMoney();
  Buffer["User Win"] = user->GetWin();
  Buffer["User Lose"] = user->GetLose();
  return Buffer;
}
json NSWrapInfo::WrapLoungeSetInfo()
{
  json Buffer;
  Buffer["Action"] = 2;
  std::map<uint32_t, CLounge *> LoungeSet = CLoungeManage::getInstance()->GetLoungeSet();
  int LoungeCount = 1;
  for(std::map<uint32_t, CLounge *>::iterator it = LoungeSet.begin();it != LoungeSet.end();++it)
  {
    json Lounge;
    Lounge["ID"] = it->first;
    Lounge["User Amount"] = it->second->getLoungeSize();
    Buffer[std::string("Lounge_")+std::to_string(LoungeCount)] = Lounge;
    LoungeCount++;
  }
  return Buffer;
}
json NSWrapInfo::WrapConfirm(int action)
{
  json Buffer;
  Buffer["Action"] = action;
  return Buffer;
}
json NSWrapInfo::WrapStartGameFail()
{
  json Buffer;
  Buffer["Action"] = 5;
  Buffer["Start"] = 0;
  return Buffer;
}
json NSWrapInfo::WrapChooseCharacter(std::string CharacterName_1, std::string CharacterName_2)
{
  json Buffer;
  Buffer["Action"] = 6;
  Buffer["Character Name 1"] = CharacterName_1;
  Buffer["Character Name 2"] = CharacterName_2;
  return Buffer;
}
json NSWrapInfo::WrapPublicGameInfo(CRoom * room, CPlayer * player)
{
  //editing
  json Buffer;
  Buffer["Action"] = 7;
  Buffer["Holding Card Amount"] = player->GetHoldingAmount();
  std::vector<CCard *> holding = player->GetHolding();
  for(int i = 0;i < static_cast<int>(holding.size());++i)
  {
    Buffer["Holding Card " + std::to_string(i)] = 1;
  }
  std::vector<CCard *> equiping = player->GetEquipment();

  for(int i = 0;i < static_cast<int>(equiping.size());++i)
  {
  }
  return Buffer;
}
json NSWrapInfo::WrapFoldAmount(int amount)
{
  json Buffer;
  Buffer["Action"] = 14;
  Buffer["Should Fold Card Amount"] = amount;
  return Buffer;
}
json NSWrapInfo::WrapEndGame(CRoom * room)
{

}
