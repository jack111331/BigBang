#pragma once

#include <string>

class CPlayer;
class CCard;

namespace NSInvokeMessage
{
  void InvokeShowHolding(CPlayer * shower, CPlayer * showee);
  std::string InvokeGetChooseCard(CPlayer * chooser, CPlayer * choosee);
  bool InvokeRevolt(CPlayer * revolter, CCard * card);
}
