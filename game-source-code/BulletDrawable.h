#ifndef BULLETDRAWABLE_H
#define BULLETDRAWABLE_H
#include <SFML/Graphics.hpp>
#include "GameObjectProperties.h"
#include "Bullet.h"

/**
 * @class BulletDrawable
 * @author Phetolo Malele(1412331), Kananelo Kortjaas (605016)
 * @date 26/09/2019
 * @file BulletDrawable.h
 * @brief class to present bullet objects
 */
class BulletDrawable : public sf::Drawable, public sf::Transformable
{
public:
    BulletDrawable(const std::shared_ptr<Bullet>& position, DataManager& data);
    /**
     * @brief function to update the drawable state of bullet objects
     */
    void UpdateBulletDrawable();
    
private:
    std::shared_ptr<Bullet> _position;
    sf::Sprite _bullet;
    sf::Texture _bulletTexture;
   /**
    * @brief function to draw the bullets on screen
    * @param target to draw to
    * @param states state of the object to be drawn
    */
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
#endif