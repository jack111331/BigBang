#pragma once

#include <string>
#include <vector>

class CPlayer;
class CPlague;

class ICharacter
{
public:
  virtual void InitCharacter() = 0;
  virtual void DrawCard(CPlague & plague, CPlayer & myself, CPlayer & target, std::vector<CPlayer *> & allPlayer) = 0;
  virtual void Attack(CPlague & plague, CPlayer & myself, CPlayer & target, std::vector<CPlayer *> & allPlayer) = 0;
  virtual void BeAttacked(CPlague & plague, CPlayer & myself, CPlayer & target, std::vector<CPlayer *> & allPlayer) = 0;
  virtual void TossCard() = 0;
};

class CCharacter : public ICharacter
{
public:
  void DrawCard(CPlague & plague, CPlayer & myself, CPlayer & target, std::vector<CPlayer *> & allPlayer);
  void Attack(CPlague & plague, CPlayer & myself, CPlayer & target, std::vector<CPlayer *> & allPlayer);
  void BeAttacked(CPlague & plague, CPlayer & myself, CPlayer & target, std::vector<CPlayer *> & allPlayer);
  void TossCard();

  const std::string & GetName() const;
  const std::string & GetFeature() const;
  int GetID() const;
  int GetMaxHP() const;

  void SetName(const std::string & name);
  void SetFeature(const std::string & feature);
  void SetID();
  void SetMaxHP(int maxHP);
protected:
  static int CurrentID;
private:
  std::string Name;
  std::string Feature;
  int ID;
  int MaxHP;
};
