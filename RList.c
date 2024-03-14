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
    list->type_size = type_size;
    return (list);
}

void rlist_destroy(RList *list)
{
    RNode *temp = list->head;
    while (temp != NULL)
    {
        RNode *next = temp->next;
        free(temp);
        temp = next;
    }
    free(list);
}

void rlist_prepend(RList *list, void *data)
{
    RNode *new_node = rnode_create(data);
    if (list->head == NULL)
        list->head = new_node;
    else
    {
        new_node->next = list->head;
        list->head = new_node;
    }
}

void rlist_append(RList *list, void *data)
{
    RNode *new_node = rnode_create(data);
    if (list->head == NULL)
        list->head = new_node;
    else
    {
        RNode *temp = NULL;
        for (temp = list->head; temp->next != NULL; temp = temp->next);
        temp->next = new_node;
    }
}

void rlist_pop(RList *list)
{
    RNode *temp = list->head->next;
    free(list->head);
    list->head = temp;
}

void rlist_remove_last(RList *list)
{
    RNode *temp_second = NULL;
    RNode *temp = list->head;
    while (temp->next != NULL)
    {
        temp_second = temp;
        temp = temp->next;
    }
    free(temp);
    temp_second->next = NULL;
}

void rlist_remove(RList *list, void *element)
{
    RNode *temp_second = NULL;
    RNode *temp = list->head;
    while (temp != NULL)
    {
        if (memcmp(element, temp->data, list->type_size) == 0)
        {
            if (temp_second == NULL || temp == list->head)
            {
                rlist_pop(list);
                return;
            }
            temp_second->next = temp->next;
            free(temp);
            return;
        }
        temp_second = temp;
        temp = temp->next;
    }
}

void *rlist_get(const RList *list, size_t index)
{
    RNode *temp = list->head;
    for (size_t i = 0; i < index; i++)
    {
        if (temp == NULL)
        {   //TODO: Print error
            return NULL;
        }
        temp = temp->next;
    }
    return (temp->data);
}

bool rlist_contains(const RList *list, const void *element)
{
    for (RNode *temp = list->head; temp != NULL; temp = temp->next)
    {
        if (memcmp(element, temp->data, list->type_size) == 0)
        {
            return (true);
        }
    }
    return (false);
}

int64_t rlist_contains_at(const RList *list, const void *element)
{
    int64_t index = 0;
    for (RNode *temp = list->head; temp != NULL; temp = temp->next)
    {
        if (memcmp(element, temp->data, list->type_size) == 0)
        {
            return (index);
        }
        index++;
    }
    return (-1);
}

void rlist_print(const RList *list, void (*print)(void*))
{
    RNode *temp = list->head;
    while (temp != NULL)
    {
        print(temp->data);
        temp = temp->next;
    }
}