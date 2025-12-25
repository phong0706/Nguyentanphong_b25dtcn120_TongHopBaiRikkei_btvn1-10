#include <stdio.h>

int i; 
int isPrime(int number) {
    if (number < 2) {
        return 0;
    }
    for (i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    int number;
    printf("Nhap mot so: ");
    scanf("%d", &number);
    if (isPrime(number)) {
        printf("La so nguyen to");
    } else {
        printf("Khong phai so nguyen to");
    }
    return 0;
}
