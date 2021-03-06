#pragma once
#include "Card.h"
#include "Player.h"
class CRoom;
class CBang : public CCard
{
public:
  CBang(CRoom * room, int number, Suit suit);
  bool UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target);
};
