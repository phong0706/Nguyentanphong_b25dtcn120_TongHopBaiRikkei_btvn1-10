#include <stdio.h>
#include <string.h> 

int main() {
    char chuoi[200];
    char ky_tu_xoa;
    int i, j;

    printf("Nhap vao mot chuoi bat ky: ");
    fgets(chuoi, sizeof(chuoi), stdin);

    chuoi[strcspn(chuoi, "\n")] = '\0';

    printf("Nhap vao mot ky tu can xoa: ");
    scanf("%c", &ky_tu_xoa);

    i = 0;
    j = 0;

    while (chuoi[i] != '\0') {
        if (chuoi[i] != ky_tu_xoa) {
            chuoi[j] = chuoi[i];
            j++;
        }
        i++;
    }

    chuoi[j] = '\0';

    printf("Ket qua sau khi xoa: %s\n", chuoi);

    return 0;
};
