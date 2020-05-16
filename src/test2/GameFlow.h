#ifndef _GAME_FLOW_
#define _GAME_FLOW_

class GameFlow
{
public :
    GameFlow();

    int RenderStartMenu();
    void RenderAbout();
    void RenderGameEnd();
private :
    char text[400] = "makers\n 20000000 ddf\n 20000000 zxv\n 20000000 ksh\n\n Press Any Key";
};

#endif