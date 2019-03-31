#pragma once

#include "Card.h"
#include <vector>

class CPlague
{
public:
  void InitPlague();
  int GetPlagueCardAmount() const;
  CCard * RandomChooseCard();
  void RemoveCardFromPlague(const CCard * card);
private:
  std::vector<CCard *> Plague;
};
