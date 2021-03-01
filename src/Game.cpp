#include <iostream>
#include <algorithm>

#include "Game.hpp"
#include "Player.hpp"


battlegame::Game::Game(std::shared_ptr<battlegame::Game> game)
{
    std::copy(game->_players.begin(), game->_players.end(), back_inserter(this->_players));
    this->numberOfPlayer = game->numberOfPlayer;
    this->_position = game->_position;
}

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
    player2->addArmy(2,4,3);
}

void battlegame::Game::FillOrders(std::vector<battlegame::OrderArmy> &orders)
{
    for(const auto& player: _players)
    {
        player->getOrders(orders);
    }
}

void battlegame::Game::performOrder(const battlegame::OrderArmy& order)
{

    for(const auto& player: _players)
    {
        if(player->getId() == order._playerId)
        {
            player->MoveArmy(order._armyId,order._mvt);
        }
    }
}

void battlegame::Game::print() const
{
    for(const auto& player: _players)
    {
        player->print();
    }
}