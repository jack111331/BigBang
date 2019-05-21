#include "Character.h"
#include "DrawCardFactory.h"
class CRoom;

class CCharacterPaul : public CCharacter
{
public:
  CCharacterPaul(CRoom * room);
  ~CCharacterPaul();
};
