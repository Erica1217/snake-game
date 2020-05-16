#ifndef _GAME_MANAGER_
#define _GAME_MANAGER_

#include <vector>
using namespace std;

class GameManager
{
public :
    GameManager();

    void StartGame();
    void Update();

    vector<vector<int>> GetCurMap();
private :
    vector<vector<int>> cur_map;
};

#endif