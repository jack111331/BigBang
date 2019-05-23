#pragma once
#include "EquipmentCard.h"
#include "Player.h"
class CRoom;
class CDynamite : public CEquipmentCard
{
public:
  CDynamite(CRoom * room, int number, Suit suit);
  static void OnEquip(CCard * card, CPlayer * Equiper);
  static void OnUnequip(CCard * card, CPlayer * Unequiper);
  static bool OnDrawCard(CRoom * room, CPlayer * Drawer);
};
