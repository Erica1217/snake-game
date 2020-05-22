#include "Game.h"
#include "GameSettings.h"
#include <iostream>

Game::Game()
{
    isClear = false;
    isValid = true;
    key = 0;

    player = new Snake();
}

// 게임별 맵 저장, 게임매니저 생성자에서 각각 호출
void Game::Init(std::vector<std::vector<int>> map, int stage)
{
    my_stage = stage;
    origin_map = map;
    map[10][10] = SNAKE_HEAD;
    map[11][10] = SNAKE_BODY;
    map[12][10] = SNAKE_BODY;
    this->map = map;
}

void Game::SetInput(int key)
{
    this->key = key;
    player->UpdateDirection(key);
}

void Game::gameStart()
{
    std::cout << my_stage << std::endl;
    std::cout << my_stage << std::endl;
    std::cout << my_stage << std::endl;
    std::cout << my_stage << std::endl;
}

void Game::gameEnd()
{
    std::cout << "??????" << std::endl;
}

// 매프레임 게임 유효성 검사
int Game::IsValid()
{
    Point next = player->NextHeadPosition();
    switch (map[next.x][next.y])
    {
    case WALL : // 벽에 닿았을 때
    case SNAKE_BODY : // 자기 몸통
    case SNAKE_HEAD : // 헤드 // 닿을 일이 있나?
        isValid = false;
        break;

    case 100 : // 감소 아이템
        if(player->length <= 3)
        {
            isValid = false;
        }
        break;

    default:
        break;
    }

    if(key == KB_BACKSPACE)  // 백스페이스 누를 경우
    {
        isValid = false;
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
    map[snake[0].x][snake[0].y] = SNAKE_HEAD; // 머리 부분
    for(int i = 1 ; i < snake.size() ; i++) // 몸통 부분
    {
        map[snake[i].x][snake[i].y] = SNAKE_BODY;
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