#include "Character.h"

class CRoom;

class CCharacterJack : public CCharacter
{
public:
  CCharacterJack(CRoom * room);
  void DrawCard(CRoom * room, CPlayer * myself);
};
