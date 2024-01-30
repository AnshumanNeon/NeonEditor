#include <ncurses.h>

void text_edit(char ch, int x, int y)
{
  if(ch == 8 || ch == 127 || ch == 7)
  {
    if(x > 0)
    {
      move(y, x - 1);
    }
    else
    {
      move(y - 1, x);
    }

    delch();
  }
  else
  {
    addch(ch);
  }
}
