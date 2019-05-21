#pragma once

#include <string>
#include <vector>

class CPlayer;
class CPlague;

class CRoom;

class CCharacter
{
public:
  CCharacter(CRoom * room);
  ~CCharacter();
  void DrawCard(CRoom * room, CPlayer * myself);
  void Attack(CRoom * room, CPlayer * myself, CPlayer * target);

  const std::string & GetName() const;
  const std::string & GetFeature() const;
  int GetID() const;
  int GetMaxHP() const;
  int GetDefaultAttackRange() const;
  int GetDefaultAddRange() const;
  int GetDefaultMinusRange() const;
  int GetDefaultMultiAttack() const;
  CRoom * GetInRoom() const;

  void SetName(const std::string & name);
  void SetFeature(const std::string & feature);
  void SetID();
  void SetMaxHP(int maxHP);
  void SetAttackRange(int AttackRange);
  void SetAddRange(int AddRange);
  void SetMinusRange(int MinusRange);
  void SetMultiAttack(bool HasMultiAttack);
protected:
  static int CurrentID;
private:
  std::string Name;
  std::string Feature;
  int ID;
  int MaxHP;
  int AttackRange;
  int AddRange;
  int MinusRange;
  bool HasMultiAttack;
  CRoom * InRoom;
};
