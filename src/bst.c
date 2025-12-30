#include "../include/bst.h"
#include <stdio.h>
#include <stdlib.h>

BST_Node *bst_insert(BST_Node *root, int key) {
    if (root == NULL) {
        BST_Node *newNode = (BST_Node *)malloc(sizeof(BST_Node));
        newNode->key = key;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (key < root->key)
        root->left = bst_insert(root->left, key);
    else if (key > root->key)
        root->right = bst_insert(root->right, key);

    return root;
}

BST_Node *bst_find_min(BST_Node *root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

BST_Node *bst_delete(BST_Node *root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = bst_delete(root->left, key);
    else if (key > root->key)
        root->right = bst_delete(root->right, key);
    else {
        // CASE: One or no child
        if (root->left == NULL) {
            BST_Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            BST_Node *temp = root->left;
            free(root);
            return temp;
        }

        // CASE: Two children
        BST_Node *temp = bst_find_min(root->right);
        root->key = temp->key;
        root->right = bst_delete(root->right, temp->key);
    }
    return root;
}

int bst_search(BST_Node *root, int key) {
    if (root == NULL)
        return 0;
    if (root->key == key)
        return 1;
    if (key < root->key)
        return bst_search(root->left, key);
    return bst_search(root->right, key);
}

void bst_inorder(BST_Node *root) {
    if (root != NULL) {
        bst_inorder(root->left);
        printf("%d ", root->key);
        bst_inorder(root->right);
    }
}

void bst_preorder(BST_Node *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        bst_preorder(root->left);
        bst_preorder(root->right);
    }
}

void bst_postorder(BST_Node *root) {
    if (root != NULL) {
        bst_postorder(root->left);
        bst_postorder(root->right);
        printf("%d ", root->key);
    }
}

void bst_free(BST_Node *root) {
    if (root == NULL)
        return;
    bst_free(root->left);
    bst_free(root->right);
    free(root);
}
