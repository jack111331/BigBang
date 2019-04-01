#include "../WeaponCard.h"
#include "../Player.h"
#include <string>

class CWinchester : public CWeaponCard
{
public:
  CWinchester();
  void InitCard();
  bool UseCardEffect(CPlayer & myself, CPlayer & target, std::vector<CPlayer> & allPlayer);
};
CWinchester::CWinchester()
{
  InitCard();
}
void CWinchester::InitCard()
{
  const std::string Name("Winchester");
  const std::string Feature("Attack range increased to 5.");
  constexpr int Number = 8;
  constexpr Suit suit = Suit::Spade;
  SetName(Name);
  SetFeature(Feature);
  SetNumber(Number);
  SetSuit(suit);

  constexpr bool multiAttack = 0;
  constexpr int attackRange = 5;
  SetMultiAttack(multiAttack);
  SetAttackRange(attackRange);
}
bool CWinchester::UseCardEffect(CPlayer & myself, CPlayer & target, std::vector<CPlayer> & allPlayer)
{
  //No any effect
}
