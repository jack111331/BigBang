#include "MessageMediatorColleague.h"

CColleague::CColleague(CMessageMediator * mediator)
{
  this->mediator = mediator;
}
void CColleague::SendMessage(std::string action, std::string message)
{
  mediator->HandleObjectMessage(action, this, message);
}
void CColleague::ReceiveMessage(std::string message)
{

}
void CColleague::SetHandledAction(int HandledAction)
{
  this->HandledAction = HandledAction;
}
int CColleague::GetHandledAction() const
{
  return this->HandledAction;
}
void CColleague::SetActionResult(int Result)
{
  this->ActionResult = Result;
}
int CColleague::GetActionResult() const
{
  return this->ActionResult;
}
CColleague::~CColleague()
{

}
