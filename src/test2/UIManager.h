#ifndef _UI_MANAGER_
#define _UI_MANAGER_

#include <ncurses.h>
#include "GameManager.h"

class UIManager
{
public:
  UIManager(GameManager& game_info);

  int RenderStartMenu();
  void Update();

private :
  WINDOW* window_game;

  GameManager& game_manager;
};

#endif
