#include "arrays.h"

void check_address(void *address) {
    if (!address) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
}

int init_capacity(int capacity) {
    if (capacity <= DEF_CAPACITY) {
        return DEF_CAPACITY;
    }
    while (capacity > DEF_CAPACITY) {
        capacity = RESIZE_FACTOR * DEF_CAPACITY;
    }
    return capacity;
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

bool darray_isempty(DArray *darray) {
    if (darray->size == 0) {
        return true;
    } else return false;
}

int darray_get(DArray *darray, int index) {
    if (index < 0 || index >= darray->size || darray_isempty(darray)) {
        return -1;
    }
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
    if (index < 0 || index >= darray->size) {
        return;
    } else if (darray->size == darray->capacity) {
        /* If max capacity is reached, grow the array */
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
        for (int i = index; i < new_size; i++) {
            darray->data[i] = darray->data[i + 1];
        }

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

void darray_print(DArray *darray) {
    printf("Size: %d\n", darray->size);
    printf("Capacity: %d\n", darray->capacity);
    printf("Data: [ ");
    for (int i = 0; i < darray->size; i++) {
        printf("%d ", darray->data[i]);
    } printf("]\n\n");
}

int main() {

    /* Some tests */
    DArray *my_darray = darray_init(16);
    darray_push(my_darray, 3);
    darray_push(my_darray, 6);
    darray_push(my_darray, 90);
    darray_push(my_darray, 300);
    darray_push(my_darray, 22);
    darray_push(my_darray, 656);
    darray_push(my_darray, 767);
    darray_push(my_darray, 6);
    darray_push(my_darray, 77);
    darray_push(my_darray, 78);
    darray_push(my_darray, 99);
    darray_push(my_darray, 23);
    darray_push(my_darray, 1);
    darray_push(my_darray, 12);
    darray_push(my_darray, 2323);
    darray_push(my_darray, 199);
    darray_push(my_darray, 632);
    darray_print(my_darray);
    darray_pop(my_darray);
    darray_print(my_darray);

    darray_insert(my_darray, 333, 5);
    darray_print(my_darray);

    darray_delete(my_darray, 6);
    darray_print(my_darray);

    printf("%d", darray_get(my_darray, 4));
    return 0;
}