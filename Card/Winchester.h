#pragma once
#include "../WeaponCard.h"
#include "../Player.h"
class CRoom;
class CWinchester : public CWeaponCard
{
public:
  CWinchester();
  void InitCard();
  void UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target);
};
