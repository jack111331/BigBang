#include "Plague.h"
#include "CardGenFactory.h"
#include <time.h>
#include <algorithm>


void CPlague::InitPlague(CRoom * room)
{
  Plague.push_back(NSCardGenFactory::createCard("Winchester", room, 1, Suit::Diamond));
  Plague.push_back(NSCardGenFactory::createCard("Barrel", room, 5, Suit::Heart));
  Plague.push_back(NSCardGenFactory::createCard("Carabine", room, 7, Suit::Spade));
  Plague.push_back(NSCardGenFactory::createCard("Jail", room, 9, Suit::Club));
  Plague.push_back(NSCardGenFactory::createCard("Mustang", room, 3, Suit::Heart));
  Plague.push_back(NSCardGenFactory::createCard("Remington", room, 9, Suit::Spade));
  Plague.push_back(NSCardGenFactory::createCard("Saloon", room, 12, Suit::Diamond));
  Plague.push_back(NSCardGenFactory::createCard("Schofield", room, 13, Suit::Club));
  Plague.push_back(NSCardGenFactory::createCard("Volcanic", room, 2, Suit::Club));
  Plague.push_back(NSCardGenFactory::createCard("Stagecoach", room, 8, Suit::Heart));
  Plague.push_back(NSCardGenFactory::createCard("Wells fargo", room, 11, Suit::Diamond));
  Plague.push_back(NSCardGenFactory::createCard("Jail", room, 4, Suit::Spade));
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
const CCard * CPlague::GetCardEntrie(int index) const
{
  if(index < 0|| index >= static_cast<int>(Plague.size()))
  {
    return nullptr;
  }
  return Plague[index];
}
