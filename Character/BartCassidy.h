#include "../Character.h"

class CCharacterBart : public CCharacter
{
  void InitCharacter();
//  bool DrawCard(CPlague & plague, CPlayer & myself, CPlayer & target, std::vector<CPlayer *> & allPlayer);
// 代表用原本的DrawCard
//  bool Attack(CPlague & plague, CPlayer & myself, CPlayer & target, std::vector<CPlayer *> & allPlayer);
// 代表用原本的Attack
  bool BeAttacked(CPlague & plague, CPlayer & myself, CPlayer & target, std::vector<CPlayer *> & allPlayer);
//  bool TossCard();
// 代表用原本的TossCard
};
