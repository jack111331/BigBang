#pragma once
#include <vector>
#include "Player.h"
class CGameEventObserver
{
public:
  static void registerOnAttack(void (*AttackFunction)(CPlayer * attacker, CPlayer * attackee));
  static void registerOnDeath(void (*DeathFunction)(CPlayer * deadPerson, CPlayer * attacker));
  static void registerOnDrawCard(void (*DrawCardFunction)(CPlayer * Drawer));
  static void CallAttack(CPlayer * attacker, CPlayer * attackee);
  static void CallDeath(CPlayer * deadPerson, CPlayer * attacker);
  static void CallDrawCard(CPlayer * Drawer);
  static void unregisterOnAttack(void (*AttackFunction)(CPlayer * attacker, CPlayer * attackee));
  static void unregisterOnDeath(void (*DeathFunction)(CPlayer * deadPerson, CPlayer * attacker));
  static void unregisterOnDeath(void (*DrawCardFunction)(CPlayer * Drawer));
private:
  static std::vector<void (*)(CPlayer * attacker, CPlayer * attackee)> AttackListener;
  static std::vector<void (*)(CPlayer * deadPerson, CPlayer * attacker)> DeathListener;
  static std::vector<void (*)(CPlayer * Drawer)> DrawCardListener;
};
