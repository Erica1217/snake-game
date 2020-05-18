#include "Game.h"

Game::Game()
{
    isClear = false;
    isValid = true;
    key = 0;

    player = new Snake();
}

// 게임별 맵 저장, 게임매니저 생성자에서 각각 호출
void Game::Init(std::vector<std::vector<int>> map)
{
    this->map = map;
    origin_map = map;
}

void Game::SetInput(int key)
{
    this->key = key;
    player->UpdateDirection(key);
}

// 매프레임 게임 유효성 검사
int Game::IsValid()
{
    Point next = player->NextHeadPosition();
    if(map[next.x][next.y] != 0)
    {
        return 0;
    }
    if(key == 263)  // 백스페이스 누를 경우
    {
        return 0;
    }


    return isValid;   
}

// 매 프레임 유효성 검사되면 모든 정보 추합해서 맵에 저장해야함
void Game::Update()
{
    map = origin_map;
    player->UpdateMoves();
    map[0][0] = key % 10;

    // 임시 사용 /////////
    Point temp = player->HeadPos();
    map[temp.x][temp.y] = 4;
    /////////////////////

    // 업데이트 된 정보 기준으로 클리어검사
    if(CheckStageClear())
    {
        isClear = true;
        //delete player;
    }
}

// 스테이지 클리어 검사
int Game::CheckStageClear()
{
    if(key == 98) // 현재는 b 키 누르면 클리어
    {
        return 1;
    }

    return 0;
}