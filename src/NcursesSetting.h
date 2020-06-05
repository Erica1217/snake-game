#ifndef _SETTING_H_
#define _SETTING_H_

#include "GameSettings.h"
#include <ncurses.h>
#include <locale.h>

void NcursesSetting()
{
  setlocale(LC_ALL, "ko_KR.utf8");
  initscr();
  noecho();
  curs_set(0);
  resize_term(MAP_Y + 2, MAP_X * 2 + 3);
  start_color();

  init_pair(1, COLOR_WHITE, COLOR_RED);

  attron(COLOR_PAIR(1));
  border('|', '|', '-', '-', '-', '-', '-', '-');
  attroff(COLOR_PAIR(1));

  mvprintw(1, 1, "Snake Game");
  refresh();
}

#endif
