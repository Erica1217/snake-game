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
    void deleteItem(int current_tick, GameData &game_data);
    void update(GameData &game_data, UserData &user_data);
    vector<Item> items;

private:
    int last_made_tick;
    int delay;
    int growth_odd;
    int disappear_tick;
};

#endif