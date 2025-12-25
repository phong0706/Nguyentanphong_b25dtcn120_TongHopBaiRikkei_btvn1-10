#include <stdio.h>

int main() {
    int n = 10;
    int *ptr;

    ptr = &n;

    printf("Gia tri cua n (dung ten bien): %d\n", n);
    printf("Dia chi cua n (dung toan tu &): %p\n", &n);

    printf("Gia tri cua n (dung con tro *ptr): %d\n", *ptr);
    printf("Dia chi cua n (dung con tro ptr): %p\n", ptr);
    
    printf("Dia chi cua con tro ptr (dung &ptr): %p\n", &ptr);

    return 0;
}
