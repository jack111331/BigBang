#include "WrapInfo.h"
#include "LoungeManage.h"
#include "Room.h"
#include "Database.h"
#include <vector>

using json = nlohmann::json;
static constexpr uint32_t NoneMagicNumber = 0xffffffff;
json NSWrapInfo::WrapUserInfo(CUser * user)
{
  json Buffer;
  Buffer["Action"] = 0;
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
  std::vector<json> LoungeJSONList;
  for(std::map<uint32_t, CLounge *>::iterator it = LoungeSet.begin();it != LoungeSet.end();++it)
  {
    json Lounge;
    Lounge["ID"] = it->first;
    Lounge["User Amount"] = it->second->getLoungeSize();
    LoungeJSONList.push_back(Lounge);
  }
  Buffer["Lounge"] = LoungeJSONList;
  return Buffer;
}
json NSWrapInfo::WrapConfirm(int action)
{
  json Buffer;
  Buffer["Action"] = action;
  return Buffer;
}
json NSWrapInfo::WrapStartGame(CRoom * room, int success)
{
  json Buffer;
  Buffer["Action"] = 5;
  Buffer["Start"] = success;
  if(success)
  {
    std::vector<CPlayer *> playerList = room->GetPlayerList();
    std::vector<json> PlayerJSONList;
    std::vector<json> CardJSONList;
    for(int i = 0;i < static_cast<int>(playerList.size());++i)
    {
      json PlayerBuffer;
      PlayerBuffer["Player Name"] = playerList[i]->GetUser()->GetName();
      PlayerBuffer["Position"] = playerList[i]->GetPosition();
      PlayerJSONList.push_back(PlayerBuffer);
    }
    Buffer["Player"] = PlayerJSONList;
    for(int i = 0;i < room->GetPlague()->GetPlagueCardAmount();i++)
    {
      json CardBuffer;
      const CCard * Entry = room->GetPlague()->GetCardEntrie(i);
      CardBuffer["Name"] = Entry->GetName();
      CardBuffer["ID"] = Entry->GetID();
      CardBuffer["Suit"] = static_cast<int>(Entry->GetSuit());
      CardBuffer["Number"] = Entry->GetNumber();
      CardJSONList.push_back(CardBuffer);
    }
    Buffer["Card"] = CardJSONList;
  }
  return Buffer;
}
json NSWrapInfo::WrapChooseCharacter(std::string CharacterName_1, std::string CharacterName_2)
{
  json Buffer;
  Buffer["Action"] = 6;
  Buffer["Character Name 0"] = CharacterName_1;
  Buffer["Character Name 1"] = CharacterName_2;
  return Buffer;
}
json NSWrapInfo::WrapPublicGameInfo(CRoom * room, CPlayer * player)
{
  json Buffer;
  Buffer["Action"] = 7;
  Buffer["Max HP"] = player->GetMaxHP();
  Buffer["HP"] = player->GetHP();
  Buffer["Team"] = static_cast<int>(player->GetIdentity());
  Buffer["Position"] = player->GetPosition();
  Buffer["Character Name"] = player->GetCharacter()->GetName();
  Buffer["Death"] = player->isDead();
  Buffer["Attack Range"] = player->GetAttackRange();
  Buffer["Add Range"] = player->GetAddRange();
  Buffer["Minus Range"] = player->GetMinusRange();
  Buffer["Multi Attack"] = player->isHasMultiAttack();
  std::vector<CCard *> holding = player->GetHolding();
  std::vector<json> HoldingJSONList;
  for(int i = 0;i < static_cast<int>(holding.size());++i)
  {
    json HoldingBuffer;
    HoldingBuffer["Card ID"] = holding[i]->GetID();
    HoldingJSONList.push_back(HoldingBuffer);
  }
  Buffer["Holding"] = HoldingJSONList;
  const CCard * Equipment = player->GetEquipment();
  Buffer["Equipment"] = Equipment?Equipment->GetID():NoneMagicNumber;

  std::vector<CPlayer *> playerList = room->GetPlayerList();
  std::vector<json> PlayerJSONList;
  for(int i = 0;i < static_cast<int>(playerList.size());++i)
  {
    json PlayerBuffer;
    PlayerBuffer["Max HP"] = playerList[i]->GetMaxHP();
    PlayerBuffer["HP"] = playerList[i]->GetHP();
    PlayerBuffer["Character Name"] = playerList[i]->GetCharacter()->GetName();
    PlayerBuffer["Holding Card Amount"] = playerList[i]->GetHoldingAmount();
    PlayerBuffer["Position"] = playerList[i]->GetPosition();
    PlayerBuffer["Death"] = playerList[i]->isDead();
    if(playerList[i]->isDead())
    {
      PlayerBuffer["Team"] = static_cast<int>(playerList[i]->GetIdentity());
    }
    PlayerBuffer["Attack Range"] = playerList[i]->GetAttackRange();
    PlayerBuffer["Add Range"] = playerList[i]->GetAddRange();
    PlayerBuffer["Minus Range"] = playerList[i]->GetMinusRange();
    PlayerBuffer["Multi Attack"] = playerList[i]->isHasMultiAttack();

    const CCard * OtherEquipment = playerList[i]->GetEquipment();
    PlayerBuffer["Equipment"] = OtherEquipment?OtherEquipment->GetID():NoneMagicNumber;
    PlayerJSONList.push_back(PlayerBuffer);
  }
  Buffer["Player"] = PlayerJSONList;

  return Buffer;
}
json NSWrapInfo::WrapShowCard(CPlayer * shower, CPlayer * showee)
{
  json Buffer;
  Buffer["Action"] = 10;
  Buffer["Shower Position"] = shower->GetPosition();
  Buffer["Showee Position"] = showee->GetPosition();
  std::vector<json> ShowCardJSONList;
  std::vector<CCard *> ShoweeHolding = showee->GetHolding();
  for(std::vector<CCard *>::iterator it = ShoweeHolding.begin();it != ShoweeHolding.end();++it)
  {
    json ShowCard;
    ShowCard["ID"] = (*it)->GetID();
    ShowCardJSONList.push_back(ShowCard);
  }
  Buffer["Card"] = ShowCardJSONList;
  return Buffer;
}
json NSWrapInfo::WrapChooseCard(CPlayer * chooser, CPlayer * choosee, bool ChooseOrDiscard)
{
  json Buffer;
  Buffer["Action"] = 11;
  Buffer["Chooser Position"] = chooser->GetPosition();
  Buffer["Choosee Position"] = choosee->GetPosition();
  Buffer["Choose or Discard"] = ChooseOrDiscard;
  std::vector<json> ChooseCardJSONList;
  std::vector<CCard *> ChooseeHolding = choosee->GetHolding();
  for(std::vector<CCard *>::iterator it = ChooseeHolding.begin();it != ChooseeHolding.end();++it)
  {
    json ChooseCard;
    ChooseCard["ID"] = (*it)->GetID();
    ChooseCardJSONList.push_back(ChooseCard);
  }
  Buffer["Card"] = ChooseCardJSONList;
  return Buffer;
}
json NSWrapInfo::WrapRevoltCard(CCard * card)
{
  json Buffer;
  Buffer["Action"] = 12;
  Buffer["Revolt Card Name"] = card->GetName();
  return Buffer;
}

json NSWrapInfo::WrapFoldAmount(int amount)
{
  json Buffer;
  Buffer["Action"] = 14;
  Buffer["Should Fold Card Amount"] = amount;
  return Buffer;
}

json NSWrapInfo::WrapEndGame(bool WinOrLose)
{
  json Buffer;
  Buffer["Action"] = 15;
  Buffer["WinOrLose"] = WinOrLose;
  return Buffer;
}
json NSWrapInfo::WrapFriendList(uint32_t ID)
{
  json Buffer;
  Buffer["Action"] = 17;
  CDatabase DB;
  std::vector<uint32_t> FriendList = DB.GetFriendList(ID);
  std::vector<json> FriendJSONList;
  for(int i = 0;i < static_cast<int>(FriendList.size());i++)
  {
    json FriendBuffer;
    FriendBuffer["Friend ID"] = FriendList[i];
    FriendJSONList.push_back(FriendBuffer);
  }
  Buffer["Friend"] = FriendJSONList;
  return Buffer;
}
json NSWrapInfo::WrapAddFriendMessage(int Result)
{
  json Buffer;
  Buffer["Action"] = 18;
  Buffer["Result"] = Result;
  return Buffer;
}
json NSWrapInfo::WrapDetermineCard(int CardID)
{
  json Buffer;
  Buffer["Action"] = 20;
  Buffer["Card ID"] = CardID;
  return Buffer;
}
json NSWrapInfo::WrapLoungeInfo(uint32_t ID)
{
  json Buffer;
  Buffer["Action"] = 22;
  CLounge * Lounge = CLoungeManage::getInstance()->searchLounge(ID);
  std::vector<json> UserIDList;
  for(std::vector<CUser *>::iterator it = Lounge->GetAllUser().begin();it != Lounge->GetAllUser().end();++it)
  {
    json UserJSON;
    UserJSON["ID"] = (*it)->GetID();
    UserJSON["Nick Name"] = (*it)->GetName();
    UserJSON["Ready"] = Lounge->getReadyState(*it);
    UserIDList.push_back(UserJSON);
  }
  Buffer["User"] = UserIDList;
  return Buffer;
}
