#include "../WeaponCard.h"
#include "../Player.h"

class CWinchester : public CWeaponCard
{
public:
  bool UseCardEffect(CPlayer & myself, std::vector<CPlayer> & allPlayer);
};

bool CWinchester::UseCardEffect(CPlayer & myself, std::vector<CPlayer> & allPlayer)
{
  myself.SetAttackRange(5);
  return true;
}
