#include "RList.h"

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct RStack { RList *list; } RStack;

RStack *rstack_init(size_t type_size)
{
    RStack *stack = (RStack *)malloc(sizeof(RStack)); //TODO: Check for errors
    stack->list = rlist_init(type_size); 
    return (stack);
}

void rstack_destroy(RStack *stack)
{
    rlist_destroy(stack->list);
    free(stack);
}

void rstack_push(RStack *stack, void *data)
{
    rlist_insert_front(stack->list, data);
}

void *rstack_pop(RStack *stack)
{
    void *data = rlist_get_head(stack->list);
    rlist_remove_front(stack->list);
    return (data);
}

void *rstack_top(const RStack *stack)
{
    return (rlist_get_head(stack->list));
}

size_t rstack_get_size(const RStack *stack)
{
    return (rlist_get_size(stack->list));
}

bool rstack_is_empty(const RStack *stack)
{
    return (rlist_is_empty(stack->list));
}

void rstack_print(const RStack *stack, void (*print)(void *))
{
    rlist_print(stack->list, print);
}
