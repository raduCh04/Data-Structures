#pragma once

#include <stdbool.h>

struct RStack;
typedef struct RStack RStack;

RStack *rstack_init(size_t type_size);
void rstack_destroy(RStack *stack);

void rstack_push(RStack *stack, void *data);
void *rstack_pop(RStack *stack);

void *rstack_top(const RStack *stack);
size_t rstack_get_size(const RStack *stack);
bool rstack_is_empty(const RStack *stack);

void rstack_print(const RStack *stack, void (*print)(void *));

