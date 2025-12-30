#pragma once

typedef struct BST_Node {
    int key;
    struct BST_Node *left, *right;
} BST_Node;

BST_Node *bst_insert(BST_Node *root, int key);
BST_Node *bst_delete(BST_Node *root, int key);
int bst_search(BST_Node *root, int key);
BST_Node *bst_find_min(BST_Node *root);

void bst_inorder(BST_Node *root);
void bst_preorder(BST_Node *root);
void bst_postorder(BST_Node *root);

void bst_free(BST_Node *root);
