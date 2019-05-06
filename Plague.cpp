#include "Plague.h"
#include "CardGenFactory.h"
#include <time.h>
#include <algorithm>


void CPlague::InitPlague()
{
//  Plague.push_back(NSCardGenFactory::createCard("Winchester"));
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
