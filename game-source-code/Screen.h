//#ifndef SCREEN_H
//#define SCREEN_H
//
////Including SFML files to display screen
//#include <SFML/Graphics.hpp>
//
//class BiggerScreen{};
//
//
//class Screen{
//    
//public:
//           Screen();
//           Screen(const float& width, const float& height, const std::string& title);//constructor to initialise the dimensions of the screen window
//        
//        void makeScreen();
//        void clearScreen();
//        void closeScreen();
//        const bool opened();
//        sf::RenderWindow& get_screen();
//        ~Screen();
//private:
//     float width_;
//     float height_;
//     std::string titlebar_;
//     sf::RenderWindow window_;
//    
//    };
//#endif

#ifndef SCREEN_H
#define SCREEN_H
#include <SFML/Graphics.hpp>

using sf::RenderWindow;


/**
 * @class Screen
 * @author Phetolo Malele(1412331),  Kananelo Kortjaas (605016)
 * @date 19/09/2019
 * @file Screen.h
 * @brief class for the render window characteristics of the game
 */
 
class Screen
{
public:
    Screen(){}
    ~Screen(){}
 /**
  * @brief function to create the screen
  * @param _width width of the screen, float
  * @param _height height of the screen, float
  * @param _windowTitle title of window, string
  * @param _style type of window used
  */
    void  CreateScreen(const float& _width, const float& _height, const std::string& _windowTitle, const uint32_t& _style);
 /**
  * @brief clears the screen
  */
    void ClearScreen();
  /**
   * @brief updates the screen
   */
    void UpdateGameScreen();
  /**
   * @brief draws and object to game screen
   * @param _drawableObject takes in a drawable object
   */
    void DrawToGameScreen(const sf::Drawable& _drawableObject);
    /**
     * @brief function to close the game window
     */
  
    void CloseGameScreen();
   /**
    * @brief function that gets the window
    * @return returns the render window of the game
    */
    RenderWindow& getGameScreen () {return _gameScreen;}

private:
    RenderWindow _gameScreen;
};

class BiggerScreen{ };
#endif