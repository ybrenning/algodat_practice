#include <stdio.h>

int binary_search(int *arr, int len, int val) {
    int l = 0;
    int r = len - 1;
    int mid = r / 2;

    while (l != r) {
        if (arr[mid] < val) {
            l = mid + 1;
            mid = l + (r - l) / 2;
        } else if (arr[mid] > val) {
            r = mid - 1;
            mid = l + (r - l) / 2;
        } else return arr[mid];
    }
    return -1;
}

int main() {

    return 0;
}