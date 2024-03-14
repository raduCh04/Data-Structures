#include "RList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct RNode
{
    void *data;
    struct RNode *next;
} RNode;

typedef struct RList
{
    RNode *head;
    RNode *tail;
    size_t size;
    size_t type_size;
} RList;

static RNode *rnode_create(void *data)
{
    RNode *new_node = (RNode *)malloc(sizeof(RNode)); //TODO: Check error
    new_node->data = data;
    new_node->next = NULL;
    return (new_node);
}

RList *rlist_init(size_t type_size)
{
    RList *list = (RList *)malloc(sizeof(RList)); //TODO: Check error
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    list->type_size = type_size;
    return (list);
}

void rlist_destroy(RList *list)
{
    RNode *current = list->head;
    while (current != NULL)
    {
        RNode *next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

void rlist_insert_front(RList *list, void *data)
{
    RNode *new_node = rnode_create(data);
    if (list->head == NULL)
    {
        list->head = new_node;
        list->tail = list->head;
    }
    else
    {
        new_node->next = list->head;
        list->head = new_node;
    }
    list->size++;
}

void rlist_insert_at(RList *list, void *data, size_t index)
{
    if (index >= list->size)
        return;
    else if (index == 0)
        rlist_insert_front(list, data);
    else if (index == list->size - 1)
        rlist_insert_back(list, data);
    else
    {
        RNode *new_node = rnode_create(data);
        RNode *prev = NULL;
        RNode *current = list->head;

        for (size_t i = 0; i < index; i++)
        {
            prev = current;
            current = current->next;
        }

        prev->next = new_node;
        new_node->next = current;
    }

    list->size++;
}

void rlist_insert_sorted(RList *list, void *data, int64_t (*compare)(const void *, const void *))
{
    if (compare(data, list->head->data) >= 0)
        rlist_insert_front(list, data);
    else if (compare(list->tail->data, data) >= 0)
        rlist_insert_back(list, data);
    else
    {
        RNode *new_node = rnode_create(data);
        RNode *prev = list->head;
        RNode *current = list->head->next;

        while (current != NULL)
        {
            if (compare(prev->data, data) >= 0 && compare(data, current->data) >= 0)
            {
                prev->next = new_node;
                new_node->next = current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

}

void rlist_insert_back(RList *list, void *data)
{
    RNode *new_node = rnode_create(data);
    if (list->head == NULL)
    {
        list->head = new_node;
        list->tail = list->head;
    }
    else
    {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
}

void rlist_remove_front(RList *list)
{
    RNode *current = list->head->next;
    free(list->head);
    list->head = current;
    list->size--;
}

void rlist_clear(RList *list)
{
    RNode *current = list->head;
    while (current != NULL)
    {
        RNode *next = current->next;
        free(current);
        current = next;
    }
    list->head = list->tail = NULL;
}

void rlist_remove_back(RList *list)
{
    RNode *prev = NULL;
    RNode *current = list->head;
    while (current->next != NULL)
    {
        prev = current;
        current = current->next;
    }
    free(current);
    prev->next = NULL;
    list->tail = prev;
    list->size--;
}

void rlist_remove(RList *list, void *element)
{
    RNode *prev = NULL;
    RNode *current = list->head;
    while (current != NULL)
    {
        if (memcmp(element, current->data, list->type_size) == 0)
        {
            if (prev == NULL || current == list->head)
                rlist_remove_front(list);
            else if (current == list->tail)
                rlist_remove_back(list);
            else
            {
                prev->next = current->next;
                free(current);
            } return;
        }
        prev = current;
        current = current->next;
    }
    list->size--;
}

void rlist_remove_at(RList *list, size_t index)
{
    if (index >= list->size)
        return;
    else if (index == 0)
        rlist_remove_front(list);
    else if (index == list->size - 1)
        rlist_remove_back(list);
    else
    {
        RNode *prev = NULL;
        RNode *current = list->head;

        for (size_t i = 0; i < index; i++)
        {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        free(current);
    }
}

void *rlist_get_head(const RList *list)
{
    return (list->head->data);
}

void *rlist_get_tail(const RList *list)
{
    return (list->tail->data);
}

size_t rlist_get_size(const RList *list)
{
    return (list->size);
}

void *rlist_get_element(const RList *list, size_t index)
{
    if (index >= list->size)
        return (NULL);
    else if (index == 0)
        return (list->head->data);
    else if (index == list->size - 1)
        return (list->tail->data);

    RNode *current = list->head;
    for (size_t i = 0; i < index; i++)
        current = current->next;

    return (current->data);
}

void *rlist_get_medium(const RList *list)
{
    RNode *slow = NULL;
    RNode *fast = NULL;
    slow = fast = list->head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return (slow->data);
}

bool rlist_is_empty(const RList *list)
{
    return (list->head == NULL);
}

bool rlist_contains(const RList *list, const void *element)
{
    for (RNode *current = list->head; current != NULL; current = current->next)
    {
        if (memcmp(element, current->data, list->type_size) == 0)
            return (true);
    }
    return (false);
}

int64_t rlist_contains_at(const RList *list, const void *element)
{
    int64_t index = 0;
    for (RNode *current = list->head; current != NULL; current = current->next)
    {
        if (memcmp(element, current->data, list->type_size) == 0)
            return (index);
        index++;
    }
    return (-1);
}

bool rlist_is_sorted(const RList *list, int64_t (*compare)(const void *, const void *))
{
    RNode *prev = list->head;
    RNode *current = list->head->next; 

    while (current != NULL)
    {
        if (compare(prev->data, current->data) < 0)
            return (false);
        prev = current;
        current = current->next;
    }

    return (true);
}

void rlist_reverse(RList *list)
{
    RNode *prev = NULL;
    RNode *next = NULL;

    list->tail = list->head;
    while (list->head != NULL)
    {
        next = list->head->next;
        list->head->next = prev;
        prev = list->head;
        list->head = next;
    }
    list->head = prev;
}

void rlist_print(const RList *list, void (*print)(void*))
{
    RNode *current = list->head;
    while (current != NULL)
    {
        print(current->data);
        current = current->next;
    }
}