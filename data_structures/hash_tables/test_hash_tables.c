#include "hash_tables.h"

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
    //test_ht_hash();
    //test_ht_add();
    //test_ht_get();
    //test_ht_key_exists();
    //test_ht_remove_key();
}

int main() {
    run_all_tests();
    return 0;
}
