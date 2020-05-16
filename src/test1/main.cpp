#include <ncurses.h>
#include "gameLoader.h"
#include "input.h"

class Help
{
public :
  bool isHelpOn = false;
  void Render();
};

void Help::Render()
{
  printw("?");
}

void MainRender()
{
  start_color();
  init_pair(1, COLOR_RED, COLOR_WHITE);
  box(stdscr, 0, 0);
  attron(COLOR_PAIR(1));
  wbkgd(stdscr, COLOR_PAIR(1));


  refresh();
}

int main(void)
{
  initscr();
  mvprintw(1,1,"");

  Help helpText;
  GameLoader gameLoader;
  char c;
  KeyBoard kb;

  while(1)
  {
    kb.update();
    // 방향키 입력, 위1 아래2 오른3 왼4
    if(kb.curKey)
    {
      printw("%d ", kb.curKey);
    }
    // 게임에 들어가있음
    if(gameLoader.curGameOn)
    {
      gameLoader.OnLoader();
    }
    // 설명창 들어가있음
    else if(helpText.isHelpOn)
    {
      helpText.Render();
    }
    // 둘다 아닐경우 선택창 렌더링
    else
    {
      MainRender();
    }
  }

  endwin();
  return 0;
}
