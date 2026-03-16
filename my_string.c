#include "my_string.h"
#include <stddef.h>
#include <string.h>

String *string_new (const char *initial)
{
    size_t len = strlen(initial);
    String *new = my_malloc(sizeof(String));

    new->len = len;
    new->capacity = len + 1;
    new->str = my_malloc(len + 1);
    memcpy(new->str, initial, len);
    new->str[len] = '\0';

    return new;
}

void string_print(String *s)
{
    printf("%s\n", s->str);
}

int string_append(String *s, const char *text)
{
    size_t text_len = strlen(text);
    size_t new_len = text_len + s->len;

    if (new_len + 1 > s->capacity)
    {
        size_t new_capacity = new_len + 1;
        
        char *new_str = my_malloc(new_capacity);
        if (!new_str) return -1;

        memcpy(new_str, s->str, s->len);
        my_free((void **)&s->str);

        s->str = new_str;
        s->capacity = new_capacity;
    }
    
    memcpy(s->str + s->len, text, text_len);
    s->str[new_len] = '\0';
    s->len = new_len;

    return APPEND_SUCCESS;
}

int string_get(String *s, size_t index, char *out)
{
    if (index >= s->len)
    {
        fprintf(stderr, "ERROR: Trying to access index out of range!\n");
        return INDEX_RANGE_ERROR;
    }

    *out = s->str[index];
    return STR_GET_SUCCESS;
}

void string_free(String **s)
{
    if (!*s || !s) return;
    my_free((void **)&(*s)->str);
    (*s)->capacity = 0;
    (*s)->len = 0;
    my_free((void **)s);
}
