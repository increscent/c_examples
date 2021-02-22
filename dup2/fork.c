#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {

    pid_t pid = fork();

    if (pid != 0) {
        printf("Pid for child: %d\n", pid);
        printf("This is the parent process\n");

        wait(NULL);
    } else {
        FILE *f = fopen("out.txt", "w");
        dup2(fileno(f), fileno(stdout));
        write(1, "abc\n", 4);
        printf("My pid: %d\n", getpid());
        printf("This is the child process\n");
        fflush(stdout);

        char *my_argv[] = {"/bin/echo", "hello", "world", NULL};
        execv(my_argv[0], my_argv);

        sleep(2);
    }

    printf("Exiting... (pid %d)\n", pid);

}
