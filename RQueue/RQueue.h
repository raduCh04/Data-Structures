#pragma once

#include <stdbool.h>

struct RQueue;
typedef struct RQueue RQueue;

RQueue *rqueue_init(size_t type_size);
void rqueue_destroy(RQueue *queue);

void rqueue_enqueue(RQueue *queue, void *data);
void *rqueue_dequeue(RQueue *queue);

void *rqueue_get_front(const RQueue *queue);
void *rqueue_get_back(const RQueue *queue);
bool rqueue_is_empty(const RQueue *queue);
size_t rqueue_get_size(const RQueue *queue);

void rqueue_print(const RQueue *queue, void (*print)(void *data));