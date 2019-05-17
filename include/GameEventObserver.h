#pragma once
#include <vector>
#include "Player.h"
class CRoom;
class CCard;
class CGameEventObserver
{
public:
  static void registerOnLossBlood(void (*LossBloodFunction)(CRoom * room, CPlayer * loser));
  static void registerOnDeath(void (*DeathFunction)(CRoom * room, CPlayer * deadPerson, CPlayer * attacker));
  static void registerOnDrawCard(void (*DrawCardFunction)(CRoom * room, CPlayer * Drawer));
  static void registerOnEquip(void (*EquipFunction)(CCard * card, CPlayer * Equiper));
  static void registerOnUnequip(void (*UnequipFunction)(CCard * card, CPlayer * Unequiper));
  static void callLossBlood(CRoom * room, CPlayer * loser);
  static void callDeath(CRoom * room, CPlayer * deadPerson, CPlayer * attacker);
  static void callDrawCard(CRoom * room, CPlayer * Drawer);
  static void callEquip(CCard * card, CPlayer * Equiper);
  static void callUnequip(CCard * card, CPlayer * Unequiper);
  static void unregisterOnLossBlood(void (*LossBloodFunction)(CRoom * room, CPlayer * loser));
  static void unregisterOnDeath(void (*DeathFunction)(CRoom * room, CPlayer * deadPerson, CPlayer * attacker));
  static void unregisterOnDeath(void (*DrawCardFunction)(CRoom * room, CPlayer * Drawer));
  static void unregisterOnEquip(void (*EquipFunction)(CCard * card, CPlayer * Equiper));
  static void unregisterOnUnequip(void (*UnequipFunction)(CCard * card, CPlayer * Unequiper));
private:
  static std::vector<void (*)(CRoom * room, CPlayer * loser)> LossBloodListener;
  static std::vector<void (*)(CRoom * room, CPlayer * deadPerson, CPlayer * attacker)> DeathListener;
  static std::vector<void (*)(CRoom * room, CPlayer * Drawer)> DrawCardListener;
  static std::vector<void (*)(CCard * card, CPlayer * Equiper)> EquipListener;
  static std::vector<void (*)(CCard * card, CPlayer * Unequiper)> UnequipListener;
};
