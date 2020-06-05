#ifndef _UI_MANAGER_
#define _UI_MANAGER_

#include <ncurses.h>
#include "GameManager.h"
#include "GameSettings.h"

class UIManager
{
public:
  UIManager(GameManager& game_info);

  void Start();
  void Update();
  void GameEnd();

  void GameInput();

private :
  WINDOW* window_game;
  WINDOW* window_score;
  WINDOW* window_mission;
  GameManager& game_manager;

  void RenderGame();
  void RenderScore();
  void RenderMission();

  void EraseWindow(WINDOW* window);
  char ChangeMap(int i);
};

#endif
