#include <stdlib.h>

typedef struct Buffer
{
  char* content;
  int length;
} Buffer;

void init_buffer(Buffer* buff, FILE* file)
{
  fseek(file, 0, SEEK_END);
  buff->length = ftell(file);
  fseek(file, 0, SEEK_SET);

  buff->content = malloc(buff->length);
}

void end_buffer(Buffer* buff)
{
  free(buff->content);
  buff->length = -1;
}

void set_buffer(Buffer* buff, FILE* file)
{
  if(!buff->content) return;

  if(!fread(buff->content, 1, buff->length, file))
  {
    end_buffer(buff);
    return;
  }
}
