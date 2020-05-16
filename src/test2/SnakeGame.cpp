#include <ncurses.h>
#include <unistd.h>

#include "UIManager.h"
#include "GameManager.h"
#include "NcursesSetting.h"
#include "GameFlow.h"


int main(void)
{
  NcursesSetting();
  GameFlow game_flow;
  GameManager game_manager;
  UIManager ui_manager(game_manager);

  // 시작메뉴 렌더링, 엔터 누르면 종료 0 - exit / 1 - start / 2 - about
  /*
  int game_status = game_flow.RenderStartMenu();
  switch(game_status)
  {
    case 0 : 
      break;
    case 1 :
      game_flow.RenderAbout();
    case 2 :
    endwin();
    return 0;
  }
  */
  while(1)
  {
    int game_status = game_flow.RenderStartMenu();
    if(game_status == 0) 
    {
      break;
    }
    else if(game_status == 1) 
    {
      game_flow.RenderAbout();
    }
    else
    {
      endwin();
      return 0;
    }
  }

  // 게임 실행
  while(1)
  {
    // 게임 플레이 관련 정보 업데이트
    // 유효성 검사도 여기서 실행할것? 지금은 아무 키나 입력하면 종료됨
    if(game_manager.Update() == 0)
    {
      ui_manager.GameEnd();
      break;
    }
    // 게임정보 반영 후 렌더링
    ui_manager.Update();
    // 0.5초
    usleep(500000);
  }
  //game_flow.RenderEnd();
  game_flow.RenderAbout();

  endwin();

  return 0;
}
