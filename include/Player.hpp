#pragma once

#include <vector>
#include <memory>
#include <utility>

#include "Army.hpp"
#include "Movement.hpp"
#include "OrderArmy.hpp"

namespace battlegame {

  class Player
  {
    public:
      Player(std::size_t& id,std::size_t &x, std::size_t &y);
      std::size_t getId() const;

      void addArmy(std::size_t power);
      void addArmy(std::size_t power,std::size_t x,std::size_t y);
      void MoveArmy(const std::size_t &id,const battlegame::movement& movement);
      void getOrders(std::vector<battlegame::OrderArmy> &ordres);


    private:
      std::vector<std::unique_ptr<Army>> _armies;
      std::size_t _id;
      std::pair<std::size_t,std::size_t> _spawn;
      std::size_t numberOfArmy = 0;

  };
} //battlegame