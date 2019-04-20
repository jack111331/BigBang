#include "Card.h"
int CCard::CurrentID = 0;
std::map<std::string, int> CCard::TypeMap;
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
int CCard::GetTypeID() const
{
  return TypeMap[Name];
}
int CCard::GetTypeID(std::string cardname)
{
  if(TypeMap.find(cardname) != TypeMap.end())
  {
    return TypeMap[cardname];
  }
  return -1;
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
void CCard::SetTypeID(std::string Cardname)
{
  TypeMap[Cardname] = TypeMap.size();
}
