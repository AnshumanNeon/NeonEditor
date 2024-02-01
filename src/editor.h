#include <ncurses.h>
#include <stdlib.h>
#include "cvector.h"
#include "./text_edit.h"
#include "./command_palette.h"

#define ctrl(x) ((x) & 0x1f)

typedef struct
{
  //Metadata
  int width, height;
  int x, y;
  int command_palette_enabled;
  // Check command palette
  int space_pressed;
  // Buffer
  cvector_vector_type(char*) m_buffer;
  int ch;
} Editor;

int should_quit(Editor* editor)
{
  return (editor->ch == ctrl('c'));
}

void get_input(Editor* editor)
{
  editor->x = getcurx(stdscr);
  editor->y = getcury(stdscr);
  editor->ch = getch();
}

void update(Editor* editor)
{
  if(editor->ch == 32)
  {
    editor->space_pressed = 1;
  }

  if(editor->space_pressed == 1 && editor->ch == ERR)
  {
    editor->space_pressed = 0;
  }

  if(editor->ch == 9 && editor->space_pressed == 1)
  {
    editor->command_palette_enabled = 1;
    move(editor->height - 1, 0);
    return;
  }
  
  if(editor->command_palette_enabled && editor->ch == 10)
  {
    editor->command_palette_enabled = 0;
    return;
  }
  
  if(!editor->command_palette_enabled)
  {
    text_edit(editor->ch, editor->x, editor->y);
  }
  else
  {
    command_palette();
  }
  
  refresh();
}

void end_editor()
{
  endwin();
}

void setup_ncurses()
{
  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();
  set_escdelay(0);
}

int load_file(Editor* editor, const char* file)
{
  if(file == NULL) return 0;

  FILE* file_ptr = fopen(file, "r");

  int len = 500;
  char line[len];

  while(fgets(line, sizeof(line), file_ptr))
  {
    cvector_push_back(editor->m_buffer, line);
  }

  fclose(file_ptr);

  return 1;
}

void init_buffer(Editor* editor, const char* file)
{
  getmaxyx(stdscr, editor->height, editor->width);
  editor->x = 0;
  editor->y = 0;
  move(editor->y, editor->x);
  editor->m_buffer = NULL;
  load_file(editor, file);

  for(size_t i = 0; i < cvector_size(editor->m_buffer); i++)
  {
    printw("%s\n", editor->m_buffer[i]);
  }
}
