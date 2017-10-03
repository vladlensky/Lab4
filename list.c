#include <stdlib.h>
#include <malloc.h>
#include "list.h"

Node_t* List_create(int value) {
	Node_t* list = malloc(sizeof(Node_t));
	list->value = value;
    list->next = NULL;
	return list;
}

int List_sum(Node_t const * node) {
	int result = 0;
	while (node != NULL) {
		result += node->value;
		node    = node->next;
	}
	return result;
}

void List_add_back(Node_t ** const node, int value) {
	Node_t* new_node = List_create(value);
    Node_t* temp = (*node);
    while(temp->next != NULL){
        temp  = temp->next;
    }
    temp->next = new_node;
}

void List_add_front(Node_t** node, int value) {
    Node_t* new_node = List_create(value);
    new_node->next=(*node);
    node = &new_node;
}

void List_free(Node_t* node) {
        while(node!=NULL){
            free(node);
            node=node->next;
        }
}

Node_t* List_node_at(Node_t * list,int element){
    if(List_length(list)<=element){
        //printf("Слишком большой номер элемента! Размер списка - %d\n",List_length(list));
        return NULL;
    }
    while (element!=0) {
        element--;
        list = list->next;
    }
    return list;
}

int List_get(Node_t * list,int element){
    Node_t * node = List_node_at(list,element);
    if(node!=NULL)
        return node->value;
    else
        return 0;
}

int List_read(Node_t * list){
    printf("Введите список целых чисел через пробел:\n");
    int temp;
    while(scanf("%d", &temp) == 1)
    {
        List_add_back(&list,temp);
    }
    if(list->next==NULL)
        return 0;
    else
        return 1;
}

int List_length(Node_t const * node){
    int length = 0;
    while(node!=NULL){
        length++;
        node=node->next;
    }
    return length;
}
