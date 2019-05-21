#include "Character.h"
#include "DrawCardFactory.h"
class CRoom;

class CCharacterRose : public CCharacter
{
public:
  CCharacterRose(CRoom * room);
  ~CCharacterRose();
};
