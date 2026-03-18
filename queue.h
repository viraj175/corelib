#ifndef QUEUE_H
#define QUEUE_H

#include "my_string.h"
#include "my_malloc.h"

typedef struct queueNode {
    struct queueNode *next;
    String *data;
} queueNode;

typedef struct queue {
    size_t size;
    queueNode *front;
    queueNode *rear;
} Queue;

Queue *queue_new (void);
void enqueue (Queue *q, String *data);
String *dequeue (Queue *q);
String *queue_peek (Queue *q);
int is_queue_empty (Queue *q);
void queue_print (Queue *q);
void queue_free (Queue **q);

#endif // !QUEUE_H
