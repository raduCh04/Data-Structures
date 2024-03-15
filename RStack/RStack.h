/**
 * @file RStack.h
 * @author Radu-D. Chira (github.com/raduCh04)
 * @date 2024-03-15
 */

#ifndef __RSTACK_H__
#define __RSTACK_H__

#include <stdbool.h>

struct RStack;
typedef struct RStack RStack;

/**
 * @brief Initialize a resizable stack for storing elements of a specified data type.
 *
 * This function initializes a resizable stack to store elements of a specified data type.
 * It requires the size of the data type.
 *
 * @param type_size The size (in bytes) of the data type.
 * @return A pointer to the initialized stack.
 */
RStack *rstack_init(size_t type_size);

/**
 * @brief Destroy a resizable stack.
 *
 * This function deallocates the memory occupied by the resizable stack (RStack),
 * including the memory occupied by its elements.
 *
 * @param stack A pointer to the RStack to be destroyed.
 */
void rstack_destroy(RStack *stack);

/**
 * @brief Push an element onto the top of the resizable stack.
 *
 * This function pushes a new element onto the top of the resizable stack (RStack).
 *
 * @param stack A pointer to the RStack.
 * @param data A pointer to the data to be pushed onto the stack.
 */
void rstack_push(RStack *stack, void *data);

/**
 * @brief Pop the top element from the resizable stack.
 *
 * This function removes and returns the top element from the resizable stack (RStack).
 *
 * @param stack A pointer to the RStack.
 * @return A pointer to the data popped from the stack.
 */
void *rstack_pop(RStack *stack);

/**
 * @brief Get the top element of the resizable stack without removing it.
 *
 * This function returns a pointer to the top element of the resizable stack (RStack)
 * without removing it from the stack.
 *
 * @param stack A pointer to the RStack.
 * @return A pointer to the top element of the stack.
 */
void *rstack_top(const RStack *stack);

/**
 * @brief Get the current size of the resizable stack.
 *
 * This function returns the current number of elements in the resizable stack (RStack).
 *
 * @param stack A pointer to the RStack.
 * @return The number of elements in the stack.
 */
size_t rstack_get_size(const RStack *stack);

/**
 * @brief Check if the resizable stack is empty.
 *
 * This function checks if the resizable stack (RStack) is empty.
 *
 * @param stack A pointer to the RStack.
 * @return true if the stack is empty, false otherwise.
 */
bool rstack_is_empty(const RStack *stack);

/**
 * @brief Print the contents of the resizable stack.
 *
 * This function prints the contents of the resizable stack (RStack) using the
 * provided printing function.
 *
 * @param stack A pointer to the RStack.
 * @param print A function pointer to a function that prints an individual element.
 */
void rstack_print(const RStack *stack, void (*print)(void *));

#endif /* __RSTACK_H__ */
