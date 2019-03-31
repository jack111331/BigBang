#pragma once

#include "Card.h"

class CWeaponCard : public CCard
{
public:
  int GetAttackRange() const;
  bool isMultiAttack() const;
  void SetAttackRange(int attackRange);
  void SetMultiAttack(bool multiAttack);
private:
  int AttackRange;
  bool MultiAttack;
};
