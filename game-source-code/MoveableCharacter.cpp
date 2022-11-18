#include "MoveableCharacter.h"

void MoveableCharacter::move(const Direction& _direction)
{
    switch(_direction) {
    case(Direction::Up):
        move_Up();
        break;
    case(Direction::Down):
        move_Down();
        break;
    case(Direction::Left):
        move_Left();
        break;
    case(Direction::Right):
        move_Right();
        break;
    default:
        return;
    }
}
void MoveableCharacter::move_Up()
{
    changePosition(0, -getSpeed());
}
void MoveableCharacter::move_Down()
{
    changePosition(0, getSpeed());
}
void MoveableCharacter::move_Left()
{
    changePosition(-getSpeed(), 0);
}

void MoveableCharacter::move_Right()
{
    changePosition(getSpeed(), 0);
}
void MoveableCharacter::setSpeed(const float& _speed)
{
    speed_ = _speed * delta;
}

void MoveableCharacter::changePosition(const float& x_pos, const float& y_pos)
{
    position_.xCoord += x_pos;
    position_.yCoord += y_pos;
}

void MoveableCharacter::setSize(const float& _xmin, const float& _ymin, const float& _xmax, const float& _ymax)
{
    size_.height_ = _ymax - _ymin;
    size_.width_ = _xmax - _xmin;
}

void MoveableCharacter::setPosition(const float& x_pos, const float& y_pos)
{
    position_.xCoord = x_pos;
    position_.yCoord = y_pos;
}