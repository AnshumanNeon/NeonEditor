#include <ncurses.h>

void insert_mode(char ch, int x, int y)
{
  if(ch == 8 || ch == 127 || ch == 7)
  {
    move(y, x - 1);
    delch();
  }
  else
  {
    addch(ch);
  }
}
