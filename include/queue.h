#pragma once

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue {
    List_Node *head;
    List_Node *tail;
} Queue;

void enQueue(Queue *q, char input[32]);

void deQueue(Queue *q);

void peek_queue(Queue *q);
