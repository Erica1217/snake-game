#include "Game.h"
#include "GameSettings.h"
#include "GameData.h"

Game::Game()
{
    is_clear = false;
    isValid = true;
    key = 0;
    player = new Snake();
}

// 게임별 맵 저장, 게임매니저 생성자에서 각각 호출
void Game::Init(int stage)
{
    my_stage = stage;
    game_data = new GameData(stage);
    user_data = new UserData();
    gate_manager = new GateManager(game_data -> getMap());

    panels[0] = game_data;

}

void Game::SetInput()
{
    game_data -> updateDirection();
    key = game_data -> getKey();
}

void Game::gameStart()
{

}


// 매프레임 게임 유효성 검사
int Game::IsValid()
{
    Point next = player -> getNextPoint(game_data -> getCurrrentDirection());
    
    //Point next = player->NextHeadPosition();
    
    // next_point
    //next_head_point
    // tick()

    switch (game_data -> getPositionInfo(next.x, next.y))
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
void Game::update(int tick)
{
    game_data -> mapReset();
    //game_data -> setNextPoint(next);
    //game_data -> setNextHeadPoint(next);
    game_data -> setCurrentTick(tick);

    //game_data->Update();
    
    player -> Update(*game_data, *user_data);
    //item_manager.Update(game_data, user_data);
    gate_manager -> update(*game_data, *user_data);

    panels[0] -> Render();
}


// Update 끝마친 후 호출
bool Game::isClear()
{
    if(key == 98)
    {
        is_clear = true;
    }
    // 여기에서 mission 클리어 판단

    return is_clear;
}

void Game::gameEnd()
{
    delete player;
    delete game_data;
    delete user_data;
    //delete gate_manager;
}