// #include "my_malloc.h"
#include "my_string.h"
#include "stack.h"
#include <bits/types/stack_t.h>
#include "my_malloc.h"

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
    // Testing String Ends here

    printf("\n");

    // Testing Stack Starts here
    Stack *s = stack_new();
    printf("empty: %d\n", is_empty(s));
    String *name = string_new("viraj");
    push(s, name);
    String *anime = string_new("World Trigger");
    push(s, anime);
    push(s, str);
    printf("STACK SIZE: %lu\n", s->size);

    printf("PEEKED: %s\n", peek(s)->str);
    stack_print(s);
    printf("POPED: %s\n", pop(s)->str);
    stack_print(s);
    printf("POPED: %s\n", pop(s)->str);
    stack_print(s);
    pop(s);
    printf("STACK SIZE: %lu\n", s->size);
    // Testing Stack Ends here
    
    printf("\n");
    
    stack_free(&s);
    string_free(&name);
    string_free(&anime);
    string_free(&str);
    
    return 0;
}
