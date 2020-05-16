#ifndef _WINDOW_MANAGER_
#define _WINDOW_MANAGER_

#include <ncurses.h>

class WindowManager
{
public:
  WINDOW* win_game;
  WINDOW* win_score;
  WINDOW* win_mission;

  WindowManager();

  int RenderStartWindow();

  void Render(WINDOW* win);
  void RenderCurWindows();
  void DeleteCurWindows();
private :
};

#endif
