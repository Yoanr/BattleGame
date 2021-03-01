#include <iostream>
#include <algorithm>

#include "Game.hpp"
#include "Player.hpp"
#include "global.h"


battlegame::Game::Game()
{
    id = global;
    global++;
}
battlegame::Game::Game(const battlegame::Game &game)
{
    //std::copy(game->_players.begin(), game->_players.end(), back_inserter(this->_players));
    this->_players = game._players;
    this->numberOfPlayer = game.numberOfPlayer;
    this->_position = game._position;
    id = global;
    global++;
}

battlegame::Player &battlegame::Game::addPlayer(std::size_t x, std::size_t y)
{
    this->_players.emplace_back(numberOfPlayer,x,y);
    numberOfPlayer++;
    return this->_players.back();
}

void battlegame::Game::initGame()
{
    auto& player1 =  this->addPlayer(0,0);
    player1.addArmy(2,2,2);
    player1.addArmy(1,2,3);

    auto& player2 =  this->addPlayer(1,1);
    player2.addArmy(2,4,3);
}

void battlegame::Game::FillOrders(std::vector<battlegame::OrderArmy> &orders)
{
    for(auto&& player: _players)
    {
        player.getOrders(orders);
    }
}

void battlegame::Game::performOrder(const battlegame::OrderArmy& order)
{
    std::cout << "performOrder: "+ std::to_string(id) << std::endl;
    for(auto&& player: _players)
    {
        if(player.getId() == order._playerId)
        {
            player.MoveArmy(order._armyId,order._mvt);
        }
    }
}

void battlegame::Game::print() const
{
    for(const auto& player: _players)
    {
        player.print();
    }
}