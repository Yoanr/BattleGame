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

    this->_game.print();

    do {
        std::cout << "### BattleGame ROUND " + std::to_string(_numberOfRounds) + " ### "<< std::endl;
        std::cout << std::endl;
        _game.FillOrders(orders);

        battlegame::Game nextState = this->perform(this->_game,orders);

        this->_game = nextState;
        this->_game.print();
        orders.clear();

        _numberOfRounds++;
        checkIfWantToQuitGame();

    } while (!_quitGame);
}

battlegame::Game battlegame::GameManager::perform(const battlegame::Game& previousState, std::vector<battlegame::OrderArmy> &orders)
{
    battlegame::Game tmpGame = previousState;
    for(const auto& order: orders)
    {
       tmpGame.performOrder(order);
    }

    tmpGame.performPotentialFights();

    return tmpGame;
}

void battlegame::GameManager::checkIfWantToQuitGame()
{
    std::cout << "Do you want to quit the game? y/n:" << std::endl;
    std::string movementchoice;

    std::cin >> movementchoice;
    if(movementchoice == "y")
    {
        _quitGame = true;
    }
}
