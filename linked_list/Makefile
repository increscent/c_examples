CC		= gcc
CFLAGS	= -Wall
OBJECTS = linked_list.o read_line.o read_names.o

read_names: $(OBJECTS)
	$(CC) $(CFLAGS) -o read_names $(OBJECTS)

read_names.o: read_names.c
	$(CC) $(CFLAGS) -c read_names.c

read_line.o: read_line.c
	$(CC) $(CFLAGS) -c read_line.c

linked_list.o: linked_list.c
	$(CC) $(CFLAGS) -c linked_list.c

clean:
	rm -f $(OBJECTS) read_names
