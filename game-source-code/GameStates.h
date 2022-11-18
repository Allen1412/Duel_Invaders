#ifndef GAMESTATES_H
#define GAMESTATES_H

#include "Armada.h"
#include "Army.h"
#include "Bullet.h"
#include "Enemy.h"
#include "EnemyDrawable.h"
#include "GameObjectProperties.h"
#include "Player.h"
#include "PlayerDrawable.h"
#include "State.h"
#include <SFML/Graphics.hpp>
#include <algorithm>

#include "BulletDrawable.h"
#include "BulletLoader.h"
#include "CollisionHandling.h"

#include <iostream>

#include <vector>

// using bulletDVector = std::vector<std::shared_ptr<BulletDrawable>>;
/**
 * @class SplashState
 * @author Phetolo Malele(1412331),  Kananelo Kortjaas (605016)
 * @date 20/09/2019
 * @file GameStates.h
 * @brief class for outputting the splash state
 */
class SplashState : public State
{
public:
    SplashState(_gameResources Data);
    ~SplashState();
    /**
     * @brief initial conditions for splash state
     */
    virtual void initial_state() override; // initialise the state
    /**
     * @brief splash state updated
     */
    virtual void state_update() override; // update the state
    /**
     * @brief checking for inputs and responding to them
     */
    virtual void input_handler() override; // handle all input on that state
    /**
     * @brief drawing changes to splash state
     */
    virtual void draw_State() override; // draw the new state

private:
    _gameResources _gameData;
    ScreenItem _backSprite;
    GameScreenSize _screen_size{ ScreenDimensions::_Screen_Width, ScreenDimensions::_Screen_Height };
    /**
     * @brief function to create screen
     */
    virtual void Create_Screen() override;
    /**
     * @brief function that checks for inputs
     */
    virtual void CheckForInput() override;
};

/**
 * @class MainMenu
 * @author Phetolo Malele(1412331),  Kananelo Kortjaas (605016)
 * @date 20/09/2019
 * @file GameStates.h
 * @brief class for displaying the main menu state, executed after user presses enter
 */

class MainMenu : public State
{
public:
    MainMenu(_gameResources Data);
    ~MainMenu();
    /**
     * @brief initial conditions for main menu
     */
    virtual void initial_state() override; // initialise the state
    /**
     * @brief main menu state updated
     */
    virtual void state_update() override; // update the state
    /**
     * @brief function that handles inputs for main menu
     */
    virtual void input_handler() override; // handle all input on that state
    /**
     * @brief function that draws main menu objects
     */
    virtual void draw_State() override; // draw the new state

private:
    _gameResources _gameData;
    ScreenItem _menuSprite;
    /**
     * @brief function to create screen
     */
    virtual void Create_Screen() override;
    /**
     * @brief function to check for inputs
     */
    virtual void CheckForInput() override;
};

using enemy_ptr = std::shared_ptr<Enemy>;
using armada_ptr = std::shared_ptr<Armada>;
using armyVec = std::vector<vector<std::unique_ptr<EnemyDrawable>>>;
using bullet_ptr = std::shared_ptr<Bullet>;
using bulletsVector = std::vector<std::unique_ptr<BulletDrawable>>;
using collision_handling_ptr = std::unique_ptr<CollisionHandling>;

/**
 * @class GameMode
 * @author Phetolo Malele(1412331),  Kananelo Kortjaas (605016)
 * @date 26/09/2019
 * @file GameStates.h
 * @brief class to model the game playing state of the game, called after user presses P
 */

class GameMode : public State
{
public:
    GameMode(_gameResources Data);
    ~GameMode();

    /**
     * @brief function to initialise game mode state
     */
    virtual void initial_state() override; // initialise the state
    /**
     * @brief function to update game mode state
     */
    virtual void state_update() override; // update the state
    /**
     * @brief function to handle inputs on game mode state
     */
    virtual void input_handler() override; // handle all input on that state
    /**
     * @brief function to draw objects on screen from game mode state
     */
    virtual void draw_State() override; // draw the new state
    //
    //
private:
    _gameResources _gameData;
    ScreenItem _background;
    std::shared_ptr<PlayerDrawable> player_;
    std::shared_ptr<PlayerDrawable> player_2;
    player_ptr _player;
    player_ptr _player2;

    enemy_ptr _enemy;

    army_ptr _army;
    army_ptr _army2;

    armyVec _armyObjects;
    armyVec _armyObjects2;

    bulletLoader_ptr bullets_1;
    bulletsVector bullet_objects_1;

    bulletLoader_ptr bullets_2;
    bulletsVector bullet_objects_2;

    collision_handling_ptr handling_col;
    collision_ptr collisions;
    /**
     * @brief function to eliminate enemies that collided with bullets
     * @param arm pointer to the Army class
     * @param army_obj 2d vector of drawable army
     */
    void enemycollision(army_ptr& arm, armyVec& army_obj);
    /**
     * @brief function to update the drawable objects
     * @param val columns of enemies
     * @param val2 row of enemies
     * @param _arm vector of army objects for presentation
     * @param _armyy pointer of army
     * @param fl filepath
     */
    void create_army_drawable(const unsigned& val,
        const unsigned& val2,
        armyVec& _arm,
        const army_ptr& _armyy,
        const string& fl);
    /**
     * @brief function to move bullets on screen
     * @param bulletss returns a vector of bullets
     * @param dir direction of movement of bullets
     * @param bul vector of presentable bullets
     */
    void moveBullet(bulletLoader_ptr& bulletss, Direction dir, std::vector<std::unique_ptr<BulletDrawable>>& bul);
  /**
   * @brief function to check if enemies have invaded
   * @param arm army of enemies
   * @param upper true for upper enemies and false otherwise
   * @return true if they have invaded, false otherwise
   */
    bool isInvasion(army_ptr arm, const bool& upper);

    /**
     * @brief function to create screen
     */
    virtual void Create_Screen() override;
    /**
     * @brief function to check inputs
     */
    virtual void CheckForInput() override;
};

/**
 * @class GameOverWin
 * @author Phetolo Malele(1412331),  Kananelo Kortjaas (605016)
 * @date 26/09/2019
 * @file GameStates.h
 * @brief class that models the game winning state of the game
 */
class GameOverWin : public State
{

public:
    GameOverWin(_gameResources Data);
    ~GameOverWin();
    /**
     * @brief function to initialise the state
     */
    virtual void initial_state() override; // initialise the state
    /**
     * @brief function that updates the state
     */
    virtual void state_update() override; // update the state
    /**
     * @brief function that handles inputs in the game_over state
     */
    virtual void input_handler() override; // handle all input on that state
    /**
     * @brief function that draws objects to the screen
     */
    virtual void draw_State() override; // draw the new state

private:
    _gameResources _gameData;
    ScreenItem _backSprite;
    /**
     * @brief function that creates the screen
     */
    virtual void Create_Screen() override;
    /**
     * @brief function that checks for inputs
     */
    virtual void CheckForInput() override;
};

/**
 * @class GameOverLose
 * @author Phetolo Malele(1412331),  Kananelo Kortjaas (605016)
 * @date 26/09/2019
 * @file GameStates.h
 * @brief class that models the state that gets called when the game is lost
 */
class GameOverLose : public State
{

public:
    GameOverLose(_gameResources Data);
    ~GameOverLose();

    virtual void initial_state() override; // initialise the state
    /**
     * @brief function to update the state
     */
    virtual void state_update() override; // update the state
    /**
     * @brief function that handles the inputs
     */
    virtual void input_handler() override; // handle all input on that state
    /**
     * @brief function to draw the state
     */
    virtual void draw_State() override; // draw the new state

private:
    _gameResources _gameData;
    ScreenItem _backSprite;
    /**
     * @brief function that creates the screen
     */
    virtual void Create_Screen() override;
    /**
     * @brief function that checks for inputs
     */
    virtual void CheckForInput() override;
};

#endif