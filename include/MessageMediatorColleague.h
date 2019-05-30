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

  void SetHandledAction(int Action);
  int GetHandledAction() const;
  void SetActionResult(int Result);
  int GetActionResult() const;
protected:
  CMessageMediator * mediator;
  int HandledAction = -1;
  int ActionResult;
};
