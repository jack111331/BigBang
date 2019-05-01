#pragma once
#include <string>
#include "DrawCard.h"
namespace NSDrawCardFactory
{
  IDrawCardFromPlayer * DrawCard(std::string DrawCardMethod);
}
