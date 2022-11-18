#include "EnemyDrawable.h"

EnemyDrawable::EnemyDrawable(const std::shared_ptr<Enemy>& position, DataManager& data, const string& path) : _position(position)
{
    data.texture_loader(Texture_::Enemy_, path);
    
    _enemyTex = data.get_texture(Texture_::Enemy_);
    _enemyDrawable.setTexture(_enemyTex);
}




void EnemyDrawable::UpdateEnemyDrawable()
{
    _enemyDrawable.setPosition(_position->getPosition().xCoord, _position->getPosition().yCoord);
}





void EnemyDrawable::draw(sf::RenderTarget& _target, sf::RenderStates _states) const
{
    
    _target.draw(_enemyDrawable);
    
}