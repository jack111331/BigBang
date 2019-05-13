#pragma once
#include "WeaponCard.h"
#include "Player.h"
class CRoom;
class CWinchester : public CWeaponCard
{
public:
  CWinchester();
  static void OnEquip(CCard * card, CPlayer * Equiper);
};
