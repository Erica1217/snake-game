#include "GameManager.h"
#include "kbhit.h"
#include <vector>

using namespace std;

GameManager::GameManager()
{
    // 아무거나 넣어놨음
    vector<int> row1 = {1, 1, 1, 1, 1};
    vector<int> row2 = {1, 0, 0, 0, 1};
    vector<int> row3 = {1, 0, 0, 0, 1};
    vector<int> row4 = {1, 0, 0, 0, 1};
    vector<int> row5 = {1, 1, 1, 1, 1};

    cur_map.push_back(row1);
    cur_map.push_back(row2);
    cur_map.push_back(row3);
    cur_map.push_back(row4);
    cur_map.push_back(row5);
}

// 게임 시작 시 한번
void GameManager::Start()
{

}

// 매 프레임, 유효성 검사만
int GameManager::IsValid()
{
    if(kbhit())
    {
        getchar();
        return 0;
    }

    return 1;
}

// 매 프레임, 게임데이터 업데이트
void GameManager::Update()
{
    cur_map[2][2]++;
    if(cur_map[2][2] > 9)
    {
        cur_map[2][2] = 0;
    }
}

// UI Manager 가 프레임마다 최종적으로 그려야 하는 데이터 (맵+뱀+게이트+아이템)
vector<vector<int>> GameManager::GetCurMap()
{
    return cur_map;
}