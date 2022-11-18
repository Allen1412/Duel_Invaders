

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "GameObjectProperties.h"
#include "GameStates.h"

typedef sf::Clock gameClock;
/**
 * @class GamePlay
 * @author Phetolo Malele(1412331),  Kananelo Kortjaas (605016)
 * @date 19/09/2019
 * @file GamePlay.h
 * @brief class that manages the logic of the game
 */

class  GamePlay{
public:
GamePlay();
~GamePlay();
          /**
         * @brief function that executes the game logic while window is open
         */
        void ExecuteLogic();
private:
gameClock _gameClock;
_gameResources _gameData;

    
    };
#endif


















