#include "Character.h"
#include "DrawCardFactory.h"
class CRoom;

class CCharacterLafayette : public CCharacter
{
public:
  CCharacterLafayette(CRoom * room);
  static void OnRoundEnd(CRoom * room, CPlayer * RoundEnder);
  ~CCharacterLafayette();
};
