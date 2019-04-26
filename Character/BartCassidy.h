#include "../Character.h"

class CCharacterBart : public CCharacter
{
  void InitCharacter();
  static void OnAttacked(CRoom * room, CPlayer * attacker, CPlayer * attackee);
};
