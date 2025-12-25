#include <stdio.h>

int compareArrays(int *a, int *b, int n) {
    for (int i = 0; i < n; i++) {
        if (*(a + i) != *(b + i)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 5};
    int arr3[] = {1, 2, 3, 9, 5};
    int n = 5;

    if (compareArrays(arr1, arr2, n) == 1) {
        printf("Mang 1 va Mang 2 giong nhau.\n");
    } else {
        printf("Mang 1 va Mang 2 khac nhau.\n");
    }

    if (compareArrays(arr1, arr3, n) == 1) {
        printf("Mang 1 va Mang 3 giong nhau.\n");
    } else {
        printf("Mang 1 va Mang 3 khac nhau.\n");
    }

    return 0;
}
