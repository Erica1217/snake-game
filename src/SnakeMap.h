#ifndef _SNAKEMAP_
#define _SNAKEMAP_

#include "Point.h"
#include <vector>
using namespace std;

class SnakeMap {
public:
    SnakeMap(const int stage);
    int getTotalStageCount(); // 전체 게임 stage의 개수를 반환한다.
    vector<vector<int>> getCurrentMap(); // currnet_map을 반환한다.
    int getPositionInfo(const int x, const int y); // current_map[x][y]를 반환한다.
    void setCurrentMap(const int next_stage); // currnet_stage를 next_stage로 set하고, current_map을 totalmap[next_stage]로 변경한다.
    void setPositionInfo(const int x, const int y, const int Info); 
    //void update(vector<Point> snake, vector<Point> gates, vector<Point> items); //뱀, 게이트, 아이템 정보를 맵에 반영한다. 

private:
    int MAP_WIDTH = 21;
    int MAP_HEIGHT = 21;
    int total_stage_count = 1;
    vector<vector<vector<int>>> total_map;
    int current_stage = 0;
    vector<vector<int>> current_map;
};

#endif