#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LINE_SIZE 5

char *read_line();

int main(int argc, char **argv)
{
    int i;
    char *line;

    printf("What is your name? ");
    fflush(stdout);

    line = read_line();

    for (i = 0; '\0' != line[i]; i++) {
        printf("'%c' ", line[i]);
    }
    printf("\n");

    printf("Hello, %s\n", line);

    free(line);

    return 0;
}

char *read_line()
{
    size_t pos = 0;
    ssize_t bytes_read;
    char *buf = malloc(LINE_SIZE);
    size_t buf_size = LINE_SIZE;

    if (buf == 0) {
        printf("Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    while ((bytes_read = read(fileno(stdin), buf + pos, buf_size - pos)) > 0) {
        pos += bytes_read;
        if ('\n' == buf[pos-1])
            break;

        if (pos == buf_size) {
            buf = realloc(buf, buf_size + LINE_SIZE);
            buf_size += LINE_SIZE;
            printf("Buffer resized!\n");
        }
    }

    if (bytes_read < 0) {
        printf("Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Make sure the string is null-terminated
    buf[pos-1] = '\0';

    return buf;
}
