/**
 * @author Yannick Brenning
 * @date 21.11.2021
 * @brief Implementation of a dynamic array data structure
 */

#include <stdlib.h>
#include <assert.h>
#include "arrays.h"

size_t init_capacity(int capacity) {
    if (capacity <= DEF_CAPACITY)
        return DEF_CAPACITY;

    size_t new_capacity = DEF_CAPACITY;
    while (new_capacity < capacity) {
        new_capacity *= RESIZE_FACTOR;
    }

    return new_capacity;
}

size_t darray_grow(size_t capacity) {
    return capacity * RESIZE_FACTOR;
}

size_t darray_shrink(size_t capacity) {
    return capacity / RESIZE_FACTOR;
}

darray_t *darray_init(int capacity) {
    darray_t *my_darray = (darray_t *) malloc(sizeof(darray_t));
    assert(my_darray);

    my_darray->size = 0;
    my_darray->capacity = init_capacity(capacity);
    my_darray->data = (int *) malloc(sizeof(int) * my_darray->capacity);
    assert(my_darray->data);

    return my_darray;
}

void darray_destroy(darray_t **darray) {
    free((*darray)->data);
    free(*darray);
    *darray = NULL;
}

bool darray_isempty(darray_t *darray) {
    return (darray->size == 0);
}

int darray_get(darray_t *darray, int index) {
    if (index < 0 || index >= darray->size || darray_isempty(darray))
        return -1;

    return darray->data[index];
}

void darray_push(darray_t *darray, int val) {
    if (darray->size == darray->capacity) {
        darray->capacity = darray_grow(darray->capacity);
        darray->data = (int *) realloc(darray->data, sizeof(int) * darray->capacity);
        assert(darray->data);
    }

    darray->size++;
    darray->data[darray->size - 1] = val;
}

int darray_pop(darray_t *darray) {
    if (darray_isempty(darray)) {
        return -1;
    } else {
        int val = darray->data[darray->size - 1];
        darray->size--;

        if (darray->size <= darray->capacity / RESIZE_FACTOR) {
            darray->capacity = darray_shrink(darray->capacity);
            darray->data = (int *) realloc(darray->data, sizeof(int) * darray->capacity);
            assert(darray->data);
        }

        return val;
    }
}

bool darray_insert(darray_t *darray, int val, int index) {
    if (index < 0 || index > darray->size) {
        return false;
    } else if (index == darray->size) {
        darray_push(darray, val);
        return true;
    }

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

int darray_delete(darray_t *darray, int index) {
    if (index < 0 || index >= darray->size || darray_isempty(darray)) {
        return -1;
    } else {
        int retval = darray->data[index];
        size_t new_size = darray->size - 1;
        for (int i = index; i < new_size; i++) {
            darray->data[i] = darray->data[i + 1];
        }

        if (new_size <= darray->capacity / RESIZE_FACTOR) {
            darray->capacity = darray_shrink(darray->capacity);
            darray->data = (int *) realloc(darray->data, sizeof(int) * darray->capacity);
            assert(darray->data);
        }

        darray->size--;
        return retval;
    }
}

int darray_find(darray_t *darray, int val) {
    if (darray_isempty(darray))
        return -1;

    for (int i = 0; i < darray->size; i++) {
        if (darray->data[i] == val)
            return i;
    }

    return -1;
}

void darray_print(darray_t *darray) {
    printf("Data: [ ");

    for (int i = 0; i < darray->size; i++) {
        printf("%d ", darray->data[i]);
    }

    printf("]\n");
}
