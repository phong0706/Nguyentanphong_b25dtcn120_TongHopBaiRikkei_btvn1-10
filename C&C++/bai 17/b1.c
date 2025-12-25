#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char chuoi_nhap[100];
    char chuoi_dao_nguoc[100];
    char chuoi_kiem_tra[100];
    int do_dai, i, j;

    printf("Nhap chuoi can kiem tra: ");
    fgets(chuoi_nhap, sizeof(chuoi_nhap), stdin);

    do_dai = strlen(chuoi_nhap);
    if (do_dai > 0 && chuoi_nhap[do_dai - 1] == '\n') {
        chuoi_nhap[do_dai - 1] = '\0';
        do_dai--;
    }

    for (i = 0; i < do_dai; i++) {
        chuoi_kiem_tra[i] = tolower(chuoi_nhap[i]);
    }
    chuoi_kiem_tra[do_dai] = '\0';

    j = 0;
    for (i = do_dai - 1; i >= 0; i--) {
        chuoi_dao_nguoc[j] = chuoi_kiem_tra[i];
        j++;
    }
    chuoi_dao_nguoc[j] = '\0';

    if (strcmp(chuoi_kiem_tra, chuoi_dao_nguoc) == 0) {
        printf("La palindrome\n");
    } else {
        printf("Khong phai palindrome\n");
    }

    return 0;
}
