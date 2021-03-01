#include <memory>

#include "GameManager.hpp"

int main()
{
    std::unique_ptr<battlegame::GameManager>  gameManager = std::make_unique<battlegame::GameManager>();

    gameManager->idle();
}
