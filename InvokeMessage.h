#pragma once

class CPlayer;
class CCard;

namespace NSInvokeMessage
{
  void InvokeShowHolding(CPlayer * shower, CPlayer * showee);
  bool InvokeRevolt(CPlayer * revolter, CCard * card);
}
