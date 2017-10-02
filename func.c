#include "list.h"
#include <stdlib.h>
#include "func.h"

void foreach(Node_t * node,void (*f)(int)){
    while(node!=NULL) {
        f(node->value);
        node=node->next;
    }
}

List_t* map(List_t* list,int (*f)(int)){
    List_t* newList = List_create();
    Node_t* node = list->head;
    while (node!=NULL){
        List_add_back(newList,f(node->value));
        node=node->next;
    }
    return newList;
}

void map_mut(List_t* list,int (*f)(int)){
    Node_t* node = list->head;
    while (node!=NULL){
        node->value=f(node->value);
        node=node->next;
    }
}

int foldl(List_t* list,int (*f)(int, int), int bat)
{
    Node_t* node = list->head;
    while (node != NULL)
    {
        bat = f(bat, node->value);
        node = node->next;
    }
    return bat;
}

List_t* iterate(int first_element,int length,int (*f)(int)){
    List_t* list = List_create();
    int i;
    for(i = 0;i < length;i++){
        List_add_back(list,first_element);
        first_element=f(first_element);
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
