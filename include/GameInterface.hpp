#pragma once

#include "OrderArmy.hpp"
#include "Game.hpp"

namespace battlegame {

class GameInterface
{
  protected:
    virtual battlegame::Game perform(const battlegame::Game &previousState, std::vector<battlegame::OrderArmy> &ordres) = 0;
};

} //battlegame
