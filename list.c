#include <stdlib.h>
#include <malloc.h>
#include "list.h"

List_t* List_create() {
	List_t* list = malloc(sizeof(List_t));
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	return list;
}

int List_sum(List_t* list) {
	int result = 0;
	Node_t* node = list->head;
	while (node != NULL) {
		result += node->value;
		node    = node->next;
	}
	return result;
}

void List_add_back(List_t* list, int value) {
	Node_t* new_node = malloc(sizeof(Node_t));
	new_node->value = value;
	new_node->next  = NULL;
	if (list->head == NULL) {
		list->head = new_node;
		list->tail = new_node;
		list->size = 1;
	} else {
		list->tail->next = new_node;
		list->tail = new_node;
		list->size = list->size + 1;
	}
}

void List_add_front(List_t* list, int value) {
    Node_t* new_node = malloc(sizeof(Node_t));
    new_node->value = value;
    new_node->next  = list->head;
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
        list->size = 1;
    } else {
        list->head=new_node;
        list->size++;
    }
}

void List_free(List_t* list) {
    if (list->head == NULL) {
        free(list);
    } else {
        Node_t * node = list->head;
        while(node!=NULL){
            free(node);
            node=node->next;
        }
        free(list);
    }
}

Node_t* List_node_at(List_t* list,int element){
    if(list->size<=element){
        printf("Слишком большой номер элемента! Максимальный размер - %d\n",list->size);
        return NULL;
    }
    Node_t* getter = list->head;
    while (element!=0) {
        element--;
        getter = getter->next;
    }
    return getter;
}

int List_get(List_t* list,int element){
    Node_t * node = List_node_at(list,element);
    if(node!=NULL)
        return node->value;
    else
        return -1;
}

void List_read(List_t* list){
    printf("Введите список целых чисел через пробел:\n");
    int temp;
    while(scanf("%d", &temp) == 1)
    {
        List_add_back(list,temp);
    }
}
