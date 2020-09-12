#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LINE_SIZE 100

int main(int argc, char **argv)
{
    int i;
    char line[LINE_SIZE];
    ssize_t bytes_read;

    printf("What is your name? ");

    bytes_read = read(fileno(stdin), line, LINE_SIZE);

    if (bytes_read < 0) {
        printf("Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < bytes_read; i++) {
        printf("'%c' ", line[i]);
    }

    printf("Hello, %s\n", line);

    return 0;
}
