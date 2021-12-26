/**
 * @author Yannick Brenning
 * @date 02.11.2021
 * @brief Implementation of simple hash table with linear probing
 */

#include "hash_tables.h"

void check_address(void *address) {
    if (!address) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
}

ht_t *ht_init() {
    ht_t *hash_table = malloc(sizeof(ht_t));
    check_address(hash_table);
    hash_table->entries = malloc(sizeof(entry_t) * MAX_SIZE);
    check_address(hash_table->entries);

    for (int i = 0; i < MAX_SIZE; i++) {
        hash_table->entries[i] = NULL;
    }

    return hash_table;
}

entry_t *ht_entry_init(const char *key, const char *value) {
    entry_t *entry = malloc(sizeof(entry_t));
    check_address(entry);
    entry->key = malloc(strlen(key) + 1);
    entry->value = malloc(strlen(value) + 1);

    strcpy(entry->key, key);
    strcpy(entry->value, value);
    return entry;
}

void ht_destroy(ht_t **hash_table) {
    for (int i = 0; i < MAX_SIZE; i++) {
        if ((*hash_table)->entries[i] != NULL) {
            free((*hash_table)->entries[i]->key);
            free((*hash_table)->entries[i]->value);
            free((*hash_table)->entries[i]);
            (*hash_table)->entries[i] = NULL;
        }
    }

    free((*hash_table)->entries);
    (*hash_table)->entries = NULL;
    free(*hash_table);
    *hash_table = NULL;
}

int ht_hash(const char *key, const int m) {
    int value = 0;
    unsigned int i = 0;
    while (key[i] != '\0') {
        value = value + (22 * key[i++]);
    }

    return value % m;
}

void ht_add(ht_t *hash_table, entry_t *entry) {
    unsigned int i = 0;
    int hash = ht_hash(entry->key, MAX_SIZE);

    /* Linear probing (if entry is not null, check next index) */
    while (hash_table->entries[(hash + i) % MAX_SIZE] != NULL && i < MAX_SIZE) {
        /* Check if the keys are identical at any point and update the value if they are */
        if (strcmp(hash_table->entries[(hash + i) % MAX_SIZE]->key, entry->key) == 0) {
            hash_table->entries[(hash + i) % MAX_SIZE]->key = entry->value;
            return;
        }

        i++;
    }

    if (hash_table->entries[(hash + i) % MAX_SIZE] == NULL) {
        hash_table->entries[(hash + i) % MAX_SIZE] = entry;
    } else return;
}

char *ht_get(ht_t *hash_table, const char *key) {
    unsigned int i = 0;
    int hash = ht_hash(key, MAX_SIZE);
    while (hash_table->entries[(hash + i) % MAX_SIZE] != NULL && i < MAX_SIZE) {
        if (strcmp(hash_table->entries[(hash + i) % MAX_SIZE]->key, key) == 0) {
            return hash_table->entries[(hash + i) % MAX_SIZE]->value;
        }

        i++;
    }

    return NULL;
}

bool ht_key_exists(ht_t *hash_table, const char *key) {
    char *value = ht_get(hash_table, key);
    return (value != NULL);
}

void ht_remove_key(ht_t *hash_table, const char *key) {
    if (ht_key_exists(hash_table, key)) {
        unsigned int i = 0;
        int hash = ht_hash(key, MAX_SIZE);
        while (hash_table->entries[(hash + i) % MAX_SIZE] != NULL && i < MAX_SIZE) {
            if (strcmp(hash_table->entries[(hash + i) % MAX_SIZE]->key, key) == 0) {
                hash_table->entries[(hash + i) % MAX_SIZE] = NULL;
            }

            i++;
        }
    }
}

void ht_print(ht_t *hash_table) {
    printf("\n");

    for (int i = 0; i < MAX_SIZE; i++) {
        if (hash_table->entries[i] == NULL) {
            printf("%d : \n", i + 1);
        } else {
            printf("%s : %s\n", hash_table->entries[i]->key, hash_table->entries[i]->value);
        }
    }

    printf("\n");
}
