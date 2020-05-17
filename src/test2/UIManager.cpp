#include "UIManager.h"
#include "kbhit.h"
#include <vector>

UIManager::UIManager(GameManager& game_info) : game_manager(game_info)
{
  window_game = newwin(21, 21, 1, 1);
  window_score = newwin(11, 21, 1, 22);
  window_mission = newwin(11, 21, 11, 22);

  //wborder(window_score, '*', '*', '*', '*', '*', '*', '*', '*');
  //wborder(window_mission, '*', '*', '*', '*', '*', '*', '*', '*');
}

// 계속 검사
// 입력받는 키값을 게임매니저에 넣어줌
void UIManager::GameInput()
{
  if(kbhit())
  {
    game_manager.SetInput(wgetch(window_game));
  }
}

// 실행 시 한번
void UIManager::Start()
{
  keypad(window_game, TRUE);
}

// 종료 시 한번
void UIManager::GameEnd()
{
  EraseWindow(window_game);
  EraseWindow(window_score);
  EraseWindow(window_mission);
}

// 매 프레임 호출됨
void UIManager::Update()
{
  if(game_manager.isValid == false)
  {
    return;
  }
  RenderGame();
  RenderScore();
  RenderMission();
}

// 게임화면 렌더링, Update 에서 매 프레임 호출
void UIManager::RenderGame()
{
  std::vector<std::vector<int>> canvas = game_manager.GetCurMap();
  
  for(int i = 0 ; i < canvas.size() ; i++)
  {
    for(int j = 0 ; j < canvas[i].size() ; j++)
    {
      mvwprintw(window_game, i, j, "%d", canvas[i][j]);
    }
  }
  wrefresh(window_game);
}

// 스코어보드 렌더링, Update 에서 매 프레임 호출
void UIManager::RenderScore()
{
  mvwprintw(window_score, 1, 1, "ScoreBoard");
  wrefresh(window_score);
}

// 미션 렌더링, Update 에서 매 프레임 호출
void UIManager::RenderMission()
{
  mvwprintw(window_mission, 1, 1, "Mission");
  wrefresh(window_mission);
}

void UIManager::EraseWindow(WINDOW* window)
{
  keypad(window, FALSE);
  werase(window);
  wrefresh(window);
  delwin(window);
}