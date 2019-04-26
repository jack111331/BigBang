#pragma once
#include <stdint.h>
class CUser
{
public:
  CUser(int money, int win, int lose) : money(money), win(win), lose(lose)
  {

  }
  void RetriveDataFromDB();
  int GetMoney();
  int GetWin();
  int GetLose();
  ~CUser();
private:
  int money;
  int win;
  int lose;
  uint32_t ip;
};
