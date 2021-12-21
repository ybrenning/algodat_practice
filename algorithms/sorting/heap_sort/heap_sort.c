/**
 * @author Yannick Brenning
 * @date 21.12.2021
 * @brief Implementation of heapsort using min-heapify
 */

#include "heap_sort.h"

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

void max_heapify(int *arr, unsigned int len, int i) {
    int largest = i; // Initialize largest as the root
    int l = (2 * i) + 1; // Left child of root
    int r = (2 * i) + 2; // Right child of root

    // If left child is larger than root
    if (l < len && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than root
    if (r < len && arr[r] > arr[largest])
        largest = r;

    // If root is not the largest
    if (largest != i) {
        // Swap so that the root is now the largest
        swap(&arr[largest], &arr[i]);
        // Heapify the subtree of the left/right child
        max_heapify(arr, len, largest);
    }
}

void heap_sort(int *arr, int len) {
    // Starting at the bottom,
    // heapify every subtree up to the root
    for (int i = len / 2 - 1; i >= 0; i--) {
        max_heapify(arr, len, i);
    }

    // Sort our array using the property of max-heaps
    for (int i = len - 1; i >= 0; i--) {
        // Since our array is max-heapified,
        // we know our first element is the largest
        // and can push it to the end of the array
        swap(&arr[0], &arr[i]);

        // Now we re-heapify the rest of the heap
        max_heapify(arr, i, 0);
    }
}

void test_heap_sort() {
    int arr[ARR_LEN];

    for (int i = 0; i < NUM_OF_TESTS; i++) {
        create_list(arr);
        heap_sort(arr, ARR_LEN);
        for (int j = 1; j < ARR_LEN; j++) {
            assert(arr[j - 1] <= arr[j]);
        }
    }
}

int main() {
    srand(time(NULL));
    test_heap_sort();
    return 0;
}