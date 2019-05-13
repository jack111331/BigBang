#include "Character.h"

class CRoom;

class CCharacterJack : public CCharacter
{
public:
  CCharacterJack();
  void DrawCard(CRoom * room, CPlayer * myself);
};
