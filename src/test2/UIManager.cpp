#include "UIManager.h"
#include <vector>
#include <ncurses.h>

UIManager::UIManager(GameManager& game_info) : game_manager(game_info)
{
  window_game = newwin(21, 21, 1, 1);
}


// 매 프레임 호출됨
void UIManager::Update()
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

// 첫화면 시작메뉴
int UIManager::RenderStartMenu()
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
        werase(win_start);
        wrefresh(win_start);
        delwin(win_start);
        return choice % 2;
        break;
    }
  }
}