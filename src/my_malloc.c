#include "my_malloc.h"

block_t *head = NULL;

block_t *request_space(size_t size)
{
    block_t *requested_block = sbrk(0);
    sbrk(sizeof(block_t) + size);
    requested_block->size = size;
    requested_block->available = 0;
    requested_block->magic = 0xDEADBEEF;
    requested_block->next = NULL;
    return requested_block;
}

block_t *find_free(size_t size)
{
    block_t *temp = head;
    while (temp != NULL)
    {
        if (temp->available == 1 && temp->size >= size)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void *my_malloc(size_t size)
{
    if (head != NULL)
    {
        block_t *block = find_free(size);
        if (block)
        {
            block->available = 0;
            return (void *)(block + 1);
        }
    }
    block_t *my_block = request_space(size);
    if (head == NULL)
    {
        head = my_block;
    }
    else
    {
        block_t *current = head;
        while (current->next != NULL) current = current->next;
        current->next = my_block;
    }
    return (void *)(my_block + 1);
}

void my_free(void **ptr)
{
    if (!ptr || !*ptr) return;
    block_t *block = (block_t *)*ptr - 1;
    if (block->magic != 0xDEADBEEF) {
        fprintf(stderr, "ERROR: invalid free\n");
        return;
    }
    if (block->available == 1) {
        fprintf(stderr, "ERROR: double free\n");
        return;
    }
    block->available = 1;
    *ptr = NULL;
}
