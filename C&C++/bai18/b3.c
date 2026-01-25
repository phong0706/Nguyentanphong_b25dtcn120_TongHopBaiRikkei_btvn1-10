#include <stdio.h>

void tinhTong(int *so1, int *so2, int *ketQua) {
    *ketQua = *so1 + *so2;
}

int main() {
    int a = 15;
    int b = 25;
    int sum = 0;

    printf("Gia tri ban dau cua bien 'tong': %d\n", sum);

    tinhTong(&a, &b, &sum);

    printf("Gia tri cua 'tong' sau khi goi ham: %d\n", sum);

    return 0;
}
