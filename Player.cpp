#include "Player.h"
#include "Plague.h"

bool CPlayer::DrawCard(CPlague & plague, std::vector<CPlayer *> & allPlayer)
{
  Character->DrawCard(plague, *this, allPlayer);
}
bool CPlayer::Attack(std::vector<CPlayer *> & allPlayer)
{
}
bool CPlayer::BeAttacked()
{
  Character->BeAttacked();
}
bool CPlayer::UseCard(CCard & card, std::vector<CPlayer *> & allPlayer)
{
  if(isCardInHolding(card))
  {
    card.UseCard(*this, allPlayer);
    RemoveHolding(card);
    return true;
  }
  return false;
}
bool CPlayer::TossCard()
{
  Character->TossCard();
}

const std::string & CPlayer::GetName() const
{
  return this->Name;
}
const ICharacter * CPlayer::GetCharacter() const
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
bool CPlayer::GetCanBombo() const
{
  return this->CanCombo;
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
bool CPlayer::isCardInHolding(const CCard & card)
{
  for(int i = 0;i < static_cast<int>(Holding.size());i++)
  {
    if(Holding[i]->GetID() == card.GetID())
    {
      return true;
    }
  }
  return false;
}
void CPlayer::RemoveHolding(const CCard & card)
{
  for(int i = 0;i < static_cast<int>(Holding.size());i++)
  {
    if(Holding[i]->GetID() == card.GetID())
    {
      Holding.erase(Holding.begin() + i);
      break;
    }
  }
}
void CPlayer::RemoveEquipment(const CCard & card)
{
  for(int i = 0;i < static_cast<int>(Equipment.size());i++)
  {
    if(Equipment[i]->GetID() == card.GetID())
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
void CPlayer::isDead(bool dead)
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
void CPlayer::SetCanBombo(bool canCombo)
{
  this->CanCombo = canCombo;
}
