#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define CHILD_EXIT_STATUS   123
#define CHILD_SLEEP_TIME    2

int main(int argc, char **argv)
{
    int pid;
    int wstatus;

    if ((pid = fork()) < 0) {
        fprintf(stderr, "Failed to fork: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        printf("Child:\tI'm the child process\n");
        printf("Child:\tMy pid is %d\n", getpid());

        sleep(CHILD_SLEEP_TIME);

        printf("Child:\tExiting with status %d ...\n", CHILD_EXIT_STATUS);

        return CHILD_EXIT_STATUS;
    } else {
        printf("Parent:\tI'm the parent process\n");

        wait(&wstatus);

        printf("WIFEXITED: %d\n", WIFEXITED(wstatus));
        printf("WEXITSTATUS: %d\n", WEXITSTATUS(wstatus));

        printf("Parent:\tNow the child has exited\n");
        printf("Parent:\tThe child's exit status was: %d\n", WEXITSTATUS(wstatus));
    }

    return 0;
}
