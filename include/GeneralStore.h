#pragma once
#include "Card.h"
#include "Player.h"
class CRoom;
class CGeneralStore : public CCard
{
public:
  CGeneralStore(CRoom * room, int number, Suit suit);
  bool UseCardEffect(CRoom * room, CPlayer * myself, CPlayer * target);
};
