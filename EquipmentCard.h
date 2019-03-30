#pragma once

#include "Card.h"

class CEquipmentCard : public CCard
{
public:
  int GetType() const;
  void SetType(int type);
private:
  int Type;
};
