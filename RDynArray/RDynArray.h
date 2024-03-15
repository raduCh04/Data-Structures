/**
 * @file RDynArray.h
 * @author Radu-D. Chira (github.com/raduCh04)
 * @date 2024-03-15
 */

#ifndef __RDARRAY_H__
#define __RDARRAY_H__

#include <stdint.h>

struct RDynArray;
typedef struct RDynArray RDynArray;

/**
 * @brief Initialize a resizable dynamic array.
 * 
 * This function initializes a resizable dynamic array (RDynArray) with the given capacity
 * and element size. The array will automatically resize itself when needed.
 * 
 * @param capacity The initial capacity of the array.
 * @param type_size The size of each element in the array.
 * @return A pointer to the newly initialized RDynArray.
 */
RDynArray *rdarray_init(size_t capacity, size_t type_size);

/**
 * @brief Destroy a resizable dynamic array.
 * 
 * This function deallocates the memory occupied by the resizable dynamic array (RDynArray),
 * including the memory occupied by its elements.
 * 
 * @param array A pointer to the RDynArray to be destroyed.
 */
void rdarray_destroy(RDynArray *array);

/**
 * @brief Add an element to the end of the resizable dynamic array.
 * 
 * This function adds a new element to the end of the resizable dynamic array (RDynArray).
 * 
 * @param array A pointer to the RDynArray.
 * @param data A pointer to the data to be added to the array.
 */
void rdarray_push_back(RDynArray *array, void *data);

/**
 * @brief Remove the last element from the resizable dynamic array.
 * 
 * This function removes the last element from the resizable dynamic array (RDynArray).
 * 
 * @param array A pointer to the RDynArray.
 */
void rdarray_pop_back(RDynArray *array);

/**
 * @brief Check if the resizable dynamic array is empty.
 * 
 * This function checks if the resizable dynamic array (RDynArray) is empty.
 * 
 * @param array A pointer to the RDynArray.
 * @return true if the array is empty, false otherwise.
 */
bool rdarray_is_empty(const RDynArray *array);

/**
 * @brief Get the current size of the resizable dynamic array.
 * 
 * This function returns the current number of elements in the resizable dynamic array (RDynArray).
 * 
 * @param array A pointer to the RDynArray.
 * @return The number of elements in the array.
 */
size_t rdarray_get_size(const RDynArray *array);

/**
 * @brief Get the current capacity of the resizable dynamic array.
 * 
 * This function returns the current capacity of the resizable dynamic array (RDynArray).
 * 
 * @param array A pointer to the RDynArray.
 * @return The current capacity of the array.
 */
size_t rdarray_get_capacity(const RDynArray *array);

/**
 * @brief Get an element from the resizable dynamic array.
 * 
 * This function returns a pointer to the element at the specified index in the resizable
 * dynamic array (RDynArray).
 * 
 * @param array A pointer to the RDynArray.
 * @param index The index of the element to retrieve.
 * @return A pointer to the element at the specified index.
 */
void *rdarray_get(const RDynArray *array, size_t index);

/**
 * @brief Print the contents of the resizable dynamic array.
 * 
 * This function prints the contents of the resizable dynamic array (RDynArray) using the
 * provided printing function.
 * 
 * @param array A pointer to the RDynArray.
 * @param print A function pointer to a function that prints an individual element.
 */
void rdarray_print(const RDynArray *array, void (*print)(void *));

#endif //__RDARRAY_H__