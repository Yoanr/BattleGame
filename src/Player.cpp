#include <iostream>
#include <stdexcept>

#include "Player.hpp"

battlegame::Player::Player(std::size_t& id, std::size_t &x, std::size_t &y)
{
    this->_id = id;
    this->_spawn.first = x;
    this->_spawn.second = y;
}

void battlegame::Player::addArmy(std::size_t power)
{
    this->_armies.emplace_back(_numberOfArmy,power,_spawn);
    _numberOfArmy++;
}

void battlegame::Player::addArmy(std::size_t power,std::size_t x,std::size_t y)
{
    this->_armies.emplace_back(_numberOfArmy,power,std::make_pair(x,y));
    _numberOfArmy++;
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

void battlegame::Player::getOrders(std::vector<battlegame::OrderArmy> &ordres) const
{
    for(const auto& army: _armies)
    {
        std::cout << "### Order - Player "+std::to_string(_id)+ " - Army "+std::to_string(army.getId())+"\n";
        std::cout << "### Movement possible: up = 0, down = 1, left = 2, right = 3, upLeft = 4, upRight = 5, downLeft = 6, downRight = 7\n> ";
        int movementchoice;
        do{
            std::cin >> movementchoice;
            std::cout <<std::endl;
        if(movementchoice < 0 || movementchoice > 7)
        {
            std::cout << "Please enter a movement between 0 and 7 included: " << std::endl;
        }
        }
        while(movementchoice < 0 || movementchoice > 7);

        ordres.emplace_back(OrderArmy(this->_id,army.getId(),static_cast<battlegame::movement>(movementchoice)));
    }
}

void battlegame::Player::print() const
{
    std:: cout << "# Player "+ std::to_string(this->getId()) << std::endl;
    for(const auto& army: this->_armies)
    {
         std:: cout << "- Army "+ std::to_string(army.getId())+ " (position: [" + std::to_string(army.getPosition().first)+","+std::to_string(army.getPosition().second)+"] , power: " + std::to_string(army.getPower()) + ")"<< std::endl;
    }
    std::cout << std::endl;
}

 std::size_t battlegame::Player::getSquareTotalPower(const std::size_t& i, const  std::size_t& j) const
 {
    std::size_t squareTotalPower{0};
    for(const auto& army: this->_armies)
    {
        if(army.getPosition().first == i && army.getPosition().second == j)
        {
            squareTotalPower += army.getPower();
        }
    }
    return squareTotalPower;
 }

 void battlegame::Player::kill(const std::size_t& i, const  std::size_t& j)
 {
     for (auto it = _armies.begin(); it != _armies.end();)
        {
            if ( it->getPosition().first == i && it->getPosition().second == j)
            {
                it = _armies.erase(it);
            }
            else
            {
                ++it;
            }
        }
 }
