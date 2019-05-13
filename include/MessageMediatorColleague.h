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
protected:
  CMessageMediator * mediator;
};
