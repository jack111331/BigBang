#include "Character.h"
#include "Card.h"
#include "Plague.h"
#include "Player.h"
int CCharacter::CurrentID = 0;

bool CCharacter::DrawCard(CPlague & plague, CPlayer & myself, CPlayer & target, std::vector<CPlayer *> & allPlayer)
{
  //Define Normal active
  constexpr int DrawCardAmount = 2;
  for(int i = 0;i < DrawCardAmount;i++)
  {
    CCard * DrawedCard = plague.RandomChooseCard();
    if(DrawedCard != nullptr)
    {
      myself.AddHolding(DrawedCard);
      plague.RemoveCardFromPlague(DrawedCard);
    }
    else
    {
      return false;
    }
  }
  return true;
}
bool CCharacter::Attack(CPlague & plague, CPlayer & myself, CPlayer & target, std::vector<CPlayer *> & allPlayer)
{
  // 先不考慮連發槍卡的連擊
  if(!myself.isAttacked())
  {
    target.GetCharacter()->BeAttacked(plague, target, myself, allPlayer);
    myself.SetAttacked(true);
  }
  return true;
}
bool CCharacter::BeAttacked(CPlague & plague, CPlayer & myself, CPlayer & target, std::vector<CPlayer *> & allPlayer)
{
  return true;
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
void CCharacter::SetID(int id)
{
  this->ID = CurrentID++;
}
void CCharacter::SetMaxHP(int maxHP)
{
  this->MaxHP = maxHP;
}
