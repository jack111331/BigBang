#include "Character.h"

class CCharacterBart : public CCharacter
{
public:
  CCharacterBart();
  ~CCharacterBart();
  static void OnLossBlood(CRoom * room, CPlayer * loser);
};
