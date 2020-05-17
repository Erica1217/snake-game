#ifndef _GAME_MANAGER_
#define _GAME_MANAGER_

#include <vector>
#include "GameFlow.h"

using namespace std;

class GameManager
{
public :
    int curStage = 0;
    bool isValid = true;
    
    GameManager(GameFlow& gameflow);

    void Start();
    void SetInput(int input_key);
    int IsStageClear();
    int IsValid();
    void Update();

    vector<vector<int>> GetCurMap();
private :
    bool isClear = false;
    int key = 0;

    GameFlow game_flow;
    vector<vector<int>> cur_map; // 현재 스테이지 맵. 전체맵정보는 따로만들어놓고 거기서 가져오기

    vector<vector<vector<int>>> maps;

    void StageSetting();
};

#endif