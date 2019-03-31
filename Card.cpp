#include "Card.h"
int CCard::CurrentID = 0;
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
Suit CCard::GetSuit() const
{
  return this->CardSuit;
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
void CCard::SetSuit(Suit suit)
{
  this->CardSuit = suit;
}
void CCard::SetID(int id)
{
  this->ID = CurrentID++;
}
void CCard::SetFeature(std::string feature)
{
  this->Feature = feature;
}
