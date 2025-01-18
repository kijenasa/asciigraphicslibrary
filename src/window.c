#include "../include/window.h"
#include "../include/input.h"
#include<stdio.h>

window* new_window(int width, int height) {
  color **front = malloc(height * sizeof(color*));
  color **back = malloc(height * sizeof(color*));
  if(front == NULL || back == NULL) {
    puts("Failed to allocate memory");
    return NULL;
  }

  for(int i = 0; i < height; i++) {
    front[i] = malloc(width * sizeof(color));
    back[i] = malloc(width * sizeof(color));
    if(front[i] == NULL || back[i] == NULL) {
      puts("Failed to allocate memory");
      for(int j = 0; j < i; j++) {
        free(front[j]);
        free(back[j]);
      }
      free(front);
      free(back);
      return NULL;
    }

    for(int c = 0; c < width; c++) {
      front[i][c] = BLACK;
      back[i][c] = BLACK;
    }
  }

  window *out = malloc(sizeof(window));

  out->width = width;
  out->height = height;
  out->front = front;
  out->back = back;
  return out;
}

color read_pixel(window *win, int x, int y) {
  return win->front[y][x];
}

void free_window(window *win) {
  for(int x = 0; x < win->height; x++) {
    free(win->front[x]);
  }
  free(win->front);
  free(win);
}

void print_window(window *win) {
  system("clear");
  for(int y = 0; y < win->height; y++) {
    for(int x = 0; x < win->width; x++) {
      printf("\033[%dm▒\033[0m", win->front[y][x]);
    }
    printf("\n");
  }
}

void push_window_buffer(window *win) {
  win->front = win->back;
}
