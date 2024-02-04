#include <ncurses.h>
#include <stdlib.h>
#include "./defs.h"
#include "./text_edit.h"
#include "./command_palette.h"

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

  if(editor->ch == ctrl('s'))
  {
    editor->save_at_end = 1;
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
    text_edit(editor);
  }
  else
  {
    command_palette();
  }

  refresh();
}

int save_file(Editor* editor, const char* file)
{
  if(file == NULL) return 0;

  FILE* file_ptr = fopen(file, "w");

  if(!fwrite(editor->m_buffer.content, 1, editor->m_buffer.length, file_ptr)) return 0;

  fclose(file_ptr);
  
  return 1;
}

void end_editor(Editor* editor)
{
  if(editor->save_at_end) save_file(editor, "./text_edit.h");

  end_buffer(&editor->m_buffer);
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

  init_buffer(&editor->m_buffer, file_ptr);
  set_buffer(&editor->m_buffer, file_ptr);

  fclose(file_ptr);

  return 1;
}

void init_editor(Editor* editor, const char* file)
{
  getmaxyx(stdscr, editor->height, editor->width);
  editor->x = 0;
  editor->y = 0;
  editor->save_at_end = 0;
  move(editor->y, editor->x);
  load_file(editor, file);

  printw("%s", editor->m_buffer.content);
}
