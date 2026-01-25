#include <stdio.h>

int main() {
    int a, b;
    printf("Nhap so nguyen duong thu nhat: ");
    scanf("%d", &a);
    printf("Nhap so nguyen duong thu hai: ");
    scanf("%d", &b);
    int num1 = a;
    int num2 = b;
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    printf("Uoc chung lon nhat (UCLN) cua %d va %d la: %d\n", num1, num2, a);

    return 0;
}
