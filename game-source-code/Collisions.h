#ifndef COLLISIONS_H
#define COLLISIONS_H
#include "MoveableCharacter.h"
#include <vector>
#include <cmath>

/**
 * @class Collisions
 * @author Phetolo Malele(1412331),  Kananelo Kortjaas (605016)
 * @date 25/09/2019
 * @file Collisions.h
 * @brief class that detects collisions between two caracters
 */
class Collisions{
    
public:
    Collisions(){};
    ~Collisions(){};
    /**
     * @brief function that detects collitions between two moveable characters
     * @param char_1 first moveable character
     * @param char_2 second moveable character
     * @return true if the two objects collided and false otherwise
     */
    bool collided(const std::shared_ptr<MoveableCharacter>& char_1,const std::shared_ptr<MoveableCharacter>& char_2);
private:
/**
 * @brief function that calculates the distance between two objects
 * @param x1  x coordinate for character1
 * @param y1 y coordinate for character1
 * @param x2 x coordinate for character2
 * @param y2 y coordinate for character2
 */
   float calculateDistance(const float& x1, const float& y1, const float& x2, const float& y2);
    };
#endif