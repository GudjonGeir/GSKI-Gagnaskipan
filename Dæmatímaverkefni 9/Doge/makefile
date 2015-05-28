CC=g++
DEBUG=-g
CFLAGS=-c -Wall $(DEBUG)
LDFLAGS=$(DEBUG)
SOURCES=BloomFilter.cpp HashCollection.cpp main.cpp

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=doge

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
