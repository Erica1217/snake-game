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

    void Start();
    void End();
    void SetInput();
    int IsValid();
    void Update(int tick);

    vector<vector<int>> GetCurMap();
private :
    int curStage;
    Game* games;
    Game* curGame;

    GameFlow game_flow;

    void StageSetting();
};

#endif