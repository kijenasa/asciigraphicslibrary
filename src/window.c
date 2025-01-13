#include "../include/window.h"
#include<stdio.h>

window* new_window(int width, int height) {
  color **data = malloc(height * sizeof(color*));
  if(data == NULL) {
    puts("Failed to allocate memory");
    return NULL;
  }

  for(int i = 0; i < height; i++) {
    data[i] = malloc(width * sizeof(color));
    if(data == NULL) {
      puts("Failed to allocate memory");
      for(int j = 0; j < i; j++) {
        free(data[j]);
      }
      free(data);
      return NULL;
    }

    for(int c = 0; c < width; c++) {
      data[i][c] = BLACK;
    }
  }

  window *out = malloc(sizeof(window));
  out->width = width;
  out->height = height;
  out->data = data;
  return out;
}

void free_window(window *win) {
  for(int x = 0; x < win->height; y++) {
    free(win->data[x]);
  }
  free(win->data);
  free(win);
}

void print_window(window *win) {
  for(int y = 0; y < win->height; y++) {
    for(int x = 0; x < win->width; x++) {
      printf("\033[%dm▒\033[0m", win->data[y][x]);
    }
    printf("\n");
  }
}
