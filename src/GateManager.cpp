#include "GateManager.h"
#include <iostream>

using namespace std;

void GateManager::makeWallMap(int num, int x, int y)
{
    for(int i=0 ; i<4 ; i++)
    {
        int X = dx[i]+x;
        int Y = dy[i]+y;
        if(X>=0 && Y>=0 &&
            X<MAP_X && Y<MAP_Y &&
            wall_map[X][Y]==-1)
        {
            wall_map[X][Y]=num;
            wall_list[num].push_back(Point(X,Y));
            makeWallMap(num, X, Y);
        }
    }
}

vector<int> GateManager::makeGateDirection(Point gate)
{
    vector<int> result;
    for(int i=0 ; i<4 ; i++)
    {
        for(int j=0 ; j<4 ; j++)
        {
            Point g = gate.moveTo(DIR_PRIORITY_TABLE[i][j]);
            if(g.isValid() && wall_map[g.x][g.y] == 0)
            {
                result.push_back(DIR_PRIORITY_TABLE[i][j]);
                break;
            }
        }
    }
    return result;
}

GateManager::GateManager(vector<vector<int>> snake_map)
{
    for(int i=0 ; i<MAP_X ; i++)
    {
        for(int j=0 ; j<MAP_Y ; j++)
        {
            if(snake_map[i][j] == WALL)
            {
                wall_map[i][j]=-1;
            }
            else if(snake_map[i][j] == IMMUNE_WALL)
            {
                wall_map[i][j] = GATE_MANAGER_IMMUNE_WALL;
            }
        }
    }
    
    int num=1;
    for(int i=0 ; i<snake_map.size() ; i++)
    {
        for(int j=0 ; j<snake_map[0].size() ; j++)
        {
            if(wall_map[i][j]==-1)
            {
                makeWallMap(num++,i,j);
            }
        }
    }

    wall_count = num-1;

}

void GateManager::makeNewGate()
{
    // 랜덤한 게이트 2개 만듬
    int x=0 , y=0;
    int gateNum1=0, gateNum2=0;
    Point gate1, gate2;
    int rand1,rand2;
    while(x*x + y*y < (3*3))
    {
        // num 게이트 번호 선택
        srand((unsigned int)time(NULL));
        while(gateNum1 == gateNum2)
        {
            gateNum1 =(rand() % (wall_count))+1; // 범위 : 1부터 wall_count까지
            gateNum2 =(rand() % (wall_count))+1;
        }
        
        rand1 = rand() % (wall_list[gateNum1].size()+1);
        rand2 = rand() % (wall_list[gateNum2].size()+1);
        

        gate1 = wall_list[gateNum1][rand1];
        gate2 = wall_list[gateNum2][rand2];

        x = (gate2.x - gate1.x);
        y = (gate2.y - gate1.y);

    }
    
    gates = make_pair(gate1, gate2);
    gate_directions = make_pair(makeGateDirection(gate1), makeGateDirection(gate2));
}

void GateManager::update(GameData &game_data, UserData &user_data)
{
    int next_x = game_data.getNextPoint().x;
    int next_y = game_data.getNextPoint().y;
    int exit_gate_tick= snake_entered_tick + user_data.getCurrentLength();

    // is_passing update
    if(game_data.getMap()[next_x][next_y] == GATE)
    {
        is_passing=true;
        snake_entered_tick = game_data.getCurrentTick();
        user_data.setUsedGateCount(user_data.getUsedGateCount());
    }
    else if(exit_gate_tick == game_data.getCurrentTick())
    {
        check_wall[wall_map[gates.first.x][gates.first.y]]=0;
        check_wall[wall_map[gates.second.x][gates.second.y]]=0;
        isExist = false;
        is_passing=false;
        last_gate_deleted_tick = game_data.getCurrentTick();
    }

    // 게이트 생성
    int gate_make_tick = last_gate_deleted_tick + live_time;
    if(!is_passing && !isExist && gate_make_tick == game_data.getCurrentTick())
    {
        makeNewGate();
        game_data.updateGatePosition(isExist, {gates.first, gates.second});
        vector<vector<int>> d = {};
        for(int x =0; x<gate_directions.first.size(); x++) {
            d.push_back({gate_directions.first[x], gate_directions.second[x]});
        }
        game_data.updateGateDirection(isExist, d);
        isExist = true;
    }
}

pair<Point, Point> GateManager::getGates()
{
    return gates;
}
