#pragma once
#include <cstring>
#include <iostream>

#include "Player.hpp"
#include "OrderArmy.hpp"

namespace battlegame {

class Game
{
  public:
    Game() = default;
    Game(const battlegame::Game &game);
    battlegame::Player &addPlayer(std::size_t x, std::size_t y);
    void initGame();
    void FillOrders(std::vector<battlegame::OrderArmy> &orders);
    void performOrder(const battlegame::OrderArmy &order);
    void print() const;
    void performPotentialFights();

  private:
    std::vector<Player> _players;
    std::pair<int,int> _position;
    std::size_t _numberOfPlayer{0};
    static const std::size_t BOARD_SIZE{10};
};

} //battlegame
