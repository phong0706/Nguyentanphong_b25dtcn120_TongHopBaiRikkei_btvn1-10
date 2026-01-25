#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char mat_khau[100];
    int do_dai;
    int i;

    int co_do_dai = 0;
    int co_chu_hoa = 0;
    int co_chu_thuong = 0;
    int co_chu_so = 0;
    int co_ky_tu_dac_biet = 0;

    printf("Nhap mat khau: ");
    fgets(mat_khau, sizeof(mat_khau), stdin);
    mat_khau[strcspn(mat_khau, "\n")] = '\0';

    do_dai = strlen(mat_khau);

    if (do_dai >= 8) {
        co_do_dai = 1;
    }

    for (i = 0; i < do_dai; i++) {
        char c = mat_khau[i];
        
        if (isupper(c)) {
            co_chu_hoa = 1;
        } else if (islower(c)) {
            co_chu_thuong = 1;
        } else if (isdigit(c)) {
            co_chu_so = 1;
        } else {
            co_ky_tu_dac_biet = 1;
        }
    }

    if (co_do_dai == 1 && co_chu_hoa == 1 && co_chu_thuong == 1 && co_chu_so == 1 && co_ky_tu_dac_biet == 1) {
        printf("Hop le\n");
    } else {
        printf("Khong hop le\n");
    }

    return 0;
};
