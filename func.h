#ifndef FUNC_H
#define FUNC_H


void foreach(Node_t * node,void (*f)(int));
Node_t* map(Node_t const * list,int (*f)(int));
void map_mut(Node_t* node,int (*f)(int));
int foldl(Node_t const * node,int (*f)(int, int), int bat);
Node_t* iterate(int first_element,int length,int (*f)(int));
int square(int element);
int cube(int element);
void node_print_space(int value);
void node_print_transfer(int value);
int more(int first,int second);
int less(int first,int second);
int summ(int f,int s);
int mul2(int element);

#endif