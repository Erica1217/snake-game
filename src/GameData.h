#ifndef _GAMEDATA_
#define _GAMEDATA_

#include "Point.h"
#include "SnakeMap.h"
#include "Renderable.h"
#include <ncurses.h>


class GameData : public Renderable
{

public:
    GameData(int stage);

    void update(int current_tick);

    int checkItem(Point head);
    
    vector<vector<int>> getMap();

    void setNextPoint(Point next_point);

    void setNextHeadPoint(Point next_head_point);

    Point getNextPoint();
    
    Point getNextHeadPoint();

    void setCurrentTick(int current_tick);

    int getCurrentTick();
    
    void updateDirection();

    void updateSnakePosition(vector<Point> snake_body);

    void updateItemPosition(vector<Point> item_positions, vector<int> item_infos);

    void updateGatePosition(bool isExist, vector<Point> gates);

    void updateGateDirection(bool isExist, vector<vector<int>> &gate_directions);

    vector<Point> getGatePositions();

    vector<vector<int>> getGateDirections();

    int getCurrrentDirection();

    void setCurrentDirection(int current_direction);

    void mapReset();

    int getPositionInfo(int x, int y);

    void setPositionInfo(int x, int y, int info);
    // 추가
    int getKey() { return key; };
    void Render();

private:
    Point next_point;
    Point next_head_point;
    SnakeMap* snake_map;
    int current_tick;
    int current_direction;

    vector<Point> gates;
    vector<vector<int>> gate_directions;

    // 추가
    int key;
    wchar_t changeMap(int i);
};


#endif