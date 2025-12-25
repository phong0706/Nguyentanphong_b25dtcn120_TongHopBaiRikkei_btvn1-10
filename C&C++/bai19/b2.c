#include <stdio.h>

void countEvenOdd(int *arr, int n, int *even, int *odd) {
    *even = 0;
    *odd = 0;
    for (int i = 0; i < n; i++) {
        if (*(arr + i) % 2 == 0) {
            (*even)++;
        } else {
            (*odd)++;
        }
    }
}

int main() {
    int arr[] = {12, 5, 7, 10, 2, 4, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int evenCount, oddCount;

    printf("Mang hien tai: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    countEvenOdd(arr, n, &evenCount, &oddCount);

    printf("So phan tu chan: %d\n", evenCount);
    printf("So phan tu le: %d\n", oddCount);

    return 0;
};
