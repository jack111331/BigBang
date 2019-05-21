#pragma once
#include <string>
#include <map>
#include <vector>

class CPlayer;
class CRoom;

enum class Suit
{
  Spade = 0, //黑桃
  Heart, //紅心
  Diamond, //方塊
  Club //梅花
};

class CCard
{
public:
  CCard(CRoom * room, int Number, Suit suit);
  virtual ~CCard();
  virtual void UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target) = 0;
  std::string GetName() const;
  std::string GetFeature() const;
  int GetNumber() const;
  Suit GetSuit() const;
  int GetID() const;
  CPlayer * GetOwner() const;
  CRoom * GetInRoom() const;

  void SetName(std::string name);
  void SetFeature(std::string feature);
  void SetNumber(int number);
  void SetSuit(Suit suit);
  void SetID();
  void ChangeOwner(CPlayer * owner);
protected:
  static uint32_t CurrentID;
private:
  std::string Name;
  std::string Feature;
  int Number;
  Suit CardSuit;
  int ID;
  CPlayer * Owner;
  CRoom * InRoom;
};
