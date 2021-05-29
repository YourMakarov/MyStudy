CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -g
OBJ = main.o stack.o
PROG = program

build: main.o stack.o
	$(CC) $(CFLAGS) -o $(PROG) $(OBJ)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

list.o: stack.c
	$(CC) $(CFLAGS) -c stack.c

clean:
	rm $(PROG) $(OBJ)