#include "Card.h"
uint32_t CCard::CurrentID = 0;
CCard::CCard()
{

}
CCard::~CCard()
{

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
CPlayer * CCard::GetOwner() const
{
  return this->Owner;
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
void CCard::ChangeOwner(CPlayer * owner)
{
  this->Owner = owner;
}
