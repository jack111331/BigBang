#include "Plague.h"
#include "CardGenFactory.h"
#include <time.h>
#include <algorithm>
#include "CardGenDecorator.h"
#include "Room.h"
#include "Lounge.h"
#include <map>
#include "ExclusiveCardStore.h"
void CPlague::InitPlague(CRoom * room)
{
  CCardGenComponent * CardComponent = new CCardGenConcreteComponent(room);
  if(room->GetLounge()->getEnableExclusiveCard())
  {
    // get all player's exclusive card
    std::map<uint32_t, bool> EffectAndEquipmentCardSet;
    for(std::vector<CPlayer *>::iterator it = room->GetPlayerList().begin();it != room->GetPlayerList().end();++it)
    {
      std::vector<uint32_t> CardList = (*it)->GetUser()->GetExclusiveCardInventory()->GetEffectAndEquipmentCardList();
      for(int i = 0;i < static_cast<int>(CardList.size());++i)
      {
        EffectAndEquipmentCardSet[CardList[i]] = 1;
      }
    }
    CardComponent = CExclusiveCardStore::GetInstance()->GenerateExclusiveCard(EffectAndEquipmentCardSet, CardComponent, room);
  }
  Plague = CardComponent->GetGeneratePlague();
  srand(time(0));
  std::random_shuffle(Plague.begin(), Plague.end());
}
int CPlague::GetPlagueCardAmount() const
{
  return static_cast<int>(Plague.size());
}
CCard * CPlague::ChooseRandomCard()
{
  srand(time(0));
  int PlagueCardAmount = GetPlagueCardAmount();
  if(PlagueCardAmount)
  {
    int random = rand() % PlagueCardAmount;
    return Plague[random];
  }
  else
  {
    return nullptr;
  }
}
CCard * CPlague::ChooseTopCard()
{
  int PlagueCardAmount = GetPlagueCardAmount();
  if(PlagueCardAmount)
  {
    return Plague[Plague.size()-1];
  }
  else
  {
    return nullptr;
  }
}

void CPlague::InsertCardToPlague(CCard * card)
{
  Plague.push_back(card);
}
void CPlague::RemoveCardFromPlague(const CCard * card)
{
  for(int i = 0;i < static_cast<int>(Plague.size());i++)
  {
    if(Plague[i] == card)
    {
      Plague.erase(Plague.begin() + i);
      break;
    }
  }
}
CCard * CPlague::GetPlagueCardByID(int CardID)
{
  for(int i = 0;i < static_cast<int>(Plague.size());i++)
  {
    if(Plague[i]->GetID() == CardID)
    {
      return Plague[i];
    }
  }
  return nullptr;
}
void CPlague::FlushPlague()
{
  srand(time(0));
  std::random_shuffle(Plague.begin(), Plague.end());
}
const CCard * CPlague::GetCardEntrie(int index) const
{
  if(index < 0|| index >= static_cast<int>(Plague.size()))
  {
    return nullptr;
  }
  return Plague[index];
}
CPlague::~CPlague()
{
  for(std::vector<CCard *>::iterator it = Plague.begin();it != Plague.end();)
  {
    delete *it;
    it = Plague.erase(it);
  }
}
