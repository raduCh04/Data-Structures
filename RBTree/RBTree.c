#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include "RBTree.h"

typedef struct RNode
{
    void *data;
    struct RNode *left;
    struct RNode *right;
} RNode;

typedef struct RBTree
{
    RNode *root;
    size_t size;
    size_t type_size;
} RBTree;

static RNode *rnode_init(void *data)
{
    RNode *node = (RNode *)malloc(sizeof(RNode));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

RBTree *rbtree_init(size_t type_size)
{
    RBTree *tree = (RBTree *)malloc(sizeof(RBTree));
    tree->type_size = type_size;
    tree->size = 0;
    tree->root = NULL;
    return (tree);
}

void rbtree_destroy(RBTree *tree)
{
    free(tree);
}

static void rbtree_insert_node(RNode **root, void *data, 
    bool (*greater)(const void *, const void *),
    bool (*less)(const void *, const void *))
{
    RNode *node = rnode_init(data);
    if (*root == NULL)
        *root = node;
    else if (*root != NULL && less(data, (*root)->data))
        rbtree_insert_node(&(*root)->left, data, greater, less);
    else if (root != NULL && greater(data, (*root)->data))
        rbtree_insert_node(&(*root)->right, data, greater, less);
}

void rbtree_insert(RBTree *tree, void *data, 
    bool (*greater)(const void *, const void *),
    bool (*less)(const void *, const void *))
{
    rbtree_insert_node(&tree->root, data, greater, less);
}

static void rbtree_inorder_root(RNode *root, void (*print)(void *))
{
    if (root == NULL)
        return;
    rbtree_inorder_root(root->left, print);
    print(root->data);
    rbtree_inorder_root(root->right, print);
}

void rbtree_inorder(RBTree *tree, void (*print)(void *))
{
    rbtree_inorder_root(tree->root, print);
}

static void rbtree_preorder_root(RNode *root, void (*print)(void *))
{
    if (root == NULL)
        return;
    print(root->data);
    rbtree_preorder_root(root->left, print);
    rbtree_preorder_root(root->right, print);
}

void rbtree_preorder(RBTree *tree, void (*print)(void *))
{
    rbtree_preorder_root(tree->root, print);
}

static void rbtree_postorder_root(RNode *root, void (*print)(void *))
{
    if (root == NULL)
        return;
    rbtree_postorder_root(root->left, print);
    rbtree_postorder_root(root->right, print);
    print(root->data);
}

void rbtree_postorder(RBTree *tree, void (*print)(void *))
{
    rbtree_postorder_root(tree->root, print);
}
