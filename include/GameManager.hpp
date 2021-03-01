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
        std::shared_ptr<battlegame::Game> perform(std::shared_ptr<battlegame::Game>& previousState, std::vector<battlegame::OrderArmy> &ordres) override;
        std::shared_ptr<battlegame::Game> game;

};

} //battlegame