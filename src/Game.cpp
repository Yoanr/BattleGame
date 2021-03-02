#include <iostream>
#include <algorithm>

#include "Game.hpp"

battlegame::Game::Game(const battlegame::Game &game)
{
    this->_players = game._players;
    this->_numberOfPlayer = game._numberOfPlayer;
    this->_position = game._position;
}

battlegame::Player &battlegame::Game::addPlayer(std::size_t x, std::size_t y)
{
    this->_players.emplace_back(_numberOfPlayer,x,y);
    _numberOfPlayer++;
    return (this->_players.back());
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
    for(auto&& player: _players)
    {
        if(player.getId() == order.getPlayerId())
        {
            player.MoveArmy(order.getArmyId(),order.getMovement());
        }
    }
}

void battlegame::Game::print() const
{
    std::cout << "======" << std::endl;
    for(const auto& player: _players)
    {
        player.print();
    }
    std::cout << "======" << std::endl;
}

void battlegame::Game::performPotentialFights()
{
    std::size_t p0SquareTotalPower{0},p1SquareTotalPower{0};
    for(std::size_t i = 0; i < BOARD_SIZE; ++i)
    {
        for(std::size_t j = 0; j< BOARD_SIZE; ++j)
        {
            p0SquareTotalPower = _players[0].getSquareTotalPower(i,j);
            p1SquareTotalPower = _players[1].getSquareTotalPower(i,j);
            if(p0SquareTotalPower > 0 && p1SquareTotalPower > 0)
            {
                if(p1SquareTotalPower > p0SquareTotalPower)
                {
                    _players[0].kill(i,j);
                }
                else
                {
                    _players[1].kill(i,j);
                }
            }
        }
    }
}
