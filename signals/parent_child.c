#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int child_pid = 0;

void handler(int sig)
{
}

int main()
{
    if (signal(SIGCHLD, handler) == SIG_ERR) {
        fprintf(stderr, "Failed to register signal handler\n");
        return EXIT_FAILURE;
    }

    if ((child_pid = fork()) > 0) {
        // Parent
        printf("Child's pid is: %d\n", child_pid);
    } else {
        // Child
        is_parent = '0';
    }
}
