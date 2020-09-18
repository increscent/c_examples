#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"
// test comment

ll *ll_create()
{
    ll *head = calloc(1, sizeof(ll));

    if (NULL == head) {
        printf("Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    return head;
}

void ll_add(ll *head, void *value)
{
    ll *new_node = calloc(1, sizeof(ll));

    if (NULL == new_node) {
        printf("Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    new_node->next = head->next;
    new_node->value = value;

    head->next = new_node;
}

ll *ll_next(ll *node)
{
    return node->next;
}

void *ll_value(ll *node)
{
    return node->value;
}

void ll_free(ll *head, int free_value)
{
    ll *node = head;
    ll *tmp;

    while (node) {
        if (free_value)
            free(node->value);

        tmp = node->next;
        free(node);
        node = tmp;
    }
}
