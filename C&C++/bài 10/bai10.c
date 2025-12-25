#include <stdio.h>

int main() {
    int n;
    int i, j, temp, min, min_idx;
    int x, left, right, mid, result_index;

    printf("Nhap so luong phan tu n: ");
    scanf("%d", &n);
    int arr[n];

    printf("Nhap %d phan tu (chua sap xep):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    min = arr[0]; 
    for (i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i]; 
        }
    }
    printf("1. So nho nhat trong mang la: %d\n", min);

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }

    printf("2. Mang sau khi sap xep (Selection Sort):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Nhap so nguyen can tim trong mang da sap xep: ");
    scanf("%d", &x);

    result_index = -1; 
    left = 0;
    right = n - 1;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            result_index = mid; 
            break;
        }
        if (arr[mid] < x) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }

    printf("3. Ket qua tim kiem (Binary Search):\n");
    if (result_index != -1) {
        printf("Tim thay %d tai chi so: %d\n", x, result_index);
    } else {
        printf("Khong tim thay %d\n", x);
    }
    
    getchar();
    getchar();

    return 0;
}
