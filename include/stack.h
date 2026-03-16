#ifndef STACK_H
#define STACK_H

#include "my_malloc.h"
#include "my_string.h"

typedef struct stack {
    String data;
    int top;
    size_t size;
    size_t capacity;
} Stack;


#endif // !STACK_H
