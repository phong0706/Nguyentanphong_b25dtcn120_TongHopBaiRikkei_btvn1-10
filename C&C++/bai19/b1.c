#include <stdio.h>

int findMax(int *arr, int n) {
    int max = *arr;
    for (int i = 1; i < n; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    return max;
}

int main() {
    int arr[] = {10, 55, 23, 7, 89, 42, 91, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Mang hien tai: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    int maxVal = findMax(arr, n);

    printf("Phan tu lon nhat la: %d\n", maxVal);

    return 0;
};
