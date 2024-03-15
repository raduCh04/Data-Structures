/**
 * @file RList.h
 * @author Radu-D. Chira (github.com/raduCh04)
 * @date 2024-03-15 
 */

#ifndef __RLIST_H__
#define __RLIST_H__

#include <stdint.h>
#include <stdbool.h>

struct RList;
typedef struct RList RList;

/**
 * @brief Initialize a list for storing elements of a specified data type.
 *
 * This function initializes a list to store elements of a specified data type.
 * It requires the size of the data type, a comparison function, and an optional
 * function to free data when the list is destroyed.
 *
 * @param type_size The size (in bytes) of the data type.
 * @param compare A pointer to a function for comparing two elements of the desired data type.
 * @param free_data A pointer to a function for freeing allocated data, or NULL if not needed.
 * @return A pointer to the initialized list.
 */
RList *rlist_init(size_t type_size, 
    int64_t (*compare)(void *, void *),
    void (*free_data)(void *));

/**
 * @brief Destroy the list and deallocate all associated memory.
 *
 * This function destroys the list and deallocates all memory associated with it.
 *
 * @param list A pointer to the list to be destroyed.
 */
void rlist_destroy(RList *list);

/**
 * @brief Insert an element at the end of the list.
 *
 * This function inserts an element at the end of the list.
 *
 * @param list A pointer to the list.
 * @param data A pointer to the data to be inserted.
 */
void rlist_insert_back(RList *list, void *data);

/**
 * @brief Insert an element at the beginning of the list.
 *
 * This function inserts an element at the beginning of the list.
 *
 * @param list A pointer to the list.
 * @param data A pointer to the data to be inserted.
 */
void rlist_insert_front(RList *list, void *data);

/**
 * @brief Insert an element at the specified index.
 *
 * This function inserts an element at the specified index in the list.
 *
 * @param list A pointer to the list.
 * @param data A pointer to the data to be inserted.
 * @param index The position at which to insert the element.
 */
void rlist_insert_at(RList *list, void *data, size_t index);

/**
 * @brief Insert an element into the list in a sorted order.
 *
 * This function inserts an element into the list in a sorted order, based on
 * the comparison function provided during initialization.
 *
 * @param list A pointer to the list.
 * @param data A pointer to the data to be inserted.
 */
void rlist_insert_sorted(RList *list, void *data);

/**
 * @brief Clear all elements from the list.
 *
 * This function removes all elements from the list.
 *
 * @param list A pointer to the list.
 */
void rlist_clear(RList *list);

/**
 * @brief Remove the element at the end of the list.
 *
 * This function removes the element at the end of the list.
 *
 * @param list A pointer to the list.
 */
void rlist_remove_back(RList *list);


/**
 * @brief Remove the element at the beginning of the list.
 *
 * This function removes the element at the beginning of the list.
 *
 * @param list A pointer to the list.
 */
void rlist_remove_front(RList *list);


/**
 * @brief Remove a specific element from the list.
 *
 * This function removes a specific element from the list.
 *
 * @param list A pointer to the list.
 * @param element A pointer to the element to be removed.
 */
void rlist_remove(RList *list, void *element);


/**
 * @brief Remove the element at the specified index.
 *
 * This function removes the element at the specified index from the list.
 *
 * @param list A pointer to the list.
 * @param index The index of the element to be removed.
 */
void rlist_remove_at(RList *list, size_t index);

/**
 * @brief Reverse the order of elements in the list.
 *
 * This function reverses the order of elements in the list.
 *
 * @param list A pointer to the list.
 */
void rlist_reverse(RList *list);

/**
 * @brief Get the first element of the list.
 *
 * This function returns a pointer to the first element of the list.
 *
 * @param list A pointer to the list.
 * @return A pointer to the first element of the list.
 */
void *rlist_get_head(const RList *list);

/**
 * @brief Get the last element of the list.
 *
 * This function returns a pointer to the last element of the list.
 *
 * @param list A pointer to the list.
 * @return A pointer to the last element of the list.
 */
void *rlist_get_tail(const RList *list);

/**
 * @brief Get the number of elements in the list.
 *
 * This function returns the number of elements currently stored in the list.
 *
 * @param list A pointer to the list.
 * @return The number of elements in the list.
 */
size_t rlist_get_size(const RList *list);

/**
 * @brief Get the median element of the list.
 *
 * This function returns a pointer to the median element of the list.
 *
 * @param list A pointer to the list.
 * @return A pointer to the median element of the list.
 */
void *rlist_get_medium(const RList *list);

/**
 * @brief Get the element at the specified index.
 *
 * This function returns a pointer to the element at the specified index.
 *
 * @param list A pointer to the list.
 * @param index The index of the element to retrieve.
 * @return A pointer to the element at the specified index.
 */
void *rlist_get_element(const RList *list, size_t index);

/**
 * @brief Check if the list is empty.
 *
 * This function checks if the list is empty.
 *
 * @param list A pointer to the list.
 * @return true if the list is empty, otherwise false.
 */
bool rlist_is_empty(const RList *list);

/**
 * @brief Check if the list contains a specific element.
 *
 * This function checks if the list contains a specific element.
 *
 * @param list A pointer to the list.
 * @param element A pointer to the element to be checked.
 * @return true if the list contains the element, otherwise false.
 */
bool rlist_contains(const RList *list, const void *element);

/**
 * @brief Check if the list contains a specific element at a given index.
 *
 * This function checks if the list contains a specific element at a given index.
 *
 * @param list A pointer to the list.
 * @param element A pointer to the element to be checked.
 * @return The index of the element if found, otherwise -1.
 */
int64_t rlist_contains_at(const RList *list, const void *element);

/**
 * @brief Check if the list is sorted.
 *
 * This function checks if the list is sorted based on the comparison function provided
 * during initialization.
 *
 * @param list A pointer to the list.
 * @return true if the list is sorted, otherwise false.
 */
bool rlist_is_sorted(const RList *list);

/**
 * @brief Print the elements of the list for debugging purposes.
 *
 * This function prints the elements of the list for debugging purposes.
 *
 * @param list A pointer to the list.
 * @param print A function pointer for printing elements of any data type.
 */

/**
 * @brief For Debugging
 * @param print A printing function for any data type
 */
void rlist_print(const RList *list, void (*print)(void*));

#endif //__RLIST_H__