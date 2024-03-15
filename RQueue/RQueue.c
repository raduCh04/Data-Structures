#include "RList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct RQueue { RList *list; } RQueue;

RQueue *rqueue_init(size_t type_size)
{
    RQueue *queue = (RQueue *)malloc(sizeof(RQueue));
    queue->list = rlist_init(type_size);
    return (queue);
}

void rqueue_destroy(RQueue *queue)
{
    rlist_destroy(queue->list);
    free(queue);
}

void rqueue_enqueue(RQueue *queue, void *data)
{
    rlist_insert_back(queue->list, data);
}

void *rqueue_dequeue(RQueue *queue)
{
    void *data = rlist_get_head(queue->list);
    rlist_remove_front(queue->list);
    return (data);
}

void *rqueue_get_front(const RQueue *queue)
{
    return (rlist_get_head(queue->list));
}

void *rqueue_get_back(const RQueue *queue)
{
    return (rlist_get_tail(queue->list));
}

bool rqueue_is_empty(const RQueue *queue)
{
    return (rlist_is_empty(queue->list));
}

size_t rqueue_get_size(const RQueue *queue)
{
    return (rlist_get_size(queue->list));
}

void rqueue_print(const RQueue *queue, void (*print)(void *data))
{
    rlist_print(queue->list, print);
}

