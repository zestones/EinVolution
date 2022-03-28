CC = gcc 
CFLAGS = -W -Wall
LDLIBS = -lglut -lGLU -lGL -lm

all: einvolution simple-clean

einvolution: main.o
	$(CC) main.o $(LDLIBS) -o einvolution

main: main.c
	$(CC) $(CFLAGS) main.c -c

simple-clean:
	rm -f *.o

clean: simple-clean
	rm -f einvolution