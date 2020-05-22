#ifndef _GAME_
#define _GAME_

#include <vector>
#include "Snake.h"

class Game
{
public :
    std::vector<std::vector<int>> map;
    bool is_clear;
    bool isValid;
    int key;

    Game();
    void Init(std::vector<std::vector<int>> map, int stage);
    void SetInput(int key);

    void gameStart();
    void Update();
    bool isClear();
    int IsValid();
    void gameEnd();
private :
    int my_stage;
    Snake* player;

    std::vector<std::vector<int>> origin_map;
};

#endif