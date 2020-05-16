#include <ncurses.h>
#include <unistd.h>

#include "UIManager.h"
#include "GameManager.h"
#include "NcursesSetting.h"


int main(void)
{
  NcursesSetting();
  GameManager game_manager;
  UIManager ui_manager(game_manager);

  // 시작메뉴 렌더링, 엔터 누르면 종료 0 - exit / 1 - start
  if(ui_manager.RenderStartMenu() == 0)
  {
    endwin();
    return 0;
  }

  while(1)
  {
    // 게임 플레이 정보 업데이트
    game_manager.Update();
    // 게임정보 반영 후 렌더링
    ui_manager.Update();
    // 0.5초
    usleep(500000);
  }



  endwin();

  return 0;
}
