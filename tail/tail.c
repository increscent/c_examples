#include <stdio.h>
#include <stdlib.h>

#define N_LINES 10

int is_number(char *str)
{
    if (*str == '\0')
        return 0;

    while (*str >= '0' && *str++ <= '9')
        ;

    return *str == '\0';
}

int main(int argc, char **argv)
{
    char **lines = NULL;
    char *line = NULL;
    size_t n = 0;
    int head = 0;
    int i;
    int nlines = 0;

    if (argc == 2 && argv[1][0] == '-' && is_number(argv[1] + 1))
        nlines = atoi(argv[1] + 1);

    if (nlines <= 0)
        nlines = N_LINES;

    lines = calloc(sizeof(char **), nlines);

    while (getline(&line, &n, stdin) >= 0) {
        lines[head] = line;
        head = (head + 1) % nlines;
        line = NULL;
        n = 0;
    }

    for (i = 0; i < nlines; i++) {
        if (lines[head])
            printf("%s", lines[head]);

        head = (head + 1) % nlines;
    }

    return 0;
}
