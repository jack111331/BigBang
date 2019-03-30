#pragma once
#include <string>
#include <vector>

class CPlayer;

class ICard
{
public:
  virtual bool UseCardEffect(CPlayer & myself, std::vector<CPlayer *> & allPlayer) = 0;
};

class CCard : public ICard
{
public:
  bool UseCard(CPlayer & myself, std::vector<CPlayer *> & allPlayer);
  std::string GetName() const;
  std::string GetFeature() const;
  int GetNumber() const;
  int GetSuit() const;
  int GetID() const;
  void SetName(std::string name);
  void SetNumber(int number);
  void SetSuit(int suit);
  void SetID(int id);
  void SetFeature(std::string feature);
protected:
  ICard * CardType = nullptr;
private:
  std::string Name;
  std::string Feature;
  int Number;
  int Suit;
  int ID;
};
