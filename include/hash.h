#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Hash_Node {
    char name[32];
    float GPA;
    struct Hash_Node *next;
} Hash_Node;

typedef struct Hash_Table {
    Hash_Node **buckets;
    int size;
} Hash_Table;

int hash_function(const char *key, int size);

Hash_Table* create_table(int size);

void insert_hashtable(Hash_Table *table, const char *name, float gpa);

Hash_Node* search_hashtable(Hash_Table *table, const char *name);

void delete_hashtable(Hash_Table *table, const char *name);

void print_hashtable(Hash_Table *table);

void free_hashtable(Hash_Table *table);