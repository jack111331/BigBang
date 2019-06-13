#pragma once
#include "Plague.h"
#include "Player.h"
#include "GameEventObserver.h"
#include <vector>

class CLounge;
class CUser;

enum class WinCondition
{
  SergeantWin, //警長
  BadAssWin, //副警長
  TraitorWin, //歹徒
  None
};

class CRoom
{
public:
  CRoom(CLounge * lounge);
  void PlayerJoin(CUser * user);
  CLounge * GetLounge() const;
  CPlague * GetPlague();
  CPlague * GetDiscardPlague();
  std::vector<CPlayer *> & GetPlayerList();
  void LoopToCheckHaveCharacter();
  WinCondition isGameEnd();
  void AutoChooseTeam();
  void InitPlayerState();
  void InitPlayerRoundState(CPlayer * player);
  int GetDistance(CPlayer * Watcher, CPlayer * Watchee);
  int GetAlivePlayer();
  CPlayer * GetNextPlayer(CPlayer * CurrentPlayer);
  CPlayer * GetPlayerByPosition(int Position);
  CGameEventObserver * GetRoomEvent() const;
  void UpdatePlayerPublicInfo();
  static void GameLoop(CRoom * room);
  void EndGame(WinCondition GameEndState);
  ~CRoom();
private:
  CLounge * lounge;
  CPlague * plague;
  CPlague * discardPlague;
  std::vector<CPlayer *> playerList;
  CGameEventObserver * RoomEvent;
};
