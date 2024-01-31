#include <ncurses.h>
#include <stdlib.h>
#include "./buffer.h"
#include "./text_edit.h"
#include "./command_palette.h"

#define ctrl(x) ((x) & 0x1f)

typedef struct
{
  //Metadata
  int width, height;
  int x, y;
  int command_palette_enabled;
  // Buffer
  buffer m_buffer;
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
  if(editor->ch == ctrl('e'))
  {
    editor->command_palette_enabled = 1;
    move(editor->height - 1, 0);
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

int load_file(Editor* editor, char* file)
{
  if(file == NULL) 
  {
    if(editor->m_buffer.lines.total <= 0)
    {
      append_line(&editor->m_buffer, "");
    }

    return 0;
  }

  FILE* file_ptr = fopen(file, "r");

  if(file_ptr == NULL) return 0;

  size_t read, len;
  char* line;

  while((read = getline(&line, &len, file_ptr)) != -1)
  {
    append_line(&editor->m_buffer, line);
  }

  fclose(file_ptr);

  return 1;
}

void init_buffer(Editor* editor)
{
  getmaxyx(stdscr, editor->height, editor->width);
  editor->x = 0;
  editor->y = 0;
  move(editor->y, editor->x);
  // load_file(editor, file);
}
