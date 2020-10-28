#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * Usage: ./cat [filename]
 * If filename is specified the program prints the contents of the file.
 * Otherwise, it prints the contents of stdin.
 */

int main(int argc, char **argv)
{
    int fd;
    char c;

    if (argc > 1) {
        // Open the file for reading
        if ((fd = open(argv[1], O_RDONLY)) == -1) {
            fprintf(stderr, "Failed to open file for reading\n");
            exit(EXIT_FAILURE);
        }

        // Overwrite stdin with new file descriptor
        if (dup2(fd, STDIN_FILENO) == -1) {
            fprintf(stderr, "Failed to duplicate file descriptor onto stdin\n");
            exit(EXIT_FAILURE);
        }
    }

    // Read from stdin and write to stdout
    while ((c = getchar()) != EOF)
        putchar(c);

    exit(EXIT_SUCCESS);
}
