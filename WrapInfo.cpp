#include "WrapInfo.h"
#include "LoungeManage.h"
#include "Room.h"

using json = nlohmann::json;
static constexpr uint32_t NoneMagicNumber = 0xffffffff;
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
  int LoungeCount = 0;
  for(std::map<uint32_t, CLounge *>::iterator it = LoungeSet.begin();it != LoungeSet.end();++it)
  {
    json Lounge;
    Lounge["ID"] = it->first;
    Lounge["User Amount"] = it->second->getLoungeSize();
    Buffer[std::string("Lounge ")+std::to_string(LoungeCount)] = Lounge;
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
    for(int i = 0;i < static_cast<int>(playerList.size());++i)
    {
      json PlayerBuffer;
      PlayerBuffer["Player Name"] = playerList[i]->GetUser()->GetName();
      PlayerBuffer["Character Name"] = playerList[i]->GetCharacter()->GetName();
      PlayerBuffer["Position"] = playerList[i]->GetPosition();

      Buffer["Player " + std::to_string(i)] = PlayerBuffer;
    }
    Buffer["Card Amount"] = room->GetPlague()->GetPlagueCardAmount();
    for(int i = 0;i < room->GetPlague()->GetPlagueCardAmount();i++)
    {
      json CardBuffer;
      const CCard * Entry = room->GetPlague()->GetCardEntrie(i);
      CardBuffer["Name"] = Entry->GetName();
      CardBuffer["Suit"] = static_cast<int>(Entry->GetSuit());
      CardBuffer["Number"] = Entry->GetNumber();
      Buffer["Card " + std::to_string(Entry->GetID())] = CardBuffer;
    }
    return Buffer;
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

  Buffer["Holding Card Amount"] = player->GetHoldingAmount();
  std::vector<CCard *> holding = player->GetHolding();
  json HoldingBuffer;
  for(int i = 0;i < static_cast<int>(holding.size());++i)
  {
    HoldingBuffer["Holding Card " + std::to_string(i)] = holding[i]->GetID();
  }
  Buffer["Holding"] = HoldingBuffer;

  Buffer["Equipment Card Amount"] = player->GetEquipmentAmount();
  std::vector<CCard *> equiping = player->GetEquipment();
  json EquipmentBuffer;
  for(int i = 0;i < static_cast<int>(equiping.size());++i)
  {
    EquipmentBuffer["Equipment Card " + std::to_string(i)] = equiping[i]->GetID();
  }
  Buffer["Equipment"] = EquipmentBuffer;

  const CCard * Weapon = player->GetWeapon();
  Buffer["Weapon"] = Weapon?Weapon->GetID():NoneMagicNumber;

  std::vector<CPlayer *> playerList = room->GetPlayerList();
  for(int i = 0;i < static_cast<int>(playerList.size());++i)
  {
    json PlayerBuffer;
    PlayerBuffer["Max HP"] = playerList[i]->GetMaxHP();
    PlayerBuffer["HP"] = playerList[i]->GetHP();
    PlayerBuffer["Holding Card Amount"] = playerList[i]->GetHoldingAmount();
    PlayerBuffer["Equipment Card Amount"] = playerList[i]->GetEquipmentAmount();

    std::vector<CCard *> OtherEquiping = playerList[i]->GetEquipment();
    json OtherEquipmentBuffer;
    for(int i = 0;i < static_cast<int>(OtherEquiping.size());++i)
    {
      OtherEquipmentBuffer["Equipment Card " + std::to_string(i)] = OtherEquiping[i]->GetID();
    }
    PlayerBuffer["Equipment"] = OtherEquipmentBuffer;

    const CCard * OtherWeapon = playerList[i]->GetWeapon();
    PlayerBuffer["Weapon"] = OtherWeapon?OtherWeapon->GetID():NoneMagicNumber;

    Buffer["Player " + std::to_string(i)] = PlayerBuffer;
  }

  return Buffer;
}
json NSWrapInfo::WrapShowCard(CPlayer * shower, CPlayer * showee)
{
  json Buffer;
  Buffer["Action"] = 10;
  Buffer["Shower"] = shower->GetPosition();
  Buffer["Showee"] = showee->GetPosition();
  return Buffer;
}
json NSWrapInfo::WrapRevoltCard(CCard * card)
{
  json Buffer;
  Buffer["Action"] = 12;
  Buffer["Revolt Card"] = card->GetID();
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
  //need some edit
  json Buffer;
  Buffer["Action"] = 15;
  return Buffer;
}
