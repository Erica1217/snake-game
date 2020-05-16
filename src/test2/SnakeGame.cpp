#include <ncurses.h>

#include "WindowManager.h"
#include "NcursesSetting.h"


int main(void)
{
  WindowManager win_manager;

  NcursesSetting();

  // 시작메뉴 렌더링, 엔터 누르면 종료 0 - exit / 1 - start
  if(win_manager.RenderStartWindow() == 0)
  {
    endwin();
    return 0;
  }
  
  getchar();
  

  /*
  while(1)
  {
    win_manager.RenderCurWindows();
    //refresh();
  

  win_manager.DeleteCurWindows();
  */
  endwin();

  return 0;
}
