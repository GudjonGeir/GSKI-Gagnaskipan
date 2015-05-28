CC=g++
DEBUG=-g
CFLAGS=-c -Wall -pedantic $(DEBUG)
LDFLAGS=$(DEBUG)
SOURCES=Contact.cpp ContactNode.cpp StringContactMap.cpp main.cpp ContactManager.cpp InteractivePhoneBook.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ContactManagerA

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
