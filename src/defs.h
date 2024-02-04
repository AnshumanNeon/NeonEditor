#pragma once
#include "./buffer.h"

#define ctrl(x) ((x) & 0x1f)

typedef struct
{
  //Metadata
  int width, height;
  int x, y;
  int command_palette_enabled;
  // Check command palette
  int space_pressed;
  // Buffer
  Buffer m_buffer;
  int save_at_end;

  int ch;
} Editor;
