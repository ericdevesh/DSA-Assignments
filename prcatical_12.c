#include <stdio.h>

int linear_search(int arr[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {5, 2, 9, 1, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 7;
    int index = linear_search(arr, n, key);
    if (index == -1) {
        printf("Element not found.\n");
    } else {
        printf("Element found at index %d.\n", index);
    }
    return 0;
}

