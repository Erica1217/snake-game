#ifndef _ITEMMANAGER_
#define _ITEMMANAGER_
#include "Item.h"
#include "Point.h"
#include "UserData.h"
#include "GameData.h"
#include <vector>

class ItemManager{

public:
    ItemManager();
    void makeItem(int current_tick, vector<vector<int>> map);
    int eatItem(Point next_head_point);
    void deleteItem(int current_tick);
    void update(GameData &game_data, UserData &user_data);

private:
    int current_tick;
    int last_made_tick;
    int delay;
    int rand_x;
    int rand_y;
    int temp;
    int growth_odd;
    int disappear_tick;
    int kind;
    Point create_location;
    vector<Item> items;
};

#endif