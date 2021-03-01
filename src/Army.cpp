#include <stdexcept>
#include <iostream>

#include <Army.hpp>

battlegame::Army::Army(std::size_t& id, std::size_t &power, std::pair<std::size_t,std::size_t> position) : _id(id),_power(power), _position(position)
{
}

battlegame::Army::Army(Army &army)
{
    this->_id =  army._id;
    this->_power = army._power;
    this->_position = army._position;
}

std::size_t battlegame::Army::getPower() const
{
    return this->_power;
}
 std::size_t battlegame::Army::getId() const
{
    return this->_id;
}

std::pair<std::size_t,std::size_t> battlegame::Army::getPosition() const
{
    return this->_position;
}

void battlegame::Army::move(battlegame::movement movement)
{
    std::pair<int, int> direction;

            try {
                direction = battlegame::getPairposition(movement);
            }
            catch(const std::runtime_error& error)
            {
                std::cout << error.what() << std::endl;
            }

    int tmpX = 0, tmpY = 0;
    tmpX = this->_position.first + direction.first;
    tmpY = this->_position.second + direction.second;

    if(tmpX > 0 && tmpY > 0)
    {
        this->_position.first = tmpX;
        this->_position.second = tmpY;
    }
    else
    {
        throw std::runtime_error("this movement isn't possible!");
    }
}