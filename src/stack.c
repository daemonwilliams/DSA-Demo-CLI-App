#include "../include/stack.h"
#include "../include/linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(Stack *s, char input[32]) {
    List_Node *newNode = (List_Node *)malloc(sizeof(List_Node));
    if (!newNode) {
        perror("Failed to allocate memory");
        exit(1);
    }

    strcpy(newNode->name, input);
    newNode->next = NULL;

    List_Node *temp = s->top;
    s->top = newNode;
    newNode->next = temp;
    printf("%s was pushed to the stack.\n", input);
}

void pop(Stack *s) {
    if (!s->top) {
        printf("Stack is empty.\n");
        return;
    }
    List_Node *temp = s->top;
    printf("%s was popped from the stack.\n", temp->name);
    s->top = s->top->next;
    free(temp);
}

void peek_stack(Stack *s) {
    if (!s->top) {
        printf("Stack is empty.\n");
        return;
    }
    printf("%s\n", s->top->name);
}
