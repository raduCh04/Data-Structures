#pragma once

#include <stdint.h>

struct RDynArray;
typedef struct RDynArray RDynArray;

RDynArray *rdarray_init(size_t capacity, size_t type_size);
void rdarray_destroy(RDynArray *array);
void rdarray_push_back(RDynArray *array, void *data);
void rdarray_pop_back(RDynArray *array);

bool rdarray_is_empty(const RDynArray *array);
size_t rdarray_get_size(const RDynArray *array);
size_t rdarray_get_capacity(const RDynArray *array);
void *rdarray_get(const RDynArray *array, size_t index);

void rdarray_print(const RDynArray *array, void (*print)(void *));
