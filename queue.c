#include "queue.h"
#include "my_malloc.h"
#include "my_string.h"
#include <stdio.h>
#include <unistd.h>

Queue
*queue_new ()
{
    Queue *new = my_malloc(sizeof(Queue));
    if (new == NULL)
    {
        fprintf(stderr, "ERROR: memory allocation failed for queue!\n");
        return NULL;
    }

    new->front = new->rear = NULL;
    new->size = 0;

    return new;
}

void
enqueue (Queue *q, String *data)
{
    if (q == NULL || data == NULL)
    {
        fprintf(stderr, "ERROR: invalid queue or data providied!\n");
        return;
    }

    queueNode *node = my_malloc(sizeof(queueNode));
    if (node == NULL)
    {
        fprintf(stderr, "ERROR: memory allocation failed for queueNode!\n");
        return;
    }

    node->data = data;
    node->next = NULL;

    if (q->size == 0)
    {
        q->front = q->rear = node;
    }
    else 
    {
        q->rear->next = node;
        q->rear = node;
    }

    q->size++;
}

String
*dequeue (Queue *q)
{
    if (q == NULL || q->size == 0)
    {
        fprintf(stderr, "ERROR: invalid or empty queue, can't dequeue!\n");
        return NULL;
    }
    
    queueNode *node = q->front;
    String *data = node->data;
    q->front = q->front->next;
    if (q->size == 1) q->rear = NULL;
    my_free((void **)&node);

    q->size--;
    return data;
}

String
*queue_peek (Queue *q)
{
    if (q == NULL || q->size == 0)
    {
        fprintf(stderr, "ERROR: invalid or empty queue, can't peek!\n");
        return NULL;
    }

    return q->front->data;
}

int
is_queue_empty(Queue *q)
{
    if (q == NULL) return 1;
    return q->size == 0;
}

void
queue_print (Queue *q)
{
    if (q == NULL)
    {
        printf("ERROR: [NULL QUEUE]-->\n");
        return;
    }

    printf("front --> ");

    queueNode *temp = q->front;
    while (temp != NULL)
    {
        printf(" [DATA: %s] --> ", temp->data ? temp->data->str : "NULL");
        temp = temp->next;
    }
    printf("rear\n");
}

void
queue_free (Queue **q)
{
    if (q == NULL || *q == NULL)
    {
        fprintf(stderr, "ERROR: invalid queue provided\n");
        return;
    }

    queueNode *temp = (*q)->front;
    while (temp != NULL)
    {
        queueNode *next = temp->next;
        my_free((void **)&temp);
        temp = next;
    }

    my_free((void **)q);
}
