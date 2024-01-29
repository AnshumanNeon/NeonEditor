#include <ncurses.h> 
#include "./src/insert_mode.h"
#include "./src/command_mode.h"

enum MODE
{
  INSERT = 1,
  COMMAND = 2,
};

int main()
{
  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();
  char str[5]; 
  int ch;
  int max_x, max_y;
  enum MODE curr_mode;

  getmaxyx(stdscr, max_y, max_x);

  mvprintw(max_y - 1, 0, "NORMAL MODE");
  move(0, 0);

  while(1)
  {
    ch = getch();
    
    if(ch == 'q') break;
    
    if(ch == 'i')
    {
      curr_mode = INSERT;
      continue;
    }
    if(ch = 'c')
    {
      curr_mode = COMMAND;
      continue;
    }

    if(curr_mode == INSERT)
    {
      insert_mode(ch);
    }  
    if(curr_mode == COMMAND)
    {
      command_mode(str);
    }
  }

  refresh();
  
  endwin();
  
  return 0;
}
