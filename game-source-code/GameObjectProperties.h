#ifndef GAMEOBJECTPROPERTIES_H
#define GAMEOBJECTPROPERTIES_H
// Logic Layer

#include "DataManager.h"
#include "InputHandler.h"
#include "MachineStates.h"
#include "Screen.h"
#include <SFML/Graphics.hpp> // use of textures and sprites, including the window that will be used to render the graphics of the game
#include <memory> // use of shared pointers
#include <vector>
/**
 * @class GameComponents
 * @author Phetolo Malele(1412331),  Kananelo Kortjaas (605016)
 * @date 20/09/2019
 * @file GameObjectProperties.h
 * @brief this has all the properties that are gonna be needed in the entite game
 */

using sf::RenderWindow;
using sf::Sprite;
using sf::Texture;
using std::vector;
using ScreenItem = Sprite;
// This struct is used to store the relevant objects that will be needed for the game to run

struct GameComponents {
    InputHandler _input;
    MachineStates _states;  // Used for state handling
    DataManager _resources; // Used to load the required textures, fonts, etc
    Screen gameScreen_;     // The window that will be used to render the screen
};

using _gameResources = std::shared_ptr<GameComponents>;

/**
 * @class Coordinates
 * @author Phetolo Malele(1412331),  Kananelo Kortjaas (605016)
 * @date 20/09/2019
 * @file GameObjectProperties.h
 * @brief all coordinates for the game
 */
struct Coordinates {
    float xCoord;
    float yCoord;

    Coordinates()
        : xCoord(0.f)
        , yCoord(0.f)
    {
    }
    Coordinates(const float& xCo, const float& yCo)
        : xCoord(xCo)
        , yCoord(yCo)
    {
    }
    Coordinates(const Coordinates& _rhs)
        : xCoord(_rhs.xCoord)
        , yCoord(_rhs.yCoord)
    {
    }

    void operator=(const Coordinates& _rhs)
    {
        this->xCoord = _rhs.xCoord;
        this->yCoord = _rhs.yCoord;
    }

    bool operator==(const Coordinates& _rhs) const
    {
        if((this->xCoord == _rhs.xCoord) && (this->yCoord == _rhs.yCoord))
            return true;
        else
            return false;
    }

    bool operator<=(const Coordinates& _rhs) const
    {
        if((this->xCoord <= _rhs.xCoord) && (this->yCoord <= _rhs.yCoord)) {
            return true;
        } else
            return false;
    }
};

struct Size {
    float height_ = 50.0f;
    float width_ = 55.0f;
};

enum class WindowType { NONE = 0, FULLSCREEN = 1 << 3, DEFAULT = 1 << 0 | 1 << 1 | 1 << 2 };

// Direction of movement
enum class Direction { Up, Down, Left, Right, Nowhere };
// Used for determining movement speeds
const float delta = 1.0f / 60.f; // Required for drawing objects to screen

struct GameScreenSize {
    GameScreenSize(const float& _width = 1300.f, const float& _height = 900.f)
        : width_(_width)
        , height_(_height)
    {
    }
    float width_;
    float height_;
};

// Dimensions of the screen, from splash screen, to game play
namespace ScreenDimensions
{
const float _Screen_Width = 1300.f;
const float _Screen_Height = 900.f;
}

namespace GameObjectSpeed
{
const float _playerSpeed = 900.f;

const float _bulletSpeed = 300.f;

const float _spawnSpeed = 2.0f;
const float enemyHorizontalSpeed = 2000.f;
const float enemyVerticalSpeed = 2000.f;
};

namespace filepath
{
const std::string splash_file_path = "resources/spsh.png";
const std::string menu_file_path = "resources/Mainmenu.png";
const std::string game_screen_file_path = "resources/_game.png";
const std::string player_file_path = "resources/_player.png";
const std::string player2_file_path = "resources/_player.png";
const std::string bullet_file_path = "resources/_bullet.jpg";
const std::string enemy_file_path = "resources/al_i_en.png";
const std::string enemy_file_path1 = "resources/alien.png";
const std::string win_file_path = "resources/_game_over_w.png";
const std::string lose_file_path = "resources/_game_over_lost.png";
}

namespace GameConstants
{

const float playerWidth = 50.f;
const float playerHeight = 55.f;
const float playerWidth_or = 0.f;
const float playerHeight_or = 0.f;

const float enemyWidth = 40.f;
const float enemyHeight = 45.f;
const float enemyWidth_or = 0.f;
const float enemyHeight_or = 0.f;

const unsigned armada_width_size = 25u;
const unsigned armada_height_size = 3u;

const float _playerOriginalPositionX = ScreenDimensions::_Screen_Width - playerWidth;
const float _playerOriginalPositionY = ScreenDimensions::_Screen_Height - playerHeight;

const float _playerOriginalPositionX_2 = playerWidth;
const float _playerOriginalPositionY_2 = playerHeight;

//    const float _enemyOrgPosX= ScreenDimensions::_Screen_Width/2.f ;
//    const float _enemyOrgPosY = ScreenDimensions::_Screen_Height/2.f;

const float bulletObjectHeight = 30.f;
const float bulletObjectWidth = 5.f;
}

#endif // GameObjectProperties_h