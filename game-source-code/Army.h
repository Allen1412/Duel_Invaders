#ifndef ARMY_H
#define ARMY_H
#include <ctime>
#include <vector>
#include "Armada.h"
using armada_ptr = std::shared_ptr<Armada>;
using armada_vector = std::vector<armada_ptr>;

/**
 * @class Army
 * @author Phetolo Malele(1412331), Kananelo Kortjaas (605016)
 * @date 25/09/2019
 * @file Army.h
 * @brief class that models a vector of armadas, 2d vector of enemies
 */

class Army{
    public:
    
    Army(const unsigned& capx, const unsigned& capy, const Direction& dir,
        const bool& isDown,
        const float& xpos,
        const float& ypos, bool isLower);
/**
 * @brief function that sets the state of the army, dead or alive
 */
    void setState();
    /**
     * @brief function that gets the state of the army
     * @return boolean, true if alive and false if dead
     */
    bool getState(){return alive;}
    /**
     * @brief function that gets the size of the army
     * @return unsigned value
     */
    unsigned army_size(){return static_cast<unsigned>(army.size());}
    /**
     * @brief function that gets the vector of armadas(army) by reference
     * @return returns a vector of armadas
     */
    armada_vector &getArmy(){return army;}
    /**
     * @brief function to move the army
     */
    void move();
    /**
     * @brief function used to delay movement
     * @return boolean, true if time delay is greater than 5 seconds false otherwise
     */
    
    bool delay();
    
private:

    bool alive, goingDown, lower;
    armada_vector army;
    float x,y;
    Direction init;
    unsigned capacityX, capacityY;
    float initial_tme, delta_time;
    /**
     * @brief function that moves all the army
     * @param dir direction of movement of all army
     * @param isTurning true if all army is turning and false otherwise
     */
    void move_all_army(const Direction& dir, const bool& isTurning);
    
    };
    
    /**
     * @class InvalidRowsOfArmy
     * @author Phetolo Malele(1412331), Kananelo Kortjaas (605016)
     * @date 25/09/2019
     * @file Army.h
     * @brief class to validate rows of enemies
     */
    class InvalidRowsOfArmy{ };
    /**
     * @class InvalidArmyInitialPosition
     * @author Phetolo Malele(1412331), Kananelo Kortjaas (605016)
     * @date 25/09/2019
     * @file Army.h
     * @brief class that validates the initial position of an army
     */
    class InvalidArmyInitialPosition{};
#endif