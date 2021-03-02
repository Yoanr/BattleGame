cmake_minimum_required(VERSION 3.13)

include_directories(include)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Werror -std=gnu++17")

add_executable(
        battleGame
        main.cpp
        src/Army.cpp
        src/Player.cpp
        src/Movement.cpp
        src/Game.cpp
        src/GameManager.cpp
        include/Army.hpp
        include/Player.hpp
        include/Movement.hpp
        include/Game.hpp
        include/OrderArmy.hpp
        include/GameInterface.hpp
        include/GameManager.hpp
        )

set_target_properties(
        battleGame
        PROPERTIES
        CXX_STANDARD 17
)
