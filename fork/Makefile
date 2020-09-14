CC		= gcc
CFLAGS	= -Wall

build: fork exec

exec: exec.o
	$(CC) $(CFLAGS) -o exec exec.o

exec.o: exec.c
	$(CC) $(CFLAGS) -c exec.c

fork: fork.o
	$(CC) $(CFLAGS) -o fork fork.o

fork.o: fork.c
	$(CC) $(CFLAGS) -c fork.c

clean:
	rm -f fork.o fork exec.o exec
