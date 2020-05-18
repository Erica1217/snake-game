#ifndef _GAME_
#define _GAME_

#include <vector>

class Game
{
public :
    std::vector<std::vector<int>> map;
    bool isClear;
    bool isValid;
    int key;

    Game();
    void Init(std::vector<std::vector<int>> map);

    void Update();
    int IsValid();
private :
    int CheckStageClear();
};

#endif