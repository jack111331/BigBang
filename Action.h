#pragma once
#include <string>

class CPlayer;
class CPlague;
class CCard;
class CRoom;

namespace NSAction
{
  bool Attack(CRoom * room, CPlayer * attacker, CPlayer * attackee, std::string dodgeByCard);
  void RecoverHealth(CPlayer * target, int health);
  void DrawCardFromPlague(CPlague * plague, CPlayer * drawer);
  void ChooseCardFromPlayer(CPlayer * chooser, CPlayer * choosee);
  void DrawCardFromPlayer(CPlayer * drawer, CPlayer * drawee);
  void FoldCard(CPlayer * folder, CCard * card, CPlague * DiscardPlague);
}
