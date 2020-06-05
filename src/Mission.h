#ifndef _MISSION_
#define _MISSION_
#include "UserData.h"
#include <vector>

using namespace std;

class Mission{
public:
    Mission(int stage);
    bool isComplete(UserData &user_data);

private:
    int snake_length;
    int posion_item_count;
    int growth_item_count;
    int used_gates_count;
    vector<int> current_mission_list;
    vector<vector<int>> total_mission_list;
    vector<int> current_state;
};

#endif