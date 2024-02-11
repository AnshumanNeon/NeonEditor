#define BUF_SIZE 65536

int count_lines(FILE* file)
{
  char buf[BUF_SIZE];
  int counter = 0;
  
  for(;;)
  {
    size_t res = fread(buf, 1, BUF_SIZE, file);
    
    if (ferror(file)) return -1;

    size_t i;
    for(i = 0; i < res; i++)
    {
      if (buf[i] == '\n') counter++;
    }

    if (feof(file)) break;
  }

  return counter;
}
