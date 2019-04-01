#include "Character.h"
#include "Card.h"
#include "Plague.h"
#include "Player.h"
int CCharacter::CurrentID = 0;

void CCharacter::DrawCard(CPlague & plague, CPlayer & myself, CPlayer & target, std::vector<CPlayer *> & allPlayer)
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
  }
}
void CCharacter::Attack(CPlague & plague, CPlayer & myself, CPlayer & target, std::vector<CPlayer *> & allPlayer)
{
  if(!myself.isAttacked() || myself.isCardInHolding(CCard::GetTypeID(std::string("Volcanic"))))
  {
    target.GetCharacter()->BeAttacked(plague, target, myself, allPlayer);
    myself.SetAttacked(true);
  }
}
void CCharacter::BeAttacked(CPlague & plague, CPlayer & myself, CPlayer & target, std::vector<CPlayer *> & allPlayer)
{
  if(myself.isCardInHolding(CCard::GetTypeID(std::string("Miss!"))))
  {
//    myself.RemoveHolding()
  }
  else
  {
    myself.SetHP(myself.GetHP()-1);
  }
}
void CCharacter::TossCard()
{
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
