#ifndef ARMADA_H
#define ARMADA_H

#include "Enemy.h"
#include <vector>
using enemy_ptr = std::shared_ptr<Enemy>;
using enemy_vector = std::vector<enemy_ptr>;
/**
 * @class Armada
 * @author Phetolo Malele(1412331), Kananelo Kortjaas (605016)
 * @date 22/09/2019
 * @file Armada.h
 * @brief class that models a row of enemies as a vector
 */

class Armada
{
public:
    Armada(const unsigned& cap, const Direction& dir, const bool& isDown, const float& xpos, const float& ypos);

    /**
     * @brief function that sets the state of the armada to dead or alive;
     */
    void setState();
    /**
     * @brief function to get the state of the armada
     * @return bool, returns true if alive and false if dead
     */
    bool getState() const
    {
        return alive;
    }
    /**
     * @brief function that gets the size of the armada
     * @return the size of the armada
     */
    unsigned armada_size() const
    {
        return static_cast<unsigned>(armada.size());
    }
    /**
     * @brief function that gets the armada vector
     * @return vector type, armada vector
     */
    enemy_vector& getArmada()
    {
        return armada;
    }
    /**
     * @brief function that moves all the armada
     * @param dir direction of movement
     */
    void moving_all(const Direction& dir);
    /**
     * @brief function that turns all the armada
     * @param dir direction of turning
     */
    void turning_all(const Direction& dir);

    /**
     * @brief function to determine the direction of movement for armada
     * @return integer, 1 if we going to the right, 2 turning from the right, 3 left, 4 turning from left
     */
    int direc();

private:
    unsigned capacity;
    float x, y;

    Direction initial_movement;
    bool alive, goingDown;
    enemy_vector armada;

    /**
     * @brief function that moves all enemies,or turns them
     * @param dir direction of movement or turning
     * @param turning all enemies turn if true, and move to the specified direction if false
     */
    void move_all(const Direction& dir, const bool& turning);
};
/**
 * @class InvalidArmadaInitialPosition
 * @author Phetolo Malele(1412331), Kananelo Kortjaas (605016)
 * @date 24/09/2019
 * @file Armada.h
 * @brief class called for validation of armada position
 */
class InvalidArmadaInitialPosition
{
};
/**
 * @class InvalidNumberOfEnemies
 * @author Phetolo Malele(1412331), Kananelo Kortjaas (605016)
 * @date 24/09/2019
 * @file Armada.h
 * @brief
 */
class InvalidNumberOfEnemies
{
};

#endif