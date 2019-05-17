#include "GameEventObserver.h"
#include "Player.h"
#include "Room.h"
#include "Card.h"

std::vector<void (*)(CRoom * room, CPlayer * loser)> CGameEventObserver::LossBloodListener;
std::vector<void (*)(CRoom * room, CPlayer * deadPerson, CPlayer * attacker)> CGameEventObserver::DeathListener;
std::vector<void (*)(CRoom * room, CPlayer * Drawer)> CGameEventObserver::DrawCardListener;
std::vector<void (*)(CCard * card, CPlayer * Equiper)> CGameEventObserver::EquipListener;
std::vector<void (*)(CCard * card, CPlayer * Unequiper)> CGameEventObserver::UnequipListener;

void CGameEventObserver::registerOnLossBlood(void (*LossBloodFunction)(CRoom * room, CPlayer * loser))
{
  LossBloodListener.push_back(LossBloodFunction);
}
void CGameEventObserver::registerOnDeath(void (*DeathFunction)(CRoom * room, CPlayer * deadPerson, CPlayer * attacker))
{
  DeathListener.push_back(DeathFunction);
}
void CGameEventObserver::registerOnDrawCard(void (*DrawCardFunction)(CRoom * room, CPlayer * Drawer))
{
  DrawCardListener.push_back(DrawCardFunction);
}
void CGameEventObserver::registerOnEquip(void (*EquipFunction)(CCard * card, CPlayer * Equiper))
{
  EquipListener.push_back(EquipFunction);
}
void CGameEventObserver::registerOnUnequip(void (*UnequipFunction)(CCard * card, CPlayer * Unequiper))
{
  UnequipListener.push_back(UnequipFunction);
}
void CGameEventObserver::callLossBlood(CRoom * room, CPlayer * loser)
{
  for(auto i = LossBloodListener.begin();i != LossBloodListener.end();++i)
  {
    (*i)(room, loser);
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
void CGameEventObserver::callEquip(CCard * card, CPlayer * Equiper)
{
  for(auto i = EquipListener.begin();i != EquipListener.end();++i)
  {
    (*i)(card, Equiper);
  }
}
void CGameEventObserver::callUnequip(CCard * card, CPlayer * Unequiper)
{
  for(auto i = UnequipListener.begin();i != UnequipListener.end();++i)
  {
    (*i)(card, Unequiper);
  }
}
void CGameEventObserver::unregisterOnLossBlood(void (*LossBloodFunction)(CRoom * room, CPlayer * loser))
{
  for(auto i = LossBloodListener.begin();i != LossBloodListener.end();++i)
  {
    if(*i == LossBloodFunction)
    {
      LossBloodListener.erase(i);
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
void CGameEventObserver::unregisterOnEquip(void (*EquipFunction)(CCard * card, CPlayer * Equiper))
{
  for(auto i = EquipListener.begin();i != EquipListener.end();++i)
  {
    if(*i == EquipFunction)
    {
      EquipListener.erase(i);
    }
  }
}
void CGameEventObserver::unregisterOnUnequip(void (*UnequipFunction)(CCard * card, CPlayer * Equiper))
{
  for(auto i = UnequipListener.begin();i != UnequipListener.end();++i)
  {
    if(*i == UnequipFunction)
    {
      UnequipListener.erase(i);
    }
  }
}
