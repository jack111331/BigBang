#pragma once
#include "Card.h"
#include "Player.h"
class CRoom;
class CBeer : public CCard
{
public:
  CBeer(CRoom * room, int number, Suit suit);
  bool UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target);
  static void OnLossBlood(CRoom * room, CPlayer * loser, CPlayer * attacker);
};
