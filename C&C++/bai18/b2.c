#include <stdio.h>

void swap(int *pa, int *pb) {
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

int main() {
    int a = 5;
    int b = 10;

    printf("Truoc khi hoan doi: %d va %d\n", a, b);

    swap(&a, &b);

    printf("Sau khi hoan doi: %d va %d\n", a, b);

    return 0;
}
