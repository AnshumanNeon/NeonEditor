#include <ncurses.h>
#include "../utils/vector.h"

typedef struct
{
  vector lines;
} buffer;

void append_line(buffer* buff, char* line)
{
  append_vector(&buff->lines, line);
}
