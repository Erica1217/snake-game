#ifndef _GAME_MANAGER_
#define _GAME_MANAGER_

#include "GameFlow.h"
#include "Game.h"
#include "GameSettings.h"

using namespace std;

class GameManager
{
public :
    
    GameManager(GameFlow& gameflow);

    void start();
    void end();
    void setInput();
    int isValid();
    void update(const int tick);

    vector<vector<int> > getCurMap();
private :
    int tick;
    int curStage;
    Game* games;
    Game* curGame;

    GameFlow* game_flow;

    void stageSetting(const int score);
};

#endif