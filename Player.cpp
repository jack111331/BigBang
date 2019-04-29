#include "Player.h"
#include "Action.h"
#include "Room.h"

void CPlayer::DrawCard(CRoom * room)
{
  if(Character != nullptr)
  {
    Character->DrawCard(room, this);
  }
}

void CPlayer::Attack(CRoom * room, CPlayer * target)
{
  if(Character != nullptr)
  {
    Character->Attack(room, this, target);
  }
}
void CPlayer::UseCard(CRoom * room, CCard * card, CPlayer * target)
{
  if(isCardInHolding(card->GetName()))
  {
    card->UseCardEffect(room, this, target);
    RemoveHolding(card);
  }
}
void CPlayer::FoldCard(CRoom * room, CCard * card)
{
  NSAction::FoldCard(this, card, room->GetDiscardPlague());
}

const std::string & CPlayer::GetName() const
{
  return this->Name;
}
CCharacter * CPlayer::GetCharacter()
{
  return this->Character;
}
Team CPlayer::GetIdentity() const
{
  return this->Identity;
}
int CPlayer::GetHP() const
{
  return this->HP;
}
int CPlayer::GetMaxHP() const
{
  return this->MaxHP;
}
const std::vector<CCard *> & CPlayer::GetHolding() const
{
  return this->Holding;
}
const std::vector<CCard *> & CPlayer::GetEquipment() const
{
  return this->Equipment;
}
int CPlayer::GetPosition() const
{
  return this->Position;
}
bool CPlayer::isAttacked() const
{
  return this->Attacked;
}
bool CPlayer::isDead() const
{
  return this->Dead;
}
int CPlayer::GetAttackRange() const
{
  return this->AttackRange;
}
int CPlayer::GetAddRange() const
{
  return this->AddRange;
}
int CPlayer::GetMinusRange() const
{
  return this->MinusRange;
}

void CPlayer::SetName(const std::string & name)
{
  this->Name = Name;
}
//??
void CPlayer::SetCharacter(CCharacter * character)
{
  this->Character = character;
}
void CPlayer::SetIdentity(Team identity)
{
  this->Identity = identity;
}
void CPlayer::SetHP(int HP)
{
  if(HP == 0)
  {
    this->Dead = true;
  }
  this->HP = HP;
}
void CPlayer::SetMaxHP(int maxHP)
{
  this->MaxHP = maxHP;
}
void CPlayer::AddHolding(CCard * card)
{
  Holding.push_back(card);
}
void CPlayer::AddEquipment(CCard * card)
{
  Equipment.push_back(card);
}
bool CPlayer::isCardInHolding(std::string cardname)
{
  for(int i = 0;i < static_cast<int>(Holding.size());i++)
  {
    if(Holding[i]->GetName() == cardname)
    {
      return true;
    }
  }
  return false;
}
void CPlayer::RemoveHolding(const CCard * card)
{
  for(int i = 0;i < static_cast<int>(Holding.size());i++)
  {
    if(Holding[i]->GetID() == card->GetID())
    {
      Holding.erase(Holding.begin() + i);
      break;
    }
  }
}
void CPlayer::RemoveEquipment(const CCard * card)
{
  for(int i = 0;i < static_cast<int>(Equipment.size());i++)
  {
    if(Equipment[i]->GetID() == card->GetID())
    {
      Equipment.erase(Equipment.begin() + i);
      break;
    }
  }
}
void CPlayer::SetPosition(int position)
{
  this->Position = position;
}
void CPlayer::SetAttacked(bool attacked)
{
  this->Attacked = attacked;
}
void CPlayer::SetDead(bool dead)
{
  this->Dead = dead;
}
void CPlayer::SetAttackRange(int attackRange)
{
  this->AttackRange = attackRange;
}
void CPlayer::SetAddRange(int addRange)
{
  this->AddRange = addRange;
}
void CPlayer::SetMinusRange(int minusRange)
{
  this->MinusRange = minusRange;
}
