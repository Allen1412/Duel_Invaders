#include "BulletLoader.h"
#include "GameStates.h"
#include "State.h"
#include <iostream>
SplashState::SplashState(_gameResources Data)
    : _gameData(Data)
{
}

void SplashState::initial_state()
{
    Create_Screen();
}

void SplashState::input_handler()
{
    sf::Event _event;
    while(_gameData->gameScreen_.getGameScreen().pollEvent(_event)) {
        if(_event.type == sf::Event::Closed) {
            _gameData->gameScreen_.CloseGameScreen();
            //    _gameData -> gameScreen_.CloseGameScreen();
        }
        CheckForInput();
    }
}
void SplashState::state_update()
{
}

void SplashState::draw_State()
{

    _gameData->gameScreen_.ClearScreen();
    _gameData->gameScreen_.DrawToGameScreen(_backSprite);
    _gameData->gameScreen_.UpdateGameScreen();
}

void SplashState::Create_Screen()
{
    _gameData->gameScreen_.CreateScreen(ScreenDimensions::_Screen_Width, ScreenDimensions::_Screen_Height,
        "SplashScreen", static_cast<uint32_t>(WindowType::NONE));

    _gameData->_resources.texture_loader(Texture_::Splashscreen, filepath::splash_file_path);
    _backSprite.setTexture(_gameData->_resources.get_texture(Texture_::Splashscreen));
}
void SplashState::CheckForInput()
{
    if(_gameData->_input.isButtonPressed(Key::Enter))
        _gameData->_states.adding_state(state_ptr(new MainMenu(this->_gameData)), true);

    if(_gameData->_input.isButtonPressed(Key::Escape)) {
        _gameData->gameScreen_.CloseGameScreen();
    }
}

SplashState::~SplashState()
{
}

//////////////////////////////////////////////////////////////////////////////////////
MainMenu::MainMenu(_gameResources Data)
    : _gameData(Data)
{
}

void MainMenu::initial_state()
{
    Create_Screen();
}

void MainMenu::input_handler()
{
    sf::Event _event;
    while(_gameData->gameScreen_.getGameScreen().pollEvent(_event)) {
        if(_event.type == sf::Event::Closed) {
            _gameData->gameScreen_.CloseGameScreen();
            //    _gameData -> gameScreen_.CloseGameScreen();
        }
        CheckForInput();
    }
}

void MainMenu::state_update()
{
}

void MainMenu::draw_State()
{

    _gameData->gameScreen_.ClearScreen();
    _gameData->gameScreen_.DrawToGameScreen(_menuSprite);
    _gameData->gameScreen_.UpdateGameScreen();
}

void MainMenu::Create_Screen()
{
    _gameData->gameScreen_.CreateScreen(ScreenDimensions::_Screen_Width, ScreenDimensions::_Screen_Height, "MainMenu",
        static_cast<uint32_t>(WindowType::NONE));

    _gameData->_resources.texture_loader(Texture_::MainMenu_, filepath::menu_file_path);
    _menuSprite.setTexture(_gameData->_resources.get_texture(Texture_::MainMenu_));
}

void MainMenu::CheckForInput()
{

    // if(_gameData->_input.isButtonPressed(Key::P))
    ///_gameData->_states.adding_state(state_ptr(new MainMenu(this->_gameData)));;

    if(_gameData->_input.isButtonPressed(Key::Escape)) {
        _gameData->gameScreen_.CloseGameScreen();
    }
    if(_gameData->_input.isButtonPressed(Key::P))
        _gameData->_states.adding_state(state_ptr(new GameMode(this->_gameData)), true);
}

MainMenu::~MainMenu()
{
}

////////////////////////xx////////////////////////////
GameMode::GameMode(_gameResources Data)
    : _gameData(Data)
{
}

void GameMode::initial_state()
{

    Create_Screen();
    _player =
        std::make_shared<Player>(GameConstants::_playerOriginalPositionX, GameConstants::_playerOriginalPositionY);
    _player2 =
        std::make_shared<Player>(GameConstants::_playerOriginalPositionX_2, GameConstants::_playerOriginalPositionY_2);

    player_ = std::make_shared<PlayerDrawable>(_player, _gameData->_resources, filepath::player_file_path);
    player_2 = std::make_shared<PlayerDrawable>(_player2, _gameData->_resources, filepath::player2_file_path);

    bullets_1 = std::make_unique<BulletLoader>(_player);
    bullets_2 = std::make_unique<BulletLoader>(_player2);
    //    _bullet_2 = std::make_unique<BulletLoader>(_player2);

    //    _armada = std::make_shared<Armada>(GameConstants::armada_width_size, Direction::Right, true,
    //        GameConstants::enemyWidth, ScreenDimensions::_Screen_Height / 2.f + GameConstants::enemyHeight);
    //
    //    _armada2 = std::make_shared<Armada>(GameConstants::armada_width_size, Direction::Right, false,
    //        GameConstants::enemyWidth, ScreenDimensions::_Screen_Height / 2.f - GameConstants::enemyHeight);

    _army = std::make_shared<Army>(GameConstants::armada_width_size, GameConstants::armada_height_size,
        Direction::Right, true, GameConstants::enemyWidth,
        ScreenDimensions::_Screen_Height / 2.f + GameConstants::enemyHeight / 2.f, true);
    _army2 = std::make_shared<Army>(GameConstants::armada_width_size, GameConstants::armada_height_size,
        Direction::Right, false, GameConstants::enemyWidth,
        ScreenDimensions::_Screen_Height / 2.f - GameConstants::enemyHeight / 2.f, false);

    //    create_armada_drawable(_armada->armada_size(), _armadaObjects, _armada);
    //    create_armada_drawable(_armada2->armada_size(), _armadaObjects2, _armada2);
    create_army_drawable(GameConstants::armada_width_size, GameConstants::armada_height_size, _armyObjects, _army,
        filepath::enemy_file_path);
    create_army_drawable(GameConstants::armada_width_size, GameConstants::armada_height_size, _armyObjects2, _army2,
        filepath::enemy_file_path1);

    collisions = std::make_shared<Collisions>();
    handling_col = std::make_unique<CollisionHandling>(collisions);
}
//
//
//    //    for(auto i = 0; i < 100; i++){
//    //        enemies.at(i) = make_shared
//    //
//    //        }
//    //
//    _enemy = std::make_shared<Enemy>(GameConstants::_enemyOrgPosX, GameConstants::_enemyOrgPosY);
//    enemy_draw = std::make_unique<EnemyDrawable>(_enemy, _gameData->_resources, filepath::enemy_file_path);
//
//    _enemy1 = std::make_shared<Enemy>(GameConstants::_enemyOrgPosX, GameConstants::_enemyOrgPosY - 50);
//    enemy_draw1 = std::make_unique<EnemyDrawable>(_enemy1, _gameData->_resources, filepath::enemy_file_path1);
//
//    _bullet_1 = std::make_unique<BulletLoader>(_player);
//    _bullet_2 = std::make_unique<BulletLoader>(_player2);}
//}
void GameMode::input_handler()
{
    sf::Event _event;
    while(_gameData->gameScreen_.getGameScreen().pollEvent(_event)) {
        if(_event.type == sf::Event::Closed) {
            _gameData->gameScreen_.CloseGameScreen();
        }
        CheckForInput();
    }
}

void GameMode::state_update()
{

    player_->UpdatePlayerDrawable();
    //
    player_2->UpdatePlayerDrawable();

    //    _armada->move();
    //    _armada2->move();
    _army->move();
    _army2->move();

    moveBullet(bullets_1, Direction::Up, bullet_objects_1);
    moveBullet(bullets_2, Direction::Down, bullet_objects_2);

    handling_col->bullet_enemy_col(bullets_1, _army);
    handling_col->bullet_enemy_col(bullets_1, _army2);

    handling_col->bullet_enemy_col(bullets_2, _army);

    handling_col->bullet_enemy_col(bullets_2, _army2);

    handling_col->bullet_bullet_col(bullets_1, bullets_2);

    handling_col->bullet_player_col(bullets_1, _player2);
    handling_col->bullet_player_col(bullets_2, _player);

 

    for(auto i = 0u; i < _armyObjects.size(); i++) {
        for(auto j = 0u; j < _armyObjects[i].size(); j++) {
            _armyObjects[i][j]->UpdateEnemyDrawable();
        }
    }

    for(auto i = 0u; i < _armyObjects2.size(); i++) {
        for(auto j = 0u; j < _armyObjects2[i].size(); j++) {
            _armyObjects2[i][j]->UpdateEnemyDrawable();
        }
    }
    
    
    enemycollision(_army, _armyObjects);
    enemycollision(_army2, _armyObjects2);

    if(!_player->getActiveState() || !_player2->getActiveState())
        _gameData->_states.adding_state(state_ptr(new GameOverLose(this->_gameData)), true);

    if(!_army->getState() && !_army2->getState())
        _gameData->_states.adding_state(state_ptr(new GameOverWin(this->_gameData)), true);

    if(isInvasion(_army, true) || isInvasion(_army2, false))
        _gameData->_states.adding_state(state_ptr(new GameOverLose(this->_gameData)), true);
}

void GameMode::draw_State()
{
    //
    _gameData->gameScreen_.ClearScreen();
    _gameData->gameScreen_.DrawToGameScreen(_background);
    _gameData->gameScreen_.DrawToGameScreen(*player_);
    _gameData->gameScreen_.DrawToGameScreen(*player_2);

    for(const auto& i : bullet_objects_1)
        _gameData->gameScreen_.DrawToGameScreen(*i);

    for(const auto& i : bullet_objects_2)
        _gameData->gameScreen_.DrawToGameScreen(*i);

    for(const auto& i : _armyObjects) {
        for(const auto& j : i)
            _gameData->gameScreen_.DrawToGameScreen(*j);
    }

    for(const auto& i : _armyObjects2) {
        for(const auto& j : i)
            _gameData->gameScreen_.DrawToGameScreen(*j);
    }
    _gameData->gameScreen_.UpdateGameScreen();
}
//
void GameMode::moveBullet(bulletLoader_ptr& bulletss, Direction dir, std::vector<std::unique_ptr<BulletDrawable>>& bul)
{

    for(auto i = 0u; i < bulletss->getBullets().size(); i++) {

        if(bulletss->getBullets().at(i)->getActiveState() && bulletss->getBullets().size() > 0 && bul.size() > 0) {
            bulletss->getBullets().at(i)->move(dir);
            bul.at(i)->UpdateBulletDrawable();
        } else {

            if(bulletss->getBullets().size() > 0 && bul.size() > 0) {
             
                bul.erase(bul.begin() + i);
                bulletss->decreaseNumberOfBullets();
                
                   bulletss->getBullets().erase(bulletss->getBullets().begin() + i);
            }
        }
    }
}

void GameMode::Create_Screen()
{
    _gameData->gameScreen_.CreateScreen(ScreenDimensions::_Screen_Width, ScreenDimensions::_Screen_Height, "GameMode",
        static_cast<uint32_t>(WindowType::NONE));
    //
    _gameData->_resources.texture_loader(Texture_::Game_Screen, filepath::game_screen_file_path);
    _background.setTexture(_gameData->_resources.get_texture(Texture_::Game_Screen));
}

void GameMode::CheckForInput()
{
    //
    if(_gameData->_input.isButtonPressed(Key::Escape)) {
        _gameData->gameScreen_.CloseGameScreen();
    }
    //
    if(_gameData->_input.isButtonPressed(Key::Left)) {
        _player->move(Direction::Left);
    }

    if(_gameData->_input.isButtonPressed(Key::Right)) {
        _player->move(Direction::Right);
    }

    if(_gameData->_input.isButtonPressed(Key::A)) {
        _player2->move(Direction::Left);
    }
    //
    if(_gameData->_input.isButtonPressed(Key::D)) {
        _player2->move(Direction::Right);
    }

    if(_gameData->_input.isButtonPressed(Key::Space)) {

        _player->shoot();

        if(bullets_1->LoadBullet()) {
            auto bullet = std::make_unique<BulletDrawable>(bullets_1->getBullets().back(), _gameData->_resources);
            bullet_objects_1.push_back(std::move(bullet));
        }
    }

    if(_gameData->_input.isButtonPressed(Key::S)) {

        _player2->shoot();

        if(bullets_2->LoadBullet()) {
            auto bullet = std::make_unique<BulletDrawable>(bullets_2->getBullets().back(), _gameData->_resources);
            bullet_objects_2.push_back(std::move(bullet));
        }
    }
}

void GameMode::create_army_drawable(const unsigned& val,
    const unsigned& val2,
    armyVec& _arm,
    const army_ptr& _armyy,
    const string& fl)

{
    for(auto i = 0u; i < val2; i++) {

        std::vector<std::unique_ptr<EnemyDrawable>> en;

        for(auto j = 0u; j < val; j++) {
            auto enem =
                std::make_unique<EnemyDrawable>(_armyy->getArmy().at(i)->getArmada().at(j), _gameData->_resources, fl);
            en.push_back(std::move(enem));
        }

        _arm.push_back(std::move(en));
    }
}

void GameMode::enemycollision(army_ptr& arm, armyVec& army_obj)
{
    
//    
    for(auto i = 0u; i < army_obj.size(); i++) {

        for(auto j = 0u; j <army_obj[i].size(); j++) {
            
            if(!(arm->getArmy().at(i)->getArmada().at(j)->getActiveState())) {
                arm->getArmy()[i]->getArmada().erase(arm->getArmy()[i]->getArmada().begin() + j);
                army_obj[i].erase(army_obj[i].begin() + j);
            }
        }
    }
    

//        for(auto i = 0u; i < army_obj.size(); i++) {
//
//        for(auto j = 0u; j <army_obj[i].size(); j++) {
//           
//            if(!(arm->getArmy().at(i)->getArmada().at(j)->getActiveState())) {
//                arm->getArmy()[i]->getArmada().erase(arm->getArmy()[i]->getArmada().begin() + j);
//                //std::cout << arm->getArmy().capacity() << std::endl;
//                army_obj[i].erase(army_obj[i].begin() + j);
//            }
//        }
//    }
    
    
//    
//    for(auto i=army_obj.begin(); i!=army_obj.end(); i++){
//    
//    for(auto j = (*i).begin(); j!=(*i).end(); j++)
//    {
//          if(!(*j)->getActiveState()){
//              
//              (*i)->getArmada().erase(--j);
//              
//          }
//    }
//    
//}
//
//   for(auto i=arm->getArmy().begin(); i!=arm->getArmy().end(); i++){
//    
//    for(auto j = (*i)->getArmada().begin(); j!=(*i)->getArmada().end(); j++)
//    {
//          if(!(*j)->getActiveState()){
//              
//              (*i)->getArmada().erase(--j);
//              
//          }
//    }
//    
//}





    arm->setState();
    
}




//    
//   for(auto& i : arm->getArmy()) {
//        for(auto& j : i->getArmada()) {
//
//            if(!j->getActiveState()){
//                   
//                    i->getArmada().erase(*j);
//                }
//        }
//   }







bool GameMode::isInvasion(army_ptr arm, const bool& upper)
{

    for(auto i = 0u; i < arm->getArmy().size(); i++) {

        if(upper) {
            if((arm->getArmy().at(i)->getArmada().at(arm->getArmy().at(i)->getArmada().size() - 1u))->getPosition().yCoord >=
                ScreenDimensions::_Screen_Height - 2.f*GameConstants::playerHeight)
                return true;
        } else {

            if((arm->getArmy().at(i)->getArmada().at(arm->getArmy().at(i)->getArmada().size() - 1u))->getPosition().yCoord <=
                1.5f*GameConstants::playerHeight)
                return true;
        }
    }
    
    return false;
}

GameOverWin::GameOverWin(_gameResources Data)
    : _gameData(Data)
{
}

void GameOverWin::initial_state()
{
    Create_Screen();
}

void GameOverWin::input_handler()
{
    sf::Event _event;
    while(_gameData->gameScreen_.getGameScreen().pollEvent(_event)) {
        if(_event.type == sf::Event::Closed) {
            _gameData->gameScreen_.CloseGameScreen();
            //    _gameData -> gameScreen_.CloseGameScreen();
        }
        CheckForInput();
    }
}

void GameOverWin::state_update()
{
}

void GameOverWin::draw_State()
{

    _gameData->gameScreen_.ClearScreen();
    _gameData->gameScreen_.DrawToGameScreen(_backSprite);
    _gameData->gameScreen_.UpdateGameScreen();
}

void GameOverWin::Create_Screen()
{
    _gameData->gameScreen_.CreateScreen(ScreenDimensions::_Screen_Width, ScreenDimensions::_Screen_Height,
        "SplashScreen", static_cast<uint32_t>(WindowType::NONE));

    _gameData->_resources.texture_loader(Texture_::GameWon, filepath::win_file_path);
    _backSprite.setTexture(_gameData->_resources.get_texture(Texture_::GameWon));
}
void GameOverWin::CheckForInput()
{
    if(_gameData->_input.isButtonPressed(Key::P))
        _gameData->_states.adding_state(state_ptr(new GameMode(this->_gameData)), true);

    if(_gameData->_input.isButtonPressed(Key::Escape)) {
        _gameData->gameScreen_.CloseGameScreen();
    }
}

GameOverWin::~GameOverWin()
{
}

GameOverLose::GameOverLose(_gameResources Data)
    : _gameData(Data)
{
}

void GameOverLose::initial_state()
{
    Create_Screen();
}

void GameOverLose::input_handler()
{
    sf::Event _event;
    while(_gameData->gameScreen_.getGameScreen().pollEvent(_event)) {
        if(_event.type == sf::Event::Closed) {
            _gameData->gameScreen_.CloseGameScreen();
            //    _gameData -> gameScreen_.CloseGameScreen();
        }
        CheckForInput();
    }
}

void GameOverLose::state_update()
{
}

void GameOverLose::draw_State()
{

    _gameData->gameScreen_.ClearScreen();
    _gameData->gameScreen_.DrawToGameScreen(_backSprite);
    _gameData->gameScreen_.UpdateGameScreen();
}

void GameOverLose::Create_Screen()
{
    _gameData->gameScreen_.CreateScreen(ScreenDimensions::_Screen_Width, ScreenDimensions::_Screen_Height,
        "SplashScreen", static_cast<uint32_t>(WindowType::NONE));

    _gameData->_resources.texture_loader(Texture_::GameWon, filepath::lose_file_path);
    _backSprite.setTexture(_gameData->_resources.get_texture(Texture_::GameWon));
}
void GameOverLose::CheckForInput()
{
    if(_gameData->_input.isButtonPressed(Key::P))
        _gameData->_states.adding_state(state_ptr(new GameMode(this->_gameData)), true);

    if(_gameData->_input.isButtonPressed(Key::Escape)) {
        _gameData->gameScreen_.CloseGameScreen();
    }
}

GameOverLose::~GameOverLose()
{
}
