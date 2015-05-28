CC=g++
DEBUG=-g
CFLAGS=-c -Wall $(DEBUG)
LDFLAGS=$(DEBUG)
SOURCES=main.cpp PrefixStringSet.cpp TrieNode.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=TheSpanishAquisition

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
