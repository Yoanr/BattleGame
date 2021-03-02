#include "Movement.hpp"

#include <exception>
#include <stdexcept>

namespace battlegame {

    std::pair<int, int> getPairposition(movement& mv)
    {
        std::pair<int, int> position;
        switch(mv) {
            case movement::up :
                position = std::make_pair(0,-1);
                break;
            case movement::down :
                    position = std::make_pair(0,1);
                    break;
            case movement::left :
                    position = std::make_pair(-1,0);
                    break;
            case movement::right :
                    position = std::make_pair(1,0);
                    break;
            case movement::upLeft :
                    position = std::make_pair(-1,-1);
                    break;
            case movement::upRight :
                    position = std::make_pair(1,-1);
                    break;
            case movement::downLeft :
                    position = std::make_pair(-1,1);
                    break;
            case movement::downRight :
                    position = std::make_pair(1,1);
                    break;
            default :
                    throw std::runtime_error("this movement doesn't exist");
                    break;
        }
        return position;
    }
} // battlegame
