#include <iostream>

#include "Game.hpp"
#include "Player.hpp"

std::shared_ptr<battlegame::Player> battlegame::Game::addPlayer(std::size_t x, std::size_t y)
{
    std::shared_ptr<Player> player = std::make_shared<Player>(numberOfPlayer,x,y);
    this->_players.emplace_back(player);
    numberOfPlayer++;
    return player;
}

void battlegame::Game::initGame()
{
    std::shared_ptr<battlegame::Player> player1 =  this->addPlayer(0,0);
    player1->addArmy(2,2,2);
    player1->addArmy(1,2,3);

    std::shared_ptr<battlegame::Player> player2 =  this->addPlayer(1,1);
    player1->addArmy(2,4,3);
}

std::vector<battlegame::OrderArmy>  battlegame::Game::getOrders()
{
        std::vector<battlegame::OrderArmy> ordres;
       // ordres.emplace_back(std::make_unique<OrderArmy>(playerId,armyId,battlegame::movement));
    for(const auto& player: _players)
    {
        player->getOrders(ordres);
    }
    return ordres;
}