#include "ClientEventObserver.h"

void CClientEventObserver::registerOnConnect(void (*ConnectFunction)())
{
  ConnectListener.push_back(ConnectFunction);
}
void CClientEventObserver::registerOnDisconnect(void (*DisconnectFunction)())
{
  DisconnectListener.push_back(DisconnectFunction);
}
void CClientEventObserver::CallConnect()
{
  for(auto i = ConnectListener.begin();i != ConnectListener.end();++i)
  {
    (*i)();
  }
}
void CClientEventObserver::CallDisconnect()
{
  for(auto i = ConnectListener.begin();i != ConnectListener.end();++i)
  {
    (*i)();
  }
}
void CClientEventObserver::unregisterOnConnect(void (*ConnectFunction)())
{
  for(auto i = ConnectListener.begin();i != ConnectListener.end();++i)
  {
    if(*i == ConnectFunction)
    {
      ConnectListener.erase(i);
    }
  }
}
void CClientEventObserver::unregisterOnDisconnect(void (*DisconnectFunction)())
{
  for(auto i = DisconnectListener.begin();i != DisconnectListener.end();++i)
  {
    if(*i == DisconnectFunction)
    {
      DisconnectListener.erase(i);
    }
  }
}
