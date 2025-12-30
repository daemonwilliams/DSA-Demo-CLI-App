#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List_Node {
    char name[32];
    struct List_Node *next;
} List_Node;

void appendNode(List_Node **head, char input[32]);

void insertAB(List_Node **head, char input[32]);

void deleteNode(List_Node **head, char target[32]);

void printList(List_Node *head);

void freeList(List_Node *head);