#ifndef PLAYERDRAWABLE_H
#define PLAYERDRAWABLE_H
#include "Player.h"
#include <SFML/Graphics.hpp>
/**
 * @class PlayerDrawable
 * @author Phetolo Malele(1412331), Kananelo Kortjaas (605016)
 * @date 20/09/2019
 * @file PlayerDrawable.h
 * @brief class that draws player objects to the screen
 */
class PlayerDrawable : public sf::Drawable, public sf::Transformable
{
public:
    PlayerDrawable(const std::shared_ptr<Player>& position, DataManager& data, const string& path) ;
  /**
   * @brief function that keeps on drawing player on screen depending on its state and position
   */
    void UpdatePlayerDrawable();
    
private:
/**
 * @brief function that draws the player object to the screen
 * @param _target the window at which object is drawn
 * @param _states states of the object to be drawn
 */
  
    virtual void draw(sf::RenderTarget& _target, sf::RenderStates _states) const override;
    std::shared_ptr<Player> _position;
    sf::Sprite _playerDrawable;
    sf::Texture _playerTex;
    
};
#endif