#pragma once

#include <utility>
#include <exception>
#include <stdexcept>

namespace battlegame {
    enum movement {up, down, left, right, upLeft, upRight, downLeft, downRight};
    std::pair<int, int> getPairposition(movement& mv);
} //battlegame



