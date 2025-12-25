#include <stdio.h>

int main() {
    int n;
    int i;
    printf("Nhap n = ");
    scanf("%d", &n);

    int arr[n];
    printf("Nhap arr = ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int value;
    printf("Nhap value = ");
    scanf("%d", &value);
    int count = 0; 
    for (i = 0; i < n; i++) {
        if (arr[i] == value) {
            count++; 
        }
    }
    printf("Output: %d\n", count);

    return 0;
}
