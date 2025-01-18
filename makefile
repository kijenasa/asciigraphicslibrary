clean: *.o
	rm *.o

build:
	gcc -c src/window.c src/draw.c
	ar rcs libagl.a draw.o window.o
