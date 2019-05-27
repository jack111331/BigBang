#pragma once
#include "MessageMediator.h"
#include <string>
class CColleague
{
public:
  CColleague(CMessageMediator * mediator);
  void SendMessage(std::string action, std::string message);
  virtual void ReceiveMessage(std::string message);
  virtual ~CColleague();

  void SetState(int State);
  int GetState() const;
protected:
  CMessageMediator * mediator;
  int State = false;
};
