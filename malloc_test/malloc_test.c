#include <setjmp.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

sigjmp_buf jmpbuf;

int actual_bytes(int malloc_bytes);

void signal_handler(int signal)
{
    const char *error_message = "Segfault!\n";
    write(STDERR_FILENO, error_message, strlen(error_message));
    siglongjmp(jmpbuf, 1);
}

int main()
{
    int i;

    if (signal(SIGSEGV, signal_handler) == SIG_ERR) {
        fprintf(stderr, "Failed to register signal handler\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i <= 100000; i += 1000) {
        fprintf(stderr, "here\n");
        printf("Malloc bytes: %d; actual bytes: %d;\n", i, actual_bytes(i));
    }

    return 0;
}

int actual_bytes(int malloc_bytes)
{
    int bytes = 0;
    char *buffer = (char *)malloc(malloc_bytes);

    while (sigsetjmp(jmpbuf, 1) == 0) {
        buffer[bytes] = buffer[bytes];
        bytes++;
    }

//    free(buffer);
    return bytes;
}
