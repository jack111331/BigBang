#include "EquipmentCard.h"
#include "GameEventObserver.h"
#include "Room.h"
#include "Action.h"
CEquipmentCard::CEquipmentCard(CRoom * room, int number, Suit suit) : CCard(room, number, suit)
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
bool CEquipmentCard::UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target)
{
  NSAction::RemoveCardToDiscardPlague(room->GetDiscardPlague(), myself, this);
  GetInRoom()->GetRoomEvent()->callEquip(this, myself);
  return true;
}
