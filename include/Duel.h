#pragma once
#include "Card.h"
#include "Player.h"
class CRoom;
class CDuel : public CCard
{
public:
  CDuel(CRoom * room, int number, Suit suit);
  void UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target);
};
