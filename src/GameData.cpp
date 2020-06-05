#include "GameData.h"
#include "GameSettings.h"
#include "kbhit.h"

GameData::GameData(int stage) 
{
    snake_map = new SnakeMap(stage);
    window = newwin(MAP_Y, MAP_X, 1, 1);
    keypad(window, TRUE);
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

void GameData::updateDirection()
{
    if(kbhit())
    {
        key = wgetch(window);
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
}

void GameData::Render()
{
    std::vector<std::vector<int>> canvas = snake_map -> getCurrentMap();
  
  for(int i = 0 ; i < canvas.size() ; i++)
  {
    for(int j = 0 ; j < canvas[i].size() ; j++)
    {
      mvwprintw(window, i, j, "%c", changeMap(canvas[i][j]));
    }
  }
  wrefresh(window);
}

char GameData::changeMap(int i)
{
    char temp;
  switch(i)
  {
    case EMPTY:
      temp = ' ';
      break;
    case SNAKE_HEAD:
      temp = 'o';
      break;
    case SNAKE_BODY:
      temp = 'x';
      break;
    case WALL:
      temp = '1';
      break;
    case IMMUNE_WALL:
      temp = '1';
      break;
    case GATE:
      temp = '%';
      break;
    case GROWTH_ITEM:
      temp = '+';
      break;
    case POSION_ITEM:
      temp = '-';
      break;
    default :
      temp = '?';
      break;
  }
  return temp;
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
        for(int i = 0; i < gates.size(); i++) 
        {
            snake_map->setPositionInfo(gates[i].x, gates[i].y, GATE);
        }
        this->gates = gates;
    }
}

void GameData::updateGateDirection(bool isExist, vector<vector<int>> &gate_directions)
{
    if(isExist){
        this->gate_directions = gate_directions;
    }
}

vector<Point> GameData::getGatePositions()
{
    return gates;
}

vector<vector<int>> GameData::getGateDirections()
{
    return gate_directions;
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
            if(snake_map -> getPositionInfo(i,j) == 1 || snake_map -> getPositionInfo(i,j) == 2) {
                snake_map -> setPositionInfo(i, j , 0);
            }
        }
    }
}

int GameData::getPositionInfo(int x, int y) {
    return snake_map -> getPositionInfo(x,y);
}

void GameData::setPositionInfo(int x, int y, int info) {
    return snake_map -> setPositionInfo(x, y, info);
}