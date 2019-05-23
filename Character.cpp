#include "Character.h"
#include "Card.h"
#include "Plague.h"
#include "Player.h"
#include "Action.h"
#include "Room.h"
int CCharacter::CurrentID = 0;

CCharacter::CCharacter(CRoom * room)
{
  this->InRoom = room;
}
CCharacter::~CCharacter()
{

}
void CCharacter::DrawCard(CRoom * room, CPlayer * myself)
{
  //Define Normal active
  constexpr int DrawCardAmount = 2;
  for(int i = 0;i < DrawCardAmount;i++)
  {
    NSAction::DrawCardFromPlague(room, myself);
  }
}
void CCharacter::Attack(CRoom * room, CPlayer * myself, CPlayer * target)
{
  if(!myself->isAttacked() || myself->GetCardInHolding(std::string("Volcanic")))
  {
    NSAction::Attack(room, myself, target, std::string("Missed!"));
    myself->SetAttacked(true);
  }
}
const std::string & CCharacter::GetName() const
{
  return this->Name;
}
const std::string & CCharacter::GetFeature() const
{
  return this->Feature;
}
int CCharacter::GetID() const
{
  return this->ID;
}
int CCharacter::GetMaxHP() const
{
  return this->MaxHP;
}
int CCharacter::GetDefaultAttackRange() const
{
  return this->AttackRange;
}
int CCharacter::GetDefaultAddRange() const
{
  return this->AddRange;
}
int CCharacter::GetDefaultMinusRange() const
{
  return this->MinusRange;
}
int CCharacter::GetDefaultMultiAttack() const
{
  return this->HasMultiAttack;
}
CRoom * CCharacter::GetInRoom() const
{
  return this->InRoom;
}

void CCharacter::SetName(const std::string & name)
{
  this->Name = name;
}
void CCharacter::SetFeature(const std::string & feature)
{
  this->Feature = feature;
}
void CCharacter::SetID()
{
  this->ID = CurrentID++;
}
void CCharacter::SetMaxHP(int maxHP)
{
  this->MaxHP = maxHP;
}
void CCharacter::SetAttackRange(int AttackRange)
{
  this->AttackRange = AttackRange;
}
void CCharacter::SetAddRange(int AddRange)
{
  this->AddRange = AddRange;
}
void CCharacter::SetMinusRange(int MinusRange)
{
  this->MinusRange = MinusRange;
}
void CCharacter::SetMultiAttack(bool HasMultiAttack)
{
  this->HasMultiAttack = HasMultiAttack;
}
