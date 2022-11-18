#include "BulletDrawable.h"

BulletDrawable::BulletDrawable(const std::shared_ptr<Bullet>& position, DataManager& data) : _position(position)
{
    data.texture_loader(Texture_::Bullets, filepath::bullet_file_path);
    _bulletTexture = data.get_texture(Texture_::Bullets);
    _bullet.setTexture(_bulletTexture);
}

void BulletDrawable::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_bullet);
}

void BulletDrawable::UpdateBulletDrawable()
{
    _bullet.setPosition(_position->getPosition().xCoord+GameConstants::playerWidth/2, _position->getPosition().yCoord);
}