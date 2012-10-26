CC = gcc
CXXFLAGS = -Wall
LDFLAGS = -Wall
TARGETS = main

all: $(TARGETS)

clean:
	rm -f *.o $(TARGETS)

main: main.o quickSort.o
main.o: main.c quickSort.h
quickSort.o: quickSort.c quickSort.h
