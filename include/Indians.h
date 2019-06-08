#pragma once
#include "Card.h"
#include "Player.h"
class CRoom;
class CIndians : public CCard
{
public:
  CIndians(CRoom * room, int number, Suit suit);
  bool UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target);
};
