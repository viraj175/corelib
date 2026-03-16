#ifndef MY_STRING_H
#define MY_STRING_H

#include "my_malloc.h"

#define APPEND_SUCCESS 0
#define APPEND_FAILURE -1
#define STR_GET_SUCCESS 1
#define INDEX_RANGE_ERROR -2

typedef struct string{
    size_t len;
    size_t capacity;
    char *str;
} String;

String *string_new(const char *initial);   // create
void    string_free(String **s);           // destroy
int     string_append(String *s, const char *text);  // safe append
int     string_get(String *s, size_t index, char *out);  // bounds checked get
void    string_print(String *s);           // print

#endif // !MY_STRING_H
