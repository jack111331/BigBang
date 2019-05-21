#include "Character.h"
#include "DrawCardFactory.h"
class CRoom;

class CCharacterWilly : public CCharacter
{
public:
  CCharacterWilly(CRoom * room);
  ~CCharacterWilly();
};
