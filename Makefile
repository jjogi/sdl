CC = gcc
CXX = g++
LIBS = -lSDL -lGL -lGLU -lGLEW
FLAGS = -g -Wall# -Weffc++
EXEC = game
OBJS = $(EXEC).o init.o event.o loop.o render.o cleanup.o objects.o vec3.o vec4.o mat3.o mat4.o quat.o

$(EXEC): $(OBJS)
	$(CXX) $(LIBS) $(FLAGS) $(OBJS) -o $(EXEC)

$(EXEC).o: src/$(EXEC).cpp
	$(CC) $(FLAGS) -c src/$(EXEC).cpp

init.o: src/init.cpp
	$(CC) $(FLAGS) -c src/init.cpp

event.o: src/event.cpp
	$(CC) $(FLAGS) -c src/event.cpp

loop.o: src/loop.cpp
	$(CC) $(FLAGS) -c src/loop.cpp

render.o: src/render.cpp
	$(CC) $(FLAGS) -c src/render.cpp

cleanup.o: src/cleanup.cpp
	$(CC) $(FLAGS) -c src/cleanup.cpp

objects.o: src/objects.cpp
	$(CC) $(FLAGS) -c src/objects.cpp

vec3.o: src/base/vec3.cpp
	$(CC) $(FLAGS) -c src/base/vec3.cpp

vec4.o: src/base/vec4.cpp
	$(CC) $(FLAGS) -c src/base/vec4.cpp

mat3.o: src/base/mat3.cpp
	$(CC) $(FLAGS) -c src/base/mat3.cpp

mat4.o: src/base/mat4.cpp
	$(CC) $(FLAGS) -c src/base/mat4.cpp

quat.o: src/base/quat.cpp
	$(CC) $(FLAGS) -c src/base/quat.cpp

clean:
	-rm *.o
#	-rm $(EXEC)

