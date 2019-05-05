#pragma once
#include <string>
#include "MessageMediatorColleague.h"
class CUser;
class CHandleClientSocket;

class CSocketSet : public CColleague
{
public:
  void ReceiveMessage(std::string message, CColleague * colleague);
private:
  std::map<CUser *, CHandleClientSocket *> SocketSet;
}
