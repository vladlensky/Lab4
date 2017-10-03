#include <stdio.h>
#include "list.h"
#include "func.h"

void foreach(Node_t * node,void (*f)(int)){
    while(node!=NULL) {
        f(node->value);
        node=node->next;
    }
}

Node_t* map(Node_t const * list,int (*f)(int)){
    Node_t* newList = List_create(f(list->value));
    list=list->next;
    while (list!=NULL){
        List_add_back(&newList,f(list->value));
        list=list->next;
    }
    return newList;
}

void map_mut(Node_t* node,int (*f)(int)){
    while (node!=NULL){
        node->value=f(node->value);
        node=node->next;
    }
}

int foldl(Node_t const * node,int (*f)(int, int), int bat)
{
    while (node != NULL)
    {
        bat = f(bat, node->value);
        node = node->next;
    }
    return bat;
}

Node_t* iterate(int first_element,int length,int (*f)(int)){
    Node_t* list = List_create(first_element);
    int i;
    for(i = 1;i < length;i++){
        first_element=f(first_element);
        List_add_back(&list,first_element);
    }
    return list;
}

int square(int element){
    return element*element;
}

int cube(int element){
    return element*element*element;
}

void node_print_space(int value){
    printf("%d ",value);
}

void node_print_transfer(int value){
    printf("%d\n",value);
}

int more(int first,int second){
    if(first>second)
        return first;
    else
        return second;
}

int less(int first,int second){
    if(first<second)
        return first;
    else
        return second;
}

int summ(int f,int s){
    return f+s;
}

int mul2(int element){
    return element*2;
}
