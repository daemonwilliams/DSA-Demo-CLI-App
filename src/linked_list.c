#include "../include/linked_list.h"
#include <stdio.h>

void appendNode(List_Node **head, char input[32]) {
    List_Node *newNode = (List_Node *)malloc(sizeof(List_Node));
    if (!newNode) {
        perror("Memory allocation error.\n");
        exit(1);
    }

    strcpy(newNode->name, input);
    newNode->next = NULL;

    if (!*head) {
        *head = newNode;
        return;
    }

    List_Node *temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAB(List_Node **head, char input[32]) {
    List_Node *newNode = (List_Node *)malloc(sizeof(List_Node));
    if (!newNode) {
        perror("Memory allocation error.\n");
        exit(1);
    }

    strcpy(newNode->name, input);
    newNode->next = NULL;

    // CASE: Insert at head
    if (!*head || strcmp((*head)->name, input) > 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    List_Node *temp = *head;
    while (temp->next && strcmp(temp->next->name, input) < 0) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(List_Node **head, char target[32]) {
    List_Node *p = *head;
    List_Node *prev = NULL;

    if (!p) {
        printf("list is already empty.\n");
        return;
    }

    // CASE: Deleting head node
    if (strcmp(p->name, target) == 0) {
        *head = p->next;
        free(p);
        return;
    }

    while (p && strcmp(p->name, target) != 0) {
        prev = p;
        p = p->next;
    }

    // CASE: Not found
    if (!p) {
        printf("Not Found.\n");
        return;
    }

    prev->next = p->next;
    free(p);
}

void printList(List_Node *head) {
    List_Node *p = head;
    while (p) {
        printf("%s,\n", p->name);
        p = p->next;
    }
}

void freeList(List_Node *head) {
    List_Node *p = head;
    while (p) {
        List_Node *next = p->next;
        free(p);
        p = next;
    }
}
