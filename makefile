CC = gcc 
CFLAGS = -W -Wall
LDLIBS = -lglut -lGLU -lGL -lm

all: einvolution simple-clean

einvolution: main.o camera.o position.o vector.o cube.o world.o face.o house.o box.o color.o pyramide.o
	$(CC) main.o camera.o position.o vector.o cube.o world.o face.o house.o box.o color.o pyramide.o $(LDLIBS) -o einvolution

main.o: main.c
	$(CC) $(CFLAGS) main.c -c

camera.o: ./src/camera.c 
	$(CC) $(CFLAGS) ./src/camera.c -c

position.o: ./src/utils/position.c 
	$(CC) $(CFLAGS) ./src/utils/position.c -c

vector.o: ./src/utils/vector.c 
	$(CC) $(CFLAGS) ./src/utils/vector.c -c

cube.o: ./src/utils/cube.c 
	$(CC) $(CFLAGS) ./src/utils/cube.c -c

world.o: ./src/world.c 
	$(CC) $(CFLAGS) ./src/world.c -c

face.o: ./src/object/face.c 
	$(CC) $(CFLAGS) ./src/object/face.c -c

house.o: ./src/object/house.c 
	$(CC) $(CFLAGS) ./src/object/house.c -c

box.o: ./src/object/box.c 
	$(CC) $(CFLAGS) ./src/object/box.c -c

pyramide.o: ./src/object/pyramide.c 
	$(CC) $(CFLAGS) ./src/object/pyramide.c -c

color.o: ./src/utils/color.c 
	$(CC) $(CFLAGS) ./src/utils/color.c -c



simple-clean:
	rm -f *.o

clean: simple-clean
	rm -f einvolution