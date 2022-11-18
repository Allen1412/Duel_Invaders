#ifndef ENEMY_H
#define ENEMY_H

#include "MoveableCharacter.h"

// using GameObjectSpeed::_enemySpeed;
using namespace GameObjectSpeed;

/**
 * @class Enemy
 * @author Phetolo Malele(1412331), Kananelo Kortjaas (605016)
 * @date 21/09/2019
 * @file Enemy.h
 * @brief class that models each enemy on an armada
 */
class Enemy : public MoveableCharacter
{
public:
    Enemy(const Direction& dir, const float& x, const float& y);//initial direction, initial x-coord, initial y-coord
    /**
     * @brief function that moves the enemy at a particular speed
     * @param dir a specific direction to which the enemy should go
     */
    void move(const Direction& dir);
    /**
     * @brief function to turn the enemies left or right
     * @param dir direction at which we turn
     * @param goingDown enemy heading up or down, true for down and false for up
     */
    void turning(const Direction& dir, const bool& goingDown);//Direction::Right, const bool& goingDown);
    /**
     * @brief function to return the direction of movement
     * @return enum of directions
     */
    Direction& getDirection(){return direc;}
    
    
private:
Direction direc;
};

class InvalidEnemyInitialPosition{ };

#endif