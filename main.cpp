#include <iostream>
#include <cstdlib>

#include "Game.hpp"
#include "OrderArmy.hpp"
#include <memory>

int main()
{
    std::unique_ptr<battlegame::Game>  game = std::make_unique<battlegame::Game>();

    game->initGame();
    
    std::vector<battlegame::OrderArmy>  orders;
    bool quitGame{false};
    
    {
        std::cout << "### BattleGame ###" << std::endl;
        orders =  game->getOrders();

    } while (!quitGame);
}
