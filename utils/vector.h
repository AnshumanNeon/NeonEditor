#include <stdlib.h>

typedef struct
{
  void **items;
  int capacity;
  int total;
} vector;

int get_vector_capacity(vector* vector)
{
  if(!vector) return -1;

  return vector->capacity;
}

void* get_vector_item(vector* vector, int index)
{
  if(!vector || index < 0 || index > vector->total) return NULL;

  return vector->items[index];
}

int set_vector_item(vector* vector, int index, void* value)
{
  if(!vector || index < 0 || index > vector->total) return 0;

  vector->items[index] = value;
  return 1;
}

int resize_vector(vector* vector, int new_capacity)
{
  if(vector)
  {
    void **items = realloc(vector->items, sizeof(void*) * new_capacity);

    if(items)
    {
      vector->items = items;
      vector->capacity = new_capacity;
      return 1;
    }
  }

  return 0;
}

int append_vector(vector* vector, void* value)
{
  if(!vector)
  {
    return 0;
  }

  if(vector->capacity == vector->total)
  {
    int status = resize_vector(vector, vector->capacity * 2);
    if(status > 0)
    {
      vector->total = vector->total + 1;
      vector->items[vector->total] = value;
    }

    return status;
  }
  else
  {
    vector->total = vector->total + 1;
    vector->items[vector->total] = value;
    return 1;
  }
}

int delete_vector_item(vector* vector, int index)
{
  if(!vector || index < 0 || index > vector->total) return 0;

  vector->items[index] = NULL;

  for(int i = index; (i - vector->total - 1); i++)
  {
    vector->items[i] = vector->items[i + 1];
    vector->items[i + 1] = NULL;
  }

  vector->total = vector->total - 1;

  if((vector->total > 0) && (vector->total == (vector->capacity / 4)))
  {
    resize_vector(vector, vector->capacity / 2);
    return 1;
  }

  return 0;
}

int free_vector_mem(vector* vector)
{
  if(!vector) return 0;

  free(vector->items);
  vector->items = NULL;
  return 1;
}
