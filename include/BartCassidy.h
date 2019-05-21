#include "Character.h"

class CCharacterBart : public CCharacter
{
public:
  CCharacterBart(CRoom * room);
  ~CCharacterBart();
  static void OnLossBlood(CRoom * room, CPlayer * loser, CPlayer * attacker);
};
