
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "RDynArray.h"

typedef struct RDynArray
{
    void *data;
    size_t capacity;
    size_t size;
    size_t type_size;
} RDynArray;

RDynArray *rdarray_init(size_t capacity, size_t type_size)
{
    RDynArray *array = (RDynArray *)malloc(sizeof(RDynArray)); //TODO: Check for error
    array->data = malloc(capacity * type_size); //TODO: Check for error
    memset(array->data, 0, capacity * type_size);
    array->capacity = capacity;
    array->size = 0;
    array->type_size = type_size;
    return (array);
}

void rdarray_destroy(RDynArray *array)
{
    if (array != NULL)
    {
        free(array->data);
        free(array);
    }
}

void rdarray_push_back(RDynArray *array, void *data)
{
    if (array->size >= array->capacity)
    {
        void *temp = realloc(array->data, array->capacity * 2 * array->type_size);
        if (temp != NULL)
        {
            array->data = temp;
            array->capacity *= 2;
        }
    }
    memcpy((char *)array->data + array->size * array->type_size, data, array->type_size); //TODO: Check for error
    array->size++;
}

void rdarray_pop_back(RDynArray *array)
{
    memset((char *)array->data + array->size * array->type_size, 0, array->type_size);
    array->size--;
}

void *rdarray_get(const RDynArray *array, size_t index)
{
    if (index >= array->size)
        return NULL;
    return ((char *)array->data + index * array->type_size);
}

bool rdarray_is_empty(const RDynArray *array)
{
    return (array->size == 0);
}

size_t rdarray_get_size(const RDynArray *array)
{
    return (array->size);
}

size_t rdarray_get_capacity(const RDynArray *array)
{
    return (array->capacity);
}

void rdarray_print(const RDynArray *array, void (*print)(void *))
{
    for (size_t i = 0; i < rdarray_get_size(array); i++)
    {
        print(rdarray_get(array, i));
    }
}