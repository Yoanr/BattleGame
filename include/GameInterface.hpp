#pragma once
#include <cstring>
#include "Player.hpp"
#include "OrderArmy.hpp"
#include "Game.hpp"

namespace battlegame {

class GameInterface
{
  protected:
    virtual std::shared_ptr<battlegame::Game> perform(std::shared_ptr<battlegame::Game> &previousState, std::vector<battlegame::OrderArmy> &ordres) = 0;
};

} //battlegame