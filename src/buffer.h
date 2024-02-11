#include <stdlib.h>
#include <string.h>
#include "../utils/count_lines.h"

typedef struct Row
{
  int size;
  char* content;
} Row;

typedef struct Buffer
{
  Row rows[1024];
  int length;
  int curr_pos;
} Buffer;

void init_buffer(Buffer* buff, FILE* file)
{
  buff->length = count_lines(file);

  for(int i = 0; i < buff->length; i++)
  {
    buff->rows[i].content = calloc(1024, sizeof(char));
  }
}

void end_buffer(Buffer* buff)
{
  for(int i = 0; i < buff->length; i++)
  {
    free(buff->rows[i].content);
  }

  buff->length = -1;
}
/*
void set_buffer(Buffer* buff, FILE* file)
{
  if(!buff->content) return;

  if(fgets(buff->rows[i].content, buff->rows[i], file))
  {
    end_buffer(buff);
    return;
  }
}

void add_chars_to_buffer(Buffer* buff, char* msg)
{
  if(msg == NULL) return;

  if(!buff->content)
  {
    buff->content = msg;
    return;
  }
  
  buff->content = strcat(buff->content, msg);
  return;
}
*/
