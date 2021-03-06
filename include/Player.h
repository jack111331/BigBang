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
  void UseCard(CRoom * room, int cardID, CPlayer * target);
  void FoldCard(CRoom * room, int cardID);
  void GetCardFromPlayer(CPlayer * Giver, uint32_t cardID);
  void RemoveCardFromMyself(uint32_t cardID);

  CUser * GetUser();
  CCharacter * GetCharacter();
  Team GetIdentity() const;
  int GetHP() const;
  int GetMaxHP() const;
  const std::vector<CCard *> & GetHolding() const;
  CCard * GetRandomHolding();
  int GetHoldingAmount() const;
  const CCard * GetEquipment() const;
  int GetPosition() const;
  bool isAttacked() const;
  bool isDead() const;
  bool isHasMultiAttack() const;
  int GetAttackRange() const;
  int GetAddRange() const;
  int GetMinusRange() const;
  int BusyWaiting(int Action);

  void SetUser(CUser * user);
  void SetCharacter(CCharacter * character);
  void SetIdentity(Team identity);
  void SetHP(int HP);
  void SetMaxHP(int maxHP);
  void AddHolding(CCard * card);
  CCard * GetCardInHolding(std::string cardname);
  CCard * GetCardInHolding(int cardID);
  void RemoveHolding(const CCard * card);
  void ChangeEquipment(CCard * equipment);
  void SetPosition(int position);
  void SetAttacked(bool attacked);
  void SetDead(bool dead);
  void SetMultiAttack(bool HasMultiAttack);
  void SetAttackRange(int attackRange);
  void SetAddRange(int addRange);
  void SetMinusRange(int minusRange);
  ~CPlayer();
private:
  CUser * User;
  Team Identity;
  int HP;
  int MaxHP;
  int Position;
  CCharacter * Character = nullptr;
  std::vector<CCard *> Holding;
  CCard * Equipment = nullptr;
  bool Attacked = false; //是否已攻擊
  bool Dead = false; //是否處於死亡狀態
  bool HasMultiAttack = false;
  int AttackRange = 1;
  int AddRange = 0; //別人看自己的距離
  int MinusRange = 0; //自己看別人的距離
};
