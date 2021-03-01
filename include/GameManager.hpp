#pragma once
#include <cstring>
#include "Player.hpp"
#include "OrderArmy.hpp"
#include  "GameInterface.hpp"
#include "Game.hpp"

namespace battlegame {

class GameManager : GameInterface
{
    public:
        GameManager();
        void idle();

    private:
        battlegame::Game perform(const battlegame::Game &previousState, std::vector<battlegame::OrderArmy> &ordres) override;
        battlegame::Game game;

};

} //battlegame