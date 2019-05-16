#include "DrawCard.h"

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
  //invoke one player to show holding to another player and draw card animation
  drawer->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapShowCard(drawer, drawee));
  drawee->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapShowCard(drawer, drawee));
  drawer->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapChooseCard(drawer, drawee));
  while(!drawer->isEndChooseCard())
  {

  }
}
void CRandomChooseCard::DrawCard(CPlayer * drawer, CPlayer * drawee)
{
  //invoke client to show draw card animation
}
