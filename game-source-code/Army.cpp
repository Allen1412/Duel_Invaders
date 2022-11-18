#include "Army.h"

Army::Army(const unsigned& capx,
    const unsigned& capy,
    const Direction& dir,
    const bool& isDown,
    const float& xpos,
    const float& ypos,
    bool isLower)
{

    capacityX = capx;
    capacityY = capy;
    goingDown = isDown;
    init = dir;
    x = xpos;
    y = ypos;

    auto capa = (ScreenDimensions::_Screen_Height / GameConstants::enemyHeight);
    if(capacityY > capa)
        throw InvalidRowsOfArmy{};

    lower = isLower;

    initial_tme = clock();

    alive = true;

    auto space_between_enemies = (GameConstants::enemyHeight);

    for(auto i = 0u; i < capacityY; i++) {

        if((x > (ScreenDimensions::_Screen_Width - GameConstants::enemyWidth)) ||
            (x + i * space_between_enemies < GameConstants::enemyWidth) ||
            (y + i * space_between_enemies >= (ScreenDimensions::_Screen_Height - GameConstants::enemyHeight)) ||
            (y + i * space_between_enemies < GameConstants::enemyHeight))
            throw InvalidArmyInitialPosition{};
        else {

            if(lower) {
                auto arm = std::make_shared<Armada>(capacityX, init, goingDown, x, y + i * space_between_enemies);
                army.push_back(arm);
            } else {
                auto arm = std::make_shared<Armada>(capacityX, init, goingDown, x, y - i * space_between_enemies);
                army.push_back(arm);
            }
        }
    }
}

void Army::setState()
{
    if(army.size() == 0)
        alive = false;
}

void Army::move()
{

    if(delay()) {

        auto a = false, b = false, c = false, d = false;

        for(auto i = 0u; i < army.size(); i++) {

            if(army.at(i)->direc() == 2)
                a = true;
            else if(army.at(i)->direc() == 4)
                b = true;
            else if(army.at(i)->direc() == 1)
                c = true;
            else if(army.at(i)->direc() == 3)
                d = true;
        }

        if(a)
            move_all_army(Direction::Right, true);
        else if(b)
            move_all_army(Direction::Left, true);
        else if(c)
            move_all_army(Direction::Right, false);
        else if(d)
            move_all_army(Direction::Left, false);
    }
}

bool Army::delay()
    {

        delta_time = clock() - initial_tme;

        if((delta_time / 1000.f) >= 0.5f) {
            initial_tme = clock();
            return true;
        }

        return false;
    }

void Army::move_all_army(const Direction& dir, const bool& isTurning)
    {

        for(unsigned i = 0; i < army.size(); i++) {

            if(!isTurning)
                army.at(i)->moving_all(dir);
            else
                army.at(i)->turning_all(dir);
        }
    }