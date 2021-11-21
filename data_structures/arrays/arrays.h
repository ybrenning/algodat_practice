#ifndef ARRAYS_H
#define ARRAYS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEF_CAPACITY 16
#define RESIZE_FACTOR 2

typedef struct dynamic_array {
    int size;
    int capacity;
    int *data;
} DArray;

void check_address(void *address);
int init_capacity(int capacity);
int darray_grow(int capacity);
int darray_shrink(int capacity);
DArray *darray_init(int capacity);
bool darray_isempty(DArray *darray);
int darray_get(DArray *darray, int index);
void darray_push(DArray *darray, int val);
int darray_pop(DArray *darray);
void darray_insert(DArray *darray, int val, int index);
int darray_delete(DArray *darray, int index);
void darray_print(DArray *darray);

#endif //ARRAYS_H
