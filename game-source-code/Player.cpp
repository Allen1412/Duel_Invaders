#include "Player.h"
Player::Player(const float& x, const float& y)
    : MoveableCharacter()
{
    setSpeed(_playerSpeed);
    setSize(GameConstants::playerWidth_or, GameConstants::playerHeight_or, GameConstants::playerWidth,
        GameConstants::playerHeight);

    if(x > (ScreenDimensions::_Screen_Width - GameConstants::playerWidth) || x < GameConstants::playerWidth ||
        y > (ScreenDimensions::_Screen_Height - GameConstants::playerHeight) || y < GameConstants::playerHeight)
        throw InvalidPosition{};
    setPosition(x, y);
}

void Player::move(const Direction& _direction)
{
    switch(_direction) {
    case Direction::Left:
        if(getPosition().xCoord <= GameConstants::playerWidth)
           { return;}
        move_Left();
        break;
    case Direction::Right:

        if(getPosition().xCoord >= ScreenDimensions::_Screen_Width - GameConstants::playerWidth) {
            return;
        }
        move_Right();
        break;
        case Direction::Up:
        return;
        break;
        case Direction::Down:
        return;
        break;
    default:
        return;
    }
}

void Player::shoot()
{
    setShooting(true);
}

void Player::setShooting(const bool& _flag)
{
    _shoot = _flag;
}
