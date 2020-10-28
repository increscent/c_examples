
# Example Makefile
#
# In this example there is 1 main module and 3 helper modules.
# Here is a list of the .c and .h files:
# 537ps.c
# module1.c module1.h
# module2.c module2.h
# module3.c module3.h
#
# Here is the dependency tree:
#
#          -- module1
#         /
# 537ps --
#         \
#          -- module2 --
#                       \
#                        -- module3
#
#
# Remember that if a module depends on another module,
# the .h file for its dependency must be included in
# the Makefile as a dependency (e.g. module2 depends
# on module3 so module3.h is listed as a dependency
# for the target module2.o)
#

CC      = gcc
CFLAGS	= -Wall -pedantic
OBJECTS = 537ps.o module1.o module2.o module3.o

537ps: $(OBJECTS)
	$(CC) $(CFLAGS) -o 537ps $(OBJECTS)

537ps.o: 537ps.c module1.h module2.h
	$(CC) $(CFLAGS) -c 537ps.c

module1.o: module1.c module1.h
	$(CC) $(CFLAGS) -c module1.c

module2.o: module2.c module2.h module3.h
	$(CC) $(CFLAGS) -c module2.c

module3.o: module3.c module3.h
	$(CC) $(CFLAGS) -c module3.c

clean:
	rm -f $(OBJECTS) 537ps
