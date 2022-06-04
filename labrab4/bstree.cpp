#include "bstree.h"

struct bstree *bstree_create(char* key, int value) {
    struct bstree *node;
    node = (bstree *)(malloc(sizeof(*node)));
    if (node != NULL) {
        strcpy(node->key, key);
        node->value = value;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

void bstree_add(struct bstree *tree, char* key, int value) {
    struct bstree *parent, *node;
    if (tree == NULL) return;
    while (tree != NULL) {
        parent = tree;
        if (strcmp(key, tree->key) < 0)
            tree = tree->left;
        else if (strcmp(key, tree->key) > 0)
            tree = tree->right;
        else
            return;
    }
    node = bstree_create(key, value);
    if (strcmp(key, parent->key) < 0)
        parent->left = node;
    else
        parent->right = node;
}

struct bstree *bstree_lookup(struct bstree *tree, char * key) {
    struct bstree* parent;
    while (tree != NULL) {
        parent = tree;
        if (strcmp(key, tree->key) == 0) {
            return tree;
        } else if (strcmp(key, tree->key) < 0) {
            tree = tree->left;
        } else {
            tree = tree->right;
        }
    }
    return parent;
}

struct bstree *bstree_min(struct bstree *tree) {
    if (tree == NULL)
        return NULL;
    while (tree->left != NULL)
        tree = tree->left;
    return tree;
}

struct bstree *bstree_max(struct bstree *tree) {
    if (tree == NULL)
        return NULL;
    while (tree->right != NULL)
        tree = tree->right;
    return tree;
}
