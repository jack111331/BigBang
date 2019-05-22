#pragma once
#include "Card.h"
#include "Player.h"
class CRoom;
class CMissed : public CCard
{
public:
  CMissed(CRoom * room, int number, Suit suit);
};
