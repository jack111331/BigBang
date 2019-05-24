#pragma once
#include <map>
#include <string>
#include <thread>
#include <sys/types.h>

class CColleague;
class CUser;
class CHandleClientSocket;
class CLoungeManage;

class CMessageMediator
{
public:
  CMessageMediator();
  virtual void HandleObjectMessage(std::string action, CColleague * colleague, std::string message) = 0;
  ~CMessageMediator();
protected:
  std::map<CUser *, CHandleClientSocket *> SocketSet;
  std::thread ProcessThread;
  static timeval timeout;//second, usecond
private:
};
class CConcreteMessageMediator : public CMessageMediator
{
public:
  CConcreteMessageMediator();
  void HandleObjectMessage(std::string action, CColleague * colleague, std::string message);
  std::map<CUser *, CHandleClientSocket *> & GetSocketSet();
  static void SocketProcessFunc(CConcreteMessageMediator * myself);
  ~CConcreteMessageMediator();
};
