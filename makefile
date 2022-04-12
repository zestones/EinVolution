CC = gcc 
CFLAGS = -W -Wall
LDLIBS = -lglut -lGLU -lGL -lm

objects = face.o box.o pyramide.o object.o house.o world_object.o
utils = position.o vector.o cube.o color.o

all: einvolution simple-clean

einvolution: main.o camera.o world.o $(utils) $(objects) 
	$(CC) main.o camera.o world.o $(utils) $(objects) $(LDLIBS) -o einvolution

main.o: main.c
	$(CC) $(CFLAGS) main.c -c

camera.o: ./src/camera.c 
	$(CC) $(CFLAGS) ./src/camera.c -c

world.o: ./src/world.c 
	$(CC) $(CFLAGS) ./src/world.c -c


##################################################

#                     UTILS                      #
#               ----------------			     #

position.o: ./src/utils/position.c 
	$(CC) $(CFLAGS) ./src/utils/position.c -c

vector.o: ./src/utils/vector.c 
	$(CC) $(CFLAGS) ./src/utils/vector.c -c

cube.o: ./src/utils/cube.c 
	$(CC) $(CFLAGS) ./src/utils/cube.c -c

color.o: ./src/utils/color.c 
	$(CC) $(CFLAGS) ./src/utils/color.c -c



##################################################

#                   OBJECTS                      #
#               ----------------			     #

face.o: ./src/object/face.c 
	$(CC) $(CFLAGS) ./src/object/face.c -c

house.o: ./src/object/house.c 
	$(CC) $(CFLAGS) ./src/object/house.c -c

box.o: ./src/object/box.c 
	$(CC) $(CFLAGS) ./src/object/box.c -c

pyramide.o: ./src/object/pyramide.c 
	$(CC) $(CFLAGS) ./src/object/pyramide.c -c

object.o: ./src/object/object.c 
	$(CC) $(CFLAGS) ./src/object/object.c -c

world_object.o: ./src/object/world_object.c 
	$(CC) $(CFLAGS) ./src/object/world_object.c -c



##################################################

#                     CLEAR                      #
#               ----------------			     #

simple-clean:
	rm -f *.o

clean: simple-clean
	rm -f einvolution

##################################################
