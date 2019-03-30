#pragma once

#include <string>
#include <vector>

class CPlayer;
class CPlague;

class ICharacter
{
public:
  virtual void InitCharacter();
  virtual bool DrawCard(CPlague & plague, CPlayer & myself, std::vector<CPlayer *> & allPlayer) = 0;
  virtual bool Attack() = 0;
  virtual bool BeAttacked() = 0;
  virtual bool TossCard() = 0;
};

class CCharacter : public ICharacter
{
public:
  const std::string & GetName() const;
  const std::string & GetFeature() const;
  int GetID() const;
  int GetMaxHP() const;

  void SetName(const std::string & name);
  void SetFeature(const std::string & feature);
  void SetID(int id);
  void SetMaxHP(int maxHP);
protected:
  static int CurrentID;
private:
  std::string Name;
  std::string Feature;
  int ID;
  int MaxHP;
};
