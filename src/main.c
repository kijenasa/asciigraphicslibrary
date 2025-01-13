#include<stdlib.h>
#include<stdio.h>

#include "../include/window.h"

int main(int argc, char *argv[]) {
  window *win = new_window(158, 35);
  print_window(win);

  free_window(win);

  return EXIT_SUCCESS;
}
