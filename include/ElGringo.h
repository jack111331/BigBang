#include "Character.h"
#include "DrawCardFactory.h"
class CRoom;

class CCharacterGringo : public CCharacter
{
public:
  CCharacterGringo(CRoom * room);
  static void OnLossBlood(CRoom * room, CPlayer * loser, CPlayer * attacker);
  ~CCharacterGringo();
};
