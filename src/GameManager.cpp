#include "GameManager.hpp"

#include <iostream>
#include <cstdlib>

#include "OrderArmy.hpp"
#include <memory>

battlegame::GameManager::GameManager()
{
    this->game = std::make_shared<battlegame::Game>();

    this->game->initGame();
}

void battlegame::GameManager::idle()
{
    std::vector<battlegame::OrderArmy>  orders;
    bool quitGame{false};

    {
        std::cout << "### BattleGame ###" << std::endl;
        game->FillOrders(orders);

        std::shared_ptr<battlegame::Game> nextState = this->perform(this->game,orders);

    } while (!quitGame);
}

std::shared_ptr<battlegame::Game> battlegame::GameManager::perform(std::shared_ptr<battlegame::Game>& previousState, std::vector<battlegame::OrderArmy> &orders)
{
    std::shared_ptr<battlegame::Game> tmpGame = std::make_shared<battlegame::Game>(previousState);
    for(const auto& order: orders)
    {
       tmpGame->performOrder(order);
    }
    return tmpGame;
}