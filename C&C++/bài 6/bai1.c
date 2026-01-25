#include <stdio.h>

int main() {
    int N;
    int tong = 0;
    int i;

    printf("Nhap N = ");
    scanf("%d", &N);

    for ( i = 1; i <= N; ++i) {
        tong += i;
    }

    printf("Tong = %d\n", tong);

    return 0;
}
