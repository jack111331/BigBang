#pragma once

#include "Card.h"
#include <vector>
class CRoom;
class CPlague
{
public:
  void InitPlague(CRoom * room);
  int GetPlagueCardAmount() const;
  CCard * ChooseRandomCard();
  CCard * ChooseTopCard();
  void InsertCardToPlague(CCard * card);
  void RemoveCardFromPlague(const CCard * card);
  void FlushPlague();
  const CCard * GetCardEntrie(int index) const;
  ~CPlague();
private:
  std::vector<CCard *> Plague;
};
