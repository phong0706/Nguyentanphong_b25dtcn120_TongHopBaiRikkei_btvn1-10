#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char chuoi1[200];
    char chuoi2[200];
    int do_dai1, do_dai2;
    int giong_nhau = 1;
    int i;

    printf("Nhap chuoi thu nhat: ");
    fgets(chuoi1, sizeof(chuoi1), stdin);
    chuoi1[strcspn(chuoi1, "\n")] = '\0';

    printf("Nhap chuoi thu hai: ");
    fgets(chuoi2, sizeof(chuoi2), stdin);
    chuoi2[strcspn(chuoi2, "\n")] = '\0';

    do_dai1 = strlen(chuoi1);
    do_dai2 = strlen(chuoi2);

    if (do_dai1 != do_dai2) {
        giong_nhau = 0;
    } else {
        for (i = 0; i < do_dai1; i++) {
            if (tolower(chuoi1[i]) != tolower(chuoi2[i])) {
                giong_nhau = 0;
                break;
            }
        }
    }

    if (giong_nhau == 1) {
        printf("Giong nhau\n");
    } else {
        printf("Khac nhau\n");
    }

    return 0;
}
