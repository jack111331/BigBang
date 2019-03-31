#pragma once

#include <string>
#include <vector>
#include "Character.h"
#include "Card.h"

enum class Team
{
  Sergeant, //警長
  ChiefSergeant, //副警長
  BadAss, //歹徒
  Traitor //叛徒
};

class CPlayer
{
public:
  bool DrawCard(CPlague & plague, CPlayer & target, std::vector<CPlayer *> & allPlayer);
  bool Attack(CPlague & plague, CPlayer & target, std::vector<CPlayer *> & allPlayer);
  bool BeAttacked(CPlague & plague, CPlayer & target, std::vector<CPlayer *> & allPlayer);
  bool UseCard(CCard & card, std::vector<CPlayer *> & allPlayer);
  bool TossCard();

  const std::string & GetName() const;
  ICharacter * GetCharacter();
  Team GetIdentity() const;
  int GetHP() const;
  int GetMaxHP() const;
  const std::vector<CCard *> & GetHolding() const;
  const std::vector<CCard *> & GetEquipment() const;
  int GetPosition() const;
  bool isAttacked() const;
  bool isDead() const;
  int GetAttackRange() const;
  int GetAddRange() const;
  int GetMinusRange() const;

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
  void SetAttacked(bool attacked);
  void SetDead(bool dead);
  void SetAttackRange(int attackRange);
  void SetAddRange(int addRange);
  void SetMinusRange(int minusRange);
protected:
  ICharacter * Character;

private:
  std::string Name;
  Team Identity;
  int HP;
  int MaxHP;
  std::vector<CCard *> Holding;
  std::vector<CCard *> Equipment;
  int Position;
  int DrawPerRound;
  //Weapon??
  bool Attacked; //是否已攻擊
  bool Dead; //是否處於死亡狀態
  int AttackRange;
  int AddRange; //別人看自己的距離
  int MinusRange; //自己看別人的距離
};
