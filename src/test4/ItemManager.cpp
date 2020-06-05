#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Item.h"
#include "Point.h"
using namespace std;
class ItemManager{
private:
    
    int current_tick = 0;
    int last_made_tick;
    int delay = 3;
    int rand_x;
    int rand_y;
    int temp;
    final int growth_odd = 6;
    final int disappear_tick = 20;
    Point create_location;

public:
    ItemManager(){
        vector<Item> items = {};
    }
    void makeItem(int current_tick, Map map){
        if(item.size()<=3 && current_tick == last_made_tick + delay){
            last_made_tick = current_tick;
            do{
                srand((unsigned int)time(NULL));
                temp = rand();
                rand_x = temp%21;
                temp = rand();
                rand_y = temp%21;
                Point create_location = Point(rand_x,rand_y);
            }
            while(map[create_location.x][create_location.y]==0)
            temp = rand()%10;
            if(temp<=growth_odd){
                int kind = 1;
            }else{
                int kind = 2;
            }
            Item add_item = Item(create_location, kind, current_tick);
            Items.push_back(add_item);
        }
    }
    int eatItem(Point next_head_point){
        for(int i = 0; i<items.size(); i++){
            
            if(items[i].getKinds(); = 1){
                item.erase(item.begin()+i);
                return 1;
            }        
            else{
                item.erase(item.begin()+i);
                return 2;
            }       
        }
        return 0;
    }
    void deleteItem(int current_tick){
        for(int i = 0; i<items.size(); i++){
            if(items[i].getCreateTick() == current_tick - disappear_tick){
                item.erase(item.begin()+i);
                break;
            }
        }
    }
    void update(GameData& game_data, UserData& user_data){
        int current_tick = game_data.getCurrentTick();
        Point next_head_point _= game_data.getNextHeadPoint();
        Map map = game_data.getMap();

        makeItem(current_tick);
        deleteItem(current_tick);
        switch(eatItem(next_point))
        {
            case 0:
            case 1:
            user_data.GrowthItemIncrease();
            break;
            case 2:
            user_data.PoisonItemIncrease();
            break;
        }
        vector<vector<int>> items_pos = {};
        vector<int> items_type = {};
        for(int i = 0; i<items.size(); i++){
            items_pos.push_back(items[i].pos);
            items_type.push_back(items[i].kinds);
        }
        game_data.updateItemPos(items_pos, items_kinds);
    }
}