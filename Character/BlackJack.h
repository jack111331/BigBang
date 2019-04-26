#include "../Character.h"

class CRoom;

class CCharacterJack : public CCharacter
{
  void InitCharacter();
  bool DrawCard(CRoom * room, CPlayer * myself, CPlayer * target);
};
