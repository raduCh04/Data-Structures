/**
 * @file RQueue.h
 * @author Radu-D. Chira (github.com/raduCh04)
 * @date 2024-03-15
 */
#ifndef __RQUEUE_H__
#define __RQUEUE_H__

#include <stdbool.h>

/**
 * @struct RQueue
 * @brief Structure representing a resizable queue.
 * 
 * This structure represents a resizable queue (RQueue) which holds elements of variable size.
 * The internal implementation is hidden from the user.
 */
struct RQueue;

typedef struct RQueue RQueue; /** Typedef for RQueue structure. */

/**
 * @brief Initialize a resizable queue.
 * 
 * @param type_size The size of each element in the queue.
 * @return A pointer to the newly initialized RQueue.
 */
RQueue *rqueue_init(size_t type_size);

/**
 * @brief Destroy a resizable queue.
 * 
 * Deallocates the memory occupied by the resizable queue (RQueue).
 * 
 * @param queue A pointer to the RQueue to be destroyed.
 */
void rqueue_destroy(RQueue *queue);

/**
 * @brief Add an element to the back of the queue.
 * 
 * @param queue A pointer to the RQueue.
 * @param data A pointer to the data to be added to the queue.
 */
void rqueue_enqueue(RQueue *queue, void *data);

/**
 * @brief Remove and return the front element from the queue.
 * 
 * @param queue A pointer to the RQueue.
 * @return A pointer to the data at the front of the queue.
 */
void *rqueue_dequeue(RQueue *queue);

/**
 * @brief Get the front element of the queue without removing it.
 * 
 * @param queue A pointer to the RQueue.
 * @return A pointer to the data at the front of the queue.
 */
void *rqueue_get_front(const RQueue *queue);

/**
 * @brief Get the back element of the queue without removing it.
 * 
 * @param queue A pointer to the RQueue.
 * @return A pointer to the data at the back of the queue.
 */
void *rqueue_get_back(const RQueue *queue);

/**
 * @brief Check if the queue is empty.
 * 
 * @param queue A pointer to the RQueue.
 * @return true if the queue is empty, false otherwise.
 */
bool rqueue_is_empty(const RQueue *queue);

/**
 * @brief Get the current size of the queue.
 * 
 * @param queue A pointer to the RQueue.
 * @return The number of elements in the queue.
 */
size_t rqueue_get_size(const RQueue *queue);

/**
 * @brief Print the contents of the queue.
 * 
 * @param queue A pointer to the RQueue.
 * @param print A function pointer to a function that prints an individual element.
 */
void rqueue_print(const RQueue *queue, void (*print)(void *data));

#endif //__RQUEUE_H__