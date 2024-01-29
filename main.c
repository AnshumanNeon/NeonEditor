#include <ncurses.h> 
#include "./src/insert_mode.h"
#include "./src/buffer.h"

#define ctrl(x) ((x) & 0x1f)

enum MODE
{
  NORMAL = 0,
  INSERT = 1,
  COMMAND = 2,
};

enum MODE curr_mode = NORMAL;

char* get_mode_str()
{
  if(curr_mode == 2)
  {
    return "COMMAND";
  }
  if(curr_mode == 1)
  {
    return "INSERT";
  }
  else
  {
    return "NORMAL";
  }
}

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
    mvprintw(max_y - 1, 0, get_mode_str());
    move(y, x);
    ch = getch();
    
    if(ch == ctrl('c')) break;
    
    if(ch == 'i' && curr_mode == NORMAL)
    {
      curr_mode = INSERT;
      continue;
    }
    
    if(curr_mode != NORMAL && ch == ctrl('n'))
    {
      curr_mode = NORMAL;
    }
    
    if(curr_mode == INSERT)
    {
      insert_mode(ch, x, y);
    }  
    
    refresh();
  }
  
  endwin();
  
return 0;
}
