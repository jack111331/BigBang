#pragma once
#include "EquipmentCard.h"
#include "Player.h"
class CRoom;
class CVolcanic : public CEquipmentCard
{
public:
  CVolcanic(CRoom * room, int number, Suit suit);
  static void OnEquip(CCard * card, CPlayer * Equiper);
  static void OnUnequip(CCard * card, CPlayer * Unequiper);
};
