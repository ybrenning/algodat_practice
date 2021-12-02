/**
 * Author: Yannick Brenning
 * Date: 02.11.2021
 * Description: Implementation of simple hash table with linear probing
 */

#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct entry_t {
    char *key;
    char *value;
} entry_t;

typedef struct ht_t {
    entry_t **entries;
} ht_t;

// Check if memory address is valid
void check_address(void *address);
// Initialize hash table
ht_t *ht_init();
// Initialize entry for hash table
entry_t *ht_entry_init(const char *key, const char *value);
// Free memory used for hash table
void ht_destroy(ht_t *hash_table);
// Create a new hash
int ht_hash(const char *key, const int m);
// Add entry to hash table
void ht_add(ht_t *hash_table, entry_t *entry);
// Get value corresponding to key
char *ht_get(ht_t *hash_table, const char *key);
// Check if entry exists in hash table
bool ht_key_exists(ht_t *hash_table, const char *key);
// Remove entry by key
void ht_remove_key(ht_t *hash_table, const char *key);
// Print content of ahsh table to console
void ht_print(ht_t *hash_table);

#endif //HASH_TABLES_H
