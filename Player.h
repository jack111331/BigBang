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

class CRoom;

class CPlayer
{
public:
  void DrawCard(CRoom * room);
  void Attack(CRoom * room, CPlayer * target);
  void UseCard(CRoom * room, CCard * card, CPlayer * target);
  void FoldCard(CRoom * room, CCard * card);

  const std::string & GetName() const;
  CCharacter * GetCharacter();
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
  bool isCardInHolding(std::string cardname);
  void RemoveHolding(const CCard * card);
  void RemoveEquipment(const CCard * card);
  void SetPosition(int position);
  void SetAttacked(bool attacked);
  void SetDead(bool dead);
  void SetAttackRange(int attackRange);
  void SetAddRange(int addRange);
  void SetMinusRange(int minusRange);
protected:
  //不是interface的原因: 因為我有可能用到Class的東西
  CCharacter * Character = nullptr;
  std::vector<CCard *> Holding;
  std::vector<CCard *> Equipment;
private:
  std::string Name;
  Team Identity;
  int HP;
  int MaxHP;
  int Position;
  int DrawPerRound;
  //Weapon??
  bool Attacked; //是否已攻擊
  bool Dead; //是否處於死亡狀態
  int AttackRange;
  int AddRange; //別人看自己的距離
  int MinusRange; //自己看別人的距離
};
