#include <ncurses.h>

int main()
{
  initscr(); // 윈도우 생성

  resize_term(20, 30); //(줄, 칸) 터미널+윈도우 조정 , 윈도우만은 resize_window()

  keypad(stdscr, TRUE); // 키보드 특수키 입력 가능
  start_color(); // 색 속성 사용 선언

  init_pair(1, COLOR_BLUE, COLOR_WHITE); // 한 쌍의 색 속성 지정 (팔레트, 폰트 색, 폰트 배경색)
  init_pair(2, COLOR_RED, COLOR_BLACK);

  bkgd(COLOR_PAIR(1)); // 전체 윈도우에 색깔 적용
  attron(COLOR_PAIR(1)); // 1번 팔레트 사용 선언
  mvprintw(10, 3, "XXX");
  attroff(COLOR_PAIR(1)); // 1번 팔레트 사용 해제

  mvprintw(1,1,""); // 커서 좌상단 이동
  printw("Hello World!!KDFJDKJKJMKNKJMKJIKDJFKDJKFDdSFJDKLFJDLFKJDKFJDLFKJDKFL");
  mvprintw(5,5,"입력해라 : "); // 윈도우 y(2),x(5) 위치에서 출력 명령
  noecho(); // 입력하는 문자 안보이게

  curs_set(0); // 커서 없애기 0 , 1 일반커서, 2 큰커서

  int n = 0;
  scanw("%d", &n);
  mvprintw(6, 2,"%d", n);

  curs_set(1);

  attron(COLOR_PAIR(2));
  border('*', '*', '*', '*', '@', '@', '@', '@');
  attroff(COLOR_PAIR(2));

  getch();
  clear();

  refresh(); // 호출되기 전 까지 수행했던 작업들을 스크린에 뽑아냄 (스크린 업데이트)
  getch(); // 실행파일 종료를 막기위함 (문자입력 대기)
  endwin(); // 윈도우 종료

  return 0;
}
