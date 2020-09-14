/*
 * This program illustrates a simple race condition.
 * The shared variable "X" is incremented concurrently
 * by two identical threads. The final value should equal
 * the sum of the number of times it was incremented by each
 * thread. But because of race conditions, its total is lower
 * than expected. Can you explain why?
 */

#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOOPS   100000

volatile long X;

void *thread(void *);
void handle_pthread_error(int);

int main()
{
    pthread_t thread1;
    pthread_t thread2;
    void *retval1;
    void *retval2;

    X = 0;

    // Start the threads.
    handle_pthread_error(pthread_create(&thread1, NULL, &thread, (void *)LOOPS));
    handle_pthread_error(pthread_create(&thread2, NULL, &thread, (void *)LOOPS));

    // Wait for both threads to finish.
    handle_pthread_error(pthread_join(thread1, &retval1));
    handle_pthread_error(pthread_join(thread2, &retval2));

    printf("Final value of X:\t%ld\n", X);
    printf("Expected value of X:\t%ld\n", (long)retval1 + (long)retval2);

    return 0;
}

/*
 * This is the actual code that gets implemented in each thread.
 */
void *thread(void *arg)
{
    long loops = (long)arg;
    long i;

    for (i = 0; i < loops; i++)
        X++;

    return (void *)i;
}

void handle_pthread_error(int err)
{
    if (err != 0) {
        fprintf(stderr, "pthread error: %s\n", strerror(err));
        fprintf(stderr, "exiting...\n");

        exit(EXIT_FAILURE);
    }
}
