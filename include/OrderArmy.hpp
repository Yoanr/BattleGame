#pragma once

#include <utility>

#include "Movement.hpp"

namespace battlegame {

  class OrderArmy
  {
    public:
        OrderArmy(std::size_t playerId, std::size_t armyId, battlegame::movement mvt) : _playerId(playerId), _armyId(armyId), _mvt(mvt){}
        [[nodiscard]] std::size_t getPlayerId() const{ return this->_playerId;};
        [[nodiscard]] std::size_t getArmyId() const{ return this->_armyId;};
        [[nodiscard]] battlegame::movement getMovement() const{ return this->_mvt;};

    private:
        std::size_t _playerId;
        std::size_t _armyId;
        battlegame::movement _mvt;
  };

} //battlegame
