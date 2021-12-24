/**
 * @author Yannick Brenning
 * @date 23.12.2021
 * @brief Implementation of quick sort
 */

#include "quick_sort.h"

void create_list(int *arr) {
    for (int i = 0; i < ARR_LEN; i++) {
        arr[i] = rand() % 100 + 1;
    }
}

void swap(int *item_1, int *item_2) {
    int temp = *item_1;
    *item_1 = *item_2;
    *item_2 = temp;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int p_index = low;

    for (int i = low; i < high; i++) {
        if (arr[i] <= pivot) {
            swap(&arr[i], &arr[p_index]);
            p_index++;
        }
    }

    swap(&arr[high], &arr[p_index]);
    return p_index;
}

void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quick_sort(arr, low, p - 1);
        quick_sort(arr, p + 1, high);
    }
}

void test_quick_sort() {
    int arr[ARR_LEN];

    for (int i = 0; i < NUM_OF_TESTS; i++) {
        create_list(arr);
        quick_sort(arr, 0, ARR_LEN - 1);
        for (int j = 1; j < ARR_LEN; j++) {
            assert(arr[j - 1] <= arr[j]);
        }
    }
}

int main() {
    test_quick_sort();
    return 0;
}