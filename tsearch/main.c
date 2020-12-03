/*
 * Robert Williams
 * 
 * tsearch example
 */

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <search.h>

// This is what we are storing in our binary tree
// You can define this struct however you want
struct node {
    int key;
    int value;
};

// This is the compare function for the binary tree
// Returns -1 if a <  b
// Returns 1  if a >  b
// Returns 0  if a == b
int compare(const void *a, const void *b)
{
    struct node *node_a = (struct node *)a;
    struct node *node_b = (struct node *)b;

    if (node_a->key < node_b->key)
        return -1;
    else if (node_a->key > node_b->key)
        return 1;
    else
        return 0;
}

// This function prints an error message and exits
void exit_with_message(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}

// Make node for binary tree
struct node *make_node(int key, int value)
{
    struct node *node;

    if ((node = malloc(sizeof(struct node))) == NULL)
        exit_with_message("Failed to malloc");

    node->key = key;
    node->value = value;

    return node;
}

// Add the node to the binary tree
void add_node(void **root, struct node *node)
{
    // Note: the tsearch interface is quite ugly
    // Instead of returning a pointer to the node passed in as the key
    // in the first parameter, the tsearch function returns a pointer to a
    // struct whose first entry is a pointer to the key.
    struct node **result;

    if ((result = tsearch(node, root, compare)) == NULL) {
        // Failed to add the node
        exit_with_message("Insufficient memory");
    } else if (*result != node) {
        printf("Node with key already exists. ");
        printf("key: %d, value: %d\n", (*result)->key, (*result)->value);
        free(node);
    } else {
        printf("Added node. key: %d, value: %d\n", node->key, node->value);
    }
}

// Find a node in the binary tree
// Returns NULL if no node is found
struct node *find_node(void **root, int key)
{
    struct node **result;
    struct node *node;
    struct node search_node;

    search_node.key = key;

    if ((result = tfind(&search_node, root, compare)) == NULL) {
        // No node found
        printf("No node found. key: %d\n", key);
        node = NULL;
    } else {
        // Node found
        node = *result;
        printf("Found node. key: %d, value: %d\n", node->key, node->value);
    }

    return node;
}

// Delete a node in the binary tree
// If it is not found, do nothing
void delete_node(void **root, int key)
{
    struct node *node;

    if ((node = find_node(root, key)) == NULL) {
        // Nothing to delete
    } else {
        tdelete(node, root, compare);
        printf("Deleted node. key: %d, value: %d\n", node->key, node->value);
        // It's important to free the only after deleting it
        free(node);
    }
}

// Free node when destroying the tree
void free_node(void *ptr)
{
    struct node *node = ptr;

    printf("Freeing node during tree destroy. key: %d, value: %d\n",
            node->key, node->value);

    free(node);
}

int main()
{
    void *root;
    struct node *node;

    // Initialize the binary tree
    root = NULL;

    printf("ADDING NODES\n------------------------------\n");
    add_node(&root, make_node(1, 1435));
    add_node(&root, make_node(2, 1436));
    add_node(&root, make_node(1, 1437));
    add_node(&root, make_node(4, 1438));
    add_node(&root, make_node(5, 1439));

    printf("\nFINDING NODES\n------------------------------\n");
    node = find_node(&root, 1);
    node = find_node(&root, 3);

    printf("\nDELETING NODES\n------------------------------\n");
    delete_node(&root, 1);
    delete_node(&root, 2);

    printf("\nDESTROYING TREE\n------------------------------\n");
    tdestroy(root, free_node);
}
