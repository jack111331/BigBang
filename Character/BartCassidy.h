#include "../Character.h"

class CCharacterBart : public CCharacter
{
  CCharacterBart();
  static void OnAttacked(CRoom * room, CPlayer * attacker, CPlayer * attackee);
};
