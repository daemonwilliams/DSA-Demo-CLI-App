#include "../include/hash.h"

int hash_function(const char *key, int size) {
    unsigned long hash = 5381;
    int c;
    const char *ptr = key;

    while ((c = *ptr++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return (int)(hash % size);
}

Hash_Table *create_table(int size) {
    Hash_Table *table = (Hash_Table *)malloc(sizeof(Hash_Table));
    if (!table)
        return NULL;

    table->size = size;
    table->buckets = (Hash_Node **)calloc(size, sizeof(Hash_Node *));
    if (!table->buckets) {
        free(table);
        return NULL;
    }

    return table;
}

void insert_hashtable(Hash_Table *table, const char *name, float gpa) {
    if (!table)
        return;

    int index = hash_function(name, table->size);

    // Check if key already exists to update GPA
    Hash_Node *curr = table->buckets[index];
    while (curr) {
        if (strcmp(curr->name, name) == 0) {
            curr->GPA = gpa;
            return;
        }
        curr = curr->next;
    }

    // Otherwise, insert at the beginning of the bucket (O(1))
    Hash_Node *newNode = (Hash_Node *)malloc(sizeof(Hash_Node));
    if (!newNode)
        return;

    strncpy(newNode->name, name, 31);
    newNode->name[31] = '\0';
    newNode->GPA = gpa;
    newNode->next = table->buckets[index];
    table->buckets[index] = newNode;
}

Hash_Node *search_hashtable(Hash_Table *table, const char *name) {
    if (!table)
        return NULL;

    int index = hash_function(name, table->size);
    Hash_Node *curr = table->buckets[index];

    while (curr) {
        if (strcmp(curr->name, name) == 0) {
            return curr;
        }
        curr = curr->next;
    }

    return NULL;
}

void delete_hashtable(Hash_Table *table, const char *name) {
    if (!table)
        return;

    int index = hash_function(name, table->size);
    Hash_Node *curr = table->buckets[index];
    Hash_Node *prev = NULL;

    while (curr) {
        if (strcmp(curr->name, name) == 0) {
            if (prev) {
                prev->next = curr->next;
            } else {
                table->buckets[index] = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void print_hashtable(Hash_Table *table) {
    if (!table)
        return;

    for (int i = 0; i < table->size; i++) {
        printf("Bucket %d: ", i);
        Hash_Node *curr = table->buckets[i];
        while (curr) {
            printf("[%s: %.2f] -> ", curr->name, curr->GPA);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

void free_hashtable(Hash_Table *table) {
    if (!table)
        return;

    for (int i = 0; i < table->size; i++) {
        Hash_Node *curr = table->buckets[i];
        while (curr) {
            Hash_Node *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(table->buckets);
    free(table);
}
