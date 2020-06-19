#ifndef _MISSION_
#define _MISSION_
#include "UserData.h"
#include "Renderable.h"
#include <vector>

using namespace std;

class Mission : public Renderable
{
public:
    Mission(const int stage);
    bool isComplete(UserData &user_data);
    void Render();

private:
    vector<bool> current_mission_state;
    vector<int> current_mission_list;
    vector<vector<int> > total_mission_list;
    vector<int> current_state;
};

#endif