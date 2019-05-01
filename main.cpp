#include <iostream>

#include "SocketFacade.h"

static constexpr int port = 28715;

int main()
{
  CLoungeManage * LoungeManager = new CLoungeManage;
  CSocketFacade SocketFacade(port, LoungeManager);

}
