#include "Bullet.h"


Bullet::Bullet(const float& x, const float& y)
    : MoveableCharacter()
{
    setSize(GameConstants::playerWidth_or, GameConstants::playerHeight_or, GameConstants::bulletObjectWidth,
        GameConstants::bulletObjectHeight);
    this->setSpeed(_bulletSpeed);

    if(x > (ScreenDimensions::_Screen_Width - GameConstants::bulletObjectWidth) ||
        x < GameConstants::bulletObjectWidth ||
        y > (ScreenDimensions::_Screen_Height - GameConstants::bulletObjectHeight) ||
        y < GameConstants::bulletObjectHeight)
            throw InvalidInitialBulletPosition{ };
            
    xCod = x;
    yCod = y;
    setPosition(xCod, yCod);
}

void Bullet::move(const Direction& direction)
{
    if(direction == Direction::Up) {
        if(getPosition().yCoord > this->getSize().height_) {
            move_Up();
        } else
            setActiveState(false);
    }

    if(direction == Direction::Down) {
        if(getPosition().yCoord > this->getSize().height_ &&
            getPosition().yCoord < ScreenDimensions::_Screen_Height - this->getSize().height_) {
            move_Down();
        } else
            setActiveState(false);
    } else
        return;
}