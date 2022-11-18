#include "InputHandler.h"

bool InputHandler::isButtonPressed(const Key& _key)
{
    switch(_key)
    {
        case Key::Escape:
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                return true;
            }   
                else return false;
                
        case Key::A:
            if (Keyboard::isKeyPressed(Keyboard::A))
                return true;
                else return false;
           case Key::D:
            if (Keyboard::isKeyPressed(Keyboard::D))
                return true;
                else return false;
           case Key::S:
            if (Keyboard::isKeyPressed(Keyboard::S))
                return true;
                else return false;
                  case Key::P:
            if (Keyboard::isKeyPressed(Keyboard::P))
                return true;
                else return false;
        case Key::Left:
            if (Keyboard::isKeyPressed(Keyboard::Left))
                return true;
                else return false;
        case Key::Right:
            if (Keyboard::isKeyPressed(Keyboard::Right))
                 return true;
                else return false;
        case Key::Space:
            if (Keyboard::isKeyPressed(Keyboard::Space))
                return true;
                else return false;
        case Key::PButton:
            if (Keyboard::isKeyPressed(Keyboard::P))
                return true;
                else return false;
            case Key::Enter:
                if (Keyboard::isKeyPressed(Keyboard::Enter))
                    return true;
                    else return false;
        default:
         assert(false);
    }
}