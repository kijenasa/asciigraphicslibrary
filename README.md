A C library for making psuedo-graphical progams for terminals using the U+2580-259F character (▒) and ANSI escape codes for color.

![example image](https://cloud-75opc1bi6-hack-club-bot.vercel.app/0screenshot_20250117_205547.png)

# Building
```
make build
make clean
```
This will produce a static library, `libagl.a`, which you can use.

# Using
## Including
Include AGL in your project.

Say this is your project's structure:
```
.
├── include
│   ├── draw.h
│   └── window.h
├── src
│   └── main.c
├── lib
│   └── libagl.a
└── a.out
```
You could compile this using
```
gcc -I./include -Llib src/*.c -l agl -o main
```
## Using
A working `main.c` could look like this:
```
#include<stdlib.h>
#include "window.h"
#include "draw.h"

int main(int argc, char *argv[]) {
  window* win = new_window(10,10);

  draw_pixel(win, 1,1, RED);

  push_window_buffer(win);
  print_window(win);

  free_window(win);
  return EXIT_SUCCESS;
}
```
Notice how you need to call `push_window_buffer()` to switch the front and back pointers.
To avoid memory leaks, make sure to use `free_window()` when your done.

More functions can be found in the header files.
