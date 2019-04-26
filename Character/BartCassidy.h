#include "../Character.h"

class CCharacterBart : public CCharacter
{
  void InitCharacter();
  void OnAttacked(CPlayer * attacker, CPlayer * attackee);
};
