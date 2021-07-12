CC=g++
CFLAGS=-c -Wall -Wextra -std=c++11 -ggdb -Iinclude/
LDFLAGS=-lncurses
SOURCES=src/main.cpp src/Board.cpp src/Game.cpp src/Input.cpp src/Object.cpp src/Score.cpp src/Snake.cpp src/Terminal.cpp src/Window.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=snake

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf src/*.o $(EXECUTABLE)
