#ifndef _SETTING_H_
#define _SETTING_H_

#define SCREEN_X 21
#define SCRREN_Y 21

#include <ncurses.h>

void NcursesSetting()
{
  initscr();
  noecho();
  curs_set(0);
  resize_term(SCRREN_Y + 2,SCREEN_X * 2 + 3);
  start_color();

  init_pair(1, COLOR_WHITE, COLOR_RED);

  attron(COLOR_PAIR(1));
  border('|', '|', '-', '-', '-', '-', '-', '-');
  attroff(COLOR_PAIR(1));

  mvprintw(1, 1, "Snake Game");
  refresh();
}

#endif
