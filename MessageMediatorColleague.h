#pragma once
#include "MessageMediator.h"
#include <string>
class CColleague
{
public:
  CColleague(CMessageMediator * mediator);
  void SendMessage(std::string action, std::string message);
protected:
  CMessageMediator * mediator;
};
