/**
 * @file RBTree.h
 * @author Radu-D. Chira (github.com/raduCh04)
 * @date 2024-03-15
 */

#ifndef __RBTREE_H__
#define __RBTREE_H__

/**
 * @brief Binary tree structure definition.
 */
struct RBTree;

/**
 * @brief Typedef for BinaryTree structure.
 */
typedef struct RBTree RBTree;

/**
 * @brief Initialize a binary tree.
 *
 * This function initializes a binary tree with the specified type size
 * and comparison functions. It also takes an optional function to free data when
 * the tree is destroyed.
 *
 * @param type_size The size (in bytes) of the data type stored in the tree.
 * @param greater A pointer to a function for determining if one element is greater than another.
 * @param less A pointer to a function for determining if one element is less than another.
 * @param free_data A pointer to a function for freeing allocated data, or NULL if not needed.
 * @return A pointer to the initialized binary tree.
 */
RBTree *rbtree_init(size_t type_size,
    bool (*greater)(const void *, const void *),
    bool (*less)(const void *, const void *),
    void (*free_data)(void *));

/**
 * @brief Destroy a binary tree.
 *
 * This function deallocates the memory occupied by the binary tree,
 * including the memory occupied by its elements.
 *
 * @param tree A pointer to the BinaryTree to be destroyed.
 */
void rbtree_destroy(RBTree *tree);

/**
 * @brief Insert an element into the binary tree.
 *
 * This function inserts a new element into the binary tree.
 *
 * @param tree A pointer to the BinaryTree.
 * @param data A pointer to the data to be inserted into the tree.
 */
void rbtree_insert(RBTree *tree, void *data);

/**
 * @brief Remove an element from the binary tree.
 *
 * This function removes an element from the binary tree based on the provided data.
 *
 * @param tree A pointer to the BinaryTree.
 * @param element A pointer to the data of the element to be removed.
 */
void rbtree_remove(RBTree *tree, void *element);

/**
 * @brief Perform an inorder traversal of the binary tree.
 *
 * This function performs an inorder traversal of the binary tree,
 * calling the provided print function on each element.
 *
 * @param tree A pointer to the BinaryTree.
 * @param print A function pointer to a function that prints an individual element.
 */
void rbtree_inorder(RBTree *tree, void (*print)(void *));

/**
 * @brief Perform a preorder traversal of the binary tree.
 *
 * This function performs a preorder traversal of the binary tree,
 * calling the provided print function on each element.
 *
 * @param tree A pointer to the BinaryTree.
 * @param print A function pointer to a function that prints an individual element.
 */
void rbtree_preorder(RBTree *tree, void (*print)(void *));


/**
 * @brief Perform a postorder traversal of the binary tree.
 *
 * This function performs a postorder traversal of the binary tree,
 * calling the provided print function on each element.
 *
 * @param tree A pointer to the BinaryTree.
 * @param print A function pointer to a function that prints an individual element.
 */
void rbtree_postorder(RBTree *tree, void (*print)(void *));

#endif //__RBTREE_H__