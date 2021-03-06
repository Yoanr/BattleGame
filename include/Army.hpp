#pragma once

#include <utility>

#include "Movement.hpp"

namespace battlegame {

class Army
{
  public:
    Army(std::size_t& id,std::size_t &power,std::pair<std::size_t,std::size_t> position);
    Army(Army const &army);
    void move(battlegame::movement movement);

    [[nodiscard]] std::size_t getPower() const { return this->_power; }
    [[nodiscard]] std::size_t getId() const { return this->_id; }
    [[nodiscard]] std::pair<std::size_t,std::size_t> getPosition() const { return this->_position; }

  private:
    std::size_t _id;
    std::size_t _power{0};
    std::pair<int,int> _position;
};

} //battlegame
