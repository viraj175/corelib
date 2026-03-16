// #include "my_malloc.h"
#include "my_string.h"

int main () 
{
    String *str = string_new("Hello");
    string_print(str);
    printf("string length: %lu\n", str->len);
    printf("string capacity: %lu\n", str->capacity);
    char c;
    string_get(str, 4, &c);
    printf("character get: %c\n", c);
    string_append(str, ", Soma Yukihira");
    string_print(str);
    string_free(&str);
    
    return 0;
}
