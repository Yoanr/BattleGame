#pragma once

#include <vector>
#include <memory>
#include <utility>

#include "Army.hpp"
#include "Movement.hpp"

namespace battlegame {

  class OrderArmy
  {
    public:
        OrderArmy(std::size_t playerId, std::size_t armyId, battlegame::movement mvt);
        std::size_t _playerId;
        std::size_t _armyId;
        battlegame::movement _mvt;
  };
} //battlegame