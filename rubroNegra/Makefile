CC = gcc
CXXFLAGS = -Wall
LDFLAGS = -Wall
TARGETS = main

all: $(TARGETS)

clean:
	rm -f *.o $(TARGETS)

main: main.o rubroNegra.o
main.o: main.c rubroNegra.h
rubroNegra.o: rubroNegra.c rubroNegra.h
