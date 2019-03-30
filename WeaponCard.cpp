#include "WeaponCard.h"

int CWeaponCard::GetAttackRange() const
{
  return this->AttackRange;
}
bool CWeaponCard::isMultiBang() const
{
  return this->MultiBang;
}
void CWeaponCard::SetAttackRange(int attackRange)
{
  this->AttackRange = attackRange;
}
void CWeaponCard::SetMultiBang(bool multiBang)
{
  this->MultiBang = multiBang;
}
