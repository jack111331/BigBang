#include "DrawCard.h"
#include "WrapInfo.h"
#include "Action.h"

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
  drawer->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapShowCard(drawer, drawee).dump());
  drawee->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapShowCard(drawer, drawee).dump());
  drawer->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapChooseCard(drawer, drawee, true).dump());
  drawer->BusyWaiting(11);
}
void CRandomChooseCard::DrawCard(CPlayer * drawer, CPlayer * drawee)
{
  //invoke client to show draw card animation
  drawer->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapShowCard(drawer, drawee).dump());
  drawee->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapShowCard(drawer, drawee).dump());
  NSAction::GiveCard(drawee, drawer, drawee->GetRandomHolding()->GetID());
}
