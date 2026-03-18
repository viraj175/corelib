#include "stack.h"
#include "my_malloc.h"
#include "my_string.h"
#include <stdio.h>
#include <string.h>

Stack *stack_new ()
{
    Stack *new_stack = my_malloc(sizeof(Stack));
    if (new_stack == NULL)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        return NULL;
    }

    new_stack->size = 0;
    new_stack->top = NULL;

    return new_stack;
}

void push (Stack *st, String *data)
{
    if (st == NULL || data == NULL)
    {
        fprintf(stderr, "ERROR: stack doesn't exist or data is invalid!\n");
        return;
    }

    stackNode *new_node = my_malloc(sizeof(stackNode));
    if (new_node == NULL)
    {
        fprintf(stderr, "ERROR: memory allocation for stackNode failed!\n");
        return;
    }

    new_node->data = data;
    new_node->next = st->top;
    st->top = new_node;
    st->size++;
}

String *pop (Stack *st)
{
    if (st == NULL || st->top == NULL)
    {
        fprintf(stderr, "ERROR: stack doesn't exist or empty, can't pop!\n");
        return NULL;
    }

    stackNode *temp = st->top;
    String *data = temp->data;
    st->top = temp->next;
    my_free((void **)&temp);
    st->size--;

    return data;
}

String *peek (Stack *st)
{
    if (st == NULL || st->top == NULL)
    {
        fprintf(stderr, "ERROR: stack is invalid or doesn't exist, can't peek!\n");
        return NULL;
    }

    return st->top->data;
}

void stack_print (Stack *st)
{
    if (st == NULL)
    {
        printf("ERROR: [NULL STACK]-->\n");
        return;
    }

    printf("TOP --> ");

    stackNode *temp = st->top;
    while (temp != NULL)
    {
        printf("[ DATA: %s ] --> ", temp->data ? temp->data->str : "NULL");
        temp = temp->next;
    }
    
    printf("NULL\n");
}

int is_empty (Stack *st)
{
    if (st == NULL) return 1;
    return st->top == NULL;
}

void stack_free (Stack **st)
{
    if (st == NULL || *st == NULL) return;

    while ((*st)->top != NULL)
    {
        stackNode *temp = (*st)->top;
        (*st)->top = temp->next;
        my_free((void **)&temp);
    }

    my_free((void **)st);
}
