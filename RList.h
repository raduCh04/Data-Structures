#pragma once

#include <stdint.h>
#include <stdbool.h>

struct RList;
typedef struct RList RList;

RList *rlist_init(size_t type_size);
void rlist_destroy(RList *list);

void rlist_prepend(RList *list, void *data);
void rlist_append(RList *list, void *data);

void rlist_pop(RList *list);
void rlist_remove_last(RList *list);
void rlist_remove(RList *list, void *element);

void *rlist_get(const RList *list, size_t index);
bool rlist_contains(const RList *list, const void *element);
int64_t rlist_contains_at(const RList *list, const void *element);

void rlist_print(const RList *list, void (*print)(void*));