#include <stdio.h>

int main() {
    // Khai bao va khoi tao cac bien theo yeu cau
    
    short a = 10;                     // short: so nguyen co dau kich thuoc nho, thuong la 2 byte
    int b = 100;                      // int: so nguyen co dau kich thuoc chuan, thuong la 4 byte
    long c = 1000L;                   // long: so nguyen co dau kich thuoc lon, thuong la 4 hoac 8 byte
    long long d = 10000LL;            // long long: so nguyen co dau kich thuoc rat lon, thuong la 8 byte
    
    unsigned short e = 20;            // unsigned short: so nguyen khong dau kich thuoc nho, 2 byte
    unsigned int f = 200;             // unsigned int: so nguyen khong dau kich thuoc chuan, 4 byte
    unsigned long g = 2000L;          // unsigned long: so nguyen khong dau kich thuoc lon, 4 hoac 8 byte
    unsigned long long h = 20000LL;   // unsigned long long: so nguyen khong dau kich thuoc rat lon, 8 byte
    
    char i = 'X';                     // char: luu tru mot ky tu don, 1 byte

    // In gia tri cua cac bien ra man hinh de kiem tra
    printf("Gia tri cua cac bien:\n");
    printf("short a = %hd\n", a);
    printf("int b = %d\n", b);
    printf("long c = %ld\n", c);
    printf("long long d = %lld\n", d);
    printf("unsigned short e = %hu\n", e);
    printf("unsigned int f = %u\n", f);
    printf("unsigned long g = %lu\n", g);
    printf("unsigned long long h = %llu\n", h);
    printf("char i = %c\n", i);

    return 0;
}	
