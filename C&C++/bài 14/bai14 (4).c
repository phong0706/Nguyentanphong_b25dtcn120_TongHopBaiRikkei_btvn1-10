#include <stdio.h>

int i; 
int isPrime(int number) {
    int sum = 0;
    for ( i = 1; i <= number / 2; i++) {
        if (number % i == 0) {
            sum += i;
        }
    }
    if (sum == number && number != 0) {
        return 1; 
    } else {
        return 0; 
    }
}

int main() {
    int number1, number2;
    printf("Nhap so thu nhat: ");
    scanf("%d", &number1);
    printf("Nhap so thu hai: ");
    scanf("%d", &number2);
    if (isPrime(number1)) {
        printf("%d la so hoan hao\n", number1);
    } else {
        printf("%d khong phai so hoan hao\n", number1);
    }
    if (isPrime(nombre2)) {
        printf("%d la so hoan hao\n", number2);
    } else {
        printf("%d khong phai so hoan hao\n", number2);
    }
    return 0;
}
