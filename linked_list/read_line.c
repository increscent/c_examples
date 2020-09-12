#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LINE_SIZE 100

char *read_line(const char *prompt)
{
    size_t pos = 0;
    ssize_t bytes_read;
    char *buf = malloc(LINE_SIZE);
    size_t buf_size = LINE_SIZE;

    if (buf == 0) {
        printf("Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf(prompt);
    fflush(stdout);

    while ((bytes_read = read(fileno(stdin), buf + pos, buf_size - pos)) > 0) {
        pos += bytes_read;
        if ('\n' == buf[pos-1])
            break;

        if (pos == buf_size) {
            buf = realloc(buf, buf_size + LINE_SIZE);
            buf_size += LINE_SIZE;
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
