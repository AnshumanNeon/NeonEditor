#include <ncurses.h>

void execute_command(char ch)
{
  switch(ch)
  {
    case 'w':
      printw("Want to save? Nah!");
      break;
    default:
      printw("Command unknown!");
      break;
  }
}

void command_mode(char str[5])
{
  getstr(str);

  for(int i = 0; str[i] != '\0' || str[i] != '\n'; i++)
  {
    execute_command(str[i]);
  }
}
