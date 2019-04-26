#include "../Character.h"

class CCharacterJack : public CCharacter
{
  void InitCharacter();
  bool DrawCard(CPlague & plague, CPlayer & myself, CPlayer & target, std::vector<CPlayer *> & allPlayer);
};
