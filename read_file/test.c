#include <stdio.h>

const int BUF_SIZE = 4096;


int main(int argc, char **argv) {

    FILE *file = NULL;

    file = fopen("test.txt", "r");
    //file = stdin;

    char buf[BUF_SIZE];
    while (fgets(buf, BUF_SIZE, file) != NULL) {
        printf("%s", buf);
    }

    fclose(file);

}
