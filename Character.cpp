#include "Character.h"
#include "Card.h"
#include "Plague.h"
#include "Player.h"
#include "Action.h"
#include "Room.h"
int CCharacter::CurrentID = 0;

void CCharacter::DrawCard(CRoom * room, CPlayer * myself, CPlayer * target)
{
  //Define Normal active
  constexpr int DrawCardAmount = 2;
  for(int i = 0;i < DrawCardAmount;i++)
  {
    NSAction::DrawCardFromPlague(room->GetPlague(), myself);
  }
}
void CCharacter::Attack(CRoom * room, CPlayer * myself, CPlayer * target)
{
  if(!myself->isAttacked() || myself->isCardInHolding(std::string("Volcanic")))
  {
    NSAction::Attack(myself, target, std::string("missed!"));
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
