#include <ncurses.h>
#include "../utils/vector.h"

typedef struct
{
  vector lines;
} buffer;

void remove_tab(buffer* buffer);
