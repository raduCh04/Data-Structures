#pragma once

#include <stdint.h>
#include <stdbool.h>

struct RList;
typedef struct RList RList;

RList *rlist_init(size_t type_size);
void rlist_destroy(RList *list);

void rlist_insert_back(RList *list, void *data);
void rlist_insert_front(RList *list, void *data);
void rlist_insert_at(RList *list, void *data, size_t index);
void rlist_insert_sorted(RList *list, void *data, int64_t (*compare)(const void *, const void *));

void rlist_clear(RList *list);
void rlist_remove_back(RList *list);
void rlist_remove_front(RList *list);
void rlist_remove(RList *list, void *element);
void rlist_remove_at(RList *list, size_t index);

void *rlist_get_head(const RList *list);
void *rlist_get_tail(const RList *list);
size_t rlist_get_size(const RList *list);
void *rlist_get_medium(const RList *list);
void *rlist_get_element(const RList *list, size_t index);

bool rlist_is_empty(const RList *list);
bool rlist_contains(const RList *list, const void *element);
int64_t rlist_contains_at(const RList *list, const void *element);
bool rlist_is_sorted(const RList *list, int64_t (*compare)(const void *, const void *));

void rlist_reverse(RList *list);

/**
 * @brief For Debugging
 * @param print A printing function for any data type
 */
void rlist_print(const RList *list, void (*print)(void*));