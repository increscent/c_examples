CC		= gcc
CFLAGS	= -Wall -pedantic
OBJECTS = linked_list.o read_line.o read_names.o

read_names: $(OBJECTS)
	$(CC) $(CFLAGS) -o read_names $(OBJECTS)

read_names.o: read_names.c read_line.h linked_list.h
	$(CC) $(CFLAGS) -c read_names.c

read_line.o: read_line.c read_line.h
	$(CC) $(CFLAGS) -c read_line.c

linked_list.o: linked_list.c linked_list.h
	$(CC) $(CFLAGS) -c linked_list.c

clean:
	rm -f $(OBJECTS) read_names
