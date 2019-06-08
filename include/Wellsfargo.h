#pragma once
#include "Card.h"
#include "Player.h"
class CRoom;
class CWellsfargo : public CCard
{
public:
  CWellsfargo(CRoom * room, int number, Suit suit);
  bool UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target);
};
