#include "GameManager.hpp"

#include <iostream>
#include <cstdlib>

#include "OrderArmy.hpp"
#include <memory>

battlegame::GameManager::GameManager()
{
    this->_game.initGame();
}

void battlegame::GameManager::idle()
{
    std::vector<battlegame::OrderArmy>  orders;
    bool quitGame{false};

     this->_game.print();

    do {
        std::cout << "### BattleGame ###" << std::endl;
        _game.FillOrders(orders);

        battlegame::Game nextState = this->perform(this->_game,orders);
        this->_game.print();
        nextState.print();


    } while (!quitGame);
}

battlegame::Game battlegame::GameManager::perform(const battlegame::Game& previousState, std::vector<battlegame::OrderArmy> &orders)
{
    battlegame::Game tmpGame = previousState;
    for(const auto& order: orders)
    {
       tmpGame.performOrder(order);
    }
    return tmpGame;
}
