#ifndef COLLISIONHANDLING_H
#define COLLISIONHANDLING_H
#include "Army.h"
#include "BulletLoader.h"
#include "Collisions.h"
#include "Player.h"

#include <iostream>

using player_ptr = std::shared_ptr<Player>;
using collision_ptr = std::shared_ptr<Collisions>;
using army_ptr = std::shared_ptr<Army>;
//using bullets_ptr = std::shared_ptr<BulletLoader>;

using bulletLoader_ptr = std::shared_ptr<BulletLoader>;
/**
 * @class CollisionHandling
 * @author Phetolo Malele(1412331),  Kananelo Kortjaas (605016)
 * @date 25/09/2019
 * @file CollisionHandling.h
 * @brief class that takes care of collisions between particular objects
 */
class CollisionHandling
{
public:
    CollisionHandling(){};
    CollisionHandling(collision_ptr& col);
    ~CollisionHandling()
    {
    }
    /**
     * @brief function to detect collision between bullets and enemy objects
     */
    void bullet_enemy_col(bulletLoader_ptr& bullets, army_ptr& arm);
    /**
     * @brief function to detect collision between player and bullet
     */
    void bullet_player_col(bulletLoader_ptr& bullets, player_ptr player);
    /**
     * @brief function to detect collision between two bullets
     */
    void bullet_bullet_col(bulletLoader_ptr& bullets, bulletLoader_ptr& bullets_2);
    
private:
    collision_ptr _collision;
    
};
#endif