#include <stdlib.h>
#include <string.h>

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
