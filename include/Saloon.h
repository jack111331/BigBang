#pragma once
#include "Card.h"
#include "Player.h"
class CRoom;
class CSaloon : public CCard
{
public:
  CSaloon(CRoom * room, int number, Suit suit);
  bool UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target);
};
