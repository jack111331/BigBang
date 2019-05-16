#include <iostream>
#include "LoungeManage.h"
#include "MessageMediator.h"
#include "CommunicateFacade.h"

int main()
{
  CConcreteMessageMediator * MessageMediator = new CConcreteMessageMediator(new CLoungeManage);
  CCommunicateFacade * CommunicateFacade = new CCommunicateFacade(MessageMediator);
  while(1)
  {
    
  }
}
