#include "Room.h"

CRoom::CRoom()
{
  this->plague = new CPlague;
  this->discardPlague = new CPlague;
}
void CRoom::PlayerJoin(CPlayer * player)
{
  playerList.push_back(player);
}
CPlague * CRoom::GetPlague()
{
  return this->plague;
}
CPlague * CRoom::GetDiscardPlague()
{
  return this->discardPlague;
}
std::vector<CPlayer *> & CRoom::GetPlayerList()
{
  return this->playerList;
}
CRoom::~CRoom()
{
  playerList.clear();
}
