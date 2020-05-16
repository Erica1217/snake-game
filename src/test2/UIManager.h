#ifndef _UI_MANAGER_
#define _UI_MANAGER_

#include <ncurses.h>
#include "GameManager.h"

class UIManager
{
public:
  UIManager(GameManager& game_info);

  void Update();
  void GameEnd();

private :
  WINDOW* window_game;
  WINDOW* window_score;
  WINDOW* window_mission;

  void RenderGame();
  void RenderScore();
  void RenderMission();

  void EraseWindow(WINDOW* window);

  GameManager& game_manager;
};

#endif
