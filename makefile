CC=g++
CFLAGS=-c -Wall -Wextra -std=c++11 -ggdb -Iinclude/
LDFLAGS=$(shell pkg-config --libs ncurses)
SOURCES=$(wildcard src/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=snake

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
