#include "CollisionHandling.h"

CollisionHandling::CollisionHandling(collision_ptr& col):_collision(col)
{
    
}

void CollisionHandling::bullet_enemy_col(bulletLoader_ptr& bullets, army_ptr& arm)
{
    
    
   for(auto& x : bullets->getBullets()) { 

    for(auto& i : arm->getArmy()) {
        for(auto& j : i->getArmada()) {

            

                if(_collision->collided(x,j)) {
                    
                    j->setActiveState(false);
                    x->setActiveState(false);
                    
                }
            }
        }
    }
}


void CollisionHandling::bullet_player_col(bulletLoader_ptr& bullets, player_ptr player)
{
      for(auto& x : bullets->getBullets()) {

                if(_collision->collided(x,player)) {
                    
                    x->setActiveState(false);
                    player->setActiveState(false);
                    
                }
            }
    
}


void CollisionHandling::bullet_bullet_col(bulletLoader_ptr& bullets, bulletLoader_ptr& bullets_2)
{
    
      for(auto& j : bullets->getBullets()){
          
      for(auto& x : bullets_2->getBullets()) {

                if(_collision->collided(x,j)) {
                    
                    j->setActiveState(false);
                    x->setActiveState(false);
                    
                }
            }
            
      }
}