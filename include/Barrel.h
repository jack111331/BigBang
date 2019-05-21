#pragma once
#include "EquipmentCard.h"
#include "Player.h"
class CRoom;
class CBarrel : public CEquipmentCard
{
public:
  CBarrel(CRoom * room, int number, Suit suit);
  static void OnEquip(CCard * card, CPlayer * Equiper);
  static bool OnPreLossBlood(CRoom * room, CPlayer * loser);
  static void OnUnequip(CCard * card, CPlayer * Unequiper);
};
