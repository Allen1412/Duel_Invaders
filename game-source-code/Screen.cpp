//#include "Screen.h"
//
//Screen::Screen(const float& width, const float& height, const std::string& title)
//{
//
//    if(width > 1920 || height > 1080)
//        throw BiggerScreen{};
//    if(width <= 1920 && height <= 1080) {
//        width_ = width;
//        height_ = height;
//        titlebar_ = title;
//    }
//}
//
//
////screen window is created here 
//void Screen::makeScreen()
//{
//
//    window_.create(sf::VideoMode(width_, height_), titlebar_, sf::Style::Close | sf::Style::Titlebar);
//}
//

//function to clear screen
//void Screen::clearScreen()
//{
//    window_.clear();
//}


///screen is closed here
//void Screen::closeScreen()
//{
//    window_.close();
//}
//
//
////return true when screen is open
//const bool Screen::opened()
//{
//    return window_.isOpen();
//}
//
//
////returns the window 
//sf::RenderWindow& Screen::get_screen()
//{
//    return window_;
//}
//
////destructor
//Screen::~Screen()
//{
//}

















#include "Screen.h"

 void Screen::CreateScreen(const float& _width, const float& _height, const std::string& _windowTitle, const uint32_t& _style)
{
     if(_width > 1920 || _height > 1080)
        throw BiggerScreen{};
    _gameScreen.create(sf::VideoMode(_width, _height), _windowTitle, _style);
    _gameScreen.setVerticalSyncEnabled(true);
}

 void Screen::UpdateGameScreen()
{
     _gameScreen.display();
}

 void Screen::ClearScreen()
{
    _gameScreen.clear();
}

 void Screen::DrawToGameScreen(const sf::Drawable& _drawableObject)
{
    _gameScreen.draw(_drawableObject);
}

 void Screen::CloseGameScreen()
{
    _gameScreen.close();
}