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
  GameManager game_manager(game_flow);
  UIManager ui_manager(game_manager);

  // 시작메뉴
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
  game_manager.Start();
  ui_manager.Start();

  int timer = 100;
  while(1)
  {
    timer++;
    // 키보드 입력검사는 0.05초마다
    ui_manager.GameInput();

    // 게임업데이트는 0.5초
    if(timer > 100)
    {
      // 유효성 검사 - 지금은 아무 키나 입력하면 종료됨
      if(game_manager.IsValid())
      {
        game_manager.Update();  // 각종 게임 정보들 업데이트
        ui_manager.Update();    // 게임정보 반영 후 화면에 렌더링
      }
      else
      {
        ui_manager.GameEnd();
        break;
      }
      timer = 0;
    }

    usleep(5000); // 시간간격이 일정하지는 않은 것 같음
  }

  game_flow.RenderGameEnd();  // 종료 시 보여줄 화면 // 아직안만듦
  game_flow.RenderAbout();    // 크레딧

  endwin();

  return 0;
}
