#include <iostream>
#include <sys/ioctl.h>
#include <termios.h>
#include <cstdio>
#include <ctime>

static const int STDIN = 0;
static bool initialized = false;

int keyEventBlocking(){
  if (!initialized)
  {
    termios term;
    tcgetattr(STDIN, &term);
    term.c_lflag &= ~ICANON;
    tcsetattr(STDIN, TCSANOW, &term);
    setbuf(stdin, NULL);
    initialized = true;
  }
  int bytesWaiting = 0;
  while (!bytesWaiting && ioctl(STDIN, FIONREAD, &bytesWaiting) >= 0) {}
  return bytesWaiting;
}