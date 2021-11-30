/**
 * Author: Yannick Brenning
 * Date: 21.11.2021
 * Description: Implementation of a dynamic array data structure
 */

#include "arrays.h"

void check_address(void *address) {
    if (!address) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
}

int init_capacity(int capacity) {
    /* if the users custom capacity is smaller or equal to the default, then set to default */
    if (capacity <= DEF_CAPACITY) {
        return DEF_CAPACITY;
    }
    /* If the custom capacity is larger, resize the default until it reaches the custon capacity */
    int new_capacity = DEF_CAPACITY;
    while (new_capacity < capacity) {
        new_capacity *= RESIZE_FACTOR;
    }
    return new_capacity;
}

int darray_grow(int capacity) {
    return capacity * RESIZE_FACTOR;
}

int darray_shrink(int capacity) {
    return capacity / RESIZE_FACTOR;
}

DArray *darray_init(int capacity) {
    DArray *my_darray = (DArray *) malloc(sizeof(DArray));
    check_address(my_darray);

    my_darray->size = 0;
    my_darray->capacity = init_capacity(capacity);
    my_darray->data = (int *) malloc(sizeof(int) * my_darray->capacity);
    check_address(my_darray->data);

    return my_darray;
}

void darray_destroy(DArray *darray) {
    free(darray->data);
    free(darray);
    darray = NULL;
}

bool darray_isempty(DArray *darray) {
    return (darray->size == 0);
}

int darray_get(DArray *darray, int index) {
    if (index < 0 || index >= darray->size || darray_isempty(darray))
        return -1;

    return darray->data[index];
}

void darray_push(DArray *darray, int val) {
    /* If max capacity is reached, grow the array */
    if (darray->size == darray->capacity) {
        darray->capacity = darray_grow(darray->capacity);
        darray->data = (int *) realloc(darray->data, sizeof(int) * darray->capacity);
        check_address(darray->data);
    }

    darray->size++;
    darray->data[darray->size - 1] = val;
}

int darray_pop(DArray *darray) {
    if (darray_isempty(darray)) {
        return -1;
    } else {
        int val = darray->data[darray->size - 1];
        darray->size--;
        /* Check if shrink is possible */
        if (darray->size <= darray->capacity / RESIZE_FACTOR) {
            darray->capacity = darray_shrink(darray->capacity);
            darray->data = (int *) realloc(darray->data, sizeof(int) * darray->capacity);
            check_address(darray->data);
        }
        return val;
    }
}

void darray_insert(DArray *darray, int val, int index) {
    if (index < 0 || index > darray->size) {
        return;
    } else if (index == darray->size) {
        darray_push(darray, val);
        return;
    }

    /* If max capacity is reached, grow the array */
    if (darray->size == darray->capacity) {
        darray->capacity = darray_grow(darray->capacity);
        darray->data = (int *) realloc(darray->data, sizeof(int) * darray->capacity);
        check_address(darray->data);
    }

    darray->size++;
    for (int i = darray->size - 1; i > index; i--) {
        darray->data[i] = darray->data[i - 1];
    }
    darray->data[index] = val;
}

int darray_delete(DArray *darray, int index) {
    if (index < 0 || index >= darray->size || darray_isempty(darray)) {
        return -1;
    } else {
        int val = darray->data[index];
        int new_size = darray->size - 1;
        for (int i = index; i < new_size; i++)
            darray->data[i] = darray->data[i + 1];

        /* Check if shrink is possible */
        if (new_size <= darray->capacity / RESIZE_FACTOR) {
            darray->capacity = darray_shrink(darray->capacity);
            darray->data = (int *) realloc(darray->data, sizeof(int) * darray->capacity);
            check_address(darray->data);
        }

        darray->size--;
        return val;
    }
}

int darray_find(DArray *darray, int val) {
    if (darray_isempty(darray))
        return -1;
    for (int i = 0; i < darray->size; i++) {
        if (darray->data[i] == val)
            return i;
    } return -1;
}

void darray_print(DArray *darray) {
    printf("Size: %d\n", darray->size);
    printf("Capacity: %d\n", darray->capacity);
    printf("Data: [ ");
    for (int i = 0; i < darray->size; i++) {
        printf("%d ", darray->data[i]);
    } printf("]\n\n");
}

/* Testing */
void test_darray_init() {
    DArray *my_darray = darray_init(0);
    assert(my_darray->size == 0);
    assert(my_darray->capacity == DEF_CAPACITY);
    darray_destroy(my_darray);

    my_darray = darray_init(DEF_CAPACITY + 1);
    assert(my_darray->capacity == DEF_CAPACITY * RESIZE_FACTOR);
}

void test_darray_isempty() {
    DArray *my_darray = darray_init(DEF_CAPACITY);
    assert(darray_isempty(my_darray));
    darray_destroy(my_darray);
}

void test_darray_push() {
    DArray *my_darray = darray_init(DEF_CAPACITY);
    darray_push(my_darray, 1);
    assert(my_darray->size == 1);

    darray_push(my_darray, 2);
    assert(my_darray->size == 2);

    darray_push(my_darray, 3);
    assert(my_darray->size == 3);
    assert(my_darray->capacity == DEF_CAPACITY);
    darray_destroy(my_darray);

    my_darray = darray_init(DEF_CAPACITY);
    for (int i = 0; i < DEF_CAPACITY + 1; i++) {
        darray_push(my_darray, i + 1);
    }
    assert(my_darray->size == 17 && my_darray->capacity == DEF_CAPACITY * RESIZE_FACTOR);
    darray_destroy(my_darray);
}

void test_darray_get() {
    DArray *my_darray = darray_init(DEF_CAPACITY);
    assert(darray_get(my_darray, 0) == -1);
    assert(darray_get(my_darray, -1) == -1);
    assert(darray_get(my_darray, 5) == -1);

    darray_push(my_darray, 1);
    assert(darray_get(my_darray, 0) == 1);
    assert(darray_get(my_darray, 1) == -1);

    darray_push(my_darray, 2);
    darray_push(my_darray, 3);
    assert(darray_get(my_darray, 2) == 3);
    darray_destroy(my_darray);
}

void test_darray_pop() {
    DArray *my_darray = darray_init(DEF_CAPACITY);
    assert(darray_pop(my_darray) == -1);
    darray_push(my_darray, 1);
    assert(darray_pop(my_darray) == 1);
    assert(darray_isempty(my_darray));
    darray_destroy(my_darray);

    my_darray = darray_init(DEF_CAPACITY * RESIZE_FACTOR);
    for (int i = 0; i < DEF_CAPACITY + 1; i++) {
        darray_push(my_darray, i + 1);
    }

    assert(darray_pop(my_darray) == 17);
    assert(my_darray->capacity == DEF_CAPACITY);
    darray_destroy(my_darray);
}

void test_darray_insert() {
    DArray *my_darray = darray_init(DEF_CAPACITY);
    darray_insert(my_darray, 1, 1);
    assert(darray_isempty(my_darray));
    darray_insert(my_darray, 1, 0);
    assert(darray_get(my_darray, 0) == 1);
    darray_insert(my_darray, 2, 1);
    assert(darray_get(my_darray, 1) == 2);
    darray_insert(my_darray, 0, 0);
    assert(darray_get(my_darray, 0) == 0);
    darray_insert(my_darray, 3, 1);
    assert(darray_get(my_darray, 1) == 3  && darray_get(my_darray, 2) == 1);
    darray_destroy(my_darray);

    my_darray = darray_init(DEF_CAPACITY);
    for (int i = 0; i < DEF_CAPACITY + 1; i++) {
        darray_push(my_darray, i + 1);
    }

    assert(my_darray->size == DEF_CAPACITY + 1);
    assert(my_darray->capacity == DEF_CAPACITY * RESIZE_FACTOR);
    darray_destroy(my_darray);
}

void test_darray_delete() {
    DArray *my_darray = darray_init(DEF_CAPACITY);
    assert(darray_delete(my_darray, 0) == -1);

    darray_push(my_darray, 1);
    assert(darray_delete(my_darray, 1) == -1);
    assert(darray_delete(my_darray, -1) == -1);
    assert(darray_delete(my_darray, 0) == 1);
    assert(darray_isempty(my_darray));
    darray_push(my_darray, 2);
    darray_push(my_darray, 3);
    darray_push(my_darray, 4);
    assert(darray_delete(my_darray, 1) == 3);
    assert(darray_get(my_darray, 1) == 4);
    darray_destroy(my_darray);

    my_darray = darray_init(DEF_CAPACITY);
    for (int i = 0; i < DEF_CAPACITY + 1; i++) {
        darray_push(my_darray, i + 1);
    }

    assert(darray_delete(my_darray, DEF_CAPACITY) == DEF_CAPACITY + 1);
    assert(my_darray->capacity == DEF_CAPACITY);
    darray_destroy(my_darray);
}

void test_darray_find() {
    DArray *my_darray = darray_init(DEF_CAPACITY);
    assert(darray_find(my_darray, 1) == -1);

    darray_push(my_darray, 1);
    darray_push(my_darray, 2);
    darray_push(my_darray, 3);
    darray_push(my_darray, 4);
    assert(darray_find(my_darray, 2) == 1);
    assert(darray_find(my_darray, 5) == -1);
    darray_destroy(my_darray);
}

void run_all_tests() {
    test_darray_init();
    test_darray_isempty();
    test_darray_push();
    test_darray_get();
    test_darray_pop();
    test_darray_insert();
    test_darray_delete();
    test_darray_find();
}

int main() {
    run_all_tests();
    return 0;
}