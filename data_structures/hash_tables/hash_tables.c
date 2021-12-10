/**
 * Author: Yannick Brenning
 * Date: 02.11.2021
 * Description: Implementation of simple hash table with linear probing
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
    } printf("\n");
}

/* Tests */

void test_ht_init() {
    ht_t *hash_table = ht_init();
    assert(hash_table != NULL);

    for (int i = 0; i < MAX_SIZE; i++) {
        assert(hash_table->entries[i] == NULL);
    }

    ht_destroy(&hash_table);
}

void test_ht_entry_init() {
    entry_t *entry = ht_entry_init("Ross", "636-48018");
    assert(strcmp(entry->key, "Ross") == 0 && strcmp(entry->value, "636-48018") == 0);
    free(entry->key);
    free(entry->value);
    free(entry);
}

void test_ht_destroy() {
    ht_t *hash_table = ht_init();
    ht_destroy(&hash_table);
    assert(hash_table == NULL);
}

void test_ht_hash() {
    int indices[11];
    int index_1 = ht_hash("BTC", MAX_SIZE);
    int index_2 = ht_hash("BTC", MAX_SIZE);
    assert(index_1 == index_2);

    indices[0] = index_1;
    indices[1] = ht_hash("ETH", MAX_SIZE);
    indices[2] = ht_hash("MIOTA", MAX_SIZE);
    indices[3] = ht_hash("DOGE", MAX_SIZE);
    indices[4] = ht_hash("XRP", MAX_SIZE);
    indices[5] = ht_hash("ADA", MAX_SIZE);
    indices[6] = ht_hash("SOL", MAX_SIZE);
    indices[7] = ht_hash("LTC", MAX_SIZE);
    indices[8] = ht_hash("BCH", MAX_SIZE);
    indices[9] = ht_hash("ETC", MAX_SIZE);

    for (int i = 0; i < 10; i++) {
        assert(indices[i] >= 0 && indices[i] < MAX_SIZE);
    }
}

void test_ht_add() {
    ht_t *hash_table = ht_init();
    entry_t *entry_1 = ht_entry_init("BTC", "Bitcoin");
    int index = ht_hash(entry_1->key, MAX_SIZE);

    ht_add(hash_table, entry_1);
    assert(strcmp(hash_table->entries[index]->value, entry_1->value) == 0);

    // Add same entry again to check if duplicate keys are possible
    ht_add(hash_table, entry_1);
    assert(hash_table->entries[index + 1] == NULL);

    // Add entry with same value to see if duplicate values are possible
    entry_t *entry_2 = ht_entry_init("BCH", "Bitcoin");
    ht_add(hash_table, entry_2);
    index = ht_hash(entry_2->key, MAX_SIZE);
    assert(strcmp(hash_table->entries[index]->value, entry_2->value) == 0);

    ht_destroy(&hash_table);
}

void test_ht_get() {
    ht_t *hash_table = ht_init();
    assert(ht_get(hash_table, "BTC") == NULL);

    entry_t *entry_1 = ht_entry_init("BTC", "Bitcoin");
    ht_add(hash_table, entry_1);
    assert(strcmp(ht_get(hash_table, "BTC"), "Bitcoin") == 0);

    ht_destroy(&hash_table);
}

void test_ht_key_exists() {
    ht_t *hash_table = ht_init();
    assert(!ht_key_exists(hash_table, "BTC"));

    entry_t *entry_1 = ht_entry_init("BTC", "Bitcoin");
    ht_add(hash_table, entry_1);
    assert(ht_key_exists(hash_table, "BTC"));

    ht_destroy(&hash_table);
}

void test_ht_remove_key() {
    ht_t *hash_table = ht_init();
    entry_t *entry_1 = ht_entry_init("BTC", "Bitcoin");
    int index = ht_hash(entry_1->key, MAX_SIZE);

    ht_add(hash_table, entry_1);
    ht_remove_key(hash_table, "BTC");
    assert(!ht_key_exists(hash_table, "BTC"));
    assert(hash_table->entries[index] == NULL);

    ht_destroy(&hash_table);
}

void run_all_tests() {
    test_ht_init();
    test_ht_entry_init();
    test_ht_destroy();
    test_ht_hash();
    test_ht_add();
    test_ht_get();
    test_ht_key_exists();
    test_ht_remove_key();
}

int main() {
    run_all_tests();
    return 0;
}
