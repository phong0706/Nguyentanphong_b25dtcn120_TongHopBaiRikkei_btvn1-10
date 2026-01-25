#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char chuoi[200];
    int lua_chon;
    int i;
    int do_dai;

    printf("--- MENU ---\n");
    printf("1. Nhap 1 -> Chuyen chuoi sang CHU HOA\n");
    printf("2. Nhap 2 -> Chuyen chuoi sang chu thuong\n");
    printf("Nhap lua chon cua ban (1 hoac 2): ");
    scanf("%d", &lua_chon);

    getchar(); 

    printf("Nhap vao mot chuoi bat ky: ");
    fgets(chuoi, sizeof(chuoi), stdin);

    do_dai = strlen(chuoi);
    if (do_dai > 0 && chuoi[do_dai - 1] == '\n') {
        chuoi[do_dai - 1] = '\0';
    }

    if (lua_chon == 1) {
        for (i = 0; chuoi[i] != '\0'; i++) {
            chuoi[i] = toupper(chuoi[i]);
        }
        printf("Ket qua: %s\n", chuoi);
    } else if (lua_chon == 2) {
        for (i = 0; chuoi[i] != '\0'; i++) {
            chuoi[i] = tolower(chuoi[i]);
        }
        printf("Ket qua: %s\n", chuoi);
    } else {
        printf("Lua chon khong hop le.\n");
    }

    return 0;
}
