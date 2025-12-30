#pragma once

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    List_Node *top;
} Stack;

void push(Stack *s, char input[32]);

void pop(Stack *s);

void peek_stack(Stack *s);
