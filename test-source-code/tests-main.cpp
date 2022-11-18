#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
//#include "../game-source-code/DisplaySprites.h"
//#include "../game-source-code/GamePlay.h"
#include "../game-source-code/BulletLoader.h"
#include "../game-source-code/CollisionHandling.h"
#include "../game-source-code/Collisions.h"
#include "../game-source-code/GameObjectProperties.h"
#include "../game-source-code/GameStates.h"
#include "../game-source-code/Player.h"
#include "../game-source-code/Screen.h"

#include <memory>

using namespace std;

//////////////////////////SCREEN TESTS/////////////////////////////////////////
TEST_CASE("Screen dimensions not bigger than 1920x1080")
{

    std::unique_ptr<Screen> scr_ptr;
    scr_ptr = std::make_unique<Screen>();
    CHECK_THROWS_AS(scr_ptr->CreateScreen(1921.f, 1081.f, "Duel Invaders"s, sf::Style::Close), BiggerScreen);
}

/////////////////////////////PLAYER TESTS///////////////////////////////////////////////////
// testing for movements
TEST_CASE("Player object can move left and right only")
{

    player_ptr _player;
    _player =
        std::make_shared<Player>(GameConstants::_playerOriginalPositionX, GameConstants::_playerOriginalPositionY);

    _player->move(Direction::Left);
    CHECK(_player->getPosition().xCoord < GameConstants::_playerOriginalPositionX);

    _player->move(Direction::Right);
    CHECK(_player->getPosition().xCoord == GameConstants::_playerOriginalPositionX);
    
     _player->move(Direction::Up);
    CHECK(_player->getPosition().yCoord == GameConstants::_playerOriginalPositionY);
    
     _player->move(Direction::Down);
    CHECK(_player->getPosition().yCoord == GameConstants::_playerOriginalPositionY);
    
    
}

// checking movement bounds
TEST_CASE("Player object cannot move boyond left and right bounds")
{
    ////////////////testing for right bound////////////
    player_ptr _player;
    _player = std::make_shared<Player>(
        ScreenDimensions::_Screen_Width - GameConstants::playerWidth, GameConstants::_playerOriginalPositionY);

    _player->move(Direction::Right);
    CHECK(_player->getPosition().xCoord == GameConstants::_playerOriginalPositionX);

    //////////////////testing for left bound///////////

    player_ptr _player2;
    _player2 = std::make_shared<Player>(GameConstants::playerWidth, GameConstants::_playerOriginalPositionY);
    _player2->move(Direction::Left);
    CHECK(_player2->getPosition().xCoord == GameConstants::playerWidth);
}

// checking for initial position bounds
TEST_CASE("Player initial position cannot be beyond screen dimensions")
{

    player_ptr _player;
    CHECK_THROWS_AS(
        _player = std::make_shared<Player>((ScreenDimensions::_Screen_Width - GameConstants::playerWidth + 1.f),
            GameConstants::_playerOriginalPositionY),
        InvalidPosition);

    player_ptr _player2;
    CHECK_THROWS_AS(_player2 = std::make_shared<Player>(
                        (GameConstants::playerWidth - 1.f), GameConstants::_playerOriginalPositionY),
        InvalidPosition);

    player_ptr _player3;
    CHECK_THROWS_AS(_player3 = std::make_shared<Player>(GameConstants::_playerOriginalPositionX,
                        (ScreenDimensions::_Screen_Height - GameConstants::playerWidth + 1.f)),
        InvalidPosition);

    player_ptr _player4;
    CHECK_THROWS_AS(_player4 = std::make_shared<Player>(
                        GameConstants::_playerOriginalPositionX, (GameConstants::playerHeight - 1.f)),
        InvalidPosition);
}

TEST_CASE("player can shoot")
{
    player_ptr _player;
    _player =
        std::make_shared<Player>(GameConstants::_playerOriginalPositionX, GameConstants::_playerOriginalPositionY);
    _player->shoot();
    CHECK(_player->isShooting());
}

TEST_CASE("Player can either be dead or alive")
{

    player_ptr _player;
    _player =
        std::make_shared<Player>(GameConstants::_playerOriginalPositionX, GameConstants::_playerOriginalPositionY);
    _player->setActiveState(true);
    CHECK(_player->getActiveState());

    _player->setActiveState(false);
    CHECK_FALSE(_player->getActiveState());
}
/////////////////////////////ENEMY TESTS//////////////////////////////////////////
// enemy initial position bounds check
TEST_CASE("Enemy initial position cannot be beyond screen dimensions")
{

    enemy_ptr enemy;
    CHECK_THROWS_AS(
        enemy = std::make_shared<Enemy>(Direction::Right,
            ScreenDimensions::_Screen_Width - GameConstants::enemyWidth + 1, ScreenDimensions::_Screen_Height / 2.f),
        InvalidEnemyInitialPosition);

    enemy_ptr enemy2;
    CHECK_THROWS_AS(enemy2 = std::make_shared<Enemy>(
                        Direction::Right, GameConstants::enemyWidth - 1, ScreenDimensions::_Screen_Height / 2.f),
        InvalidEnemyInitialPosition);

    enemy_ptr enemy3;
    CHECK_THROWS_AS(enemy3 = std::make_shared<Enemy>(Direction::Right, ScreenDimensions::_Screen_Width / 2.f,
                        ScreenDimensions::_Screen_Height - GameConstants::enemyHeight + 1),
        InvalidEnemyInitialPosition);

    enemy_ptr enemy4;
    CHECK_THROWS_AS(enemy4 = std::make_shared<Enemy>(
                        Direction::Right, ScreenDimensions::_Screen_Width / 2.f, GameConstants::enemyHeight - 1),
        InvalidEnemyInitialPosition);
}

/// enemy movements tests
TEST_CASE("Enemy can move up, down, left and right")
{
    enemy_ptr enemy;
    enemy = std::make_shared<Enemy>(
        Direction::Down, ScreenDimensions::_Screen_Width / 2.f, ScreenDimensions::_Screen_Height / 2.f);
    auto x = enemy->getPosition().xCoord;
    auto y = enemy->getPosition().yCoord;

    enemy->move(Direction::Left);
    CHECK(x > enemy->getPosition().xCoord);

    enemy->move(Direction::Right);
    CHECK(x == enemy->getPosition().xCoord);

    enemy->move(Direction::Up);
    CHECK(y > enemy->getPosition().yCoord);

    enemy->move(Direction::Down);
    CHECK(y == enemy->getPosition().yCoord);
}

// enemy turning tests
//
TEST_CASE("Enemy can turn from either left or right")
{
    enemy_ptr enemy;
    enemy = std::make_shared<Enemy>(
        Direction::Right, ScreenDimensions::_Screen_Width / 2.f, ScreenDimensions::_Screen_Height / 2.f);
    auto y = enemy->getPosition().yCoord;

    // turning downwards
    enemy->turning(Direction::Left, true);

    CHECK((y < enemy->getPosition().yCoord));

    // turning upwards
    enemy->turning(Direction::Right, false);
    CHECK(y == enemy->getPosition().yCoord);
}

TEST_CASE("Enemy initial movement can be in either to the left or to the right")
{

    enemy_ptr enemy;
    enemy = std::make_shared<Enemy>(
        Direction::Right, ScreenDimensions::_Screen_Width / 2.f, ScreenDimensions::_Screen_Height / 2.f);

    CHECK(enemy->getDirection() == Direction::Right);

    enemy = std::make_shared<Enemy>(
        Direction::Left, ScreenDimensions::_Screen_Width / 2.f, ScreenDimensions::_Screen_Height / 2.f);

    CHECK(enemy->getDirection() == Direction::Left);
}

// movement boundaries
TEST_CASE("Enemy cannot move beyond boundaries")
{

    enemy_ptr enemy;
    enemy = std::make_shared<Enemy>(Direction::Right, ScreenDimensions::_Screen_Width - GameConstants::enemyWidth,
        ScreenDimensions::_Screen_Height / 2.f);
    auto x = enemy->getPosition().xCoord;
    auto y = enemy->getPosition().yCoord;
    enemy->move(Direction::Right);

    CHECK(x == enemy->getPosition().xCoord);

    enemy_ptr enemy2;
    enemy2 =
        std::make_shared<Enemy>(Direction::Right, GameConstants::enemyWidth, ScreenDimensions::_Screen_Height / 2.f);
    x = enemy2->getPosition().xCoord;
    y = enemy2->getPosition().yCoord;
    enemy->move(Direction::Left);

    CHECK(x == enemy2->getPosition().xCoord);

    enemy_ptr enemy3;
    enemy3 =
        std::make_shared<Enemy>(Direction::Right, ScreenDimensions::_Screen_Width / 2.f, GameConstants::enemyHeight);
    x = enemy3->getPosition().xCoord;
    y = enemy3->getPosition().yCoord;
    enemy->move(Direction::Up);

    CHECK(y == enemy3->getPosition().yCoord);

    enemy_ptr enemy4;
    enemy4 = std::make_shared<Enemy>(Direction::Right, ScreenDimensions::_Screen_Width / 2.f,
        ScreenDimensions::_Screen_Height - GameConstants::enemyHeight);
    x = enemy4->getPosition().xCoord;
    y = enemy4->getPosition().yCoord;
    enemy->move(Direction::Down);

    CHECK(y == enemy4->getPosition().yCoord);
}

TEST_CASE("Enemy can either be dead or alive")
{

    enemy_ptr enemy;
    enemy = std::make_shared<Enemy>(Direction::Right, ScreenDimensions::_Screen_Width - GameConstants::enemyWidth,
        ScreenDimensions::_Screen_Height / 2.f);

    enemy->setActiveState(true);

    CHECK(enemy->getActiveState());

    enemy->setActiveState(false);

    CHECK_FALSE(enemy->getActiveState());
}

/////////////////////////////////ARMADA TESTS////////////////////////////////////////////

// testing valid armada capacity
TEST_CASE("Armada cannot contain enemies exceeding screen size")
{

    armada_ptr _armada;
    auto cap = (ScreenDimensions::_Screen_Width) / (GameConstants::enemyWidth);
    CHECK_THROWS_AS(_armada = make_shared<Armada>(cap + 1.f, Direction::Right, true,
                        ScreenDimensions::_Screen_Width / 2.f, ScreenDimensions::_Screen_Height / 2.f),
        InvalidNumberOfEnemies);
}

// testing valid initial position
TEST_CASE("Armada initial position validated")
{

    armada_ptr _armada;
    auto cap = 3u;
    CHECK_THROWS_AS(_armada = make_shared<Armada>(cap, Direction::Right, true, GameConstants::enemyWidth / 2.f,
                        ScreenDimensions::_Screen_Height / 2.f),
        InvalidArmadaInitialPosition);

    CHECK_THROWS_AS(_armada = make_shared<Armada>(cap, Direction::Right, true,
                        (ScreenDimensions::_Screen_Width - GameConstants::enemyWidth + 2.f),
                        ScreenDimensions::_Screen_Height / 2.f),
        InvalidArmadaInitialPosition);

    CHECK_THROWS_AS(_armada = make_shared<Armada>(cap, Direction::Right, true, (ScreenDimensions::_Screen_Height / 2.f),
                        (GameConstants::enemyHeight / 2.f)),
        InvalidArmadaInitialPosition);

    CHECK_THROWS_AS(_armada = make_shared<Armada>(cap, Direction::Right, true, (ScreenDimensions::_Screen_Height / 2.f),
                        (ScreenDimensions::_Screen_Height - GameConstants::enemyHeight + 2.f)),
        InvalidArmadaInitialPosition);
}

// testing armada movements
TEST_CASE("Each enemy of the armada can move")
{

    auto cap = 2u;
    armada_ptr _armada = make_shared<Armada>(
        cap, Direction::Right, true, GameConstants::enemyWidth * 2.f, GameConstants::enemyHeight * 2.f);
    auto x1 = _armada->getArmada().at(0)->getPosition().xCoord;
    auto x2 = _armada->getArmada().at(1)->getPosition().xCoord;

    _armada->moving_all(Direction::Right);

    CHECK(x2 < _armada->getArmada().at(1u)->getPosition().xCoord);
    CHECK(x1 < _armada->getArmada().at(0u)->getPosition().xCoord);
}

TEST_CASE("Armada does not move beyond screen boundaries")
{

    auto cap = 1u;
    armada_ptr _armada = make_shared<Armada>(cap, Direction::Right, true,
        ScreenDimensions::_Screen_Width - GameConstants::enemyWidth, GameConstants::enemyHeight * 2.f);
    auto x1 = _armada->getArmada().at(0)->getPosition().xCoord;

    _armada->moving_all(Direction::Right);

    CHECK(x1 == _armada->getArmada().at(0)->getPosition().xCoord);
}

// testing initial movements
// TEST_CASE("armada initial movement can either be left or right")
//{
//    // moving to the right
//    auto cap = 2u;
//    armada_ptr _armada = make_shared<Armada>(
//        cap, Direction::Right, true, GameConstants::enemyWidth * 2.f, GameConstants::enemyHeight * 2.f);
//    auto x1 = _armada->getArmada().at(0)->getPosition().xCoord;
//    auto x2 = _armada->getArmada().at(1)->getPosition().xCoord;
//
//    _armada->move();
//
//    CHECK(x2 < _armada->getArmada().at(1u)->getPosition().xCoord);
//    CHECK(x1 < _armada->getArmada().at(0u)->getPosition().xCoord);
//
//    _armada = make_shared<Armada>(
//        cap, Direction::Left, true, GameConstants::enemyWidth * 2.f, GameConstants::enemyHeight * 2.f);
//    x1 = _armada->getArmada().at(0)->getPosition().xCoord;
//    x2 = _armada->getArmada().at(1)->getPosition().xCoord;
//
//    _armada->move();
//
//    CHECK(x2 > _armada->getArmada().at(1u)->getPosition().xCoord);
//    CHECK(x1 > _armada->getArmada().at(0u)->getPosition().xCoord);
//}
//

// armada turning tests
TEST_CASE("Armada turns either left or right")
{

    auto cap = 2u;
    armada_ptr _armada = make_shared<Armada>(cap, Direction::Right, true,
        ScreenDimensions::_Screen_Width - GameConstants::enemyWidth * 3.f, GameConstants::enemyHeight * 2.f);
    auto y1 = _armada->getArmada().at(0)->getPosition().yCoord;
    auto y2 = _armada->getArmada().at(1)->getPosition().yCoord;

    _armada->turning_all(Direction::Right);

    CHECK(y1 < _armada->getArmada().at(0)->getPosition().yCoord);
    CHECK(y2 < _armada->getArmada().at(1)->getPosition().yCoord);
    //
    _armada =
        make_shared<Armada>(cap, Direction::Left, false, GameConstants::enemyWidth, GameConstants::enemyHeight * 2.f);
    y1 = _armada->getArmada().at(0)->getPosition().yCoord;
    y2 = _armada->getArmada().at(1)->getPosition().yCoord;

    _armada->turning_all(Direction::Left);

    CHECK(y1 > _armada->getArmada().at(0)->getPosition().yCoord);
    CHECK(y2 > _armada->getArmada().at(1)->getPosition().yCoord);
}

// state testing

TEST_CASE("true if armada has enemies and false if armada has no enemies")
{
    auto cap = 2u;
    armada_ptr _armada = make_shared<Armada>(
        cap, Direction::Right, true, GameConstants::enemyWidth * 2.f, GameConstants::enemyHeight * 2.f);

    _armada->setState();

    CHECK(_armada->getState());

    _armada = make_shared<Armada>(0u, Direction::Right, true,
        ScreenDimensions::_Screen_Width - GameConstants::enemyWidth, GameConstants::enemyHeight * 2.f);

    _armada->setState();
    CHECK_FALSE(_armada->getState());
}

//////////////////ARMY TESTING/////////////
// valid rows testing
TEST_CASE("Row of armies cannot exceed screen dimensions")
{

    auto capi = (ScreenDimensions::_Screen_Height / GameConstants::enemyHeight) + 2.f;

    army_ptr _armada;
    CHECK_THROWS_AS(
        _armada = std::make_shared<Army>(GameConstants::armada_width_size, capi, Direction::Right, true,
            GameConstants::enemyWidth, ScreenDimensions::_Screen_Height / 2.f + GameConstants::enemyHeight / 2.f, true),
        InvalidRowsOfArmy);
}

// movement time delay test
TEST_CASE("Army moves after 0.5 seconds")
{

    // auto army_dimensions = 1u;
    army_ptr _army = std::make_shared<Army>(GameConstants::armada_width_size, GameConstants::armada_height_size,
        Direction::Right, true, GameConstants::enemyWidth,
        ScreenDimensions::_Screen_Height / 2.f + GameConstants::enemyHeight / 2.f, true);

    auto xpos = _army->getArmy().at(0)->getArmada().at(0)->getPosition().xCoord;

    _army->move();

    if(_army->delay())
        CHECK(xpos < (_army->getArmy().at(0)->getArmada().at(0)->getPosition().xCoord));
}

//
//// initial movement test
// TEST_CASE("Army movement initialised to either left or right")
//{
//
//    /// initial right
//    army_ptr _army = std::make_shared<Army>(GameConstants::armada_width_size, GameConstants::armada_height_size,
//        Direction::Right, true, GameConstants::enemyWidth,
//        ScreenDimensions::_Screen_Height / 2.f + GameConstants::enemyHeight / 2.f, true);
//
//    auto xpos = _army->getArmy().at(0)->getArmada().at(0)->getPosition().xCoord;
//
//    _army->move();
//
//    if(_army->delay())
//        CHECK(xpos < (_army->getArmy().at(0)->getArmada().at(0)->getPosition().xCoord));
//
//    /// initial left
//    _army = std::make_shared<Army>(GameConstants::armada_width_size, GameConstants::armada_height_size,
//    Direction::Left,
//        true, GameConstants::enemyWidth * 5.f,
//        ScreenDimensions::_Screen_Height / 2.f + GameConstants::enemyHeight / 2.f, true);
//
//    xpos = _army->getArmy().at(0)->getArmada().at(0)->getPosition().xCoord;
//
//    _army->move();
//
//    if(_army->delay())
//        CHECK(xpos > (_army->getArmy().at(0)->getArmada().at(0)->getPosition().xCoord));
//}
//

//// turning test
TEST_CASE("Army turn (up or down)to either left or right at screen boundaries")
{

    /****
     * TESTS FOR TURNING DOWN
     * */
    army_ptr _army = std::make_shared<Army>(GameConstants::armada_width_size, GameConstants::armada_height_size,
        Direction::Left, true, GameConstants::enemyWidth,
        ScreenDimensions::_Screen_Height / 2.f + GameConstants::enemyHeight / 2.f, true);

    auto ypos = _army->getArmy().at(0)->getArmada().at(0)->getPosition().yCoord;

    _army->move();

    if(_army->delay())
        CHECK(ypos < (_army->getArmy().at(0)->getArmada().at(0)->getPosition().yCoord));

    auto cap = 1u;
    _army = std::make_shared<Army>(cap, cap, Direction::Right, true,
        ScreenDimensions::_Screen_Width - GameConstants::enemyWidth,
        ScreenDimensions::_Screen_Height / 2.f + GameConstants::enemyHeight / 2.f, true);

    ypos = _army->getArmy().at(0)->getArmada().at(0)->getPosition().yCoord;

    _army->move();

    if(_army->delay())
        CHECK(ypos < (_army->getArmy().at(0)->getArmada().at(0)->getPosition().yCoord));

    /****
     * TESTS FOR TURNING UP
     * */
    _army = std::make_shared<Army>(GameConstants::armada_width_size, GameConstants::armada_height_size, Direction::Left,
        true, GameConstants::enemyWidth, ScreenDimensions::_Screen_Height / 2.f + GameConstants::enemyHeight / 2.f,
        true);

    ypos = _army->getArmy().at(0)->getArmada().at(0)->getPosition().yCoord;

    _army->move();

    if(_army->delay())
        CHECK(ypos > (_army->getArmy().at(0)->getArmada().at(0)->getPosition().yCoord));

    cap = 1u;
    _army = std::make_shared<Army>(cap, cap, Direction::Right, true,
        ScreenDimensions::_Screen_Width - GameConstants::enemyWidth,
        ScreenDimensions::_Screen_Height / 2.f + GameConstants::enemyHeight / 2.f, true);

    ypos = _army->getArmy().at(0)->getArmada().at(0)->getPosition().yCoord;

    _army->move();

    if(_army->delay())
        CHECK(ypos > (_army->getArmy().at(0)->getArmada().at(0)->getPosition().yCoord));
}

// army death test
TEST_CASE("Army state can either be alive or dead")
{

    // Alive testing
    army_ptr _army = std::make_shared<Army>(GameConstants::armada_width_size, GameConstants::armada_height_size,
        Direction::Left, true, GameConstants::enemyWidth,
        ScreenDimensions::_Screen_Height / 2.f + GameConstants::enemyHeight / 2.f, true);
    _army->setState();

    CHECK(_army->getState());

    // Dead testing
    _army = std::make_shared<Army>(0u, 0u, Direction::Left, true, GameConstants::enemyWidth,
        ScreenDimensions::_Screen_Height / 2.f + GameConstants::enemyHeight / 2.f, true);
    _army->setState();

    CHECK_FALSE(_army->getState());
}

TEST_CASE("Army initial position validated")
{

    army_ptr _army;
    // x position less than enemy width
    CHECK_THROWS_AS(_army = std::make_shared<Army>(GameConstants::armada_width_size, GameConstants::armada_height_size,
                        Direction::Left, true, GameConstants::enemyWidth / 2.f,
                        ScreenDimensions::_Screen_Height / 2.f + GameConstants::enemyHeight / 2.f, true),
        InvalidArmyInitialPosition);

    // x position greter than screen width
    CHECK_THROWS_AS(_army = std::make_shared<Army>(GameConstants::armada_width_size, GameConstants::armada_height_size,
                        Direction::Left, true, ScreenDimensions::_Screen_Width - GameConstants::enemyWidth + 2.f,
                        ScreenDimensions::_Screen_Height / 2.f + GameConstants::enemyHeight / 2.f, true),
        InvalidArmyInitialPosition);

    // y position less than enemy height
    CHECK_THROWS_AS(_army = std::make_shared<Army>(GameConstants::armada_width_size, GameConstants::armada_height_size,
                        Direction::Left, true, GameConstants::enemyWidth, GameConstants::enemyHeight / 2.f, true),
        InvalidArmyInitialPosition);

    // y position greater than screen height
    CHECK_THROWS_AS(_army = std::make_shared<Army>(GameConstants::armada_width_size, GameConstants::armada_height_size,
                        Direction::Left, true, GameConstants::enemyWidth,
                        ScreenDimensions::_Screen_Height - GameConstants::enemyHeight + 2.f, true),
        InvalidArmyInitialPosition);
}

//////////////////BULLET TESTING/////////////////
// initial position
TEST_CASE("Bullet initial position cannot be beyond screen")
{

    bullet_ptr bul;
    CHECK_THROWS_AS(bul = make_shared<Bullet>(ScreenDimensions::_Screen_Width - GameConstants::bulletObjectWidth + 2.f,
                        ScreenDimensions::_Screen_Height / 2.f),
        InvalidInitialBulletPosition);

    CHECK_THROWS_AS(
        bul = make_shared<Bullet>(GameConstants::bulletObjectWidth / 2.f, ScreenDimensions::_Screen_Height / 2.f),
        InvalidInitialBulletPosition);

    CHECK_THROWS_AS(bul = make_shared<Bullet>(ScreenDimensions::_Screen_Width / 2.f,
                        ScreenDimensions::_Screen_Height - GameConstants::bulletObjectHeight + 2.f),
        InvalidInitialBulletPosition);

    CHECK_THROWS_AS(
        bul = make_shared<Bullet>(ScreenDimensions::_Screen_Width / 2.f, GameConstants::bulletObjectHeight / 2.f),
        InvalidInitialBulletPosition);
}

// bullet movement

TEST_CASE("bullet can move up or down")
{

    bullet_ptr bul = make_shared<Bullet>(ScreenDimensions::_Screen_Width / 2.f, ScreenDimensions::_Screen_Height / 2.f);
    auto ypos = bul->getPosition().yCoord;

    bul->move(Direction::Down);

    CHECK(ypos < bul->getPosition().yCoord);

    bul->move(Direction::Up);

    CHECK(ypos == bul->getPosition().yCoord);
}
// state testing
TEST_CASE("Bullets can either be active or non Active")
{

    bullet_ptr bul = make_shared<Bullet>(
        ScreenDimensions::_Screen_Width / 2.f, ScreenDimensions::_Screen_Height - GameConstants::bulletObjectHeight);

    bul->setActiveState(true);

    CHECK(bul->getActiveState());

    bul->setActiveState(false);

    CHECK_FALSE(bul->getActiveState());
}
// out of bounds
TEST_CASE("bullet is destroyed once it gets out of bounds")
{

    bullet_ptr bul = make_shared<Bullet>(
        ScreenDimensions::_Screen_Width / 2.f, ScreenDimensions::_Screen_Height - GameConstants::bulletObjectHeight);

    bul->move(Direction::Down);
    bul->move(Direction::Down);

    CHECK_FALSE(bul->getActiveState());

    bul = make_shared<Bullet>(ScreenDimensions::_Screen_Width / 2.f, GameConstants::bulletObjectHeight);

    bul->move(Direction::Up);
    bul->move(Direction::Up);

    CHECK_FALSE(bul->getActiveState());
}

//////////////////////////BULLETLOADER TESTING/////////
// bullets are loaded
TEST_CASE("Bullets are successfully loaded after player shoots")
{

    player_ptr _player =
        std::make_shared<Player>(GameConstants::_playerOriginalPositionX, GameConstants::_playerOriginalPositionY);
    bulletLoader_ptr bullets = std::make_unique<BulletLoader>(_player);
    _player->shoot();

    CHECK(bullets->LoadBullet());
}

// bullet loaded at a middle top position of player
TEST_CASE("Bullets are at the same position as player")
{

    player_ptr _player =
        std::make_shared<Player>(GameConstants::_playerOriginalPositionX, GameConstants::_playerOriginalPositionY);
    bulletLoader_ptr bullets = std::make_unique<BulletLoader>(_player);

    _player->shoot();
    bullets->LoadBullet();
    bullets->LoadBullet();

    CHECK((bullets->getBullets().at(0)->getPosition().xCoord) == (_player->getPosition().xCoord));
    CHECK((bullets->getBullets().at(0)->getPosition().yCoord) == (_player->getPosition().yCoord));
}

/////////////////////COLLISIONS TESTING///////////////
TEST_CASE("true if two moveable characters have collided and false otherwise")
{

    collision_ptr col = std::make_shared<Collisions>();

    player_ptr _player = std::make_shared<Player>(80.f, 80.f);

    enemy_ptr enemy;
    enemy = std::make_shared<Enemy>(Direction::Down, 180.f, 180.f);

    CHECK_FALSE(col->collided(_player, enemy));

    enemy = std::make_shared<Enemy>(Direction::Down, 80.f, 80.f);
    
    CHECK(col->collided(_player, enemy));
}

///////////////////////////////////COLLISIONHANDLING TESTING//////////////////////////////

//bullet to enemy collision 

TEST_CASE("both enemy and bullet are destroyed after collision"){
    
    player_ptr _player = std::make_shared<Player>(80.f,80.f);
    
        army_ptr army = std::make_shared<Army>(2u, 2u,
        Direction::Right, true, 80.f,
        80.f, true);
        
    bulletLoader_ptr bullets = std::make_unique<BulletLoader>(_player);
    
     collision_ptr col = std::make_shared<Collisions>();
     
     collision_handling_ptr handling_col = std::make_unique<CollisionHandling>(col);
     
     _player->shoot();
    
    bullets->LoadBullet();
//    
    handling_col->bullet_enemy_col(bullets,army);
    auto i = bullets->getBullets().at(0);
    auto j = army->getArmy().at(0)->getArmada().at(0);
//    
    CHECK_FALSE(i->getActiveState());
    CHECK_FALSE(j->getActiveState());
    
    
}



//bullet to player collision test 

TEST_CASE("both enemy and bullet are destroyed after collision"){
    
    player_ptr _player = std::make_shared<Player>(75.f,75.f);
    player_ptr _player2 = std::make_shared<Player>(80.f,80.f);
    
        
    bulletLoader_ptr bullets = std::make_unique<BulletLoader>(_player);
    
     collision_ptr col = std::make_shared<Collisions>();
     
     collision_handling_ptr handling_col = std::make_unique<CollisionHandling>(col);
     
    _player->shoot();
    bullets->LoadBullet();
//    
    handling_col->bullet_player_col(bullets,_player2);
    auto i = bullets->getBullets().at(0);
//    
    CHECK_FALSE(i->getActiveState());
    CHECK_FALSE(_player2->getActiveState());
    
    
}


//bullet to bullet test
TEST_CASE("both enemy and bullet are destroyed after collision"){
    
    player_ptr _player = std::make_shared<Player>(75.f,75.f);
    player_ptr _player2 = std::make_shared<Player>(80.f,80.f);
    
        
    bulletLoader_ptr bullets = std::make_unique<BulletLoader>(_player);
    bulletLoader_ptr bullets2 = std::make_unique<BulletLoader>(_player2);
    
    
     collision_ptr col = std::make_shared<Collisions>();
     
     collision_handling_ptr handling_col = std::make_unique<CollisionHandling>(col);
     
    _player->shoot();
    _player2->shoot();
    bullets->LoadBullet();
    bullets2->LoadBullet();
//    
    handling_col->bullet_bullet_col(bullets,bullets2);
    auto i = bullets->getBullets().at(0);
    auto j = bullets2->getBullets().at(0);
//    
    CHECK_FALSE(i->getActiveState());
    CHECK_FALSE(j->getActiveState());
    
    
}







