#include "BulletLoader.h"

//int BulletLoader::numberOfBullets = 0;

bool BulletLoader::LoadBullet()
{
    _delay=0.f;
    if ((_delay == 0.f) && (_PlayerPosition->isShooting()))
    {
        auto _bullet = std::make_shared<Bullet>(_PlayerPosition->getPosition().xCoord, _PlayerPosition->getPosition().yCoord);
        _bulletVector.push_back(_bullet);
        numberOfBullets++;
        _delay = _spawnSpeed;
        return true;
}

else {--_delay;
        return false;
        }
}