#pragma once

#include "Card.h"

class CWeaponCard : public CCard
{
public:
  int GetAttackRange() const;
  bool isMultiAttack() const;
  void SetAttackRange(int attackRange);
  void SetMultiAttack(bool multiAttack);
  void UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target);
private:
  int AttackRange;
  bool MultiAttack;
};
