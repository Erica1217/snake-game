#ifndef _GAME_
#define _GAME_

#include <vector>
#include "Snake.h"
#include "GameData.h"
#include "UserData.h"
#include "GateManager.h"
#include "Mission.h"
#include "ItemManager.h"

class Game
{
public :
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
    ItemManager* item_manager;
    Mission* mission;
    GateManager* gate_manager;

    Renderable* panels[3];
};

#endif