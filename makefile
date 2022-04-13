CC = gcc 
CFLAGS = -W -Wall
LDLIBS = -lglut -lGLU -lGL -lm

entities = camera.o world.o world_object.o object.o
systems = position.o vector.o cube.o color.o face.o
components = house.o box.o pyramide.o


all: einvolution simple-clean

einvolution: main.o $(entities) $(systems) $(components) 
	$(CC) main.o $(entities) $(systems) $(components) $(LDLIBS) -o einvolution


##################################################

#                     MAIN                       #
#               ----------------			     #

main.o: main.c
	$(CC) $(CFLAGS) main.c -c



##################################################

#                    ENTITIES                    #
#               ----------------			     #

camera.o: ./src/entities/camera.c 
	$(CC) $(CFLAGS) ./src//entities/camera.c -c

world.o: ./src/entities/world/world.c 
	$(CC) $(CFLAGS) ./src/entities/world/world.c -c

world_object.o: ./src/entities/world/world_object.c 
	$(CC) $(CFLAGS) ./src/entities/world/world_object.c -c

object.o: ./src/entities/world/object.c 
	$(CC) $(CFLAGS) ./src/entities/world/object.c -c



##################################################

#                     SYSTEMS                    #
#               ----------------			     #

position.o: ./src/systems/geometry/position.c 
	$(CC) $(CFLAGS) ./src/systems/geometry/position.c -c

vector.o: ./src/systems/geometry/vector.c 
	$(CC) $(CFLAGS) ./src/systems/geometry/vector.c -c

cube.o: ./src/systems/cube.c 
	$(CC) $(CFLAGS) ./src/systems/cube.c -c

face.o: ./src/systems/shape/face.c 
	$(CC) $(CFLAGS) ./src/systems/shape/face.c -c

color.o: ./src/systems/shape/color.c 
	$(CC) $(CFLAGS) ./src/systems/shape/color.c -c



##################################################

#                   COMPONENTS                   #
#               ----------------			     #

box.o: ./src/components/primitive-shape/box.c 
	$(CC) $(CFLAGS) ./src/components/primitive-shape/box.c -c

pyramide.o: ./src/components/primitive-shape/pyramide.c 
	$(CC) $(CFLAGS) ./src/components/primitive-shape/pyramide.c -c

house.o: ./src/components/complex-shape/house.c 
	$(CC) $(CFLAGS) ./src/components/complex-shape/house.c -c



##################################################

#                     CLEAR                      #
#               ----------------			     #

simple-clean:
	rm -f *.o

clean: simple-clean
	rm -f einvolution

##################################################
