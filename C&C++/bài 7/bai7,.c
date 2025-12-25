#include <stdio.h>

int main() {
    int a, b;
    int i;
    int j;

    printf("Nhap vao so nguyen a: ");
    scanf("%d", &a);
    printf("Nhap vao so nguyen b: ");
    scanf("%d", &b);
    
    printf("Cac so nguyen to trong khoang [%d, %d] la: ", a, b);

    for (i = a; i <= b; i++) {
        
        int isPrime = 1;

        if (i < 2) {
            isPrime = 0;
        } else {
            for ( j = 2; j * j <= i; j++) {
                
                if (i % j == 0) {
                    isPrime = 0;
                    break;
                }
            }
        }

        if (isPrime == 1) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}
