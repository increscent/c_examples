#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int pid;

    if ((pid = fork()) < 0) {
        fprintf(stderr, "Failed to fork: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        if (argc > 1) {
            execvp(argv[1], argv+1);
        } else {
            execlp("/usr/bin/cat", "/usr/bin/cat", "fork.c", NULL);
        }

        fprintf(stderr, "There was an error with exec: %s\n", strerror(errno));
    } else {
        // Parent process
        wait(NULL);
    }

    return 0;
}
