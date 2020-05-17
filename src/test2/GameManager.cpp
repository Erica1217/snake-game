#include "GameManager.h"

using namespace std;

GameManager::GameManager(GameFlow& gameflow) : game_flow(gameflow)
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
    if(game_flow.RenderStageEnter(curStage + 1) == 0)
    {
        isValid = false;
    }
}

// ui_manager 가 키 입력받고 얘한테 세팅해줌
void GameManager::SetInput(int input_key)
{
    key = input_key;
}

// 매 프레임. 게임 완료 검사
int GameManager::IsStageClear()
{
    return isClear;
}

// 매 프레임, 유효성 검사만
int GameManager::IsValid()
{
    if(isValid == false)
    {
        return 0;
    }
    if(key == 263)  // 백스페이스 누름
    {
        return 0;
    }
    if(key == 98)
    {
        isClear = true;
    }
    return 1;   
}

// 매 프레임, 게임데이터 업데이트
void GameManager::Update()
{
    // 데이터 모두 업데이트
    cur_map[1][1] = key % 10;
    
    cur_map[2][2]++;
    if(cur_map[2][2] > 9)
    {
        cur_map[2][2] = 0;
    }
    


    // 스테이지 클리어 확인
    if(IsStageClear())
    {
        StageSetting();
    }
}

// 스테이지 클리어 시 다음 스테이지 세팅, 대기창 띄워줌
void GameManager::StageSetting()
{
    if(game_flow.RenderStageClear(++curStage) == 0)
    {
        isValid = false;
    }
    isClear = false;
    key = 0;

    //cur_map = maps[curStage];
}

// UI Manager 가 프레임마다 최종적으로 그려야 하는 데이터를 넘겨줌 (맵+뱀+게이트+아이템)
vector<vector<int>> GameManager::GetCurMap()
{
    return cur_map;
}