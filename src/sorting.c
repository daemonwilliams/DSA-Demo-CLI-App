#include "../include/sorting.h"
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void randomize_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }
}

int partition(int a[], int l, int r) {
    int pivot = a[r];
    int i = (l - 1);

    for (int j = l; j <= r - 1; j++) {
        if (a[j] < pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[r]);
    return (i + 1);
}

void quick_sort(int a[], int l, int r) {
    if (l < r) {
        int pi = partition(a, l, r);
        quick_sort(a, l, pi - 1);
        quick_sort(a, pi + 1, r);
    }
}

List_Node *merge(List_Node *l, List_Node *r) {
    List_Node *result = NULL;

    if (l == NULL)
        return r;
    else if (r == NULL)
        return l;

    if (strcmp(l->name, r->name) <= 0) {
        result = l;
        result->next = merge(l->next, r);
    } else {
        result = r;
        result->next = merge(l, r->next);
    }
    return result;
}

void divide(List_Node *head, List_Node **l, List_Node **r) {
    List_Node *fast;
    List_Node *slow;

    if (head == NULL || head->next == NULL) {
        *l = head;
        *r = NULL;
    } else {
        slow = head;
        fast = head->next;

        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *l = head;
        *r = slow->next;
        slow->next = NULL;
    }
}

void merge_sort(List_Node **head) {
    List_Node *h = *head;
    List_Node *l;
    List_Node *r;

    if ((h == NULL) || (h->next == NULL)) {
        return;
    }

    divide(h, &l, &r);

    merge_sort(&l);
    merge_sort(&r);

    *head = merge(l, r);
}
