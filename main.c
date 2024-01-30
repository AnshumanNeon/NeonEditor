#include <ncurses.h> 
#include "./src/text_edit.h"
#include "./src/command_palette.h"
#include "./src/buffer.h"

#define ctrl(x) ((x) & 0x1f)

int command_palette_enabled = 0;

int main()
{
  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();
  char str[5]; 
  int ch;
  int max_y, max_x;

  getmaxyx(stdscr, max_y, max_x);

  int x, y;
  move(0, 0);

  while(1)
  {
    getyx(stdscr, y, x);
    move(y, x);
    ch = getch();
    
    if(ch == ctrl('c')) break;
    
    if(ch == ctrl('e'))
    {
      command_palette_enabled = 1;
    }

    if(command_palette_enabled && ch == 10)
    {
      command_palette_enabled = 0;
    }

    if(!command_palette_enabled)
    {
      text_edit(ch, x, y);
    }
    else
    {
      command_palette();
    }
    
    refresh();
  }
  
  endwin();
  
return 0;
}
