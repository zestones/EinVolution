CC = gcc 
CFLAGS = -W -Wall
LDLIBS = -lglut -lGLU -lGL -lm

all: einvolution simple-clean

einvolution: main.o camera.o position.o vector.o
	$(CC) main.o camera.o position.o vector.o $(LDLIBS) -o einvolution

main.o: main.c
	$(CC) $(CFLAGS) main.c -c

camera.o: ./src/camera.c 
	$(CC) $(CFLAGS) ./src/camera.c -c

position.o: ./src/utils/position.c 
	$(CC) $(CFLAGS) ./src/utils/position.c -c


vector.o: ./src/utils/vector.c 
	$(CC) $(CFLAGS) ./src/utils/vector.c -c


simple-clean:
	rm -f *.o

clean: simple-clean
	rm -f einvolution