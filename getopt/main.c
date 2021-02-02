#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {

    opterr = 0;

    int c;
    while ((c = getopt(argc, argv, "a:b:")) != -1) {
        switch (c) {
            case 'a':
                printf("got -a, argument: %s\n", optarg);
                break;

            case 'b':
                printf("got -b, argument: %s\n", optarg);
                break;

            case '?':
                printf("got invalid option\n");
                break;

            default:
                printf("got %c\n", c);
                break;
        }
    }

    for (int i = 0; i < argc; i++) {
        printf("argv[%i] = %s\n", i, argv[i]);
    }
}
