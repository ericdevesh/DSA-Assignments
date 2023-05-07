#include <stdio.h>

void bubble_sort(int arr[], int n, int order) {
    int i, j, temp;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(order == 1) {
                // Ascending order
                if(arr[j] > arr[j+1]) {
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            } else {
                // Descending order
                if(arr[j] < arr[j+1]) {
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }
}

int main() {
    int arr[] = {10, 3, 7, 2, 8, 4, 9, 1, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    // Ascending order
    printf("Array before sorting in ascending order:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bubble_sort(arr, n, 1);
    printf("Array after sorting in ascending order:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Descending order
    printf("Array before sorting in descending order:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bubble_sort(arr, n, 0);
    printf("Array after sorting in descending order:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

