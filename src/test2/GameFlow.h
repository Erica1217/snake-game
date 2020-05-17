#ifndef _GAME_FLOW_
#define _GAME_FLOW_

#include <ncurses.h>

class GameFlow
{
public :
    GameFlow();

    int RenderStartMenu();
    void RenderAbout();
    void RenderGameEnd();

    int RenderStageEnter(int stage); // 게임 진입 시
    int RenderStageClear(int stage); // 클리어 시
private :
    char text[400] = "makers\n 20000000 ddf\n 20000000 zxv\n 20000000 ksh\n\n Press Any Key";

    void EraseWindow(WINDOW* window);
};

#endif