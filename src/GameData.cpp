#include "GameData.h"
#include "GameSettings.h"

GameData::GameData(int stage) 
{
    snake_map = new SnakeMap(stage);
}

void GameData::update(int current_tick)
{
    this -> current_tick = current_tick;
}

int GameData::checkItem(Point head) 
{
    int info = snake_map->getPositionInfo(head.x, head.y);
    if(info == 6) return 1;
    if(info == 7) return -1;
    return 0;
}

vector<vector<int>> GameData::getMap() 
{
    return snake_map->getCurrentMap();
}

void GameData::setNextPoint(Point next_point) 
{
    this -> next_point = next_point;
}

void GameData::setNextHeadPoint(Point next_head_point) 
{
    this -> next_head_point = next_head_point;
}

Point GameData::getNextPoint() {
    return next_point;
}

Point GameData::getNextHeadPoint() 
{
    return next_head_point;
}

void GameData::setCurrentTick(int current_tick) 
{
    this -> current_tick = current_tick;
}

int GameData::getCurrentTick() 
{
    return this -> current_tick;
}

// 키값 입력될때마다 방향 변경해줌

void GameData::updateDirection(int key)
{
    switch (key)
    {
    case KB_W : // w
    case KB_UP : // 위
        current_direction = DIR_UP;
        break;
    case KB_S : // s
    case KB_DOWN : // 아래
        current_direction = DIR_DOWN;
        break;
    case KB_RIGHT : // d
    case KB_D : // 오른
        current_direction = DIR_RIGHT;
        break;
    case KB_A :  // a
    case KB_LEFT : // 왼
        current_direction = DIR_LEFT;
        break;
    default:
        break;
    }
}


void GameData::updateItemPosition(vector<Point> item_positions, vector<int> item_infos) 
{
    for(int i=0; i<item_positions.size(); i++) 
    {
        snake_map->setPositionInfo(item_positions[i].x, item_positions[i].y, item_infos[i]+5);
    }
}

void GameData::updateSnakePosition(vector<Point> snake_body)
{
    snake_map->setPositionInfo(snake_body[0].x, snake_body[0].y,1);
    for(int i = 1; i < snake_body.size(); i++) 
    {
        snake_map->setPositionInfo(snake_body[i].x, snake_body[i].y,2);
    }
}

void GameData::updateGatePosition(bool isExist, vector<Point> gates)
{
    if(isExist) {
        for(int i = 1; i < gates.size(); i++) 
        {
            snake_map->setPositionInfo(gates[i].x, gates[i].y,5);
        }
    }
}

int GameData::getCurrrentDirection() 
{
    return this -> current_direction;
}

void GameData::setCurrentDirection(int current_direction) 
{
    this -> current_direction = current_direction;
}


void GameData::mapReset() {
    for(int i = 0; i <21; i++) {
        for(int j = 0; j < 21; j ++) {
            if(snake_map -> getPositionInfo(i,j) == 1 || snake_map -> getPositionInfo(i,j) == 2 ) {
                snake_map -> setPositionInfo(i, j , 0);
            }
        }
    }
}

int GameData::getPositionInfo(int x, int y) {
    return snake_map -> getPositionInfo(x,y);
}