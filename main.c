#include <ncurses.h> 

int main()
{
  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();

  printw("Hello, World!");
  
  int ch;
  ch = getch();
  if(ch == KEY_F(1))
  {
    printw("A key is pressed");
  }
  else
  {
    printw("pressed key is");
    attron(A_BOLD);
    printw("%c", ch);
    attroff(A_BOLD);
  }

  refresh();
  
  getch();
  endwin();
  
  return 0;
}
