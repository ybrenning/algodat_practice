/**
 * @author Yannick Brenning
 * @date 02.11.2021
 * @brief Implementation of simple hash table with linear probing
 */

#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE ((size_t) 1 << 4)

typedef struct entry_t {
    char *key;
    char *value;
} entry_t;

typedef struct ht_t {
    entry_t **entries;
} ht_t;

// Initialize hash table
ht_t *ht_init();
// Initialize entry for hash table
entry_t *ht_entry_init(const char *key, const char *value);
// Free memory used for hash table
void ht_destroy(ht_t **hash_table);
// Create a new hash
unsigned int ht_hash(const char *key, int m);
// Add entry to hash table
void ht_add(ht_t *hash_table, entry_t *entry);
// Get value corresponding to key
char *ht_get(ht_t *hash_table, const char *key);
// Check if entry exists in hash table
bool ht_key_exists(ht_t *hash_table, const char *key);
// Remove entry by key
bool ht_remove_key(ht_t *hash_table, const char *key);
// Print content of hash table to console
void ht_print(ht_t *hash_table);

// Tests
void test_ht_init();
void test_ht_entry_init();
void test_ht_destroy();
void test_ht_hash();
void test_ht_add();
void test_ht_get();
void test_ht_key_exists();
void test_ht_remove_key();
void run_all_tests();

#endif //HASH_TABLES_H
