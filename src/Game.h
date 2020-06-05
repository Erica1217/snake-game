#ifndef _GAME_
#define _GAME_

#include <vector>
#include "Snake.h"
#include "GameData.h"
#include "UserData.h"
#include "GateManager.h"
#include "Renderable.h"

class Game
{
public :
    std::vector<std::vector<int>> map;
    bool is_clear;
    bool isValid;
    int key;

    Game();
    void Init(int stage);
    void SetInput();

    void gameStart();
    void update(int tick);
    bool isClear();
    int IsValid();
    void gameEnd();
private :
    int my_stage;
    Snake* player;
    GameData* game_data;
    UserData* user_data;
    GateManager* gate_manager;

    Renderable* panels[3];

    std::vector<std::vector<int>> origin_map;
};

#endif