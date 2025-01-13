#include<stdlib.h>
#include<stdio.h>

#include "../include/window.h"
#include "../include/draw.h"

int main(int argc, char *argv[]) {
  window *win = new_window(158, 35);

  draw_pixel(win, 157, 34, BLUE);
  draw_rect(win, 1, 1, 10, 12, GREEN);
  draw_rect(win, 2, 2, 9, 11, BLACK);
  draw_line(win, 0, 0, 156, 34, WHITE);
  print_window(win);

  free_window(win);

  return EXIT_SUCCESS;
}
