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

List_t* List_create();
int List_sum(List_t* list);
void List_add_back(List_t* list, int value);
void List_add_front(List_t* list, int value);
void List_free(List_t* list);
Node_t* List_node_at(List_t* list,int element);
int List_get(List_t* list,int element);
void List_read(List_t* list);

#endif