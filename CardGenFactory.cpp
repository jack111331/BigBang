#include "CardGenFactory.h"
#include "Winchester.h"
#include "Barrel.h"
#include "Carabine.h"
#include "Jail.h"
#include "Mustang.h"
#include "Remington.h"
#include "Saloon.h"
#include "Schofield.h"
#include "Stagecoach.h"
#include "Volcanic.h"
#include "Wellsfargo.h"
#include "Bang.h"
#include "Missed.h"
#include "Indians.h"
#include "Gatling.h"
#include "Duel.h"
#include "Beer.h"
#include "Panic.h"
#include "CatBalou.h"
#include "Dynamite.h"
#include <string>

CCard * NSCardGenFactory::createCard(std::string Cardname, CRoom * room, int Number, Suit suit)
{
  if(Cardname == "Winchester")
  {
    return new CWinchester(room, Number, suit);
  }
  else if(Cardname == "Barrel")
  {
    return new CBarrel(room, Number, suit);
  }
  else if(Cardname == "Carabine")
  {
    return new CCarabine(room, Number, suit);
  }
  else if(Cardname == "Jail")
  {
    return new CJail(room, Number, suit);
  }
  else if(Cardname == "Mustang")
  {
    return new CMustang(room, Number, suit);
  }
  else if(Cardname == "Remington")
  {
    return new CRemington(room, Number, suit);
  }
  else if(Cardname == "Saloon")
  {
    return new CSaloon(room, Number, suit);
  }
  else if(Cardname == "Schofield")
  {
    return new CSchofield(room, Number, suit);
  }
  else if(Cardname == "Volcanic")
  {
    return new CVolcanic(room, Number, suit);
  }
  else if(Cardname == "Stagecoach")
  {
    return new CStagecoach(room, Number, suit);
  }
  else if(Cardname == "Wells fargo")
  {
    return new CWellsfargo(room, Number, suit);
  }
  else if(Cardname == "Bang!")
  {
    return new CBang(room, Number, suit);
  }
  else if(Cardname == "Missed!")
  {
    return new CMissed(room, Number, suit);
  }
  else if(Cardname == "Indians!")
  {
    return new CIndians(room, Number, suit);
  }
  else if(Cardname == "Gatling")
  {
    return new CGatling(room, Number, suit);
  }
  else if(Cardname == "Duel")
  {
    return new CDuel(room, Number, suit);
  }
  else if(Cardname == "Beer")
  {
    return new CBeer(room, Number, suit);
  }
  else if(Cardname == "Cat Balou")
  {
    return new CCatBalou(room, Number, suit);
  }
  else if(Cardname == "Panic!")
  {
    return new CPanic(room, Number, suit);
  }
  else if(Cardname == "Dynamite")
  {
    return new CDynamite(room, Number, suit);
  }
  else
  {
    return nullptr;
  }
}
CCard * NSCardGenFactory::createCard(char const * Cardname, CRoom * room, int Number, Suit suit)
{
  return createCard(std::string(Cardname), room, Number, suit);
}
