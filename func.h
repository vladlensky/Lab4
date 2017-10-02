#ifndef FUNC_H
#define FUNC_H


void foreach(Node_t * node,void (*f)(int));
List_t* map(List_t* list,int (*f)(int));
void map_mut(List_t* list,int (*f)(int));
int foldl(List_t* list,int (*f)(int, int), int bat);
List_t* iterate(int first_element,int length,int (*f)(int));
int square(int element);
int cube(int element);
void node_print_space(int value);
void node_print_transfer(int value);
int more(int first,int second);
int less(int first,int second);
int summ(int f,int s);
int mul2(int element);

#endif