#include <ncurses.h>

void insert_mode(char ch)
{
  addch(ch);
  if(ch == 27)
  {
    nodelay(TRUE);
    ch = getch();
    if(ch == -1)
    {
      continue;
    }
  }
}
