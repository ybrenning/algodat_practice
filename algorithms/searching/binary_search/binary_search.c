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

int binary_search_rec(int *arr, int val, int l, int r) {
    int m = (l + r) / 2;
    if (arr[m] == val) return arr[m];
    else if (m == l && m == r) return -1;
    else if (arr[m] < val) {
        l = m + 1;
        return binary_search_rec(arr, val, l, r);
    } else {
        r = m - 1;
        return binary_search_rec(arr, val, l, r);
    }
}

int main() {

    return 0;
}