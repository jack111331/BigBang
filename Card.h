#pragma once
#include <string>
#include <map>
#include <vector>

class CPlayer;
class CRoom;

enum class Suit
{
  Spade, //黑桃
  Heart, //紅心
  Diamond, //方塊
  Club //梅花
};

class CCard
{
public:
  CCard();
  virtual ~CCard();
  virtual void UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target) = 0;
  std::string GetName() const;
  std::string GetFeature() const;
  int GetNumber() const;
  Suit GetSuit() const;
  int GetID() const;
  int GetTypeID() const;
  static int GetTypeID(std::string cardname);

  void SetName(std::string name);
  void SetFeature(std::string feature);
  void SetNumber(int number);
  void SetSuit(Suit suit);
  void SetID(int id);
  static void SetTypeID(std::string cardname);
protected:
  static int CurrentID;
private:
  std::string Name;
  std::string Feature;
  int Number;
  Suit CardSuit;
  int ID;
  static std::map<std::string, int> TypeMap;
};
