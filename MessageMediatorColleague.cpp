#include "MessageMediatorColleague.h"

CColleague::CColleague(CMessageMediator * mediator)
{
  this->mediator = mediator;
}
void CColleague::SendMessage(std::string action, std::string message)
{
  mediator->HandleObjectMessage(action, this, message);
}
