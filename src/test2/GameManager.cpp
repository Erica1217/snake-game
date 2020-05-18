#include "GameManager.h"
#include "MapInfo.h"

GameManager::GameManager(GameFlow& gameflow) : game_flow(gameflow)
{
    curStage = 0;

    games = new Game[MAX_STAGE];

    for(int i = 0 ; i < MAX_STAGE ; i++)
    {
        games[i].Init(maps[i]);
    }
}

// 게임 시작 (첫 스테이지 시작) 시 한번
void GameManager::Start()
{
    // 첫스테이지 로드
    curGame = games;

    if(game_flow.RenderStageEnter(curStage + 1) == 0)
    {
        curGame->isValid = false;
    }
}

// ui_manager 가 키 입력받고 게임에 세팅해줌
void GameManager::SetInput(int input_key)
{
    curGame->key = input_key;
}

// 매 프레임, 유효성 검사만
int GameManager::IsValid()
{
    return curGame->IsValid();
}

// 매 프레임, 게임데이터 업데이트
void GameManager::Update()
{
    curGame->Update();

    if(IsStageClear())
    {
        StageSetting();
    }
}

// 매 프레임. 게임 완료 검사
int GameManager::IsStageClear()
{
    return curGame->isClear;
}

// 스테이지 클리어 시 다음 스테이지 세팅, 대기창 띄워줌
void GameManager::StageSetting()
{
    // 마지막 스테이지일 시 게임종료
    /*
    if (curStage == MAX_STAGE - 1)
    {
        curGame->isValid = false;
        game_flow.RenderStageClear(MAX_STAGE);
        return;
    }
    */

    // 마지막 스테이지가 아니라면
    if(++curStage < MAX_STAGE)
    {
        // 다음 스테이지 로드
        curGame = games + curStage;
    }
    // 해당 스테이지 클리어 렌더링, 입력대기
    if(game_flow.RenderStageClear(curStage) == 0)
    {
        // 대기중 백스페이스 눌렀을 경우
        curGame->isValid = false;
    }
}

// UI Manager 가 프레임마다 최종적으로 그려야 하는 데이터를 넘겨줌 (맵+뱀+게이트+아이템)
std::vector<std::vector<int>> GameManager::GetCurMap()
{
    return curGame->map;
}