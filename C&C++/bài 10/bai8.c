#include <stdio.h>

int main() {
    int n;
    int i, j, temp, check;
    int x, left, right, mid, result_index;

    scanf("%d", &n);
    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &x);

    for (i = 0; i < n - 1; i++) {
        check = 0; 
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                check = 1; 
            }
        } 
        if (check == 0) {
            break; 
        }
    } 

    printf("Mang sau khi sap xep: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

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
        }
        else {
            right = mid - 1;
        }
    }

    printf("Chi so cua phan tu can tim: %d\n", result_index);

    getchar();
    getchar();

    return 0;
}
