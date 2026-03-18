// #include "my_malloc.h"
#include "my_string.h"
#include "stack.h"
#include "queue.h"
// #include "my_malloc.h"
// #include <bits/types/stack_t.h>

int main () 
{
    // Tetisng String Start here
    String *str = string_new("Hello");
    string_print(str);
    printf("string length: %lu\n", str->len);
    printf("string capacity: %lu\n", str->capacity);
    char c;
    string_get(str, 4, &c);
    printf("character get: %c\n", c);
    string_append(str, ", Soma Yukihira");
    string_print(str);
    String *name = string_new("viraj");
    String *anime = string_new("World Trigger");
    // Testing String Ends here

    printf("\n");

    // Testing Stack Starts here
    Stack *s = stack_new();
    printf("empty: %d\n", is_stack_empty(s));
    push(s, name);
    push(s, anime);
    push(s, str);
    printf("STACK SIZE: %lu\n", s->size);

    printf("PEEKED: %s\n", stack_peek(s)->str);
    stack_print(s);
    printf("POPED: %s\n", pop(s)->str);
    stack_print(s);
    printf("POPED: %s\n", pop(s)->str);
    stack_print(s);
    pop(s);
    printf("STACK SIZE: %lu\n", s->size);
    // Testing Stack Ends here
    
    printf("\n");

    // Tetisng Queue Starts here
    Queue *q = queue_new();
    printf("empty: %d\n", is_queue_empty(q));
    queue_peek(q);
    dequeue(q);
    enqueue(q, name);
    queue_print(q);
    printf("PEEKED: %s\n", queue_peek(q)->str);
    enqueue(q, anime);
    queue_print(q);
    printf("PEEKED: %s\n", queue_peek(q)->str);
    enqueue(q, str);
    queue_print(q);
    printf("QUEUE SIZE: %lu\n", q->size);
    printf("DEQUEUED: %s\n", dequeue(q)->str);
    queue_print(q);
    printf("PEEKED: %s\n", queue_peek(q)->str);
    // Testing Queue Ends here
    
    printf("\n");
   
    stack_free(&s);
    string_free(&name);
    string_free(&anime);
    string_free(&str);
    queue_free(&q);
    
    return 0;
}
