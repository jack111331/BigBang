#pragma once
#include <vector>
#include <stdint.h>
enum class ExclusiveCardType
{
  CharacterCard = 1,
  EffectAndEquipmentCard
};
class CUser;
class CExclusiveCardInventory
{
public:
  CExclusiveCardInventory(CUser * user);
  std::vector<uint32_t> & GetCharacterCardList();
  std::vector<uint32_t> & GetEffectAndEquipmentCardList();
  void AddExclusiveCard(uint32_t ID, int type);
  ~CExclusiveCardInventory();
private:
  CUser * User;
  std::vector<uint32_t> CharacterCardList;
  std::vector<uint32_t> EffectAndEquipmentCardList;
};
