/**
 * @author Yannick Brenning
 * @date 23.12.2021
 * @brief Implementation of merge sort
 */

#include "merge_sort.h"

void create_list(int *arr) {
    for (int i = 0; i < ARR_LEN; i++) {
        arr[i] = rand() % 100 + 1;
    }
}

void merge(int *arr, unsigned int l, unsigned int m, unsigned int r) {
    unsigned int len_l = m - l + 1;
    unsigned int len_r = r - m;
    int arr_l[len_l], arr_r[len_r];

    for (int i = 0; i < len_l; i++) {
        arr_l[i] = arr[i + l];
    }

    for (int i = 0; i < len_r; i++) {
        arr_r[i] = arr[i + m + 1];
    }

    unsigned int i = 0; unsigned int j = 0;
    unsigned int k = l;
    while (i < len_l && j < len_r) {
        if (arr_l[i] <= arr_r[j]) {
            arr[k] = arr_l[i];
            i++;
        } else if (arr_l[i] > arr_r[j]) {
            arr[k] = arr_r[j];
            j++;
        }

        k++;
    }

    while (i < len_l) {
        arr[k] = arr_l[i];
        i++;
        k++;
    }

    while (j < len_r) {
        arr[k] = arr_r[j];
        j++;
        k++;
    }
}

void merge_sort(int *arr, unsigned int l, unsigned int r) {
    if (l < r) {
        int m = l + ((r - l) / 2);
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void test_merge_sort() {
    int arr[ARR_LEN];

    for (int i = 0; i < NUM_OF_TESTS; i++) {
        create_list(arr);
        merge_sort(arr, 0, ARR_LEN - 1);
        for (int j = 1; j < ARR_LEN; j++) {
            assert(arr[j - 1] <= arr[j]);
        }
    }
}

int main() {
    test_merge_sort();
    return 0;
}