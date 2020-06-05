#ifndef _ITEMMANAGER_
#define _ITEMMANAGER_
#include "Item.h"
#include "Point.h"
#include "UserData.h"
#include "GameData.h"
#include <vector>

class ItemManager{

public:
    void makeItem();
    int eatItem();
    void deleteItem();
    void update();

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