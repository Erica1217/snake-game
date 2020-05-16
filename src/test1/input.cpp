#include <sys/ioctl.h>
#include <termios.h>
#include <ncurses.h>
#include "input.h"

void KeyBoard::update()
{
  if(kbhit())
  {
    char c = getchar();
    switch (c)
    {
      case 'A' :
        curKey = 1;
        break;
      case 'B' :
        curKey = 2;
        break;
      case 'C' :
        curKey = 3;
        break;
      case 'D' :
        curKey = 4;
        break;
    }
  }
  else
  {
    curKey = 0;
  }
}

int KeyBoard::kbhit() {
    static bool initflag = false;
    static const int STDIN = 0;

    if (!initflag) {
        // Use termios to turn off line buffering
        struct termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initflag = true;
    }

    int nbbytes;
    ioctl(STDIN, FIONREAD, &nbbytes);  // 0 is STDIN
    return nbbytes;
}
