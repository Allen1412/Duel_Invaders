#include "PlayerDrawable.h"

PlayerDrawable::PlayerDrawable(const std::shared_ptr<Player>& position, DataManager& data, const string& path) : _position(position)
{
    data.texture_loader(Texture_::Player_, path);
    
    _playerTex = data.get_texture(Texture_::Player_);
    _playerDrawable.setTexture(_playerTex);
}




void PlayerDrawable::UpdatePlayerDrawable()
{
    _playerDrawable.setPosition(_position->getPosition().xCoord, _position->getPosition().yCoord);
}





void PlayerDrawable::draw(sf::RenderTarget& _target, sf::RenderStates _states) const
{
    
    _target.draw(_playerDrawable);
    
}