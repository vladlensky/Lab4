#ifndef LIST_H
#define LIST_H

typedef struct Node_t {
    int value;
    struct Node_t* next;
} Node_t;

typedef struct List_t {
    int size;
    struct Node_t* head;
    struct Node_t* tail;
} List_t;

Node_t* List_create(int value);
int List_sum(Node_t const* list);
void List_add_back(Node_t** list, int value);
void List_add_front(Node_t** list, int value);
void List_free(Node_t* list);
Node_t* List_node_at(Node_t * list,int element);
int List_get(Node_t * list,int element);
int List_read(Node_t* list);
int List_length(Node_t const * node);
#endif