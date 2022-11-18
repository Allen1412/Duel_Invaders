#ifndef PLAYER_H
#define PLAYER_H

#include "MoveableCharacter.h"

using GameObjectSpeed::_playerSpeed;

/**
 * @class Player
 * @author Phetolo Malele(1412331), Kananelo Kortjaas (605016)
 * @date 20/09/2019
 * @file Player.h
 * @brief class that models a player and it capabilities
 */
class Player : public MoveableCharacter
{
public:
//constructor to set the initial position of a player
    Player(const float& x, const float& y);
/**
 * @brief function to move a player
 * @param direction the direction of movement, type Direction
 */
    void move(const Direction& direction);
/**
 * @brief function that gets called when player shoots
 */
    void shoot();
    /**
     * @brief function that detects if a player is shooting or not 
     * @return boolean for shooting
     */

    bool isShooting() const
    {
        return _shoot;
    }
    

private:
    bool _shoot;
    /**
     * @brief function that is set when a player shoots
     * @param _flag boolean that determines if a player is shooting or not
     */
    void setShooting(const bool& _flag = false);
};

class InvalidPosition{ };

#endif