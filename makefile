clean: *.o
	rm *.o

build:
	gcc -c src/window.c src/draw.c
	ar rcs agl.a draw.o window.o
