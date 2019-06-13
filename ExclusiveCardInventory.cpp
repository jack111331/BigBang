#include "ExclusiveCardInventory.h"
#include "Database.h"
#include "User.h"
CExclusiveCardInventory::CExclusiveCardInventory(CUser * user)
{
  User = user;
  CDatabase DB;
  this->CharacterCardList = DB.GetExclusiveCardList(User->GetID(), static_cast<int>(ExclusiveCardType::CharacterCard));
  this->EffectAndEquipmentCardList = DB.GetExclusiveCardList(User->GetID(), static_cast<int>(ExclusiveCardType::EffectAndEquipmentCard));
}
std::vector<uint32_t> & CExclusiveCardInventory::GetCharacterCardList()
{
  return this->CharacterCardList;
}
std::vector<uint32_t> & CExclusiveCardInventory::GetEffectAndEquipmentCardList()
{
  return this->EffectAndEquipmentCardList;
}
void CExclusiveCardInventory::AddExclusiveCard(uint32_t ID, int type)
{
  CDatabase DB;
  DB.InsertExclusiveCard(User->GetID(), type, ID);
  if(type == 1)
  {
    CharacterCardList.push_back(ID);
  }
  else if(type == 2)
  {
    EffectAndEquipmentCardList.push_back(ID);
  }
}
CExclusiveCardInventory::~CExclusiveCardInventory()
{

}
