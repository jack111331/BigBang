#pragma once
#include "Plague.h"
#include "Player.h"
#include <vector>
class CRoom
{
public:
  CRoom();
  void PlayerJoin(CPlayer * player);
  CPlague * GetPlague();
  CPlague * GetDiscardPlague();
  std::vector<CPlayer *> & GetPlayerList();
  ~CRoom();
private:
  CPlague * plague;
  CPlague * discardPlague;
  std::vector<CPlayer *> playerList;
};
