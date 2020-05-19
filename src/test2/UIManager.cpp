#include "UIManager.h"
#include "kbhit.h"
#include <vector>

UIManager::UIManager(GameManager& game_info) : game_manager(game_info)
{
  window_game = newwin(MAP_Y, MAP_X, 1, 1);
  window_score = newwin((MAP_Y + 1) / 2, MAP_X, 1, 22);
  window_mission = newwin((MAP_Y + 1) / 2, MAP_X, 11, 22);

  //wborder(window_score, '*', '*', '*', '*', '*', '*', '*', '*');
  //wborder(window_mission, '*', '*', '*', '*', '*', '*', '*', '*');
}

// 0.05초 간격 검사
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

// 매 프레임마다 게임데이터 모두 업데이트 후에 호출됨
void UIManager::Update()
{
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
      mvwprintw(window_game, i, j, "%c", ChangeMap(canvas[i][j]));
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

// 맵 숫자 -> 문자변환 , 인코딩 문제 해결 필요
char UIManager::ChangeMap(int i)
{
  char temp;
  switch(i)
  {
    case 0 :
      temp = ' ';
      break;
    case 1 :
      temp = '1';
      break;
    case 4 :
      temp = 'x';
      break;
    case 5 :
      temp = 'o';
      break;
    default :
      temp = '?';
      break;
  }
  return temp;
}