#pragma once
#include <map>
#include <stdint.h>
#include <string>
#include "CardGenDecorator.h"
#include "CharacterGenDecorator.h"
#include "Room.h"
struct ExclusiveCard
{
  std::string Name;
  std::string Description;
  int Cost;
};
class CExclusiveCardStore
{
public:
  CExclusiveCardStore();
  CCardGenComponent * GenerateExclusiveCard(const std::map<uint32_t, bool> & CardSet, CCardGenComponent * Component, CRoom * Room);
  CCharacterGenComponent * GenerateExclusiveCharacter(const std::map<uint32_t, bool> & CharacterSet, CCharacterGenComponent * Component);
  const std::map<uint32_t, ExclusiveCard> & GetCharacterCardStore();
  const std::map<uint32_t, ExclusiveCard> & GetEffectAndEquipmentCardStore();
  static CExclusiveCardStore * GetInstance();
private:
  static CExclusiveCardStore * myself;
  std::map<uint32_t, ExclusiveCard> CharacterCardStoreSet;
  std::map<uint32_t, ExclusiveCard> EffectAndEquipmentCardStoreSet;
};
