CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -g
OBJ = main.o stack.o sort.o
PROG = program

build: main.o sort.o stack.o
	$(CC) $(CFLAGS) -o $(PROG) $(OBJ)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

sort.o: sort.c
	$(CC) $(CFLAGS) -c sort.c

stack.o: stack.c
	$(CC) $(CFLAGS) -c stack.c

clean:
	rm $(PROG) $(OBJ)