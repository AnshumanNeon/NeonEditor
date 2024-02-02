#include "./src/editor.h"

int main()
{
  Editor editor;
  setup_ncurses();
  init_editor(&editor, "./test.txt");

  while(1)
  {
    get_input(&editor);

    if(should_quit(&editor)) break;

    update(&editor);
  }
  
  end_editor(&editor);
  
  return 0;
}
