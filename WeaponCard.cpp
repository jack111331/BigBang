#include "WeaponCard.h"

int CWeaponCard::GetAttackRange() const
{
  return this->AttackRange;
}
bool CWeaponCard::isMultiAttack() const
{
  return this->MultiAttack;
}
void CWeaponCard::SetAttackRange(int attackRange)
{
  this->AttackRange = attackRange;
}
void CWeaponCard::SetMultiAttack(bool multiAttack)
{
  this->MultiAttack = multiAttack;
}
