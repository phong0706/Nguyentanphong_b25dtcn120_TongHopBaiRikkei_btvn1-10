#include <stdio.h>

void copyArray(int *src, int *dest, int n) {
    for (int i = 0; i < n; i++) {
        *(dest + i) = *(src + i);
    }
}

int main() {
    int mangA[] = {10, 20, 30, 40, 50};
    int n = 5;
    int mangB[5];

    copyArray(mangA, mangB, n);

    printf("Mang B sau khi sao chep: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(mangB + i));
    }
    printf("\n");

    return 0;
}
