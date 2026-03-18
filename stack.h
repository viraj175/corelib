#ifndef STACK_H
#define STACK_H

#include "my_malloc.h"
#include "my_string.h"

typedef struct node {
    struct node *next;
    String *data;
} stackNode;

typedef struct stack {
    stackNode *top;
    size_t size;
} Stack;

void push (Stack *st, String *data);
String *pop (Stack *st);
String *peek (Stack *st);
int is_empty (Stack *st);
void stack_print (Stack *st);
Stack *stack_new (void);
void stack_free (Stack **st);

#endif // !STACK_H
