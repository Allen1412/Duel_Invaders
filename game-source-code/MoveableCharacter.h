
#ifndef MOVEABLECHAR_H
#define MOVEABLECHAR_H
#include "GameObject.h"
#include "GameObjectProperties.h"

/**
 * @class MoveableCharacter
 * @author Phetolo Malele(1412331), Kananelo Kortjaas (605016)
 * @date 20/09/2019
 * @file MoveableCharacter.h
 * @brief class to model every moveable character
 */

class MoveableCharacter : public GameObject
{
public:
    MoveableCharacter()
        : isActive(true)
    {
    }
    virtual ~MoveableCharacter()
    {
    }
/**
 * @brief virtual voud function to set the position of any moveable character
 * @param x_pos the x-coordinate of a moveable character
 * @param y_pos the y-coordinate of a moveable character
 */
    virtual void setPosition(const float& x_pos, const float& y_pos) override;
/**
 * @brief function that sets the size of any moveable character
 * @param _xmin minimum width of a moveable character
 * @param _ymin minimum height of a moveable character
 * @param _xmax maximum width of any moveable character
 * @param _ymax maximum height of any moveable character
 */
    virtual void setSize(const float& _xmin = 0.f,
        const float& _ymin = 0.f,
        const float& _xmax = 60.f,
        const float& _ymax = 60.f) override;
/**
 * @brief function getter, that gets the position of any moveable character
 * @return position of moveable character
 */
    virtual Coordinates getPosition() const override
    {
        return position_;
    }
    /**
     * @brief getter for the size of the character
     * @return size of any moveable character, type size
     */

    virtual Size getSize() const override
    {
        return size_;
    }

/**
 * @brief function getter to 
 * @return speed of moveable character, float type
 */
    float getSpeed() const
    {
        return speed_;
    }

/**
 * @brief function to return the state of a moveable character
 * @return returns the state, boolean
 */
    virtual bool getActiveState() const override
    {
        return isActive;
    }
    /**
     * @brief function to set the state of a moveable character, sets true or false
     * @param _flag boolean character that sets the state of a moveable character
     */

    virtual void setActiveState(const bool& _flag) override
    {
        isActive = _flag;
    }

protected:
/**
 * @brief function to move character
 * @param direction parameter to determine the direction of movement
 */
    virtual void move(const Direction& direction);
    /**
     * @brief function to move a moveable character up
     */

    void move_Up();
/**
 * @brief function to move a moveable character down
 */
    void move_Down();
/**
 * @brief function to move a character to the left
 */
    void move_Left();
/**
 * @brief function that moves a character to the right
 */
    void move_Right();
    /**
     * @brief function that sets the speed of all moveable characters
     * @param _speed the speed of which a specific character moves
     */

    void setSpeed(const float& _speed);
/**
 * @brief function to change the position of a specific moveable character
 * @param x_pos the new x-coordinate, float
 * @param y_pos the new y-coordinate, float
 */
    void changePosition(const float& x_pos, const float& y_pos);

private:
    double speed_;
    Coordinates position_;
    Size size_;
    bool isActive;
};

#endif