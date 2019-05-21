#pragma once
#include "Plague.h"
#include "Player.h"
#include "GameEventObserver.h"
#include <vector>

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
  CRoom();
  void PlayerJoin(CUser * user);
  CPlague * GetPlague();
  CPlague * GetDiscardPlague();
  std::vector<CPlayer *> & GetPlayerList();
  void LoopToCheckHaveCharacter();
  WinCondition isGameEnd();
  void AutoChooseTeam();
  void InitPlayerState();
  void InitPlayerRoundState(CPlayer * player);
  CPlayer * GetNextPlayer(CPlayer * CurrentPlayer);
  CPlayer * GetPlayerByPosition(int Position);
  CGameEventObserver * GetRoomEvent() const;
  void UpdatePlayerPublicInfo();
  static void GameLoop(CRoom * room);
  void EndGame(WinCondition GameEndState);
  ~CRoom();
private:
  CPlague * plague;
  CPlague * discardPlague;
  std::vector<CPlayer *> playerList;
  CGameEventObserver * RoomEvent;
};
