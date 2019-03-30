#pragma once

#include "Card.h"

class CWeaponCard : public CCard
{
public:
  int GetAttackRange() const;
  bool isMultiBang() const;
  void SetAttackRange(int attackRange);
  void SetMultiBang(bool multiBang);
private:
  int AttackRange;
  bool MultiBang;
};
