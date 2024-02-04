#include <ncurses.h>
#include "./defs.h"

void text_edit(Editor* editor)
{
  if(editor->ch == 8 || editor->ch == 127 || editor->ch == 7)
  {
    if(editor->x > 0)
    {
      move(editor->y, editor->x - 1);
    }
    else
    {
      move(editor->y - 1, editor->x);
    }

    delch();
  }
  else
  {
    char ch = editor->ch;
    editor->m_buffer.content = strcat(editor->m_buffer.content, &ch);
    addch(editor->ch);
  }
}
