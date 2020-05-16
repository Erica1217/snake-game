#include "GameManager.h"
#include "kbhit.h"
#include <vector>

using namespace std;

GameManager::GameManager()
{
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

void GameManager::StartGame()
{

}


// 매 프레임 호출됨
int GameManager::Update()
{
    cur_map[2][2]++;
    if(cur_map[2][2] > 9)
    {
        cur_map[2][2] = 0;
    }

    if(kbhit())
    {
        getchar();
        return 0;
    }
    return 1;
}

vector<vector<int>> GameManager::GetCurMap()
{
    return cur_map;
}