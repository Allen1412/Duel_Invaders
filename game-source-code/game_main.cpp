#include "GamePlay.h"
#include <memory>
#include <iostream>
int main()
{
    auto game_ = std::make_unique<GamePlay>();
    game_->ExecuteLogic();

    return 0;
}