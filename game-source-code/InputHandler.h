#ifndef  INPUTHANDLER_H
#define INPUTHANDLER_H

#include <cassert>
#include <SFML/Graphics.hpp>

enum class Key
{
    A = 0,D,S, P, Right, Left, Space, Escape, PButton, Enter
};
 using sf::Keyboard;
/**
 * @class InputHandler
 * @author  Phetolo Malele(1412331), Kananelo Kortjaas (605016)
 * @date 19/09/2019
 * @file InputHandler.h
 * @brief class to detect keyboard pressed by user
 */
class InputHandler
{
public: 
   InputHandler( ) {}
    ~InputHandler( ) {}
 
 /**
  * @brief function that detects if a specific key is pressed or not
  * @param _key the specific key pressed
  * @return true if key was pressed and false if it was not
  */
    bool isButtonPressed (const Key& _key);
};

#endif