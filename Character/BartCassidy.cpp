#include "../Character.h"
#include <string>

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
void CCharacterBart::InitCharacter()
{
  const std::string Name("Bart Cassidy");
  const std::string Feature("Draw one card while HP decrease one point.");
  const int MaxHP = 4;
  SetName(Name);
  SetFeature(Feature);
  SetID();
  SetMaxHP(MaxHP);
}
bool CCharacterBart::BeAttacked(CPlague & plague, CPlayer & myself, CPlayer & target, std::vector<CPlayer *> & allPlayer)
{

}
