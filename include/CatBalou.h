#pragma once
#include "Card.h"
#include "Player.h"
class CRoom;
class CCatBalou : public CCard
{
public:
  CCatBalou(CRoom * room, int number, Suit suit);
  bool UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target);
};
