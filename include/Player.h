#pragma once

#include <string>
#include <vector>
#include "Character.h"
#include "Card.h"

enum class Team
{
  Sergeant = 0, //警長
  ChiefSergeant = 1, //副警長
  BadAss = 2, //歹徒
  Traitor = 3 //叛徒
};

class CRoom;
class CUser;

class CPlayer
{
public:
  void DrawCard(CRoom * room);
  void Attack(CRoom * room, CPlayer * target);
  void UseCard(CRoom * room, std::string cardName, CPlayer * target);
  void FoldCard(CRoom * room, std::string cardName);

  CUser * GetUser();
  CCharacter * GetCharacter();
  Team GetIdentity() const;
  int GetHP() const;
  int GetMaxHP() const;
  const std::vector<CCard *> & GetHolding() const;
  int GetHoldingAmount() const;
  const std::vector<CCard *> & GetEquipment() const;
  int GetEquipmentAmount() const;
  const CCard * GetWeapon() const;
  int GetPosition() const;
  bool isAttacked() const;
  bool isDead() const;
  bool isEndUsingCard() const;
  int GetAttackRange() const;
  int GetAddRange() const;
  int GetMinusRange() const;

  void SetUser(CUser * user);
  void SetCharacter(CCharacter * character);
  void SetIdentity(Team identity);
  void SetHP(int HP);
  void SetMaxHP(int maxHP);
  void AddHolding(CCard * card);
  void AddEquipment(CCard * card);
  CCard * GetCardInHolding(std::string cardname);
  void RemoveHolding(const CCard * card);
  void RemoveEquipment(const CCard * card);
  void ChangeWeapon(CCard * weapon);
  void SetPosition(int position);
  void SetAttacked(bool attacked);
  void SetDead(bool dead);
  void SetEndUsingCard(bool endUsingCard);
  void SetAttackRange(int attackRange);
  void SetAddRange(int addRange);
  void SetMinusRange(int minusRange);
private:
  CUser * User;
  Team Identity;
  int HP;
  int MaxHP;
  int Position;
  CCharacter * Character = nullptr;
  std::vector<CCard *> Holding;
  std::vector<CCard *> Equipment;
  CCard * EquipedWeapon = nullptr;
  bool Attacked = false; //是否已攻擊
  bool Dead = false; //是否處於死亡狀態
  bool EndUsingCard = false;
  int AttackRange = 1;
  int AddRange = 0; //別人看自己的距離
  int MinusRange = 0; //自己看別人的距離
};
