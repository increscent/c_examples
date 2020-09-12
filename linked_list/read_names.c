#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"
#include "read_line.h"

int main()
{
    ll *names = ll_create();
    char *name;

    name = read_line("Enter a name: ");
    while (strlen(name)) {
        ll_add(names, (void*)name);

        name = read_line("Enter a name: ");
    }
    free(name);

    printf("Here are the names:\n");

    ll *iter = ll_next(names);
    while (iter) {
        printf("%s\n", (char*)ll_value(iter));

        iter = ll_next(iter);
    }

    ll_free(names, 1);
}
