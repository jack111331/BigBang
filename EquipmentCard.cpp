#include "EquipmentCard.h"
#include "GameEventObserver.h"
CEquipmentCard::CEquipmentCard(int number, Suit suit) : CCard(number, suit)
{

}
int CEquipmentCard::GetAttackRange() const
{
  return this->AttackRange;
}
int CEquipmentCard::GetDefendRange() const
{
  return this->DefendRange;
}
bool CEquipmentCard::isMultiAttack() const
{
  return this->MultiAttack;
}
void CEquipmentCard::SetAttackRange(int attackRange)
{
  this->AttackRange = attackRange;
}
void CEquipmentCard::SetDefendRange(int defendRange)
{
  this->DefendRange = defendRange;
}
void CEquipmentCard::SetMultiAttack(bool multiAttack)
{
  this->MultiAttack = multiAttack;
}
void CEquipmentCard::UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target)
{
  CGameEventObserver::callEquip(this, myself);
}
