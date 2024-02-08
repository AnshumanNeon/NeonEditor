#include <ncurses.h>
#include "./defs.h"

void text_edit(Editor* editor)
{
  char ch = editor->ch;
  editor->m_buffer.content = strcat(editor->m_buffer.content, &ch);
  addch(editor->ch);
  return;
}
