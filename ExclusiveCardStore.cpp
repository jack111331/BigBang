#include "ExclusiveCardStore.h"
#include "GeneralStore.h"
#include "GodDeveloper.h"
#include "Card.h"
#include "Character.h"

CExclusiveCardStore * CExclusiveCardStore::myself = nullptr;
CExclusiveCardStore::CExclusiveCardStore()
{
  int CardStoreItemCount = 1;
  CCard * GeneralStore = new CGeneralStore(nullptr, 0, Suit::Spade);

  EffectAndEquipmentCardStoreSet[CardStoreItemCount++] = {GeneralStore->GetName(), GeneralStore->GetFeature(), 20}; // 1

  delete GeneralStore;

  int CharacterStoreItemCount = 1;
  CCharacter * GodDeveloper = new CCharacterGod(nullptr);

  CharacterCardStoreSet[CharacterStoreItemCount++] = {GodDeveloper->GetName(), GodDeveloper->GetFeature(), 20}; // 1

  delete GodDeveloper;

}
CCardGenComponent * CExclusiveCardStore::GenerateExclusiveCard(const std::map<uint32_t, bool> & CardSet, CCardGenComponent * Component, CRoom * Room)
{
  for(auto it = CardSet.begin();it != CardSet.end();++it)
  {
    if(it->first == 1)
    {
      Component = new CCardGenConcreteDecoratorGeneralStore(Component, Room);
    }
  }
  return Component;
}
CCharacterGenComponent * CExclusiveCardStore::GenerateExclusiveCharacter(const std::map<uint32_t, bool> & CharacterSet, CCharacterGenComponent * Component)
{
  for(auto it = CharacterSet.begin();it != CharacterSet.end();++it)
  {
    if(it->first == 1)
    {
      Component = new CCharacterGenConcreteDecoratorGodDeveloper(Component);
    }
  }
  return Component;
}
const std::map<uint32_t, ExclusiveCard> & CExclusiveCardStore::GetCharacterCardStore()
{
  return CharacterCardStoreSet;
}
const std::map<uint32_t, ExclusiveCard> & CExclusiveCardStore::GetEffectAndEquipmentCardStore()
{
  return EffectAndEquipmentCardStoreSet;
}
CExclusiveCardStore * CExclusiveCardStore::GetInstance()
{
  if(myself == nullptr)
  {
    myself = new CExclusiveCardStore();
  }
  return myself;
}
