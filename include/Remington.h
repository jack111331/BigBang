#pragma once
#include "EquipmentCard.h"
#include "Player.h"
class CRoom;
class CRemington : public CEquipmentCard
{
public:
  CRemington(CRoom * room, int number, Suit suit);
  static void OnEquip(CCard * card, CPlayer * Equiper);
  static void OnUnequip(CCard * card, CPlayer * Unequiper);
};
