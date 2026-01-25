#include <stdio.h>
#include <string.h> 

int main() {
    char chuoi1[200]; 
    char chuoi2[100];

    printf("Nhap chuoi thu nhat: ");
    fgets(chuoi1, sizeof(chuoi1), stdin);

    printf("Nhap chuoi thu hai: ");
    fgets(chuoi2, sizeof(chuoi2), stdin);

    chuoi1[strcspn(chuoi1, "\n")] = '\0';
    chuoi2[strcspn(chuoi2, "\n")] = '\0';

    strcat(chuoi1, chuoi2);

    printf("Ket qua sau khi noi: %s\n", chuoi1);

    return 0;
}
