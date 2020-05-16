#ifndef _GAME_MANAGER_
#define _GAME_MANAGER_

#include <vector>
using namespace std;

class GameManager
{
public :
    GameManager();

    void Start();
    int IsValid();
    void Update();

    vector<vector<int>> GetCurMap();
private :
    vector<vector<int>> cur_map; // 현재 스테이지 맵. 전체맵정보는 따로만들어놓고 거기서 가져오기
};

#endif