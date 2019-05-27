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
void CColleague::SetState(int State)
{
  this->State = State;
}
int CColleague::GetState() const
{
  return this->State;
}
CColleague::~CColleague()
{

}
