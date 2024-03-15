#pragma once

struct RBTree;
typedef struct RBTree RBTree;

RBTree *rbtree_init(size_t type_size);
void rbtree_destroy(RBTree *tree);

void rbtree_insert(RBTree *tree, void *data, 
    bool (*greater)(const void *, const void *),
    bool (*less)(const void *, const void *));

void rbtree_inorder(RBTree *tree, void (*print)(void *));
void rbtree_preorder(RBTree *tree, void (*print)(void *));
void rbtree_postorder(RBTree *tree, void (*print)(void *));