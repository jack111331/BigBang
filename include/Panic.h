#pragma once
#include "Card.h"
#include "Player.h"
class CRoom;
class CPanic : public CCard
{
public:
  CPanic(CRoom * room, int number, Suit suit);
  void UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target);
};
