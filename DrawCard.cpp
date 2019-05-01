#include "DrawCard.h"
#include "InvokeMessage.h"

CDrawCardFromPlayer::CDrawCardFromPlayer(IDrawCardFromPlayer * Method)
{
  this->Strategy = Method;
}
void CDrawCardFromPlayer::DrawCardFromPlayer(CPlayer * drawer, CPlayer * drawee)
{
  Strategy->DrawCard(drawer, drawee);
}
void CChooseCard::DrawCard(CPlayer * drawer, CPlayer * drawee)
{
  //invoke one player to show holding to another player and draw card UI
  NSInvokeMessage::InvokeShowHolding(drawee, drawer);
}
void CRandomChooseCard::DrawCard(CPlayer * drawer, CPlayer * drawee)
{
  //invoke client to show draw card UI
}
