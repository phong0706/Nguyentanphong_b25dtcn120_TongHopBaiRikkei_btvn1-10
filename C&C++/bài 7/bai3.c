#include <stdio.h>

int main() {
    int n, reversedNum = 0, remainder, originalNum;
    printf("Nhap mot so nguyen duong n: ");
    scanf("%d", &n);
    originalNum = n;
    while (n > 0) {
        remainder = n % 10;
        n /= 10; 
    }
    if (originalNum == reversedNum) {
        printf("%d la so doi xung (palindrome).\n", originalNum);
    } else {
        printf("%d khong phai la so doi xung (palindrome).\n", originalNum);
    }

    return 0;
}
