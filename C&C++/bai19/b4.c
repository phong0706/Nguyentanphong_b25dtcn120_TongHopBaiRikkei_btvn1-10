#include <stdio.h>

int countValue(int *arr, int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (*(arr + i) == x) {
            count++;
        }
    }
    return count;
}

int main() {
    int arr[] = {2, 5, 8, 2, 10, 2, 15, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;

    printf("Mang hien tai: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    printf("Nhap gia tri x can tim: ");
    scanf("%d", &x);

    int result = countValue(arr, n, x);

    printf("Gia tri %d xuat hien %d lan trong mang.\n", x, result);

    return 0;
};
