#include<stdlib.h>

#ifndef WINDOW_H
#define WINDOW_H

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
  color **front;
  color **back;
} window;


window* new_window(int height, int width);

color read_pixel(window *win, int x, int y);

void free_window(window *win);

void print_window(window *win);

void push_window_buffer(window *win); // TODO

#endif
