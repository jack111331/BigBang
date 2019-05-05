#pragma once
#include <stdint.h>
#include <string>
#include "HandleMessage.h"
#include "MessageMediatorColleague.h"

class CUser : public CColleague
{
public:
  CUser(CMessageMediator * mediator);
  void RetriveDataFromDB();
  void ReceiveMessageAndUpdate(const std::string & message);
  void SetID(uint32_t ID);
  std::string GetName();
  int GetMoney();
  int GetWin();
  int GetLose();
  uint32_t GetID();
  ~CUser();
private:
  std::string name;
  int money;
  int win;
  int lose;
  uint32_t ID;
};
