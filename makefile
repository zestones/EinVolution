CC = gcc 
CFLAGS = -W -Wall
LDLIBS = -lglut -lGLU -lGL -lm

entities = camera.o frustum.o world.o world_object.o object.o 
systems = position.o vector.o color.o face.o
components = house.o box.o pyramide.o
window = display.o window.o mouse.o keyboard.o
octree = cube.o octree.o world2tree.o tree_leaves.o


all: einvolution simple-clean

einvolution: main.o $(entities) $(systems) $(components) $(window) $(octree)
	$(CC) main.o $(entities) $(systems) $(components) $(window) $(octree) $(LDLIBS) -o einvolution


##################################################

#                     MAIN                       #
#               ----------------			     #

main.o: main.c
	$(CC) $(CFLAGS) main.c -c



##################################################

#                    ENTITIES                    #
#               ----------------			     #

camera.o: ./src/entities/camera/camera.c 
	$(CC) $(CFLAGS) ./src//entities/camera/camera.c -c

frustum.o: ./src/entities/camera/frustum.c 
	$(CC) $(CFLAGS) ./src//entities/camera/frustum.c -c

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

face.o: ./src/systems/shape/face.c 
	$(CC) $(CFLAGS) ./src/systems/shape/face.c -c

color.o: ./src/systems/shape/color.c 
	$(CC) $(CFLAGS) ./src/systems/shape/color.c -c

window.o: ./src/systems/window/window.c 
	$(CC) $(CFLAGS) ./src/systems/window/window.c -c

display.o: ./src/systems/window/display.c 
	$(CC) $(CFLAGS) ./src/systems/window/display.c -c

mouse.o: ./src/systems/window/mouse.c 
	$(CC) $(CFLAGS) ./src/systems/window/mouse.c -c

keyboard.o: ./src/systems/window/keyboard.c 
	$(CC) $(CFLAGS) ./src/systems/window/keyboard.c -c

cube.o: ./src/systems/octree/cube.c 
	$(CC) $(CFLAGS) ./src/systems/octree/cube.c -c

octree.o: ./src/systems/octree/octree.c 
	$(CC) $(CFLAGS) ./src/systems/octree/octree.c -c

tree_leaves.o: ./src/systems/octree/tree_leaves.c 
	$(CC) $(CFLAGS) ./src/systems/octree/tree_leaves.c -c

world2tree.o: ./src/systems/octree/world2tree.c 
	$(CC) $(CFLAGS) ./src/systems/octree/world2tree.c -c


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