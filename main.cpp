#include <iostream>
#include "LoungeManage.h"
#include "MessageMediator.h"
#include "CommunicateFacade.h"

int main()
{
  CConcreteMessageMediator * MessageMediator = new CConcreteMessageMediator();
  CCommunicateFacade * CommunicateFacade = new CCommunicateFacade(MessageMediator);
  while(1)
  {

  }
  delete CommunicateFacade;
}
