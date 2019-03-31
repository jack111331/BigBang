#pragma once
#include <string>
#include <vector>

class CPlayer;

enum class Suit
{
  Spade, //黑桃
  Heart, //紅心
  Diamond, //方塊
  Club //梅花
};

class ICard
{
public:
  virtual void InitCard() = 0;
  virtual bool UseCardEffect(CPlayer & myself, std::vector<CPlayer *> & allPlayer) = 0;
};

class CCard
{
public:
  bool UseCard(CPlayer & myself, std::vector<CPlayer *> & allPlayer);
  std::string GetName() const;
  std::string GetFeature() const;
  int GetNumber() const;
  Suit GetSuit() const;
  int GetID() const;
  void SetName(std::string name);
  void SetFeature(std::string feature);
  void SetNumber(int number);
  void SetSuit(Suit suit);
  void SetID(int id);
protected:
  ICard * CardType = nullptr;
  static int CurrentID;
private:
  std::string Name;
  std::string Feature;
  int Number;
  Suit CardSuit;
  int ID;
};
