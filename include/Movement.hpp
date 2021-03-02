#pragma once

#include <utility>

namespace battlegame {
    enum movement {up, down, left, right, upLeft, upRight, downLeft, downRight};
    std::pair<int, int> getPairposition(movement& mv);

} //battlegame
