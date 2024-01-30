#include "./src/editor.h"

int main()
{
  Editor editor;
  setup_ncurses();
  init_buffer(&editor);

  while(should_quit(&editor))
  {
    get_input(&editor);

    update(&editor);
  }
  
  end_editor();
  
  return 0;
}
