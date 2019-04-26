#include "GameEventObserver.h"
#include "Player.h"
#include "Room.h"

std::vector<void (*)(CRoom * room, CPlayer * attacker, CPlayer * attackee)> CGameEventObserver::AttackListener;
std::vector<void (*)(CRoom * room, CPlayer * deadPerson, CPlayer * attacker)> CGameEventObserver::DeathListener;
std::vector<void (*)(CRoom * room, CPlayer * Drawer)> CGameEventObserver::DrawCardListener;

void CGameEventObserver::registerOnAttack(void (*AttackFunction)(CRoom * room, CPlayer * attacker, CPlayer * attackee))
{
  AttackListener.push_back(AttackFunction);
}
void CGameEventObserver::registerOnDeath(void (*DeathFunction)(CRoom * room, CPlayer * deadPerson, CPlayer * attacker))
{
  DeathListener.push_back(DeathFunction);
}
void CGameEventObserver::registerOnDrawCard(void (*DrawCardFunction)(CRoom * room, CPlayer * Drawer))
{
  DrawCardListener.push_back(DrawCardFunction);
}
void CGameEventObserver::callAttack(CRoom * room, CPlayer * attacker, CPlayer * attackee)
{
  for(auto i = AttackListener.begin();i != AttackListener.end();++i)
  {
    (*i)(room, attacker, attackee);
  }
}
void CGameEventObserver::callDeath(CRoom * room, CPlayer * deadPerson, CPlayer * attacker)
{
  for(auto i = DeathListener.begin();i != DeathListener.end();++i)
  {
    (*i)(room, deadPerson, attacker);
  }
}
void CGameEventObserver::callDrawCard(CRoom * room, CPlayer * Drawer)
{
  for(auto i = DrawCardListener.begin();i != DrawCardListener.end();++i)
  {
    (*i)(room, Drawer);
  }
}
void CGameEventObserver::unregisterOnAttack(void (*AttackFunction)(CRoom * room, CPlayer * attacker, CPlayer * attackee))
{
  for(auto i = AttackListener.begin();i != AttackListener.end();++i)
  {
    if(*i == AttackFunction)
    {
      AttackListener.erase(i);
    }
  }
}
void CGameEventObserver::unregisterOnDeath(void (*DeathFunction)(CRoom * room, CPlayer * deadPerson, CPlayer * attacker))
{
  for(auto i = DeathListener.begin();i != DeathListener.end();++i)
  {
    if(*i == DeathFunction)
    {
      DeathListener.erase(i);
    }
  }
}
void CGameEventObserver::unregisterOnDeath(void (*DrawCardFunction)(CRoom * room, CPlayer * Drawer))
{
  for(auto i = DrawCardListener.begin();i != DrawCardListener.end();++i)
  {
    if(*i == DrawCardFunction)
    {
      DrawCardListener.erase(i);
    }
  }
}
