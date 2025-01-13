#include "../include/draw.h"

void draw_pixel(window *win, int x, int y, color c) {
  win->data[y][x] = c;
}

void draw_rect(window *win, int x1, int y1, int x2, int y2, color c) {
  for(int y = y1; y <= y2; y++) {
    for(int x = x1; x <= x2; x++) {
      draw_pixel(win, x, y, c);
    }
  }
}

void draw_line(window *win, int x1, int y1, int x2, int y2, color c) {
  int dx = abs(x2 - x1);
  int sx = (x1 < x2) ? 1 : -1;
  int dy = -abs(y2 - y1);
  int sy = (y1 < y2) ? 1 : -1;
  int error = dx + dy;

  while(1) {
    draw_pixel(win, x1, y1, c);
    if(x1 == x2 && y1 == y2) {
      break;
    }
    int e2 = 2 * error;
    if(e2 >= dy) {
      error += dy;
      x1 += sy;
    }
    if(e2 <= dx) {
      error += dx;
      y1 += sy;
    }
  }
}
