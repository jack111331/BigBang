#pragma once

#include "Card.h"

class CEquipmentCard : public CCard
{
public:
  int GetType() const;
  void SetType(int type);
  void UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target);
private:
  int Type;
};
