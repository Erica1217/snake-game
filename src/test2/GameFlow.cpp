#include <ncurses.h>
#include <unistd.h>
#include "GameFlow.h"
#include "kbhit.h"

GameFlow::GameFlow()
{
    
}

// 크레딧 출력하는 창
void GameFlow::RenderAbout()
{
    WINDOW* window_about = newwin(8, 20, 5, 3);
    keypad(window_about, TRUE);
    wborder(window_about, '*', '*', '*', '*', '*', '*', '*', '*');

    mvwprintw(window_about, 1, 1, "");
    for(int i = 0 ; i < 400 ; i++)
    {
        wprintw(window_about, "%c", text[i]);
        wrefresh(window_about);
        usleep(50000);
        if(kbhit()) break;
    }
    // 버퍼비워주기
    getchar();

    keypad(window_about, FALSE);
    werase(window_about);
    wrefresh(window_about);
    delwin(window_about);
}

// 첫화면 시작메뉴 (처음 한번만 호출)
int GameFlow::RenderStartMenu()
{
  WINDOW* window_start = newwin(8, 15, 5, 3);
  keypad(window_start, TRUE);
  wborder(window_start, '*', '*', '*', '*', '*', '*', '*', '*');

  // start/exit 중 선택된것
  int choice = 0;
  int key;
  
  while(1)
  {
    choice = choice % 3;
    werase(window_start);
    // choice 기준으로 start / about / exit 하이라이트 표시
    if(choice == 0)
    {
      wattron(window_start, A_REVERSE);
      mvwprintw(window_start, 2, 2, "start");
      wattroff(window_start, A_REVERSE);
      mvwprintw(window_start, 4, 2, "about");
      mvwprintw(window_start, 6, 2, "exit");
    }
    else if(choice == 1)
    {
      mvwprintw(window_start, 2, 2, "start");
      wattron(window_start, A_REVERSE);
      mvwprintw(window_start, 4, 2, "about");
      wattroff(window_start, A_REVERSE);
      mvwprintw(window_start, 6, 2, "exit");
    }
    else
    {
      mvwprintw(window_start, 2, 2, "start");
      mvwprintw(window_start, 4, 2, "about");
      wattron(window_start, A_REVERSE);
      mvwprintw(window_start, 6 , 2, "exit");
      wattroff(window_start, A_REVERSE);
    }
    
    wrefresh(window_start);

    // 키입력받아서 엔터 누를 경우엔 choice 값 반환
    key = wgetch(window_start);
    switch(key)
    {
      case KEY_UP:
        choice--;
        break;
      case KEY_DOWN:
        choice++;
        break;
      case 10:
        keypad(window_start, FALSE);
        werase(window_start);
        wrefresh(window_start);
        delwin(window_start);
        return choice;
        break;
    }
  }
}


// 게임 종료 시 한번 호출
void GameFlow::RenderGameEnd()
{

}