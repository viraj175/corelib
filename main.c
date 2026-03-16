// #include "my_malloc.h"
#include "my_string.h"

int main () 
{
    String *str = string_new("hello");
    string_print(str);
    printf("string length: %lu\n", str->len);
    printf("string capacity: %lu\n", str->capacity);
    char c;
    string_get(str, 4, &c);
    printf("character get: %c\n", c);
    
    return 0;
}
