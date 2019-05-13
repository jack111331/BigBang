#include "EquipmentCard.h"
#include "GameEventObserver.h"
int CEquipmentCard::GetType() const
{
  return this->Type;
}
void CEquipmentCard::SetType(int type)
{
  this->Type = type;
}
void CEquipmentCard::UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target)
{
  CGameEventObserver::callEquip(this, myself);
}
