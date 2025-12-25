#include <stdio.h>

int main() {
    int n;
    int i, x;
    int left, right, mid;
    int result_index = -1; // -1 nghia là chua tim thay
    
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &x);
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
    if (result_index != -1) {
        printf("%d\n", result_index);
    } else {
        printf("Khong tim thay\n");
    }

    return 0;
}
