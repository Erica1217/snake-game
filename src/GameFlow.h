#ifndef _GAME_FLOW_
#define _GAME_FLOW_

#include <ncurses.h>
#include <string>

class GameFlow
{
public :
    GameFlow();

    int RenderStartMenu();
    void RenderMakers();
    void RenderAbout();
    void RenderGameEnd();

    int RenderStageEnter(const int stage); // 게임 진입 시
    int RenderStageClear(const int stage); // 클리어 시
private :
    char text[400] = "      Makers\n\n\n  20191564 김신건\n\n  20152635 김상홍\n\n  20191567 김유진\n\n  20185290 이하영\n\n  20191678 최영락\n\n\n   Press Any Key";
    std::string explain[17] = 
    {
        "dddd", 
        "a", 
        "b", 
        "c", 
        "d", 
        "e", 
        "f", 
        "g", 
        "h", 
        "i", 
        "d", 
        "ads", 
        "asdf", 
        "2",
        "3", 
        "4", 
        "5"
    };

    void EraseWindow(WINDOW* window);
};

#endif
