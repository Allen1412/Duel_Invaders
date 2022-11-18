#ifndef BULLETLOADER_H
#define BULLETLOADER_H
#include "Bullet.h"
#include "Player.h"
#include "GameObjectProperties.h"
#include <vector>

using bulletVector = std::vector<std::shared_ptr<Bullet>>;
/**
 * @class BulletLoader
 * @author Phetolo Malele(1412331), Kananelo Kortjaas (605016)
 * @date 25/09/2019
 * @file BulletLoader.h
 * @brief class that models a bullet vector and the position at which it is loaded
 */
class BulletLoader
{
public:
    BulletLoader(const std::shared_ptr<Player>& position) : _delay(GameObjectSpeed::_spawnSpeed*3.f), _PlayerPosition(position){}
    
   /**
    * @brief function that loads a bullet to a specific position
    * @return true if bullet are successfully loaded and false otherwise
    */
    bool LoadBullet();
    /**
     * @brief function that gets the loaded bullets
     * @return vector of bullets
     */
  
    bulletVector& getBullets() {return _bulletVector;}
   
   /**
    * @brief function that decreases the number of bullets
    */
     void decreaseNumberOfBullets() {numberOfBullets--;}
  /**
   * @brief function that gets the number of bullets
   * @return an integer number of bullets
   */
     int getNumberOfBullets() {return numberOfBullets;}
private:
    float _delay;
    bulletVector _bulletVector;
    std::shared_ptr<Player> _PlayerPosition;
    int numberOfBullets;
};
#endif