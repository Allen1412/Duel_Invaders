#ifndef Bullet_H
#define Bullet_H

#include "GameObjectProperties.h"
#include "MoveableCharacter.h"
using namespace GameObjectSpeed;
/**
 * @class Bullet
 * @author Phetolo Malele(1412331), Kananelo Kortjaas (605016)
 * @date 25/09/2019
 * @file Bullet.h
 * @brief class that models the bullets of the game
 */
class Bullet : public MoveableCharacter
{
public:
   Bullet(const float& x, const float& y);
    /**
     * @brief function for moving the bullet
     * @param direction the direction of movement of the bullet
     */
    void move(const Direction& direction);

private:
float xCod, yCod;
};

class InvalidInitialBulletPosition{ };

#endif