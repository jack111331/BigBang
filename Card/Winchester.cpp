#include "../WeaponCard.h"
#include "../Player.h"
#include <string>

class CWinchester : public CWeaponCard
{
public:
  void InitCard();
  bool UseCardEffect(CPlayer & myself, std::vector<CPlayer> & allPlayer);
};
void CWinchester::InitCard()
{
  const std::string Name("Bart Cassidy");
  const std::string Feature("Draw one card while HP decrease one point.");
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
bool CWinchester::UseCardEffect(CPlayer & myself, std::vector<CPlayer> & allPlayer)
{
  //No any effect
}
