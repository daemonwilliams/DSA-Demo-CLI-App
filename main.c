#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "include/bst.h"
#include "include/hash.h"
#include "include/linked_list.h"
#include "include/queue.h"
#include "include/sorting.h"
#include "include/stack.h"

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void demo_array() {
    char answer[64];
    printf("\nWhat is the Time Complexity of accessing an element in an Array by index? (in Big-O "
           "Notation): ");
    scanf("%63s", answer);
    if (strcasecmp(answer, "O(1)") == 0) {
        printf("Correct! Arrays provide constant time access.\n");
    } else {
        printf("Incorrect. It is O(1) because of sequential memory.\n");
    }

    int choice;
    do {
        printf("\n--- Array Demo ---\n");
        printf("1. Quick Sort Random Array\n2. Back\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int n;
            printf("Enter array size: ");
            scanf("%d", &n);
            int *arr = malloc(sizeof(int) * n);
            if (arr) {
                randomize_array(arr, n);
                printf("Original: ");
                for (int i = 0; i < n; i++)
                    printf("%d ", arr[i]);
                printf("\n");

                quick_sort(arr, 0, n - 1);

                printf("Sorted:   ");
                for (int i = 0; i < n; i++)
                    printf("%d ", arr[i]);
                printf("\n");
                free(arr);
            }
        }
    } while (choice != 2);
}

void demo_linked_list() {
    char answer[64];
    printf("\nTo sort a Linked List, should we use Merge Sort or Quick Sort?: ");
    scanf("%63s", answer);
    if (strcasecmp(answer, "Merge") == 0 || strcasecmp(answer, "Merge Sort") == 0) {
        printf("Correct! Merge Sort doesn't require random access.\n");
    } else {
        printf("Incorrect. The answer is Merge Sort.\n");
    }

    List_Node *head = NULL;
    int choice;
    char buffer[32];

    do {
        printf("\n--- Linked List Demo ---\n");
        printf("1. Append Node\n2. Insert Alphabetically\n3. Delete Node\n4. Sort List (Merge "
               "Sort)\n5. Print List\n6. Back\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%31s", buffer);
                appendNode(&head, buffer);
                break;
            case 2:
                printf("Enter Name: ");
                scanf("%31s", buffer);
                insertAB(&head, buffer);
                break;
            case 3:
                printf("Enter Name to Delete: ");
                scanf("%31s", buffer);
                deleteNode(&head, buffer);
                break;
            case 4:
                printf("Sorting list...\n");
                merge_sort(&head);
                printf("List sorted!\n");
                printList(head);
                break;
            case 5:
                printList(head);
                break;
            case 6:
                break;
        }
    } while (choice != 6);
    freeList(head);
}

void demo_stack() {
    char answer[64];
    printf("\nDoes Stack use LIFO or FIFO: ");
    scanf("%63s", answer);
    if (strcasecmp(answer, "FIFO") == 0) {
        printf("Correct!\n");
    } else {
        printf("Incorrect. It is a FIFO (First-In-First-Out).\n");
    }

    Stack s = {NULL};
    int choice;
    char buffer[32];

    do {
        printf("\n--- Stack Demo ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Print Stack\n5. Back\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Value: ");
                scanf("%31s", buffer);
                push(&s, buffer);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                peek_stack(&s);
                break;
            case 4:
                printf("Stack Top -> ");
                printList(s.top);
                break;
            case 5:
                break;
        }
    } while (choice != 5);
    freeList(s.top);
}

void demo_queue() {
    char answer[64];
    printf("\nWhich data structure is used for Breadth-First Search?");
    scanf("%63s", answer);
    if (strcasecmp(answer, "Queue") == 0) {
        printf("Correct!\n");
    } else {
        printf("Incorrect It is a Queue.\n");
    }

    Queue q = {NULL, NULL};
    int choice;
    char buffer[32];

    do {
        printf("\n--- Queue Demo ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Print Queue\n5. Back\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Value: ");
                scanf("%31s", buffer);
                enQueue(&q, buffer);
                break;
            case 2:
                deQueue(&q);
                break;
            case 3:
                peek_queue(&q);
                break;
            case 4:
                printf("Queue Front -> ");
                printList(q.head); // Reusing Linked List print
                break;
            case 5:
                break;
        }
    } while (choice != 5);
    freeList(q.head);
}

void demo_hashtable() {
    char answer[64];
    printf("\nWhat is the average time complexity of a Hash Table lookup? (Big-O Notaion) ");
    scanf("%63s", answer);
    if (strcasecmp(answer, "O(1)") == 0) {
        printf("Correct! It's constant time on average.\n");
    } else {
        printf("Incorrect. Ideally, it is O(1).\n");
    }

    int size;
    printf("\nEnter Hash Table Size: ");
    scanf("%d", &size);
    Hash_Table *table = create_table(size);

    int choice;
    char name[32];
    float gpa;

    do {
        printf("\n--- Hash Table Demo ---\n");
        printf("1. Insert\n2. Search\n3. Print Table\n4. Back\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%31s", name);
                printf("Enter GPA: ");
                scanf("%f", &gpa);
                insert_hashtable(table, name, gpa);
                break;
            case 2:
                printf("Enter Name to Search: ");
                scanf("%31s", name);
                Hash_Node *node = search_hashtable(table, name);
                if (node)
                    printf("Found: %s with GPA %.2f\n", node->name, node->GPA);
                else
                    printf("Not Found.\n");
                break;
            case 3:
                print_hashtable(table);
                break;
            case 4:
                break;
        }
    } while (choice != 4);

    free_hashtable(table);
}

void demo_bst() {
    char answer[64];
    printf("\nDoes a Binary Search Tree always guarantee O(log n) search? (yes/no) ");
    scanf("%63s", answer);
    if (strcasecmp(answer, "no") == 0) {
        printf("Correct! It can degrade to O(n) if unbalanced.\n");
    } else {
        printf("Incorrect, It can degrade to O(n) if the tree is unbalanced.\n");
    }

    BST_Node *root = NULL;
    int choice, val;

    do {
        printf("\n--- BST Demo ---\n");
        printf("1. Insert\n2. In-Order Traversal\n3. Search\n4. Back\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter integer: ");
                scanf("%d", &val);
                root = bst_insert(root, val);
                break;
            case 2:
                printf("Tree: ");
                bst_inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Search for: ");
                scanf("%d", &val);
                if (bst_search(root, val))
                    printf("Found %d!\n", val);
                else
                    printf("%d not found.\n", val);
                break;
            case 4:
                break;
        }
    } while (choice != 4);

    bst_free(root);
}

int main() {
    srand(time(NULL));
    int choice;

    while (1) {
        printf("\n=============================\n");
        printf("   DATA STRUCTURES CLI APP   \n");
        printf("=============================\n");
        printf("1. Array\n");
        printf("2. Linked List\n");
        printf("3. Stack\n");
        printf("4. Queue\n");
        printf("5. Hash Table\n");
        printf("6. Binary Search Tree (BST)\n");
        printf("0. Exit\n");
        printf("-----------------------------\n");
        printf("Select an option: ");

        if (scanf("%d", &choice) != 1) {
            clear_buffer();
            continue;
        }

        switch (choice) {
            case 1:
                demo_array();
                break;
            case 2:
                demo_linked_list();
                break;
            case 3:
                demo_stack();
                break;
            case 4:
                demo_queue();
                break;
            case 5:
                demo_hashtable();
                break;
            case 6:
                demo_bst();
                break;
            case 0:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option.\n");
        }
    }
    return 0;
}
