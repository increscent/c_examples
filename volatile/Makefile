CC		= gcc
CFLAGS	= -Wall -pthread

volatile: volatile.o
	$(CC) $(CFLAGS) -o volatile volatile.o

volatile.o: volatile.c
	$(CC) $(CFLAGS) -c volatile.c

clean:
	rm -f volatile.o volatile
