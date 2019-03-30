#pragma once

#include "Card.h"
#include <vector>

class CPlague
{
public:
  void InitPlague();
  int GetPlagueCardAmount() const;
  const CCard * RandomChooseCard();
private:
  std::vector<CCard *> Plague;
};
