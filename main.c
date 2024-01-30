#include "./src/editor.h"

int main()
{
  Editor editor;
  setup_ncurses();
  init_buffer(&editor);

  while(1)
  {
    get_input(&editor);

    if(editor.ch == ctrl('c')) break;

    update(&editor);
  }
  
  end_editor();
  
  return 0;
}
