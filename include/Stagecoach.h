#pragma once
#include "Card.h"
#include "Player.h"
class CRoom;
class CStagecoach : public CCard
{
public:
  CStagecoach(CRoom * room, int number, Suit suit);
  void UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target);
};
