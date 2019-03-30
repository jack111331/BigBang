#include "Plague.h"
#include <time.h>


void CPlague::InitPlague()
{

}
int CPlague::GetPlagueCardAmount() const
{
  return static_cast<int>(Plague.size());
}
const CCard * CPlague::RandomChooseCard()
{
  srand(time(0));
  int random = rand() % GetPlagueCardAmount();
  return Plague[random];
}
