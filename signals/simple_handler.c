#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

volatile int signal_count = 5;

void handler(int sig)
{
    char *str = "Signals remaining: ";
    char c = --signal_count + '0';

    write(STDOUT_FILENO, str, strlen(str));
    write(STDOUT_FILENO, &c, 1);
    write(STDOUT_FILENO, "\n", 1);
}

int main()
{
    if (signal(SIGINT, handler) == SIG_ERR) {
        fprintf(stderr, "Failed to register signal handler\n");
        return EXIT_FAILURE;
    }

    while (signal_count > 0) {
        printf("Waiting for signal...\n");
        pause();
    }
}
