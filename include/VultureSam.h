#include "Character.h"
class CRoom;

class CCharacterSam : public CCharacter
{
public:
  CCharacterSam(CRoom * room);
  static void OnDeath(CRoom * room, CPlayer * deadPerson, CPlayer * attacker);
};
