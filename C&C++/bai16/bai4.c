#include <stdio.h>

int main() {
    char str[] = "Xin chao, day la mot chuoi vi du.";
    
    char kyTuNhap;
    
    int count = 0;
    
    printf("Chuoi goc: \"%s\"\n", str);

    printf("Nhap vao 1 ky tu bat ky de dem: ");
    
    scanf(" %c", &kyTuNhap);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == kyTuNhap) {
            count++;
        }
    }

    printf("Ky tu '%c' xuat hien %d lan trong chuoi.\n", kyTuNhap, count);

    return 0;
}
