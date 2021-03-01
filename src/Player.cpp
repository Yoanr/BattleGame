#include <iostream>
#include <stdexcept>

#include "Player.hpp"

battlegame::Player::Player(std::size_t& id, std::size_t &x, std::size_t &y)
{
    this->_id = id;
    this->_spawn.first = x;
    this->_spawn.second = y;
}

std::size_t battlegame::Player::getId() const
{
    return this->_id;
}

void battlegame::Player::addArmy(std::size_t power)
{
    this->_armies.emplace_back(numberOfArmy,power,_spawn);
    numberOfArmy++;
}

void battlegame::Player::addArmy(std::size_t power,std::size_t x,std::size_t y)
{
    this->_armies.emplace_back(numberOfArmy,power,std::make_pair(x,y));
    numberOfArmy++;
}

void battlegame::Player::MoveArmy(const std::size_t &id,const battlegame::movement& movement)
{
    for(auto& army: _armies) {
        if(army.getId() == id)
        {
            try {
                army.move(movement);
            }
            catch(const std::runtime_error& error)
            {
                std::cout << error.what() << std::endl;
            }

        }
    }
}

void battlegame::Player::getOrders(std::vector<battlegame::OrderArmy> &ordres)
{
    for(const auto& army: _armies)
    {
        std::cout << "Choose army "+std::to_string(army.getId())+ " movement [between 0 and 7] for player "+std::to_string(_id)+"\n";
        std::cout << "up, down, left, right, upLeft, upRight, downLeft, downRight" << std::endl;
        int movementchoice;
        std::cin >> movementchoice;
        ordres.emplace_back(OrderArmy(this->_id,army.getId(),static_cast<battlegame::movement>(movementchoice)));
    }
}

void battlegame::Player::print() const
{
    std:: cout << "Player "+ std::to_string(this->getId()) << std::endl;
    for(const auto& army: this->_armies)
    {
         std:: cout << "Army "+ std::to_string(army.getId())+ " [" + std::to_string(army.getPosition().first)+","+std::to_string(army.getPosition().second)+"] :" + std::to_string(army.getPower()) << std::endl;
    }
}