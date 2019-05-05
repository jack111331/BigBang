#include "SocketSet.h"

CSocketSet::ReceiveMessage(std::string message, CColleague * colleague)
{
  if(message == "New User")
  {
    SocketSet.insert(std::pair<CUser *, CHandleClientSocket *>(newUser, static_cast<CHandleClientSocket *>(colleague)))
  }
}
