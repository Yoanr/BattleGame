#pragma once
#include <cstring>
#include "Player.hpp"
#include "OrderArmy.hpp"
#include "GameInterface.hpp"
#include "OrderArmy.hpp"

namespace battlegame {

class Game : GameInterface
{
  public:
    Game() = default;
    std::shared_ptr<battlegame::Player>  addPlayer(std::size_t x, std::size_t y);
    void initGame();
    std::vector<battlegame::OrderArmy>  getOrders();

  private:
    std::vector<std::shared_ptr<Player>> _players;
    std::pair<int,int> _position;
    std::size_t numberOfPlayer = 0;
    //Game *perform(Game *etatPrecedent, std::vector<battlegame::OrderArmy*> &ordres) override;
};

} //battlegame