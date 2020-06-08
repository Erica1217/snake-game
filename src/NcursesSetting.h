#ifndef _SETTING_H_
#define _SETTING_H_

#include "GameSettings.h"
#include <ncurses.h>
#include <locale.h>

void NcursesSetting()
{
    setlocale(LC_ALL, "");
    // setlocale(LC_ALL, "ko_KR.utf8");
    initscr();
    noecho();
    curs_set(0);
    resize_term(MAP_Y + 2, MAP_X * 2 + 3);
    start_color();

    // init_pair(1, COLOR_WHITE, COLOR_RED);
    // attron(COLOR_PAIR(1));

    border(ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
    // attroff(COLOR_PAIR(1));

    mvprintw(0, 2, " Snake Game ");
    refresh();
}

#endif
