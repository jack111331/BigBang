#pragma once

#include <string>
#include <vector>
#include "Character.h"
#include "Card.h"

enum class Team
{
  Sergeant,
  ChiefSergeant,
  BadAss,
  Traitor
};

class CPlayer
{
public:
  bool DrawCard();
  bool Attack();
  bool UseCard(CCard & card, std::vector<CPlayer *> & allPlayer);
  bool TossCard();

  const std::string & GetName() const;
  const CCharacter * GetCharacter() const;
  Team GetIdentity() const;
  int GetHP() const;
  int GetMaxHP() const;
  const std::vector<CCard *> & GetHolding() const;
  const std::vector<CCard *> & GetEquipment() const;
  int GetPosition() const;
  bool isDead() const;
  int GetAttackRange() const;
  int GetAddRange() const;
  int GetMinusRange() const;
  bool GetCanBombo() const;

  void SetName(const std::string & name);
  void SetCharacter(CCharacter * character);
  void SetIdentity(Team identity);
  void SetHP(int HP);
  void SetMaxHP(int maxHP);
  void AddHolding(CCard * card);
  void AddEquipment(CCard * card);
  bool isCardInHolding(const CCard & card);
  void RemoveHolding(const CCard & card);
  void RemoveEquipment(const CCard & card);
  void SetPosition(int position);
  void isDead(bool dead);
  void SetAttackRange(int attackRange);
  void SetAddRange(int addRange);
  void SetMinusRange(int minusRange);
  void SetCanBombo(bool canCombo);

private:
  std::string Name;
  CCharacter * Character;
  Team Identity;
  int HP;
  int MaxHP;
  std::vector<CCard *> Holding;
  std::vector<CCard *> Equipment;
  int Position;
  //Weapon??
  bool Dead;
  int AttackRange;
  int AddRange;
  int MinusRange;
  bool CanCombo;
};
