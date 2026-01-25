#include <stdio.h>
#include <string.h>

int main() {
    char chuoiA[200];
    char chuoiB[100];
    int do_dai_A, do_dai_B;
    int i, j;
    int tim_thay = 0;

    printf("Nhap chuoi A: ");
    fgets(chuoiA, sizeof(chuoiA), stdin);
    chuoiA[strcspn(chuoiA, "\n")] = '\0';

    printf("Nhap chuoi B: ");
    fgets(chuoiB, sizeof(chuoiB), stdin);
    chuoiB[strcspn(chuoiB, "\n")] = '\0';

    do_dai_A = strlen(chuoiA);
    do_dai_B = strlen(chuoiB);

    if (do_dai_B == 0) {
        tim_thay = 1;
    }

    for (i = 0; i <= do_dai_A - do_dai_B; i++) {
        int khop = 1;
        for (j = 0; j < do_dai_B; j++) {
            if (chuoiA[i + j] != chuoiB[j]) {
                khop = 0;
                break;
            }
        }
        
        if (khop == 1) {
            tim_thay = 1;
            break;
        }
    }

    if (tim_thay == 1) {
        printf("Co\n");
    } else {
        printf("Khong\n");
    }

    return 0;
};
