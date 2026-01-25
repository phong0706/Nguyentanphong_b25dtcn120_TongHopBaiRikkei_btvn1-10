#include <stdio.h>

void pointerArray(int *ptr, int n) {
    printf("Cac phan tu trong mang la:\n");
    
    for (int i = 0; i < n; i++) {
        printf("%d ", *(ptr + i));
    }
    
    printf("\n");
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Goi ham de in mang \n");
    pointerArray(arr, n);

    return 0;
}
