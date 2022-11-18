#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include  <vector>

#include <SFML/Graphics.hpp>
using sf::Font;
using sf::Texture;
using std::vector;
using std::string;

enum class Texture_
{
    Splashscreen = 0, MainMenu_, Game_Screen, Player_, Bullets, Enemy_, GameWon, GameLost
    };
    
enum class Font_
{
    GameScreen_ = 0, GameOver
    };

/**
 * @class DataManager
 * @author Phetolo Malele(1412331), Kananelo Kortjaas (605016)
 * @date 19/09/2019
 * @file DataManager.h 
 * @brief class used to load all data used in the game
 */
class DataManager
{
public:
    DataManager()  {    }
    ~DataManager()  {    }
    /**
     * @brief function to load game textures in a vector
     * @param texture_name the name of the texture that is being loaded
     * @param path file path for the texture that is being loaded
     */
    void texture_loader(const  Texture_& texture_name,const string& path);
    
    /**
     * @brief function that gets a specific texture from a vector
     * @param texture_name name of that specific texture
     * @return returns a texture, texture type
     */
    Texture& get_texture(const Texture_& texture_name);
/**
 * @brief function to load game fonts in a vector
 * @param font_name the name of the font that is being loaded
 * @param path file path for the font that is being loaded
 */
    void  font_loader(const Font_& font_name,const string& path);
    /**
     * @brief function that gets a specific font
     * @param font_name name of font that is being returned
     * @return a font type
     */
    Font& get_font(const Font_& font_name);

private:

    vector<sf::Texture>  _textures{8};
   vector<Font>  _fonts{2};
}; 

/**
 * @class TextureNotFound
 * @author  Phetolo Malele(1412331), Kananelo Kortjaas (605016)
 * @date 19/09/2019
 * @file DataManager.h
 * @brief empty class that is called when texture could not be loaded
 */
class  TextureNotFound{};

/**
 * @class FontNotFound
 * @author  Phetolo Malele(1412331), Kananelo Kortjaas (605016)
 * @date 19/09/2019
 * @file DataManager.h
 * @brief empty class that gets called when font could not be loaded
 */
class FontNotFound{};

#endif