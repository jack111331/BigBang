#include "ClientEventObserver.h"
#include "User.h"
std::vector<void (*)(CUser * user)> CClientEventObserver::ConnectListener;
std::vector<void (*)(CUser * user)> CClientEventObserver::DisconnectListener;
void CClientEventObserver::registerOnConnect(void (*ConnectFunction)(CUser * user))
{
  ConnectListener.push_back(ConnectFunction);
}
void CClientEventObserver::registerOnDisconnect(void (*DisconnectFunction)(CUser * user))
{
  DisconnectListener.push_back(DisconnectFunction);
}
void CClientEventObserver::CallConnect(CUser * user)
{
  for(auto i = ConnectListener.begin();i != ConnectListener.end();++i)
  {
    (*i)(user);
  }
}
void CClientEventObserver::CallDisconnect(CUser * user)
{
  for(auto i = ConnectListener.begin();i != ConnectListener.end();++i)
  {
    (*i)(user);
  }
}
void CClientEventObserver::unregisterOnConnect(void (*ConnectFunction)(CUser * user))
{
  for(auto i = ConnectListener.begin();i != ConnectListener.end();++i)
  {
    if(*i == ConnectFunction)
    {
      ConnectListener.erase(i);
    }
  }
}
void CClientEventObserver::unregisterOnDisconnect(void (*DisconnectFunction)(CUser * user))
{
  for(auto i = DisconnectListener.begin();i != DisconnectListener.end();++i)
  {
    if(*i == DisconnectFunction)
    {
      DisconnectListener.erase(i);
    }
  }
}
