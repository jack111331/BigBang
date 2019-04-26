#pragma once
#include <vector>
#include "Player.h"
class CRoom;
class CGameEventObserver
{
public:
  static void registerOnAttack(void (*AttackFunction)(CRoom * room, CPlayer * attacker, CPlayer * attackee));
  static void registerOnDeath(void (*DeathFunction)(CRoom * room, CPlayer * deadPerson, CPlayer * attacker));
  static void registerOnDrawCard(void (*DrawCardFunction)(CRoom * room, CPlayer * Drawer));
  static void callAttack(CRoom * room, CPlayer * attacker, CPlayer * attackee);
  static void callDeath(CRoom * room, CPlayer * deadPerson, CPlayer * attacker);
  static void callDrawCard(CRoom * room, CPlayer * Drawer);
  static void unregisterOnAttack(void (*AttackFunction)(CRoom * room, CPlayer * attacker, CPlayer * attackee));
  static void unregisterOnDeath(void (*DeathFunction)(CRoom * room, CPlayer * deadPerson, CPlayer * attacker));
  static void unregisterOnDeath(void (*DrawCardFunction)(CRoom * room, CPlayer * Drawer));
private:
  static std::vector<void (*)(CRoom * room, CPlayer * attacker, CPlayer * attackee)> AttackListener;
  static std::vector<void (*)(CRoom * room, CPlayer * deadPerson, CPlayer * attacker)> DeathListener;
  static std::vector<void (*)(CRoom * room, CPlayer * Drawer)> DrawCardListener;
};
