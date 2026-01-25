#include <stdio.h>

int main() {
    int a, b;
    int temp_a, temp_b;
    int ucln;
    int bcnn;

    printf("Nhap so nguyen duong thu nhat: ");
    scanf("%d", &a);
    
    printf("Nhap so nguyen duong thu hai: ");
    scanf("%d", &b);

    temp_a = a;
    temp_b = b;

    while (temp_a != temp_b) {
        if (temp_a > temp_b) {
            temp_a = temp_a - temp_b;
        } else {
            temp_b = temp_b - temp_a;
        }
    }
    
    ucln = temp_a;

    bcnn = (a * b) / ucln;

    printf("Uoc chung lon nhat (UCLN) la: %d\n", ucln);
    printf("Boi chung nho nhat (BCNN) cua %d va %d la: %d\n", a, b, bcnn);

    return 0;
}
