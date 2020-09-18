/*
 * This program takes a variable number of arguments,
 * reverses each argument in-place, and then prints it.
 *
 * In its original form, it should never terminate.
 * So the first task is to find the infinite loop and
 * correct it.
 *
 * After the infinite loop is corrected, it should
 * terminate with a segmentation fault before it
 * finishes.
 *
 * Use gdb to find the offending code and fix it. 
 * The goal is to explore gdb.
 * 
 * Here's a summary of the basic gdb commands:
 * https://darkdust.net/files/GDB%20Cheat%20Sheet.pdf
 *
 * Hint: make sure to compile with the -g flag
 * to use your executable binary with gdb.
 */

#include <stdio.h>

void reverse(char *str);

int main(int argc, char **argv)
{
    int i;

    for (i = 0; i < argc; i++) {
        reverse(argv[i]);
        printf("argv[%d] reversed is '%s'\n", i, argv[i]);
    }

    return 0;
}

void reverse(char *str)
{
    int front;
    int back;
    char tmp;

    back = 0;
    while (str[back] != '\0')
        back++;

    back--;
    front = 0;

    while (front < back) {
        tmp = str[front];
        str[front] = str[back];
        str[back] = tmp;

        front++;
        back--;
    }
}
