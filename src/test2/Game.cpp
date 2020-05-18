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
    // 뱀 업데이트
    player->UpdateMoves();

    // 맵 초기화
    map = origin_map;

    // 키값 인식여부 테스트용도
    map[0][0] = key % 10;

    // 뱀 위치 맵에 저장
    std::vector<Point> snake = player->HeadPos();
    map[snake[0].x][snake[0].y] = 5; // 머리 부분
    for(int i = 1 ; i < snake.size() ; i++) // 몸통 부분
    {
        map[snake[i].x][snake[i].y] = 4;
    }

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