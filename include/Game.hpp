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
    Game() = default;
    Game(std::shared_ptr<battlegame::Game> game);
    std::shared_ptr<battlegame::Player>  addPlayer(std::size_t x, std::size_t y);
    void initGame();
    void FillOrders(std::vector<battlegame::OrderArmy> &orders);
    void performOrder(const battlegame::OrderArmy &order);
    void print() const;

  private:
    std::vector<std::shared_ptr<Player>> _players;
    std::pair<int,int> _position;
    std::size_t numberOfPlayer = 0;
};

} //battlegame