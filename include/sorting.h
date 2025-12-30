#pragma once

#include "linked_list.h"
#include <stdio.h>
#include <string.h>

void randomize_array(int a[], int n);

void swap(int *a, int *b);

int partition(int a[], int l, int r);

void quick_sort(int a[], int l, int r);

List_Node* merge(List_Node *l, List_Node *r);

void divide(List_Node *head, List_Node **l, List_Node **r);

void merge_sort(List_Node **head);