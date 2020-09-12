
typedef struct linked_list {
    void *value;
    struct linked_list *next;
} ll;

ll *ll_create();
void ll_add(ll *head, void *value);
ll *ll_next(ll *node);
void *ll_value(ll *node);
void ll_free(ll *head, int free_value);
