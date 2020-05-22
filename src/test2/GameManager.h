#ifndef _GAME_MANAGER_
#define _GAME_MANAGER_

#include "GameSettings.h"
#include "GameFlow.h"
#include "Game.h"

using namespace std;

class GameManager
{
public :
    
    GameManager(GameFlow& gameflow);

    void Start();
    void SetInput(int input_key);
    int IsStageClear();
    int IsValid();
    void Update();

    vector<vector<int>> GetCurMap();
private :
    int curStage;
    Game* games;
    Game* curGame;

    GameFlow game_flow;

    void StageSetting();
};

#endif