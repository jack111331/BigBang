#include "Card.h"
bool CCard::UseCard(CPlayer & myself, std::vector<CPlayer *> & allPlayer)
{
  if(CardType != nullptr)
  {
    return CardType->UseCardEffect(myself, allPlayer);
  }
  return false;
}
std::string CCard::GetName() const
{
  return this->Name;
}
std::string CCard::GetFeature() const
{
  return this->Feature;
}
int CCard::GetNumber() const
{
  return this->Number;
}
int CCard::GetSuit() const
{
  return this->Suit;
}
int CCard::GetID() const
{
  return this->ID;
}
void CCard::SetName(std::string name)
{
  this->Name = name;
}
void CCard::SetNumber(int number)
{
  this->Number = number;
}
void CCard::SetSuit(int suit)
{
  this->Suit = suit;
}
void CCard::SetID(int id)
{
  this->ID = id;
}
void CCard::SetFeature(std::string feature)
{
  this->Feature = feature;
}
