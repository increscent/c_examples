#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LINE_SIZE 100

void read_line(char *line, size_t count);

int main(int argc, char **argv)
{
    int i;
    char line[LINE_SIZE];

    printf("What is your name? ");
    fflush(stdout);

    read_line(line, LINE_SIZE);

    for (i = 0; '\0' != line[i]; i++) {
        printf("'%c' ", line[i]);
    }
    printf("\n");

    printf("Hello, %s\n", line);

    return 0;
}

void read_line(char *line, size_t count)
{
    size_t pos = 0;
    ssize_t bytes_read;

    while (pos < count && (bytes_read = read(fileno(stdin), line + pos, count - pos)) > 0) {
        pos += bytes_read;
        if ('\n' == line[pos-1])
            break;
    }

    if (bytes_read < 0) {
        printf("Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    line[pos-1] = '\0';
}
