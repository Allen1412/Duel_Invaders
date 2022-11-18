#ifndef ENEMYDRAWABLE_H
#define ENEMYDRAWABLE_H
#include "Enemy.h"
#include <SFML/Graphics.hpp>
/**
 * @class EnemyDrawable
 * @author Phetolo Malele(1412331), Kananelo Kortjaas (605016)
 * @date 26/09/2019
 * @file EnemyDrawable.h
 * @brief class to draw enemy objects on screen
 */

class EnemyDrawable : public sf::Drawable, public sf::Transformable
{
public:
    EnemyDrawable(const std::shared_ptr<Enemy>& position, DataManager& data, const string& path) ;
  /**
   * @brief function to update what needs to be presented
   */
    void UpdateEnemyDrawable();
    
private:
  /**
   * @brief function to draw the object
   * @param _target to draw to
   * @param _states of the object to be drawn
   */
    virtual void draw(sf::RenderTarget& _target, sf::RenderStates _states) const override;
    std::shared_ptr<Enemy> _position;
    sf::Sprite _enemyDrawable;
    sf::Texture _enemyTex;
    
};
#endif