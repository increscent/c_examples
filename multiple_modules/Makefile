
program1: main.o module1.o
	gcc -o program1 main.o module1.o

program2: main.o module2.o
	gcc -o program2 main.o module2.o

module1.o: module1.c module_interface.h
	gcc -c module1.c

module2.o: module2.c module_interface.h
	gcc -c module2.c

main.o: main.c module_interface.h
	gcc -c main.c

clean:
	rm -f *.o program1 program2
