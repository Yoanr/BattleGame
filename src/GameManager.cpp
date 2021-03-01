#include "GameManager.hpp"

#include <iostream>
#include <cstdlib>

#include "OrderArmy.hpp"
#include <memory>

battlegame::GameManager::GameManager()
{
    this->game.initGame();
}

void battlegame::GameManager::idle()
{
    std::vector<battlegame::OrderArmy>  orders;
    bool quitGame{false};

     this->game.print();

    do {
        std::cout << "### BattleGame ###" << std::endl;
        game.FillOrders(orders);

        battlegame::Game nextState = this->perform(this->game,orders);
        this->game.print();
        std::cout << "idle::previousgame: "+ std::to_string(this->game.id) << std::endl;
        nextState.print();
        std::cout << "idle::tmpgame: "+ std::to_string(nextState.id) << std::endl;


    } while (!quitGame);
}

battlegame::Game battlegame::GameManager::perform(const battlegame::Game& previousState, std::vector<battlegame::OrderArmy> &orders)
{
   
    battlegame::Game tmpGame = previousState;

    std::cout << "Perform::previousgame: "+ std::to_string(previousState.id) << std::endl;
    std::cout << "Perform::tmpgame: "+ std::to_string(tmpGame.id) << std::endl;

    for(const auto& order: orders)
    {
       tmpGame.performOrder(order);
    }
    return tmpGame;
}