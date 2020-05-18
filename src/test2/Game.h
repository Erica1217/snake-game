#ifndef _GAME_
#define _GAME_

#include <vector>
#include "Snake.h"

class Game
{
public :
    std::vector<std::vector<int>> map;
    bool isClear;
    bool isValid;
    int key;

    Game();
    void Init(std::vector<std::vector<int>> map);
    void SetInput(int key);

    void Update();
    int IsValid();
private :
    Snake* player;

    std::vector<std::vector<int>> origin_map;

    int CheckStageClear();
};

#endif