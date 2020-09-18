#include <stdio.h>
#include <stdlib.h>

#define N_LINES 10

int main(int argc, char **argv)
{
    char **lines = NULL;
    char *line = NULL;
    size_t n = 0;
    int head = 0;
    int i;
    int nlines = N_LINES;

    if (argc == 2 && argv[1][0] == '-')
        nlines = atoi(argv[1] + 1);

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
