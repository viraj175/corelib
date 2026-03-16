#ifndef MY_MALLOC_H
#define MY_MALLOC_H

#include <unistd.h>
#include <stdio.h>

typedef struct block 
{
    size_t size;
    int available;
    unsigned int magic;
    struct block *next;
} block_t;

// function declarations
block_t *request_space(size_t size);
block_t *find_free(size_t size);
void *my_malloc(size_t size);
void my_free(void **ptr);

#endif
