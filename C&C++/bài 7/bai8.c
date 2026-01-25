#include <stdio.h>

int main() {
    int n, x;
    int originalNum;
    int count = 0; 

    printf("Nhap vao so nguyen n: ");
    scanf("%d", &n);
    printf("Nhap vao chu so x (0-9) can dem: ");
    scanf("%d", &x);
    originalNum = n;
    do {
        int lastDigit = n % 10;
        if (lastDigit == x) {
            count++;
        }
        n = n / 10;

    } while (n > 0);

    printf("Chu so %d xuat hien %d lan trong so %d.\n", x, count, originalNum);

    return 0;
}
