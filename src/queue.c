#include "../include/queue.h"
#include "../include/linked_list.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void enQueue(Queue *q, char input[32]) {
    List_Node *newNode = (List_Node *)malloc(sizeof(List_Node));
    if (!newNode) {
        perror("Failed to allocate memory");
        exit(1);
    }
    strcpy(newNode->name, input);
    newNode->next = NULL;

    // CASE: Empty Queue
    if (!q->tail) {
        q->head = q->tail = newNode;
        return;
    }

    q->tail->next = newNode;
    q->tail = newNode;
}

void deQueue(Queue *q) {
    if (!q->head) {
        printf("Queue is empty.\n");
        return;
    }

    List_Node *temp = q->head;

    // CASE: Only one item left in queue
    if (!(q->head->next)) {
        printf("Dequeued %s, queue is now empty.\n", q->head->name);
        free(temp);
        q->head = NULL;
        q->tail = NULL;
        return;
    }

    printf("Dequeued %s.\n", q->head->name);
    q->head = q->head->next;
    free(temp);
}

void peek_queue(Queue *q) {
    if (!q->head) {
        printf("Queue is empty.\n");
        return;
    }
    printf("%s\n", q->head->name);
}
