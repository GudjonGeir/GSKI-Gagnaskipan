CC=g++
DEBUG=-g
CFLAGS=-c -Wall $(DEBUG)
LDFLAGS=$(DEBUG)
SOURCES= Ant.cpp Bug.cpp Organism.cpp World.cpp main.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=hello

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
