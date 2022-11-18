#include "Enemy.h"
Enemy::Enemy(const Direction& init_dir, const float& x, const float& y)
    : MoveableCharacter()
{
    direc = init_dir;
    setSize(GameConstants::enemyWidth_or, GameConstants::enemyHeight_or, GameConstants::enemyWidth,
        GameConstants::enemyHeight);
    if(x > ScreenDimensions::_Screen_Width - GameConstants::enemyWidth || x < GameConstants::enemyWidth ||
        y > ScreenDimensions::_Screen_Height - GameConstants::enemyHeight || y < GameConstants::enemyHeight)
        throw InvalidEnemyInitialPosition{};
    setPosition(x, y);
    setActiveState(true);
}

void Enemy::move(const Direction& dir)
{

    switch(dir) {
    case Direction::Right:
        if(getPosition().xCoord >= (ScreenDimensions::_Screen_Width - GameConstants::enemyWidth))
            return;
        setSpeed(enemyHorizontalSpeed);
        move_Right();
        break;
    case Direction::Left:
        if(getPosition().xCoord <=GameConstants::enemyWidth)
            return;
        setSpeed(enemyHorizontalSpeed);
        move_Left();
        break;
    case Direction::Down:
        if(getPosition().yCoord >= (ScreenDimensions::_Screen_Height - GameConstants::enemyHeight))
            return;
        setSpeed(enemyVerticalSpeed);
        move_Down();
        break;
    case Direction::Up:
        if(getPosition().yCoord <= GameConstants::enemyHeight)
            return;
        setSpeed(enemyVerticalSpeed);
        move_Up();
        break;
    default:
        return;
    }
}









void Enemy::turning(const Direction& dir, const bool& goingDown)
{
    if(goingDown) {
        switch(dir) {
        case Direction::Right:
            direc = Direction::Down;
            move(direc);
            direc = Direction::Left;
            //move(direc);
            break;
        case Direction::Left:
            direc = Direction::Down;
            move(direc);
            direc = Direction::Right;
            //move(direc);
            break;
        default:
            return;
        }

    } else {
        switch(dir) {
        case Direction::Right:
            direc = Direction::Up;
            move(direc);
            direc = Direction::Left;
           // move(direc);
            break;
        case Direction::Left:
            direc = Direction::Up;
            move(direc);
            direc = Direction::Right;
            //move(direc);
            break;
        default:
            return;
        }
    }
}