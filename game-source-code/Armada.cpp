#include "Armada.h"

Armada::Armada(const unsigned& cap, const Direction& dir, const bool& isDown, const float& xpos, const float& ypos)
{
    capacity = cap;
    x = xpos;
    y = ypos;
    goingDown = isDown;
    initial_movement = dir;
    alive = true;

    auto allowed_cap = (ScreenDimensions::_Screen_Width) / (GameConstants::enemyWidth);

    if(cap >= allowed_cap)
        throw InvalidNumberOfEnemies{};

    auto space_between_enemies = (GameConstants::enemyWidth);

    // armada.reserve(capacity);

    // std::cout <<armada.size()<< " armada.size()" << std::endl;

    for(auto i = 0u; i < capacity; i++) {
        if((x + i * space_between_enemies > (ScreenDimensions::_Screen_Width - GameConstants::enemyWidth)) ||
            (x + i * space_between_enemies < GameConstants::enemyWidth) ||
            (y >= (ScreenDimensions::_Screen_Height - GameConstants::enemyHeight)) || (y < GameConstants::enemyHeight))
            throw InvalidArmadaInitialPosition{};
        else {
            auto enem = std::make_shared<Enemy>(initial_movement, x + i * space_between_enemies, y);
            armada.push_back(enem);
        }
    }
}

void Armada::setState()
{
    if(armada.size() == 0)
        alive = false;
}

void Armada::moving_all(const Direction& dir)
{

    for(auto i = 0u; i < armada.size(); i++) {
        armada.at(i)->move(dir);
    }
}

void Armada::turning_all(const Direction& dir)
{

    for(auto i = 0u; i < armada.size(); i++) {
        armada.at(i)->turning(dir, goingDown);
    }
}

int Armada::direc()
{
    // right movement until screen edge
    if((armada.at(armada.size() - 1u)->getPosition().xCoord <
           ScreenDimensions::_Screen_Width - GameConstants::enemyWidth) &&
        (armada.at(armada.size() - 1u)->getDirection() == Direction::Right))
        return 1;

    // turning from right direction
    if((armada.at(armada.size() - 1u)->getPosition().xCoord >=
           ScreenDimensions::_Screen_Width - GameConstants::enemyWidth) &&
        (armada.at(armada.size() - 1u)->getDirection() == Direction::Right))
        return 2;

    // left movement until screen edge
    if((armada.at(0u)->getPosition().xCoord > GameConstants::enemyWidth) &&
        (armada.at(armada.size() - 1u)->getDirection() == Direction::Left))
        return 3;

    // turning from left position
    if((armada.at(0u)->getPosition().xCoord <= GameConstants::enemyWidth) &&
        (armada.at(armada.size() - 1u)->getDirection() == Direction::Left))
    return 4;
}

// void Armada::move_all(const Direction& dir, const bool& turning)
//{
//
//    for(auto i = 0u; i < armada.size(); i++) {
//        if(!turning)
//            armada.at(i)->move(dir);
//        else
//            armada.at(i)->turning(dir, goingDown);
//    }
//}