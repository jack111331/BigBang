#include "ClientEventObserver.h"
#include "User.h"
std::map<void (*)(CUser * user), int> CClientEventObserver::ConnectListener;
std::map<void (*)(CUser * user), int> CClientEventObserver::DisconnectListener;
void CClientEventObserver::registerOnConnect(void (*ConnectFunction)(CUser * user))
{
  if(ConnectListener.find(ConnectFunction) == ConnectListener.end())
  {
    ConnectListener[ConnectFunction] = 0;
  }
  ConnectListener[ConnectFunction]++;
}
void CClientEventObserver::registerOnDisconnect(void (*DisconnectFunction)(CUser * user))
{
  if(DisconnectListener.find(DisconnectFunction) == DisconnectListener.end())
  {
    DisconnectListener[DisconnectFunction] = 0;
  }
  DisconnectListener[DisconnectFunction]++;
}
void CClientEventObserver::CallConnect(CUser * user)
{
  for(auto i = ConnectListener.begin();i != ConnectListener.end();++i)
  {
    (i->first)(user);
  }
}
void CClientEventObserver::CallDisconnect(CUser * user)
{
  for(auto i = DisconnectListener.begin();i != DisconnectListener.end();++i)
  {
    (i->first)(user);
  }
}
void CClientEventObserver::unregisterOnConnect(void (*ConnectFunction)(CUser * user))
{
  if(ConnectListener[ConnectFunction] <= 1)
  {
    ConnectListener.erase(ConnectFunction);
  }
  else
  {
    ConnectListener[ConnectFunction]--;
  }
}
void CClientEventObserver::unregisterOnDisconnect(void (*DisconnectFunction)(CUser * user))
{
  if(DisconnectListener[DisconnectFunction] <= 1)
  {
    DisconnectListener.erase(DisconnectFunction);
  }
  else
  {
    DisconnectListener[DisconnectFunction]--;
  }
}
