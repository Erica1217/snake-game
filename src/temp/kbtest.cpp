#include <stdio.h>
#include <sys/ioctl.h> // For FIONREAD
#include <termios.h>
#include <stdlib.h>
//#include <stdbool.h>

using namespace std;

int kbhit(void) {
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

// main
//#include <unistd.h>

// int main(int argc, char** argv) {
int main() {

  char a;
  char b;
    char c;
    //setbuf(stdout, NULL); // Optional: No buffering.
    //setbuf(stdin, NULL);  // Optional: No buffering.
    printf("Press key");
    while (1)
    {
      if(kbhit())
      {
        c = getchar();
        switch (c)
        {
          case 'A' :
            printf("위\n");
            break;
          case 'B' :
            printf("아래\n");
            break;
          case 'C' :
            printf("오른쪽\n");
            break;
          case 'D' :
            printf("왼쪽\n");
            break;
        }
        sleep(10);
      }
      /*
        printf(".");
        fflush(stdout);
        sleep(1);
        */
    }
    c = getchar();
    printf("\nChar received:%c\n", c);
    printf("Done.\n");

    return 0;
}
