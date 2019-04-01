#include "Plague.h"
#include <time.h>
#include "../Card/Winchester.h"


void CPlague::InitPlague()
{
  Plague.push_back(new CWinchester);
}
int CPlague::GetPlagueCardAmount() const
{
  return static_cast<int>(Plague.size());
}
CCard * CPlague::RandomChooseCard()
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
