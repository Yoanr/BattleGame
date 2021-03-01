#pragma once
#include <cstring>
#include <iostream>

#include "Player.hpp"
#include "OrderArmy.hpp"
#include "OrderArmy.hpp"

namespace battlegame {

class Game
{
  public:
    Game();
    Game(const battlegame::Game &game);
    battlegame::Player &addPlayer(std::size_t x, std::size_t y);
    void initGame();
    void FillOrders(std::vector<battlegame::OrderArmy> &orders);
    void performOrder(const battlegame::OrderArmy &order);
    void print() const;
    int id;

  private:
    std::vector<Player> _players;
    std::pair<int,int> _position;
    std::size_t numberOfPlayer = 0;
};

} //battlegame