#ifndef _GAMEDATA_
#define _GAMEDATA_

#include "Point.h"
#include "SnakeMap.h"
#include "Renderable.h"
#include <ncurses.h>


class GameData : public Renderable
{

public:
    GameData(const int stage);

    void update(const int current_tick);

    int checkItem(const Point& head);
    
    vector<vector<int>> getMap();

    void setNextPoint(const Point& next_point);

    void setNextHeadPoint(const Point& next_head_point);

    Point getNextPoint();
    
    Point getNextHeadPoint();

    void setCurrentTick(const int current_tick);

    int getCurrentTick();
    
    void updateDirection();

    void updateSnakePosition(const vector<Point>& snake_body);

    void updateItemPosition(const vector<Point>& item_positions, const vector<int>& item_infos);

    void updateGatePosition(bool isExist, const vector<Point>& gates);

    void updateGateDirection(bool isExist, const vector<vector<int>>& gate_directions);

    vector<Point> getGatePositions();

    vector<vector<int>> getGateDirections();

    int getCurrrentDirection();

    void setCurrentDirection(const int current_direction);

    void mapReset();

    int getPositionInfo(const int x, const int y);

    void setPositionInfo(const int x, const int y, const int info);
    // 추가
    int getKey() { return key; };
    void Render();

    vector<vector<int>> mo_count;
    vector<vector<Point>> mo_points;
    int sq;

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