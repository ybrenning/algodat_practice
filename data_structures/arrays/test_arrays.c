#include "arrays.h"

void test_darray_init() {
    DArray *my_darray = darray_init(0);
    assert(my_darray->size == 0);
    assert(my_darray->capacity == DEF_CAPACITY);
    darray_destroy(&my_darray);

    my_darray = darray_init(DEF_CAPACITY + 1);
    assert(my_darray->capacity == DEF_CAPACITY * RESIZE_FACTOR);
}

void test_darray_destroy() {
    DArray *my_darray = darray_init(DEF_CAPACITY);
    darray_destroy(&my_darray);
    assert(my_darray == NULL);
}

void test_darray_isempty() {
    DArray *my_darray = darray_init(DEF_CAPACITY);
    assert(darray_isempty(my_darray));
    darray_destroy(&my_darray);
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
    darray_destroy(&my_darray);

    my_darray = darray_init(DEF_CAPACITY);
    for (int i = 0; i < DEF_CAPACITY + 1; i++) {
        darray_push(my_darray, i + 1);
    }
    assert(my_darray->size == 17 && my_darray->capacity == DEF_CAPACITY * RESIZE_FACTOR);
    darray_destroy(&my_darray);
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
    darray_destroy(&my_darray);
}

void test_darray_pop() {
    DArray *my_darray = darray_init(DEF_CAPACITY);
    assert(darray_pop(my_darray) == -1);
    darray_push(my_darray, 1);
    assert(darray_pop(my_darray) == 1);
    assert(darray_isempty(my_darray));
    darray_destroy(&my_darray);

    my_darray = darray_init(DEF_CAPACITY * RESIZE_FACTOR);
    for (int i = 0; i < DEF_CAPACITY + 1; i++) {
        darray_push(my_darray, i + 1);
    }

    assert(darray_pop(my_darray) == 17);
    assert(my_darray->capacity == DEF_CAPACITY);
    darray_destroy(&my_darray);
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
    darray_destroy(&my_darray);

    my_darray = darray_init(DEF_CAPACITY);
    for (int i = 0; i < DEF_CAPACITY + 1; i++) {
        darray_push(my_darray, i + 1);
    }

    assert(my_darray->size == DEF_CAPACITY + 1);
    assert(my_darray->capacity == DEF_CAPACITY * RESIZE_FACTOR);
    darray_destroy(&my_darray);
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
    darray_destroy(&my_darray);

    my_darray = darray_init(DEF_CAPACITY);
    for (int i = 0; i < DEF_CAPACITY + 1; i++) {
        darray_push(my_darray, i + 1);
    }

    assert(darray_delete(my_darray, DEF_CAPACITY) == DEF_CAPACITY + 1);
    assert(my_darray->capacity == DEF_CAPACITY);
    darray_destroy(&my_darray);
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
    darray_destroy(&my_darray);
}

void run_all_tests() {
    test_darray_init();
    test_darray_destroy();
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
