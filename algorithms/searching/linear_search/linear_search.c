#include <stdio.h>

int linear_search(int *arr, int len, int val) {
    for (int i = 0; i < len; i++)
        if (arr[i] == val)
            return val;
    return -1;
}

int main() {

    return 0;
}