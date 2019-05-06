#pragma once
#include <stdint.h>
#include <string>
#include "HandleMessage.h"
#include "MessageMediatorColleague.h"
#include "Player.h"

class CUser : public CColleague
{
public:
  CUser(CMessageMediator * mediator);
  void RetriveDataFromDB();
  void ReceiveMessage(std::string message);
  //user的SendMessage已經有父類別的CColleague幫忙處理了
  void SetID(uint32_t ID);
  CPlayer * GetPlayer();
  std::string GetName();
  int GetMoney();
  int GetWin();
  int GetLose();

  void SetPlayer(CPlayer * player);
  void SetName(const std::string & name);
  void SetMoney(int money);
  void SetWin(int win);
  void SetLose(int lose);
  uint32_t GetID();
  ~CUser();
private:
  std::string name;
  int money;
  int win;
  int lose;
  uint32_t ID;
  CPlayer * player = nullptr;
};
