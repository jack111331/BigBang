#pragma once
#include "../WeaponCard.h"
#include "../Player.h"

class CWinchester : public CWeaponCard
{
public:
  CWinchester();
  void InitCard();
  void UseCardEffect(CPlayer & myself, CPlayer & target, std::vector<CPlayer *> & allPlayer);
};
