#include "../Character.h"
#include <string>

class CCharacterBart : public CCharacter
{
  void InitCharacter();
  bool DrawCard(CPlague & plague, CPlayer & myself, std::vector<CPlayer *> & allPlayer) = 0;
  bool Attack() = 0;
  bool BeAttacked() = 0;
  bool TossCard() = 0;
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
bool CCharacterBart::DrawCard(CPlague & plague, CPlayer & myself, std::vector<CPlayer *> & allPlayer)
{

}
bool CCharacterBart::Attack()
{

}
bool CCharacterBart::BeAttacked()
{

}
bool CCharacterBart::TossCard()
{

}
