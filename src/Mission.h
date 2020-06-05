#ifndef _MISSION_
#define _MISSION_

using namespace std;

class Mission{
public:
    Mission();
    bool isComplete();
    void setMission();

private:
    int snake_length;
    int posion_item_count;
    int growth_item_count;
    int used_gates_count;
};

#endif