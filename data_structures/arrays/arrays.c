/**
 * @author Yannick Brenning
 * @date 21.11.2021
 * @brief Implementation of a dynamic array data structure
 */

#include "arrays.h"

int init_capacity(int capacity) {
    // If the users custom capacity is smaller or equal to the default, then set to default
    if (capacity <= DEF_CAPACITY)
        return DEF_CAPACITY;

    // If the custom capacity is larger, resize the default until it reaches the custom capacity
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
    assert(my_darray);

    my_darray->size = 0;
    my_darray->capacity = init_capacity(capacity);
    my_darray->data = (int *) malloc(sizeof(int) * my_darray->capacity);
    assert(my_darray->data);

    return my_darray;
}

void darray_destroy(DArray **darray) {
    free((*darray)->data);
    free(*darray);
    *darray = NULL;
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
    // If max capacity is reached, grow the array
    if (darray->size == darray->capacity) {
        darray->capacity = darray_grow(darray->capacity);
        darray->data = (int *) realloc(darray->data, sizeof(int) * darray->capacity);
        assert(darray->data);
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
        // Check if shrink is possible
        if (darray->size <= darray->capacity / RESIZE_FACTOR) {
            darray->capacity = darray_shrink(darray->capacity);
            darray->data = (int *) realloc(darray->data, sizeof(int) * darray->capacity);
            assert(darray->data);
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

    // If max capacity is reached, grow the array
    if (darray->size == darray->capacity) {
        darray->capacity = darray_grow(darray->capacity);
        darray->data = (int *) realloc(darray->data, sizeof(int) * darray->capacity);
        assert(darray->data);
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
        for (int i = index; i < new_size; i++) {
            darray->data[i] = darray->data[i + 1];
        }

        // Check if shrink is possible
        if (new_size <= darray->capacity / RESIZE_FACTOR) {
            darray->capacity = darray_shrink(darray->capacity);
            darray->data = (int *) realloc(darray->data, sizeof(int) * darray->capacity);
            assert(darray->data);
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
    }

    return -1;
}

void darray_print(DArray *darray) {
    printf("Size: %d\n", darray->size);
    printf("Capacity: %d\n", darray->capacity);

    printf("Data: [ ");
    for (int i = 0; i < darray->size; i++) {
        printf("%d ", darray->data[i]);
    }

    printf("]\n\n");
}
