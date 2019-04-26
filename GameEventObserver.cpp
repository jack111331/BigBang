#include "GameEventObserver.h"
#include "Player.h"

std::vector<void (*)(CPlayer * attacker, CPlayer * attackee)> AttackListener;
std::vector<void (*)(CPlayer * deadPerson, CPlayer * attacker)> DeathListener;
std::vector<void (*)(CPlayer * Drawer)> DrawCardListener;

void CGameEventObserver::registerOnAttack(void (*AttackFunction)(CPlayer * attacker, CPlayer * attackee))
{
  AttackListener.push_back(AttackFunction);
}
void CGameEventObserver::registerOnDeath(void (*DeathFunction)(CPlayer * deadPerson, CPlayer * attacker))
{
  DeathListener.push_back(DeathFunction);
}
void CGameEventObserver::registerOnDrawCard(void (*DrawCardFunction)(CPlayer * Drawer))
{
  DrawCardListener.push_back(DrawCardFunction);
}
void CGameEventObserver::CallAttack(CPlayer * attacker, CPlayer * attackee)
{
  for(auto i = AttackListener.begin();i != AttackListener.end();++i)
  {
    (*i)(attacker, attackee);
  }
}
void CGameEventObserver::CallDeath(CPlayer * deadPerson, CPlayer * attacker)
{
  for(auto i = DeathListener.begin();i != DeathListener.end();++i)
  {
    (*i)(deadPerson, attacker);
  }
}
void CGameEventObserver::CallDrawCard(CPlayer * Drawer)
{
  for(auto i = DrawCardListener.begin();i != DrawCardListener.end();++i)
  {
    (*i)(Drawer);
  }
}
void CGameEventObserver::unregisterOnAttack(void (*AttackFunction)(CPlayer * attacker, CPlayer * attackee))
{
  for(auto i = AttackListener.begin();i != AttackListener.end();++i)
  {
    if(*i == AttackFunction)
    {
      AttackListener.erase(i);
    }
  }
}
void CGameEventObserver::unregisterOnDeath(void (*DeathFunction)(CPlayer * deadPerson, CPlayer * attacker))
{
  for(auto i = DeathListener.begin();i != DeathListener.end();++i)
  {
    if(*i == DeathFunction)
    {
      DeathListener.erase(i);
    }
  }
}
void CGameEventObserver::unregisterOnDeath(void (*DrawCardFunction)(CPlayer * Drawer))
{
  for(auto i = DrawCardListener.begin();i != DrawCardListener.end();++i)
  {
    if(*i == DrawCardFunction)
    {
      DrawCardListener.erase(i);
    }
  }
}
