#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Item.h"
#include "Point.h"
#include "ItemManager.h"
#include "GameSettings.h"

using namespace std;

ItemManager::ItemManager(){
    last_made_tick = 0;
    delay = 8;
    growth_odd = 6;
    disappear_tick = 40;
    items = {};
}

void ItemManager::makeItem(int current_tick, const vector<vector<int>>& map, GameData &game_data){
    if(items.size() < 3 && current_tick >= last_made_tick + delay)
    {   
        Point mo_create_location = Point(1,1);
        int mx_zero = 0;
        int create_x, create_y;

        for(int x=0; x<game_data.sq; x++) {
            for(int y=0; y<game_data.sq; y++) {
                if(game_data.mo_count[x][y] > mx_zero && game_data.mo_count[x][y] > 0) {
                    mo_create_location = Point(x,y);
                    mx_zero = game_data.mo_count[x][y];
                }
            }
        }

        int rand_x;
        int rand_y;
        int temp;

        do {
            int rand_number = (rand() % (game_data.mo_points[mo_create_location.x * game_data.sq + mo_create_location.y].size()));
            rand_x = game_data.mo_points[mo_create_location.x * game_data.sq + mo_create_location.y][rand_number].x;
            rand_y = game_data.mo_points[mo_create_location.x * game_data.sq + mo_create_location.y][rand_number].y;
        }
        while(rand_x > 0 && rand_y > 0 && rand_x < MAP_X && rand_y < MAP_Y && map[rand_x][rand_y] != 0 && mx_zero > 0);

        Point create_location = Point(rand_x, rand_y);
        last_made_tick = current_tick;

        temp = rand()%10;
        int kind;
        if(temp<=growth_odd){
            kind = 1;
        }else{
            kind = 2;
        }

        game_data.mo_count[rand_x/game_data.sq][rand_y/game_data.sq] -=3;
        // Item add_item = Item(create_location, kind, current_tick);
        items.push_back(Item(create_location, kind, current_tick));
    }    
}

int ItemManager::eatItem(const Point& next_head_point, GameData &game_data){
    for(int i = 0; i<items.size(); i++){
        if(items.at(i).getPos() == next_head_point) {
            game_data.mo_count[items.at(i).getPos().x/game_data.sq][items.at(i).getPos().y/game_data.sq]+=1;
            if(items.at(i).getKinds() == 1){
                items.erase(items.begin()+i);
                return 1;
            }        
            else{
                items.erase(items.begin()+i);
                return 2;
            }
        }       
    }
    return 0;
}
void ItemManager::deleteItem(const int current_tick, GameData &game_data){
    for(int i = 0; i<items.size(); i++){
        if(items.at(i).getCreatedTick() + disappear_tick <= current_tick ){
            game_data.setPositionInfo(items.at(i).getPos().x, items.at(i).getPos().y, 0);
            game_data.mo_count[items.at(i).getPos().x/game_data.sq][items.at(i).getPos().y/game_data.sq]+=3;
            items.erase(items.begin()+i);
        }
    }
}

void ItemManager::update(GameData &game_data, UserData &user_data){

    int current_tick = game_data.getCurrentTick();
    Point next_head_point = game_data.getNextHeadPoint();
    vector<vector<int>> map = game_data.getMap();

    makeItem(current_tick, map, game_data);
    deleteItem(current_tick, game_data);
    switch(eatItem(next_head_point, game_data))
    {
        case 0:
            break;
        case 1:
            user_data.GrowthItemIncrease();
            break;
        case 2:
            user_data.PoisonItemIncrease();
            break;
    }

    vector<Point> items_pos = {};
    vector<int> items_type = {};

    for(int i = 0; i<items.size(); i++){
        items_pos.push_back(items.at(i).getPos());
        items_type.push_back(items.at(i).getKinds());
    }

    game_data.updateItemPosition(items_pos, items_type);
}