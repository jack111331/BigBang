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
  int LoungeCount = 0;
  Buffer["Lounge Amount"] = static_cast<int>(LoungeSet.size());
  for(std::map<uint32_t, CLounge *>::iterator it = LoungeSet.begin();it != LoungeSet.end();++it)
  {
    json Lounge;
    Lounge["ID"] = it->first;
    Lounge["User Amount"] = it->second->getLoungeSize();
    Buffer[std::string("Lounge ") + std::to_string(LoungeCount)] = Lounge;
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
  Buffer["Character Name"] = player->GetCharacter()->GetName();
  Buffer["Death"] = player->isDead();
  Buffer["Holding Card Amount"] = player->GetHoldingAmount();
  std::vector<CCard *> holding = player->GetHolding();
  json HoldingBuffer;
  for(int i = 0;i < static_cast<int>(holding.size());++i)
  {
    HoldingBuffer["Holding Card " + std::to_string(i)] = holding[i]->GetID();
  }
  Buffer["Holding"] = HoldingBuffer;
  const CCard * Equipment = player->GetEquipment();
  Buffer["Equipment"] = Equipment?Equipment->GetID():NoneMagicNumber;

  std::vector<CPlayer *> playerList = room->GetPlayerList();
  for(int i = 0;i < static_cast<int>(playerList.size());++i)
  {
    json PlayerBuffer;
    PlayerBuffer["Max HP"] = playerList[i]->GetMaxHP();
    PlayerBuffer["HP"] = playerList[i]->GetHP();
    PlayerBuffer["Character Name"] = playerList[i]->GetCharacter()->GetName();
    PlayerBuffer["Holding Card Amount"] = playerList[i]->GetHoldingAmount();
    PlayerBuffer["Death"] = playerList[i]->isDead();
    const CCard * OtherEquipment = playerList[i]->GetEquipment();
    PlayerBuffer["Equipment"] = OtherEquipment?OtherEquipment->GetID():NoneMagicNumber;

    Buffer["Player " + std::to_string(i)] = PlayerBuffer;
  }

  return Buffer;
}
json NSWrapInfo::WrapShowCard(CPlayer * shower, CPlayer * showee)
{
  json Buffer;
  Buffer["Action"] = 10;
  Buffer["Shower Position"] = shower->GetPosition();
  Buffer["Showee Position"] = showee->GetPosition();
  return Buffer;
}
json NSWrapInfo::WrapChooseCard(CPlayer * chooser, CPlayer * choosee, bool ChooseOrDiscard)
{
  json Buffer;
  Buffer["Action"] = 11;
  Buffer["Chooser Position"] = chooser->GetPosition();
  Buffer["Choosee Position"] = choosee->GetPosition();
  Buffer["Choose or Discard"] = ChooseOrDiscard;
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
  Buffer["Friend Amount"] = FriendList.size();
  json FriendBuffer;
  for(int i = 0;i < static_cast<int>(FriendList.size());i++)
  {
    FriendBuffer["Friend " + std::to_string(i)] = FriendList[i];
  }
  Buffer["Friend"] = FriendBuffer;
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
