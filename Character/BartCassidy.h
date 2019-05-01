#include "../Character.h"

class CCharacterBart : public CCharacter
{
  CCharacterBart();
  ~CCharacterBart();
  static void OnLossBlood(CRoom * room, CPlayer * loser);
};
