#pragma once

#include "Card.h"

class CEquipmentCard : public CCard
{
public:
  CEquipmentCard(CRoom * room, int number, Suit suit);
  int GetAttackRange() const;
  int GetDefendRange() const;
  bool isMultiAttack() const;
  void SetAttackRange(int attackRange);
  void SetDefendRange(int defendRange);
  void SetMultiAttack(bool multiAttack);
  void UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target);
private:
  int Type;
  int AttackRange;
  int DefendRange;
  bool MultiAttack;
};
