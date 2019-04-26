#include "Room.h"

CRoom::CRoom()
{
}
void CRoom::PlayerJoin(CPlayer * player)
{
  playerList.push_back(player);
}
CPlague & CRoom::GetPlague()
{
  return this->plague;
}
std::vector<CPlayer *> & CRoom::GetPlayerList()
{
  return this->playerList;
}
CRoom::~CRoom()
{
  playerList.clear();
}
