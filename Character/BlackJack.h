#include "../Character.h"

class CRoom;

class CCharacterJack : public CCharacter
{
  CCharacterJack();
  void DrawCard(CRoom * room, CPlayer * myself);
};
