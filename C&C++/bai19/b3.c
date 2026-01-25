#include <stdio.h>

void average(int *arr, int n, float *result) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *(arr + i);
    }
    *result = (float)sum / n;
}

int main() {
    int arr[] = {10, 5, 20, 15, 30};
    int n = 5;
    float avgResult;

    printf("Mang hien tai: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    average(arr, n, &avgResult);

    printf("Gia tri trung binh la: %.2f\n", avgResult);

    return 0;
};
