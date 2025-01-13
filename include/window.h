#include<stdlib.h>

// https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
typedef enum {
  BLACK   = 30,
  RED     = 31,
  GREEN   = 32,
  YELLOW  = 33,
  BLUE    = 34,
  MAGENTA = 35,
  CYAN    = 36,
  WHITE   = 37,
} color;

typedef struct {
  int width;
  int height;
  color **data;
} window;


window* new_window(int height, int width);

void free_window(window *win); // TODO:

void print_window(window *win);
