#include "WindowManager.h"
#include <ncurses.h>

WindowManager::WindowManager()
{
  win_game = newwin(21, 21, 11, 11);
  win_score = newwin(11, 21, 1, 23);
  win_mission = newwin(11, 21, 11, 23);
}

// 첫화면 시작메뉴
int WindowManager::RenderStartWindow()
{
  WINDOW* win_start = newwin(8, 15, 5, 3);
  keypad(win_start, TRUE);
  box(win_start, 0, 0);

  // start/exit 중 선택된것
  int choice = 1;
  int key;
  
  while(1)
  {
    // choice 기준으로 start / exit 하이라이트 표시
    if(choice % 2)
    {
      wattron(win_start, A_REVERSE);
      mvwprintw(win_start, 2, 2, "start");
      wattroff(win_start, A_REVERSE);
      mvwprintw(win_start, 3, 2, "exit");
    }
    else
    {
      mvwprintw(win_start, 2, 2, "start");
      wattron(win_start, A_REVERSE);
      mvwprintw(win_start, 3 , 2, "exit");
      wattroff(win_start, A_REVERSE);
    }
    wrefresh(win_start);

    // 키입력받아서 엔터시 start or exit 값 반환
    key = wgetch(win_start);
    switch(key)
    {
      case KEY_UP:
      case KEY_DOWN:
        choice++;
        break;
      case 10:
        keypad(win_start, FALSE);
        delwin(win_start);
        endwin();
        return choice % 2;
        break;
    }
  }
}

void WindowManager::Render(WINDOW* window)
{
  mvprintw(1,3," ");
  printw("12345");
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_RED);
  wbkgd(window, COLOR_PAIR(1));
  wattron(window, COLOR_PAIR(1));
  mvwprintw(window, 1, 1, "A NEW WINDOW");
  wborder(window, '*', '*', '*', '*', '*', '*', '*', '*');
  wattroff(window, COLOR_PAIR(1));

  wrefresh(window);
}

void WindowManager::RenderCurWindows()
{
  Render(win_game);
  Render(win_score);
  Render(win_mission);
}

void WindowManager::DeleteCurWindows()
{
  delwin(win_game);
  delwin(win_score);
  delwin(win_mission);
  mvprintw(1, 1, "delete");
  refresh();
}
