#pragma once
#include "Card.h"
#include "Player.h"
class CRoom;
class CGatling : public CCard
{
public:
  CGatling(CRoom * room, int number, Suit suit);
  bool UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target);
};
