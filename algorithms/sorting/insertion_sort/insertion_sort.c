/**
 * @author Yannick Brenning
 * @date 10.12.2021
 * @brief Implementation of insertion sort
 */

#include "insertion_sort.h"

void create_list(int *arr) {
    for (int i = 0; i < ARR_LEN; i++) {
        arr[i] = rand() % 100 + 1;
    }
}

void insertion_sort(int *arr, unsigned const int len) {
    int i, j, key;
    for (i = 1; i < len; i++) {
        key = arr[i];

        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void test_insertion_sort() {
    int arr[ARR_LEN];

    for (int i = 0; i < NUM_OF_TESTS; i++) {
        create_list(arr);
        insertion_sort(arr, ARR_LEN);
        for (int j = 1; j < ARR_LEN; j++) {
            assert(arr[j - 1] <= arr[j]);
        }
    }
}

int main() {
    srand(time(NULL));
    test_insertion_sort();
    return 0;
}